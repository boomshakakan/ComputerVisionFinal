#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <array>
#include <string>
#include <opencv2/opencv.hpp>
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include "imgProcess.h"

using namespace cv;
using namespace std;
using namespace tesseract;

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Usage: ./imgProcess <Image_Path>\n");
        return -1;
    }

    Mat image, originalImg, grayImg;
    // read image sent via the command line in RGB format
    originalImg = imread(argv[1], 1);

    imshow("Original Image", originalImg);

    if (!originalImg.data) {
        printf("No image data\n");
        return -1;
    }
    // convert the rgb image to grayscale
    cvtColor(originalImg, grayImg, CV_RGB2GRAY);

    imshow("Grayscale Image", grayImg);

    int threshVal = 200;

    Mat binaryImg = grayImg.clone();

    cout << "ROWS:" << grayImg.rows << endl << "COLS:" << grayImg.cols << endl;

    for (int a=1; a<grayImg.cols-1; a++) {
        for (int b=1; b<grayImg.rows-1; b++) {
            int sum = 0;
            int avg = 0;
            // this loop is for finding our 3x3 neighborhood
            for (int c=-1; c<=1; c++) {
                for (int d=-1; d<=1; d++) {
                    sum = sum + (int)grayImg.at<uchar>(b+d,a+c);
                    avg = sum / 9;
                }
            }
            // correctly returns the value (0-255) of each pixel
            
            if (avg > threshVal) {
                binaryImg.at<uchar>(b,a) = 255;
            }
            else {
                binaryImg.at<uchar>(b,a) = 0;
            }
            int pixelValue = (int)binaryImg.at<uchar>(b,a);
            //cout << pixelValue << endl;
        }
    }

    imshow("Binary image", binaryImg);

    Mat erosionImg = binaryImg.clone();
    int currMin, newC, newR;
    // PERFORM FIRST STAGE OF DILATION AND EROSION
    // START OF EROSION
    for (int a=1; a<binaryImg.cols-1; a++) {
        for (int b=1; b<binaryImg.rows-1; b++) {
            currMin = (int)binaryImg.at<uchar>(b,a);
            // loop to find 3x3 neighborhood of pixel
            for (int c=a-1; c<=a+1; c++) {
                for (int d=b-1; d<=b+1; d++) {
                    newC = c;
                    newR = d;

                    if (currMin > (int)binaryImg.at<uchar>(newR,newC)) {
                        currMin= (int)binaryImg.at<uchar>(newR,newC);
                    }
                }
            }
            erosionImg.at<uchar>(b,a) = currMin;
        }
    }

    imshow("Image after erosion applied", erosionImg);

    Mat dilationImg = erosionImg.clone();
    int currMax;
    // START OF DILATION
    for (int a=1; a<erosionImg.cols-1; a++) {
        for (int b=1; b<erosionImg.rows-1; b++) {
            currMax = (int)erosionImg.at<uchar>(b,a);
            // loop to find 3x3 neighborhood of pixel
            for (int c=a-1; c<=a+1; c++) {
                for (int d=b-1; d<=b+1; d++) {
                    newC = c;
                    newR = d;

                    if (currMax < (int)erosionImg.at<uchar>(newR,newC)) {
                        currMax = (int)erosionImg.at<uchar>(newR,newC);
                    }
                }
            }
            dilationImg.at<uchar>(b,a) = currMax;
        }
    }

    // ONE PASS OF EROSION AND DILATION HAS BEEN PERFORMED
    imshow("Image after 1 pass Erosion/Dilation", dilationImg);

    // initialize pointer to instance of TessBaseAPI class

    //string textOutput;

    //TessBaseAPI *ocr = new TessBaseAPI();
    //ocr->Init(NULL, "eng", OEM_LSTM_ONLY);

    waitKey(0);
    return 0;
}
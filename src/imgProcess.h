#ifndef IMGPROCESS_H
#define IMGPROCESS_H
#define imgProcess_VERSION_MAJOR @imgProcess_VERSION_MAJOR@
#define imgProcess_VERSION_MINOR @imgProcess_VERSION_MINOR@

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void writeToFile(string results) {
    ofstream newFile;

    newFile.open ("TesseractResults.txt");
    newFile << results;
    newFile.close();

    return;
}

void performThresholding(Mat grayscaleImg, Mat targetImg, int thresholdVal) {
    for (int a=1; a<grayscaleImg.cols-1; a++) {
        for (int b=1; b<grayscaleImg.rows-1; b++) {
            int sum = 0;
            int avg = 0;
            // this loop is for finding our 3x3 neighborhood
            for (int c=-1; c<=1; c++) {
                for (int d=-1; d<=1; d++) {
                    sum = sum + (int)grayscaleImg.at<uchar>(b+d,a+c);
                    avg = sum / 9;
                }
            }
            if (avg > thresholdVal) {
                targetImg.at<uchar>(b,a) = 255;
            }
            else {
                targetImg.at<uchar>(b,a) = 0;
            }
            int pixelValue = (int)targetImg.at<uchar>(b,a);
            //cout << pixelValue << endl;
        }
    }
    return;
}

void performErosion(Mat binaryImg, Mat targetImg, int stages) {
    int currMin, newC, newR;

    for (int x=0; x<stages; x++) {
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
                targetImg.at<uchar>(b,a) = currMin;
            }
        }
    }
    return;
}

void performDilation(Mat erosionImg, Mat targetImg, int stages) {
    int currMax, newC, newR;

    for (int x=0; x<stages; x++) {
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
                targetImg.at<uchar>(b,a) = currMax;
            }
        }
    }
    return;
}


#endif
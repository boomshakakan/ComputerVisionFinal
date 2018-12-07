
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
//using namespace tesseract;

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
    //imshow("Grayscale Image", grayImg);

    Mat binaryImg = grayImg.clone();
    // cout << "ROWS:" << grayImg.rows << endl << "COLS:" << grayImg.cols << endl;
    
    // we chose not to use openCV functions in order to better understand the implementation
    // some functions defined in imgProcess.h
    int threshVal = 200;
    performThresholding(grayImg, binaryImg, threshVal);

    //imshow("Binary image", binaryImg);
    // use this to invert the background and foreground pixels
    bitwise_not(binaryImg, binaryImg);
    //imshow("Inverted Colors", binaryImg);

    // PERFORM FIRST STAGE OF EROSION
    Mat erosionImg = binaryImg.clone();
    // pass in the binarized image, target image and number of iterations of erosion
    performErosion(binaryImg, erosionImg, 1);
    imshow("Image after erosion applied", erosionImg);

    Mat dilationImg = erosionImg.clone();
    // pass in the image after erosion, target image and number of iterations
    performDilation(erosionImg, dilationImg, 1);
    //imshow("Image after 1 pass Erosion/Dilation", dilationImg);

    // find all points where white pixels exist
    vector<Point> points;
    Mat_<uchar>::iterator iter = dilationImg.begin<uchar>();
    Mat_<uchar>::iterator end = dilationImg.end<uchar>();
    // we loop through the image and when we encounter a white pixel we push position to our vector
    for (; iter != end; ++iter) {
        if (*iter) {
            points.push_back(iter.pos());
        }
    }

    // compute the bounding box (rectangle) of text content using our points vector
    RotatedRect boundingBox = minAreaRect(Mat(points));

    // the problem with our output angle is that we have no reference for its direction
    // here we correct the angle
    double degree = boundingBox.angle;
    if (degree < -45) {
        degree += 90;
    }

    // THERE ARE SOME OUTLIERS HERE (WHEN CORRECTLY ALIGNED OR UPSIDE DOWN WE GET -90)
    cout << "Angle of our bounding box: " << degree << endl;
    // pass into this function some variables defined by the RotatedRect object (center, angle) and a scale factor of 1
    Mat rotationMatrix = getRotationMatrix2D(boundingBox.center, degree, 1);
    
    Mat rotatedImg;
    // INTER_CUBIC is our selected interpolation method
    warpAffine(dilationImg, rotatedImg, rotationMatrix, erosionImg.size(), INTER_CUBIC);
    imshow("Image after Rotation", rotatedImg);
    
    unsigned char selection;
    cout << "Press 1 if the image is inverted (upside-down), Otherwise press 2" << endl;
    waitKey(10);
    cin >> selection;

    if (selection == '1') {
        degree = degree + 180;
        rotationMatrix = getRotationMatrix2D(boundingBox.center, degree, 1);
        warpAffine(dilationImg, rotatedImg, rotationMatrix, erosionImg.size(), INTER_CUBIC);
        imshow("Corrected image angle", rotatedImg);
    }
    else {
        cout << "No changes made to image alignment" << endl;
    }

    // initialize pointer to instance of TessBaseAPI class
    string textOutput;
    string languageChoice = "eng";

    TessBaseAPI *ocr = new TessBaseAPI();
    ocr->Init(NULL, languageChoice, OEM_LSTM_ONLY);
    ocr->SetPageSegMode(PSM_AUTO);
    ocr->SetImage(rotatedImg.data, rotatedImg.cols, rotatedImg.rows, 3, rotatedImg.step);

    textOutput = string(ocr->GetUTF8Text());

    writeToFile(textOutput);

    cout << "Type 'e' to close the program" << endl;
    waitKey(10);
    cin >> selection;

    if (selection == 'e') {
        return 1;
    }

    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <array>
#include <opencv2/opencv.hpp>
#include "imgProcess.h"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    if (argc != 2) {
        printf("Usage: ./imgProcess <Image_Path>\n");
        return -1;
    }
    
    // OBJECT INITIALIZATIONS ARE WORKING CORRECTLY
    // pixel *pix = new pixel();
    // cout << pix->getIntensity() << endl;

    // image *img = new image;

    Mat image;
    image = imread(argv[1], 1);

    if (!image.data) {
        printf("No image data\n");
        return -1;
    }
    namedWindow("Display image", WINDOW_NORMAL);
    imshow("Display Image", image);

    waitKey(0);
    return 0;
}
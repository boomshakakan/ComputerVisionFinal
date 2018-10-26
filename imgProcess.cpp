#include <cstdio>
#include <cstdlib>
#include <opencv2/opencv.hpp>
#include "imgProcess.h"

using namespace cv;

/*
// CLASSES DEFINED IN HEADER FILE
class pixel {

}

class image {
    // This will be populated with our image object 
    // img[x][y] = our 2-D array of pixels
}
*/

int main(int argc, char** argv) {

    /*
    if (argc != 2){
        printf("Usage: ./imgProcess <Image_Path>\n");
        return -1;
    }
    */

        pixel pix = new pixel();
        pix.getIntensity();
        

        /*
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
        */
    }
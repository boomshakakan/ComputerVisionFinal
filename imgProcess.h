#ifndef IMGPROCESS_H
#define IMGPROCESS_H
#define imgProcess_VERSION_MAJOR @imgProcess_VERSION_MAJOR@
#define imgProcess_VERSION_MINOR @imgProcess_VERSION_MINOR@

#include <cstdio>
#include <iostream>

using namespace std;

class pixel { 
    private:
    // an image object (defined below) will contain a 2-D array of pixels (defined here)
    // pixel will also hold values such as PIXEL INTENSITY, ... ?
    // VARIABLES
    int intensity; // range of 0-255
    int x, y;

    public:
    // CONSTRUCTORS
    pixel() {
        cout << "Default pixel constructor called" << endl;
        intensity = 0;
    }

    pixel(int newIntensity) {
        cout << "Constructor called... intensity set" << endl;
        intensity = newIntensity;
    }

    pixel(int newIntensity, int c, int r) {
        cout << "Constructor called... intensity & coordinates set" << endl;
        intensity = newIntensity;
        x = c;
        y = r;
    }

    // destructor for pixel object 
    ~pixel() {
        cout << "Destructor called for pixel" << endl;
        // DESTROY (more important for image object)
    }

    // MEMBER FUNCTIONS
    void printIntensity() {
        cout << intensity << endl;
    }

    // GETTER AND SETTER FUNCTION FOR OUR PIXEL'S INTENSITY
    int getIntensity() {
        return intensity;
    }

    void setIntensity(int newIntensity) {
        intensity = newIntensity;
    }
};

class image { 
    private:
    // This will be populated with our image object -> img[x][y] = our 2-D array of pixels
    // VARIABLES
    // an example of how we would create our image object creating an array of pixel objects
    int r, c;

    public:
    // CONSTRUCTORS 
    image() {
        cout << "Default image constructor called" << endl;
    }

    image(int x, int y) {
        cout << "Constructor called with given row and column size" << endl;
        pixel arr[x][y];
    }
    
    ~image() {

    }
    // MEMBER FUNCTIONS
    
};

// we will use constructors and a nested for loop in order to initialize an array of pixels
// to give to our image object 

#endif
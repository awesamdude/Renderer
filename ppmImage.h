
#ifndef PPMIMAGE_H
#define PPMIMAGE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Pixel.h"


using namespace std;

class ppmImage {
    vector<Pixel> *pixels;
    int width, height;
    public:
        // Constructors
        ppmImage() : pixels(new vector<Pixel>()) {}
        ppmImage(vector<Pixel> *pixels, int width, int height) : 
        pixels(pixels), width(width), height(height) {}

        //Big Three
        ~ppmImage();
        ppmImage(const ppmImage& rhs);
        ppmImage& operator=(const ppmImage& rhs);

        //Helpers
        void copy(const ppmImage& rhs);

        //public
        void writeFile(string filename);



};

// Helper Functions

ppmImage::~ppmImage() {
    for(auto pixel: *pixels) {
        delete &pixel;
    }
}

void ppmImage::copy(const ppmImage& rhs) {
    this->pixels->clear();
}

ppmImage::ppmImage(const ppmImage& rhs) {
    copy(rhs);
}

ppmImage& ppmImage::operator=(const ppmImage& rhs) {
    if (this != &rhs) {
        copy(rhs);
    }
    return *this;
}

void ppmImage::writeFile(string filename) {
    ofstream img(filename);
    //Write Header
    img << "P3" << endl;
    img << this->width << " " << this->height << endl;
    img << "255" << endl;

    for(Pixel pixel: *pixels) {
        img << pixel.writable();
    }
}

#endif
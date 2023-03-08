#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include "Pixel.h"
#include "ppmImage.h"

using namespace std;
using namespace std::chrono;

const int width = 6000, height = 6000;

const int NUM_THREADS = 2;

const string FILENAME = "image.ppm";

int main() {

    vector<Pixel> *pixels = new vector<Pixel>(); 

    for (int y = 0; y < height; y++) {
        for (int x =0; x < width; x++) {
            Pixel *p = new Pixel();
            p->setRandomColor();
            pixels->push_back(*p);
            // Pixel* p = new Pixel(255, 0, 0);
            // img << p->writable();
        }
    }

    ppmImage *image = new ppmImage(pixels, width, height);

    auto start = high_resolution_clock::now();

    image->writeFile(FILENAME);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: "<< duration.count() << " ms" << endl;


    system("open image.ppm");

    return 0;
}
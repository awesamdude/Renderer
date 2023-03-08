#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include "Pixel.h"

using namespace std;
using namespace std::chrono;

const int width = 255, height = 255;

const int NUM_THREADS = 2;

int main() {

    ofstream img ("image.ppm");

    img << "P3" << endl;
    img << width << " " << height << endl;
    img << "255" << endl;

    auto start = high_resolution_clock::now();
    for (int y = 0; y < height; y++) {
        for (int x =0; x < width; x++) {
            Pixel* p = new Pixel();
            p->setRandomColor();
            img << p->writable();
            // Pixel* p = new Pixel(255, 0, 0);
            // img << p->writable();
        }
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken: "<< duration.count() << " ms" << endl;


    system("open image.ppm");

    return 0;
}
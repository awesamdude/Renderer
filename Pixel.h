#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <ctime>


class Pixel {
    int r;
    int g;
    int b;
    public:
        // Constructors
        Pixel() : r(0), g(0), b(0) {}
        Pixel(int r, int g, int b) : r(r), g(g), b(b) {}

        // Big three
        Pixel(const Pixel& p); // where p is a pixel
        Pixel& operator=(const Pixel& rhs); // Where rhs is a pixel on right side of =
        ~Pixel();
        //Helpers
        void copy(const Pixel& rhs);

        // public
        std::string writable();

        void setColor(int r, int g, int b);
        void setRandomColor();

};

void Pixel::copy(const Pixel& rhs) {
    this->r = rhs.r;
    this->g = rhs.g;
    this->b = rhs.b;
}

Pixel::Pixel(const Pixel& p) {
    copy(p);
}

Pixel& Pixel::operator=(const Pixel& rhs) {
    if(this != &rhs) {
        copy(rhs);
    }
    return *this;
}

Pixel::~Pixel() {
    delete this;
}

std::string Pixel::writable() {
    std::ostringstream oss;
    oss << this->r << " " << this->g << " " << this->b << std::endl;
    return oss.str();
}

void Pixel::setColor(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Pixel::setRandomColor() {
    std::srand(std::time(0));
    this->r = random() % 255;
    this->g =random() % 255;
    this->b = random() % 255;
}
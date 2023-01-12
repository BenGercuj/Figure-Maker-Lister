#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>
#include <fstream>
#include <vector>

// Import data and make representation of the colors on the rectangles; export a list of rectangles as a vector

struct sarok
{
    int R;
    int G;
    int B;

    sarok(int a, int b, int c): R(a), G(b), B(c) {}
};


class Rectangle
{

public:
    std::vector<sarok> sarkok;

    Rectangle() {}

    void beolvas(std::ifstream &bf);

    void forgat();

    void antiforgat();

    void kiirat()
    {
        for (sarok a : sarkok)
        {
            std::cout << a.R << " " << a.G << " " << a.B << std::endl;
        }

    }
};

#endif // RECTANGLE_HPP

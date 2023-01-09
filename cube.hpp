#ifndef CUBE_HPP
#define CUBE_HPP

#include "rectangle.hpp"
#include <iostream>

// Sort the imported rectangles and make as many cubes as possible from any vector of rectangles; export the cubes as a vector

class Cube
{

public:

    Rectangle base;
    Rectangle top;
    Rectangle near;
    Rectangle far;
    Rectangle right;
    Rectangle left;

    Cube() {}

    void cube_check();
};

#endif // CUBE_HPP

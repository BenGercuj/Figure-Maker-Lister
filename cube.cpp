#include "cube.hpp"


void Cube::cube_check()
{
    std::cout << 0 << " " << 0 << " " << 0 << " ; " << base.sarkok[0].R << " " << base.sarkok[0].G << " " << base.sarkok[0].B << std::endl;
    std::cout << 1 << " " << 0 << " " << 0 << " ; " << base.sarkok[1].R << " " << base.sarkok[1].G << " " << base.sarkok[1].B << std::endl;
    std::cout << 1 << " " << 1 << " " << 0 << " ; " << base.sarkok[2].R << " " << base.sarkok[2].G << " " << base.sarkok[2].B << std::endl;
    std::cout << 0 << " " << 1 << " " << 0 << " ; " << base.sarkok[3].R << " " << base.sarkok[3].G << " " << base.sarkok[3].B << std::endl;
    std::cout << 0 << " " << 0 << " " << 1 << " ; " << top.sarkok[0].R << " " << top.sarkok[0].G << " " << top.sarkok[0].B << std::endl;
    std::cout << 1 << " " << 0 << " " << 1 << " ; " << top.sarkok[1].R << " " << top.sarkok[1].G << " " << top.sarkok[1].B << std::endl;
    std::cout << 1 << " " << 1 << " " << 1 << " ; " << top.sarkok[2].R << " " << top.sarkok[2].G << " " << top.sarkok[2].B << std::endl;
    std::cout << 0 << " " << 1 << " " << 1 << " ; " << top.sarkok[3].R << " " << top.sarkok[3].G << " " << top.sarkok[3].B << std::endl;
}

void Cube::xrotate()
{
    Rectangle temprec1 = base;
    Rectangle temprec2 = near;

    base = far;
    near = temprec1;

    temprec1 = top;

    top = temprec2;
    far = temprec1;

    left.forgat();
    right.antiforgat();
    base.antiforgat();
    near.antiforgat();
}

void Cube::yrotate()
{
    Rectangle temprec1 = base;
    Rectangle temprec2 = right;

    base = left;
    right = temprec1;

    temprec1 = top;

    top = temprec2;
    left = temprec1;

    near.forgat();
    far.antiforgat();
    right.forgat();
    base.antiforgat();
}

void Cube::zrotate()
{
    Rectangle temprec1 = left;
    Rectangle temprec2 = near;

    left = far;
    near = temprec1;

    temprec1 = right;

    right = temprec2;
    far = temprec1;

    base.forgat();
    top.forgat();
    right.forgat();
    far.forgat();
    left.forgat();
    near.forgat();
}

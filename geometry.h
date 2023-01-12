#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "cube.hpp"

// Take the vector of cubes and create the biggest geometry possible

class Geometry
{
    std::vector<Cube> cubes;
    std::vector<Cube> geometry;

public:
    Geometry(std::vector<Cube> cube_vec);

    void cubes_to_geometry();
};

#endif // GEOMETRY_H

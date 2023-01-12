#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "cube.hpp"

// Take the vector of cubes and create the biggest geometry possible

class Geometry
{
    std::vector<Cube> cubes;
    std::vector<std::vector<std::vector<Cube>>> geometry;
    std::vector<std::vector<std::vector<int>>> occupancy;

public:
    Geometry(std::vector<Cube> cube_vec);

    void cubes_to_geometry();
};

#endif // GEOMETRY_H

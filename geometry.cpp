#include "geometry.h"

Geometry::Geometry(std::vector<Cube> cube_vec) : cubes(cube_vec)
{
    Cube plh;
    sarok s(-1, -1, -1);

    for (int i = 0; i < 4; i++)
    {
        plh.base.sarkok.push_back(s);
        plh.top.sarkok.push_back(s);
        plh.left.sarkok.push_back(s);
        plh.right.sarkok.push_back(s);
        plh.near.sarkok.push_back(s);
        plh.far.sarkok.push_back(s);
    }

    std::vector<std::vector<std::vector<Cube>>> geometry_plh(cubes.size()*2, std::vector<std::vector<Cube>>(cubes.size()*2, std::vector<Cube>(cubes.size()*2, plh)));
    geometry = geometry_plh;
}

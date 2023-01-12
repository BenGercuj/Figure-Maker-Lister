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

    std::vector<std::vector<std::vector<int>>> occupancy_plh(cubes.size()*2, std::vector<std::vector<int>>(cubes.size()*2, std::vector<int>(cubes.size()*2, 0)));
    occupancy = occupancy_plh;
}

std::vector<std::vector<int>> check_neighbour_occupancy(std::vector<std::vector<std::vector<int>>> occupancy, unsigned x, unsigned y, unsigned z)
{
    std::vector<std::vector<int>> occupied;

    for (size_t x_i = std::max((int)x-1, 0); x_i < std::min((int)x+1, (int)occupancy.size()-1); x_i++)
    {
        for (size_t y_i = std::max((int)y-1, 0); y_i < std::min((int)y+1, (int)occupancy[x_i].size()-1); y_i++)
        {
            for (size_t z_i = std::max((int)z-1, 0); z_i < std::min((int)z+1, (int)occupancy[x_i][y_i].size()-1); z_i++)
            {
                if (occupancy[x_i][y_i][z_i] == 1)
                {
                    occupied.push_back({(int)x_i, (int)y_i, (int)z_i});
                }
            }
        }
    }

    return {{-1}};
}

void Geometry::cubes_to_geometry()
{
    int geo_size = geometry[0][0].size();
    int geo_mid = geo_size/2;
    geometry[geo_mid][geo_mid][geo_mid] = cubes.back();
    occupancy[geo_mid][geo_mid][geo_mid] = 1;
    cubes.pop_back();

    for (size_t i = 0; i < cubes.size(); i++)
    {
        for (int x = 0; x < geo_size; x++)
        {
            for (int y = 0; y < geo_size; y++)
            {
                for (int z = 0; z < geo_size; z++)
                {
                    if (occupancy[x][y][z] == 1)
                    {
                        // X oldal vizsgálata 'balról'
                        if (x > 0)
                        {
                            if (occupancy[x-1][y][z] == 0)
                            {
                                //if (occupancy[x-1][y-1][z])
                            }
                        }
                    }
                }
            }
        }
    }
}

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

    std::vector<Cube> geometry_plh(cubes.size());
    geometry = geometry_plh;
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

//void Geometry::cubes_to_geometry()
//{
//    int geo_size = geometry[0][0].size();
//    int geo_mid = geo_size/2;
//    geometry[geo_mid][geo_mid][geo_mid] = cubes.back();
//    occupancy[geo_mid][geo_mid][geo_mid] = 1;
//    cubes.pop_back();

//    for (size_t i = 0; i < cubes.size(); i++)
//    {
//        for (int x = 0; x < geo_size; x++)
//        {
//            for (int y = 0; y < geo_size; y++)
//            {
//                // Z tengely egyelõre ignorálva
//                if (occupancy[x][y][geo_mid] == 1)
//                    {
//                        // X oldal vizsgálata 'balról'
//                        if (x > 0)
//                        {
//                            if (occupancy[x-1][y][geo_mid] == 0)
//                            {
//                                //
//                            }
//                        }
//                    }
//            }
//        }
//    }
//}

bool operator==(const sarok &s1, const sarok &s2)
{
    return s1.B == s2.B && s1.G == s2.G && s1.R == s2.R;
}

void Geometry::cubes_to_geometry()
{
    geometry.push_back(cubes.back());
    cubes.pop_back();

    for (int i = 0; i < 4; i++)
    {
        if (geometry[0].right.sarkok[1] == cubes[0].left.sarkok[0] && geometry[0].right.sarkok[2] == cubes[0].left.sarkok[3] && geometry[0].right.sarkok[3] == cubes[0].left.sarkok[2] && geometry[0].right.sarkok[0] == cubes[0].left.sarkok[1])
        {
            geometry.push_back(cubes.back());
        }

        else
        {
            //
        }
    }
}

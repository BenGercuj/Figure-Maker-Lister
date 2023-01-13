#include "geometry.h"
#include <fstream>

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

    std::vector<Cube> geometry_plh(0);
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
    if (cubes.size() > 0)
    {
        geometry.push_back(cubes.back());
        cubes.pop_back();
    }

    if (cubes.size() > 0)
    {
        for (int i = 0; i < 4; i++)
        {
            if (cubes[0].left.sarkok[0].R == -1 && cubes[0].right.sarkok[0].R == -1)
            {
                if (cubes[0].base.sarkok[0] == geometry[0].base.sarkok[1] && cubes[0].base.sarkok[3] == geometry[0].base.sarkok[2] && cubes[0].top.sarkok[0] == geometry[0].top.sarkok[1] && cubes[0].top.sarkok[3] == geometry[0].top.sarkok[2])
                {
                    Rectangle plh = cubes[0].right;
                    cubes[0].right = geometry[0].right;
                    geometry[0].right = plh;
                    geometry.push_back(cubes[0]);
                    cubes.erase(cubes.begin());
                    i = 4;
                }

                else { cubes[0].xrotate(); }
            }

            else
            {
                if (geometry[0].right.sarkok[1] == cubes[0].left.sarkok[0] && geometry[0].right.sarkok[2] == cubes[0].left.sarkok[3] && geometry[0].right.sarkok[3] == cubes[0].left.sarkok[2] && geometry[0].right.sarkok[0] == cubes[0].left.sarkok[1])
                {
                    geometry.push_back(cubes[0]);
                    cubes.erase(cubes.begin());
                    i = 4;
                }

                else { cubes[0].yrotate(); }
            }
        }
    }
}

void Geometry::geometry_to_ply()
{
    std::ofstream kf("az_koczka.ply");
    kf << "ply\n" << "format ascii 1.0\n" << "element vertex " << 8*geometry.size() << '\n';
    kf << "property float32 x\n" << "property float32 y\n" << "property float32 z\n";
    kf << "property uchar red\n" << "property uchar green\n" << "property uchar blue\n";
    kf << "element face " << 6*geometry.size() << '\n' << "property list uint8 int32 vertex_indices\n";
    kf << "end_header\n";

    for (int i = 0; i < geometry.size(); i++)
    {
        kf << i << ' ' << 0 << ' ' << 0 << ' ' << geometry[i].base.sarkok[0].R << ' ' << geometry[i].base.sarkok[0].G << ' ' << geometry[i].base.sarkok[0].B << '\n';
        kf << i+1 << ' ' << 0 << ' ' << 0 << ' ' << geometry[i].base.sarkok[1].R << ' ' << geometry[i].base.sarkok[1].G << ' ' << geometry[i].base.sarkok[1].B << '\n';
        kf << i+1 << ' ' << 1 << ' ' << 0 << ' ' << geometry[i].base.sarkok[2].R << ' ' << geometry[i].base.sarkok[2].G << ' ' << geometry[i].base.sarkok[2].B << '\n';
        kf << i << ' ' << 1 << ' ' << 0 << ' ' << geometry[i].base.sarkok[3].R << ' ' << geometry[i].base.sarkok[3].G << ' ' << geometry[i].base.sarkok[3].B << '\n';

        kf << i << ' ' << 0 << ' ' << 1 << ' ' << geometry[i].top.sarkok[0].R << ' ' << geometry[i].top.sarkok[0].G << ' ' << geometry[i].top.sarkok[0].B << '\n';
        kf << i+1 << ' ' << 0 << ' ' << 1 << ' ' << geometry[i].top.sarkok[1].R << ' ' << geometry[i].top.sarkok[1].G << ' ' << geometry[i].top.sarkok[1].B << '\n';
        kf << i+1 << ' ' << 1 << ' ' << 1 << ' ' << geometry[i].top.sarkok[2].R << ' ' << geometry[i].top.sarkok[2].G << ' ' << geometry[i].top.sarkok[2].B << '\n';
        kf << i << ' ' << 1 << ' ' << 1 << ' ' << geometry[i].top.sarkok[3].R << ' ' << geometry[i].top.sarkok[3].G << ' ' << geometry[i].top.sarkok[3].B << '\n';
    }

    // base, top
    for (int i = 1; i <= 2*geometry.size(); i++)
    {
        kf << "4 " << i*4-1 << ' ' << i*4-2 << ' ' << i*4-3 << ' ' << i*4-4 << '\n';
    }

    // right, left
    for (int i = 1; i <= geometry.size(); i++)
    {
        kf << "4 " << i*4-2 << ' ' << i*4-3 << ' ' << i*4+1 << ' ' << i*4+2 << '\n';
        kf << "4 " << i*4-4 << ' ' << i*4-1 << ' ' << i*4 << ' ' << i*4+3 << '\n';
    }

    // near, far
    for (int i = 1; i <= geometry.size(); i++)
    {
        kf << "4 " << i*4-4 << ' ' << i*4-3 << ' ' << i*4 << ' ' << i*4+1 << '\n';
        kf << "4 " << i*4-2 << ' ' << i*4-1 << ' ' << i*4+2 << ' ' << i*4+3 << '\n';
    }

    kf.close();
}

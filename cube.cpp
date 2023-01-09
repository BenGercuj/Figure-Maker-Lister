#include "cube.hpp"

/*Cube::Cube()
{

}*/



void Cube::cube_check()
{
    std::cout << 0 << " " << 0 << " " << 0 << " ; " << base.sarkok[0].R << " " << base.sarkok[0].G << " " << base.sarkok[0].B << std::endl;
    std::cout << 1 << " " << 0 << " " << 0 << " ; " << base.sarkok[1].R << " " << base.sarkok[1].G << " " << base.sarkok[1].B << std::endl;
    std::cout << 1 << " " << 1 << " " << 0 << " ; " << base.sarkok[2].R << " " << base.sarkok[2].G << " " << base.sarkok[2].B << std::endl;
    std::cout << 0 << " " << 1 << " " << 0 << " ; " << base.sarkok[3].R << " " << base.sarkok[3].G << " " << base.sarkok[3].B << std::endl;
    std::cout << 0 << " " << 0 << " " << 1 << " ; " << top.sarkok[0].R << " " << top.sarkok[0].G << " " << top.sarkok[0].B << std::endl;
    std::cout << 1 << " " << 0 << " " << 1 << " ; " << top.sarkok[0].R << " " << top.sarkok[1].G << " " << top.sarkok[1].B << std::endl;
    std::cout << 1 << " " << 1 << " " << 1 << " ; " << top.sarkok[0].R << " " << top.sarkok[2].G << " " << top.sarkok[2].B << std::endl;
    std::cout << 0 << " " << 1 << " " << 1 << " ; " << top.sarkok[0].R << " " << top.sarkok[3].G << " " << top.sarkok[3].B << std::endl;
}

#include "rectangle.hpp"
#include "geometry.h"

int main()
{

    std::vector<Rectangle> rec_vec;
    std::ifstream bf("text.txt");  // ide majd a file nevét írjuk be!

    if(!bf.good())
    {
        std::cout << "Beolvasási hiba lépett fel kolléga urak..." << std::endl;
        exit(-1);
    }

    while(bf.good())
    {
        Rectangle rec;
        rec.beolvas(bf);

        rec_vec.push_back(rec);
    }
    bf.close();

    for (Rectangle r : rec_vec)
    {
        r.kiirat();
    }

    rec_vec[0].forgat();

    std::cout << std::endl;

    rec_vec[0].kiirat();

    //első rész vége mentem sörözni szoszi


    return 0;
}

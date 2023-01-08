#include "rectangle.hpp"
#include "geometry.h"
#include "cube.hpp"

bool sarokeq(Rectangle a, Rectangle b, int as, int bs)
{
    bool R, G, B;
    R = false;
    G = false;
    B = false;
    if(a.sarkok[as].R == b.sarkok[bs].R) {R = true;}
    if(a.sarkok[as].G == b.sarkok[bs].G) {G = true;}
    if(a.sarkok[as].B == b.sarkok[bs].B) {B = true;}

    if((R && G) && B) {return true;}
    else {return false;}
}

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

    std::vector<Cube> Cubes;

    std::vector<Rectangle> used;
    std::vector<Rectangle> potential = rec_vec;
    bool cubedone = false;

    while(!cubedone)
    {
        Rectangle temprec1;
        Rectangle temprec2;
        Rectangle temprec3;
        Rectangle temprec4;
        Rectangle temprec5;
        Rectangle temprec6 ;

        for(auto i = potential.begin(); i != potential.end();i++)
        {
            temprec1 = *i;
            potential.erase(i);

            for(Rectangle r : potential)
            {
                bool match = false;
                while(!match)
                {
                    int j = 0;
                    if(sarokeq(temprec1, r, 0, 0))
                    {
                        if(sarokeq(temprec1, r, 1, 1))
                        {
                            temprec3 = r;
                            match = true;
                        }
                        else if(sarokeq(temprec1, r, 3, 3))
                        {
                            temprec6 = r;
                            match = true;
                        }
                    }
                    else if(sarokeq(temprec1, r, 1, 1))
                    {
                        if(sarokeq(temprec1, r, 2, 2))
                        {
                            temprec5 = r;
                            match = true;
                        }
                    }
                    else if(sarokeq(temprec1, r, 2, 2))
                    {
                        if(sarokeq(temprec1, r, 3, 3))
                        {
                            temprec4 = r;
                            match = true;
                        }
                    }
                    else if(j < 3)
                    {
                        j++;
                        temprec1.forgat();
                    }
                    else
                    {
                        match = true;
                    }

                }
            }
        }



        if(potential.size() == 0 || used.size() == 6) {cubedone = true;}
    }



    if(potential.size() == 0) {std::cout << "Nem lehet egy kockat se csinalni." << std::endl;}

    return 0;
}

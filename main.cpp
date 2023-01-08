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

    std::vector<Rectangle> potential = rec_vec;
    bool cubedone = false;
    Cube tempcube;

    if(rec_vec.size() > 5){
    while(!cubedone)
    {
        Rectangle temprecbase;
        Rectangle temprecnear;
        Rectangle temprecfar;
        Rectangle temprecright;
        Rectangle temprecleft;
        Rectangle temprectop;

        for(auto i = potential.begin(); i != potential.end();i++)
        {
            temprecbase = *i;
            potential.erase(i);

            bool goodbase = true;
            bool match = false;
            int j = 0;
            int k = 0;

            while(!match) //kozeli(near) oldal kereses
            {
                if(sarokeq(temprecbase, potential[j], 0, 0)  && sarokeq(temprecbase, potential[j], 1, 1))
                {
                    match = true;
                    temprecnear = potential[j];
                    potential.erase(potential.begin() + j);
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size())
                {
                    j++;
                }
                else
                {
                    match = true;
                    goodbase = false;
                    potential.push_back(temprecbase);
                }
            }

            match = false;
            j = 0;
            k = 0;

            while(!match && goodbase) //tavoli(far) oldal kereses
            {
                if(sarokeq(temprecbase, potential[j], 2, 2)  && sarokeq(temprecbase, potential[j], 3, 3))
                {
                    match = true;
                    temprecfar = potential[j];
                    potential.erase(potential.begin() + j);
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size())
                {
                    j++;
                }
                else
                {
                    match = true;
                    goodbase = false;
                    potential.push_back(temprecbase);
                    potential.push_back(temprecnear);
                }
            }

            match = false;
            j = 0;
            k = 0;

            while(!match && goodbase) //jobb(right) oldal kereses
            {
                if(sarokeq(temprecbase, potential[j], 1, 1))
                {
                    if(sarokeq(temprecbase, potential[j], 2, 2))
                    {
                        if(sarokeq(temprecnear, potential[j], 2, 0))
                        {
                            if(sarokeq(temprecfar, potential[j], 1, 3))
                            {
                                match = true;
                                temprecright = potential[j];
                                potential.erase(potential.begin() + j);
                            }
                        }
                    }
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size())
                {
                    j++;
                }
                else
                {
                    match = true;
                    goodbase = false;
                    potential.push_back(temprecbase);
                    potential.push_back(temprecnear);
                    potential.push_back(temprecfar);
                }
            }

            match = false;
            j = 0;
            k = 0;

            while(!match && goodbase) //bal(left) oldal kereses
            {
                if(sarokeq(temprecbase, potential[j], 0, 0))
                {
                    if(sarokeq(temprecbase, potential[j], 3, 3))
                    {
                        if(sarokeq(temprecnear, potential[j], 3, 1))
                        {
                            if(sarokeq(temprecfar, potential[j], 0, 2))
                            {
                                match = true;
                                temprecleft = potential[j];
                                potential.erase(potential.begin() + j);
                            }
                        }
                    }
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size())
                {
                    j++;
                }
                else
                {
                    match = true;
                    goodbase = false;
                    potential.push_back(temprecbase);
                    potential.push_back(temprecnear);
                    potential.push_back(temprecfar);
                    potential.push_back(temprecright);
                }
            }

            match = false;
            j = 0;
            k = 0;

            while(!match && goodbase) //felso(top) oldal kereses
            {
                if(sarokeq(temprecnear, potential[j], 3, 0))
                {
                    if(sarokeq(temprecnear, potential[j], 2, 1))
                    {
                        if(sarokeq(temprecfar, potential[j], 1, 2))
                        {
                            if(sarokeq(temprecfar, potential[j], 0, 3))
                            {
                                match = true;
                                temprectop = potential[j];
                                potential.erase(potential.begin() + j);
                            }
                        }
                    }
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size())
                {
                    j++;
                }
                else
                {
                    match = true;
                    goodbase = false;
                    potential.push_back(temprecbase);
                    potential.push_back(temprecnear);
                    potential.push_back(temprecfar);
                    potential.push_back(temprecright);
                    potential.push_back(temprecleft);
                }
            }

            if(goodbase)
            {
                tempcube.base = temprecbase;
                tempcube.near = temprecnear;
                tempcube.far = temprecfar;
                tempcube.right = temprecright;
                tempcube.left = temprecleft;
                tempcube.top = temprectop;

                Cubes.push_back(tempcube);
            }
        }

        cubedone = true;

    }
    }



    if(Cubes.size() == 0) {std::cout << "Nem lehet egy kockat se csinalni." << std::endl;}

    return 0;
}

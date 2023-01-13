#include "geometry.h"

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

std::vector<Cube> rectangle_to_cube(std::vector<Rectangle> &rec_vec)
{
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

        for(auto i = potential.begin(); potential.size() > 3 && i != potential.end();i++)
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
                    k = 0;
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
                    k = 0;
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

            if(potential.size() == 1) //Teglatesthez csonka kocka
            {
                while(!match)
                {
                    if(((sarokeq(temprecnear, potential[0], 3, 0) && sarokeq(temprecnear, potential[0], 2, 1)) && sarokeq(temprecfar, potential[0], 1, 2)) && sarokeq(temprecfar, potential[0], 0, 3))
                    {
                        match = true;
                        temprectop = potential[0];
                        potential.erase(potential.begin());

                        sarok uressar(-1, -1, -1);

                        for(int l = 0; l < 4;l++)
                        {
                            temprecright.sarkok[l] = uressar;
                            temprecleft.sarkok[l] = uressar;
                        }

                        tempcube.base = temprecbase;
                        tempcube.near = temprecnear;
                        tempcube.far = temprecfar;
                        tempcube.right = temprecright;
                        tempcube.left = temprecleft;
                        tempcube.top = temprectop;

                        Cubes.push_back(tempcube);
                        tempcube.cube_check();
                        std::cout<< Cubes.size()<<std::endl;

                        return Cubes;
                    }
                    else if(k < 3)
                    {
                        potential[0].forgat();
                        k++;
                    }
                    else
                    {
                        goodbase = false;
                        potential.push_back(temprecbase);
                        potential.push_back(temprecnear);
                        potential.push_back(temprecfar);
                    }
                }
            }

            if(potential.size() == 2) {goodbase = false;}

            while(!match && goodbase) //jobb(right) oldal kereses
            {
                if(((sarokeq(temprecbase, potential[j], 1, 1) && sarokeq(temprecbase, potential[j], 2, 2)) && sarokeq(temprecnear, potential[j], 2, 0)) && sarokeq(temprecfar, potential[j], 1, 3))
                {
                    match = true;
                    temprecright = potential[j];
                    potential.erase(potential.begin() + j);
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size()-1)
                {
                    j++;
                    k = 0;
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
                if(((sarokeq(temprecbase, potential[j], 0, 0) && sarokeq(temprecbase, potential[j], 3, 3)) && sarokeq(temprecnear, potential[j], 3, 1)) && sarokeq(temprecfar, potential[j], 0, 2))
                {
                    match = true;
                    temprecleft = potential[j];
                    potential.erase(potential.begin() + j);
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size()-1)
                {
                    j++;
                    k = 0;
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
                if(((sarokeq(temprecnear, potential[j], 3, 0) && sarokeq(temprecnear, potential[j], 2, 1)) && sarokeq(temprecfar, potential[j], 1, 2)) && sarokeq(temprecfar, potential[j], 0, 3))
                {
                    match = true;
                    temprectop = potential[j];
                    potential.erase(potential.begin() + j);
                }
                else if(k < 3)
                {
                    potential[j].forgat();
                    k++;
                }
                else if(j < potential.size()-1)
                {
                    j++;
                    k = 0;
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
                tempcube.cube_check();
                std::cout<< Cubes.size()<<std::endl;
            }
        }

        cubedone = true;

    }
    }

    if(Cubes.size() == 0) {std::cout << "Nem lehet egy kockat se csinalni." << std::endl;}
    std::cout<< Cubes.size()<<std::endl;

    return Cubes;
}

int main()
{
    std::vector<Rectangle> rec_vec;
    std::ifstream bf("dupla_pepita.txt");  // ide majd a file nevét írjuk be!

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

    //első rész vége mentem sörözni szoszi

    std::vector<Cube> Cubes = rectangle_to_cube(rec_vec);
    Geometry geo(Cubes);
    geo.cubes_to_geometry();
    //if (Cubes.size() > 0) { geo.geometry_to_ply(); }

    return 0;
}

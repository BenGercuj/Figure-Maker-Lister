#include "rectangle.hpp"


void Rectangle::beolvas(std::ifstream &bf)
{


    for (int i = 0; i < 4; i++)
    {
        int a, b, c;
        bf >> a >> b >> c;

        sarok corner(a, b, c);

        sarkok.push_back(corner);

    }

}

void Rectangle::forgat()
{
    sarok forgatott = sarkok[sarkok.size()-1];

    sarkok.pop_back();
    sarkok.insert(sarkok.begin(), forgatott);
}

void Rectangle::antiforgat()
{
    sarok sar = sarkok[0];

    sarkok.erase(sarkok.begin());

    sarkok.push_back(sar);
}

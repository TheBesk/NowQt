#include "cinema.h"

cinema::cinema(string n, string c, int aN, int mN, int gN, string cf, string em, int aA, int mA, int gA, unsigned int me, bool cosc, string coup, double tot, string tC, string dC, double cC, unsigned int scC, bool hideC): nowqt(n, c, aN, mN, gN, cf, em, aA, mA, gA, me, cosc, coup, tot), titoloC(tC), descrizioneC(dC), costoC(cC), schermicontC(scC), hdC(hideC) {}

cinema *cinema::clone() const
{
    return new cinema(*this);
}

string cinema::getTipoPacc() const
{
    return "Cinema";
}

double cinema::getTot() const
{
    return totale;
}

string cinema::getTitoloC() const
{
    return titoloC;
}

string cinema::getDescC() const
{
    return descrizioneC;
}

double cinema::getCostoC() const
{
    return costoC;
}

unsigned int cinema::getSchermiContC() const
{
    return schermicontC;
}

bool cinema::isHdC() const
{
    return hdC;
}

void cinema::aumentaSchermiC()
{
    schermicontC++;
    costoC=costoC+2;
}

void cinema::aumentaCostoCHD()
{
    if(hdC) {
        costoC=costoC+3;
    }
}

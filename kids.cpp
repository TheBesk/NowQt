#include "kids.h"


kids::kids(string n, string c, int aN, int mN, int gN, string cf, string em, int aA, int mA, int gA, unsigned int me, bool cosc, string coup, float tot, string tK, string dK, float cK, unsigned int scK, bool hideK): nowqt(n, c, aN, mN, gN, cf, em, aA, mA, gA, me, cosc, coup, tot), titoloK(tK), descrizioneK(dK), costoK(cK), schermicontK(scK), hdK(hideK) {}

kids *kids::clone() const
{
    return new kids(*this);
}

string kids::getTipoPacc() const
{
    return "Kids";
}

float kids::getTot() const
{
    return totale;
}

string kids::getTitoloK() const
{
    return titoloK;
}

string kids::getDescK() const
{
    return descrizioneK;
}

float kids::getCostoK() const
{
    return costoK;
}

unsigned int kids::getSchermiContK() const
{
    return schermicontK;
}

bool kids::isHdK() const
{
    return hdK;
}

void kids::aumentaSchermiK()
{
    schermicontK++;
    costoK=costoK+2;
}

void kids::aumentaCostoKHD()
{
    if(hdK) {
        costoK=costoK+1;
    }
}

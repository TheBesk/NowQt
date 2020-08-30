#include "sport.h"

sport::sport(string n, string c, int aN, int mN, int gN, string cf, string em, int aA, int mA, int gA, unsigned int me, bool cosc, string coup, double tot, string tS, string dS, double cS, unsigned int scS, bool shdS): nowqt(n, c, aN, mN, gN, cf, em, aA, mA, gA, me, cosc, coup, tot), titoloS(tS), descrizioneS(dS), costoS(cS), schermicontS(scS), superhdS(shdS) {}

sport *sport::clone() const
{
    return new sport(*this);
}

string sport::getTipoPacc() const
{
    return "Sport";
}

double sport::getTot() const
{
    return totale;
}

string sport::getTitoloS() const
{
    return titoloS;
}

string sport::getDescS() const
{
    return descrizioneS;
}

double sport::getCostoS() const
{
    return costoS;
}

unsigned int sport::getSchermiContS() const
{
    return schermicontS;
}

bool sport::isSuperHdS() const
{
    return superhdS;
}

void sport::aumentaSchermiS()
{
    schermicontS++;
    costoS=costoS+4;
}

void sport::aumentaCostoSHD()
{
    if(superhdS) {
        costoS=costoS+5;
    }
}

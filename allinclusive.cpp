#include "allinclusive.h"

allinclusive::allinclusive(string n, string c, int gN, int mN, int aN, string cf, string em, int gA, int mA, int aA, unsigned int me, bool cosc, string coup, double tot, string tK, string dK, double cK, unsigned int scK, bool hideK, string tC, string dC, double cC, unsigned int scC, bool hideC, string tS, string dS, double cS, unsigned int scS, bool shdS): nowqt(n, c, gN, mN, aN, cf, em, gA, mA, aA, me, cosc, coup, tot), kids(n, c, gN, mN, aN, cf, em, gA, mA, aA, me, cosc, coup, tot, tK, dK, cK, scK, hideK), cinema(n, c, gN, mN, aN, cf, em, gA, mA, aA, me, cosc, coup, tot, tC, dC, cC, scC, hideC), sport(n, c, gN, mN, aN, cf, em, gA, mA, aA, me, cosc, coup, tot, tS, dS, cS, scS, shdS) {}

allinclusive *allinclusive::clone() const
{
    return new allinclusive(*this);
}

string allinclusive::getTipoPacc() const
{
    return "All inclusive";
}

double allinclusive::getTot() const
{
    return totale;
}

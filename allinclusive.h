#ifndef ALLINCLUSIVE_H
#define ALLINCLUSIVE_H

#include "kids.h"
#include "cinema.h"
#include "sport.h"

class allinclusive: public kids, public cinema, public sport
{
public:
    allinclusive* clone() const override;
    allinclusive(string="", string="", int=2000, int=1, int=1, string="", string="", int=2000, int=1, int=1, unsigned int=1, bool=false, string="", float=0, string="Offerta Kids", string="I programmi più amati da bambini e ragazzi.", float=4, unsigned int=2, bool=false, string="Offerta Cinema", string="Film sempre nuovi da non perdere.", float=10, unsigned int=2, bool=false, string="Offerta Sport", string="Calcio, MotoGP, Formula 1 molto altro.", float=15, unsigned int=2, bool=false);

    virtual string getTipoPacc() const final;
    float getTot() const;
};

#endif  // ALLINCLUSIVE_H

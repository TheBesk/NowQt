#ifndef SPORT_H
#define SPORT_H

#include "nowqt.h"

class sport: virtual public nowqt {
private:
    string titoloS;
    string descrizioneS;
    double costoS;
    unsigned int schermicontS;
    bool superhdS;
public:
    sport(string="", string="", int=2000, int=1, int=1, string="", string="", int=2000, int=1, int=1, unsigned int=1, bool=false, string="", double=0, string="Offerta Sport", string="Calcio, MotoGP, Formula 1 e molto altro.", double=15, unsigned int=2, bool=false);
    virtual ~sport() = default;
    sport* clone() const override;
    virtual string getTipoPacc() const;
    double getTot() const;

    string getTitoloS() const;
    string getDescS() const;
    double getCostoS() const;
    unsigned int getSchermiContS() const;
    bool isSuperHdS() const;

    void aumentaSchermiS();
    void aumentaCostoSHD();

};

#endif // SPORT_H

#ifndef CINEMA_H
#define CINEMA_H

#include "nowqt.h"

class cinema: virtual public nowqt {
private:
    string titoloC;
    string descrizioneC;
    double costoC;
    unsigned int schermicontC;
    bool hdC;
public:
    cinema(string="", string="", int=2000, int=1, int=1, string="", string="", int=2000, int=1, int=1, unsigned int=1, bool=false, string="", double=0, string="Offerta Cinema", string="Film sempre nuovi da non perdere.", double=10, unsigned int=2, bool=false);
    virtual ~cinema() = default;
    cinema* clone() const override;
    virtual string getTipoPacc() const;
    double getTot() const;

    string getTitoloC() const;
    string getDescC() const;
    double getCostoC() const;
    unsigned int getSchermiContC() const;
    unsigned int getSchermiTotC() const;
    bool isHdC() const;

    void aumentaSchermiC();
    void aumentaCostoCHD();

};

#endif // CINEMA_H

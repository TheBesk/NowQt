#ifndef KIDS_H
#define KIDS_H

#include "nowqt.h"

class kids: virtual public nowqt {

private:
    string titoloK;
    string descrizioneK;
    double costoK;
    unsigned int schermicontK;
    bool hdK;

public:
    kids(string="", string="", int=2000, int=1, int=1, string="", string="", int=2000, int=1, int=1, unsigned int=1, bool=false, string="", double=0, string="Offerta Kids", string="I programmi più amati da bambini e ragazzi.", double=4, unsigned int=2, bool=false);

    virtual ~kids() = default;
    kids* clone() const override;
    virtual string getTipoPacc() const;
    double getTot() const;

    string getTitoloK() const;
    string getDescK() const;
    double getCostoK() const;
    unsigned int getSchermiContK() const;
    bool isHdK() const;

    void aumentaSchermiK();
    void aumentaCostoKHD();

};


#endif // KIDS_H

#include "nowqt.h"

nowqt::nowqt(string n, string c, int aN, int mN, int gN, string cf, string em, int aA, int mA, int gA, unsigned int me, bool cosc, string coup, float tot) : nome(n), cognome(c), dataNascita(aN, mN, gN), codicefiscale(cf), email(em), dataInAbb(aA, mA, gA), mesi(me), codicesconto(cosc), coupon(coup), totale(tot) {}

string nowqt::getNome() const
{
    return nome;
}

string nowqt::getCognome() const
{
    return cognome;
}

QDate nowqt::getDataN() const
{
    return dataNascita;
}

int nowqt::getGiornoN() const
{
    return dataNascita.QDate::day();
}

int nowqt::getMeseN() const
{
    return dataNascita.QDate::month();
}

int nowqt::getAnnoN() const
{
    return dataNascita.QDate::year();
}

string nowqt::getCodFisc() const
{
    return codicefiscale;
}

string nowqt::getEMail() const
{
    return email;
}

QDate nowqt::getDataInAbb() const
{
    return dataInAbb;
}

int nowqt::getGiornoInAbb() const
{
    return dataInAbb.QDate::day();
}

int nowqt::getMeseInAbb() const
{
    return dataInAbb.QDate::month();
}

int nowqt::getAnnoInAbb() const
{
    return dataInAbb.QDate::year();
}

unsigned int nowqt::getMesi() const
{
    return mesi;
}

bool nowqt::isCodSconto() const
{
    return codicesconto;
}

string nowqt::getCoupon() const {
    return coupon;
}

void nowqt::verificaCoupon()
{
    if(coupon=="UNIPD") {
        codicesconto=true;
    }
}

void nowqt::aggiornaTot()
{
    if(codicesconto) {
        int sconto=(totale*10)/100;
        totale=totale-sconto;
    }
}

float nowqt::calcolaTotAbb()
{
    return (getMesi()*getTot());
}

QDate nowqt::CalcolaFineAbb() const {
    QDate FiAbb=getDataInAbb();
    FiAbb=FiAbb.addMonths(getMesi()%12);
    FiAbb=FiAbb.addYears(getMesi()/12);
    return FiAbb;
}

bool nowqt::operator==(const nowqt& n) const{
    return nome == n.getNome() && cognome == n.getCognome() && dataNascita == QDate(n.getAnnoN(),n.getMeseN(),n.getGiornoN()) && codicefiscale == n.getCodFisc()  && email == n.getEMail();
}

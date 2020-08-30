#include "model.h"
model::model(QString path) : path(path), datiTotali(new container<deepPointer<nowqt>>()), modificato(false)
{
}

model::~model()
{
    datiTotali->erase();
    delete datiTotali;
}

QStringList model::getCampiCliente(const int indice) const
{
    QStringList temp;
    deepPointer<nowqt> clienteTemp = datiTotali->get_T_at_pos(indice);
    temp.push_back(QString::fromStdString(clienteTemp->getNome())); // 0
    temp.push_back(QString::fromStdString(clienteTemp->getCognome())); // 1
    temp.push_back(QString::fromStdString(clienteTemp->getCodFisc())); // 2
    temp.push_back(clienteTemp->getDataN().toString());
    temp.push_back(QString::fromStdString(clienteTemp->getEMail()));
    temp.push_back(clienteTemp->getDataInAbb().toString());
    QString m= QString::number(clienteTemp->getMesi());
    temp.push_back(m);  // 6
    temp.push_back(clienteTemp->isCodSconto()? "true":"false"); // 7
    temp.push_back(QString::fromStdString(clienteTemp->getCoupon())); // 8
    QString t= QString::number(clienteTemp->getTot());
    temp.push_back(t); // 9

    if(dynamic_cast<allinclusive*>(&(*(clienteTemp))) != nullptr){
        auto clienteai = dynamic_cast<allinclusive*>(&(*(clienteTemp)));
        temp.push_back("true"); // 10
        temp.push_back("true"); // 11
        temp.push_back("true"); // 12

        //kids
        temp.push_back(QString::fromStdString(clienteai->getTitoloK())); // 13
        temp.push_back(QString::fromStdString(clienteai->getDescK())); // 14
        QString cK= QString::number(clienteai->getCostoK());
        temp.push_back(cK); // 15
        QString sK= QString::number(clienteai->getSchermiContK());
        temp.push_back(sK); // 16
        temp.push_back(clienteai->isHdK()? "true":"false"); // 17

        // cinema
        temp.push_back(QString::fromStdString(clienteai->getTitoloC())); // 18
        temp.push_back(QString::fromStdString(clienteai->getDescC())); // 19
        QString cC= QString::number(clienteai->getCostoC());
        temp.push_back(cC); // 20
        QString sC= QString::number(clienteai->getSchermiContC());
        temp.push_back(sC); // 21
        temp.push_back(clienteai->isHdC()? "true":"false"); // 22

        // sport
        temp.push_back(QString::fromStdString(clienteai->getTitoloS())); // 24
        temp.push_back(QString::fromStdString(clienteai->getDescS())); // 25
        QString cS= QString::number(clienteai->getCostoS());
        temp.push_back(cS); // 26
        QString sS= QString::number(clienteai->getSchermiContS());
        temp.push_back(sS); // 27
        temp.push_back(clienteai->isSuperHdS()? "true":"false"); // 27
    }
    else if(dynamic_cast<kids*>(&(*(clienteTemp))) != nullptr){
        auto clientek = dynamic_cast<kids*>(&(*(clienteTemp)));

        //kids
        temp.push_back("true"); // 10
        temp.push_back("false"); // 11
        temp.push_back("false"); // 12
        temp.push_back(QString::fromStdString(clientek->getTitoloK())); // 13
        temp.push_back(QString::fromStdString(clientek->getDescK())); // 14
        QString cK= QString::number(clientek->getCostoK());
        temp.push_back(cK); // 15
        QString sK= QString::number(clientek->getSchermiContK());
        temp.push_back(sK); // 16
        temp.push_back(clientek->isHdK()? "true":"false"); // 18

    }
    else if(dynamic_cast<cinema*>(&(*(clienteTemp))) != nullptr){
        auto clientec = dynamic_cast<cinema*>(&(*(clienteTemp)));

        //cinema
        temp.push_back("true"); // 10
        temp.push_back("false"); // 17
        temp.push_back("false"); // 18
        temp.push_back(QString::fromStdString(clientec->getTitoloC())); // 11
        temp.push_back(QString::fromStdString(clientec->getDescC())); // 12
        QString cC= QString::number(clientec->getCostoC());
        temp.push_back(cC); // 13
        QString sC= QString::number(clientec->getSchermiContC());
        temp.push_back(sC); // 14
        temp.push_back(clientec->isHdC()? "true":"false"); // 16
    }
    else if(dynamic_cast<sport*>(&(*(clienteTemp))) != nullptr){
        auto clientes = dynamic_cast<sport*>(&(*(clienteTemp)));

        //sport
        temp.push_back("true"); // 10
        temp.push_back("false"); // 17
        temp.push_back("false"); // 18
        temp.push_back(QString::fromStdString(clientes->getTitoloS())); // 11
        temp.push_back(QString::fromStdString(clientes->getDescS())); // 12
        QString cS= QString::number(clientes->getCostoS());
        temp.push_back(cS); // 13
        QString sS = QString::number(clientes->getSchermiContS());
        temp.push_back(sS); // 14
        temp.push_back(clientes->isSuperHdS()? "true":"false"); // 16
    }
    return temp;
}

void model::removeC(const int i)
{
    modificato=true;
    datiTotali->erase_pos(i);
    emit clienteRimosso();
}

deepPointer<nowqt> model::mostraCliente(const int i) const
{
    deepPointer<nowqt> clienteDaVisualizzare;
    clienteDaVisualizzare = (datiTotali->get_T_at_pos(i));
    return clienteDaVisualizzare;
}

bool model::getModificato() const
{
    return modificato;
}

QStringList model::getListaClientiT(QMap<int, int>& indexMapper) const
{
    QStringList ret;
    QString cliente;
    auto it=datiTotali->begin();
    int count=0;
    if(!datiTotali->empty()){
        while(it!=datiTotali->end()){
            cliente = (QString::fromStdString((*(*it)).getNome() + " " + (*(*it)).getCognome()));
            indexMapper.insert((int)ret.count(),count);
            ret.push_back(cliente);
            count++;
            ++it;
        }
    }
    return ret;
}

bool model::controlloCliente(const QString cf) const {
    QString codf;
    auto it=datiTotali->begin();
    if(!datiTotali->empty()){
        while(it!=datiTotali->end()){
            codf = (QString::fromStdString((*(*it)).getCodFisc()));
            if(cf==codf) {
                return false;
            }
            ++it;
        }
        return true;
    }
    else return true;
}

double model::applicaScontoAI(double t, unsigned int s) {
    double sconto=(t*s)/100;
    t=t-sconto;
    return t;
}

void model::aggNelContainer(const QStringList c)
{
    modificato=true;
    deepPointer<nowqt> cliente;
    QString cf = QString::fromStdString(c.at(2).toStdString());
    if (!controlloCliente(cf)) {
        throw new std::runtime_error("Errore: Il cliente che si sta tentando di inserire è già presente nella lista dei clienti. Riprovare.");
    }
    else {
        QDate dataNascitaTemp = QDate::fromString(c.at(3));
        QDate dataInizioAbbTemp = QDate::fromString(c.at(25));
        if ((c.at(5) == "true" && c.at(11) == "true") && (c.at(17) == "true")) {
            double costoAI;
            costoAI=applicaScontoAI(c.at(27).toDouble(), 35);
            cliente = new allinclusive(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                       c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                       c.at(23)=="true" ? true:false, c.at(24).toStdString(), costoAI, c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(),
                                       c.at(9).toUInt(), c.at(10)=="true" ? true:false, c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                                       c.at(15).toUInt(), c.at(16)=="true" ? true:false, c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                                        c.at(21).toUInt(), c.at(22)=="true" ? true:false);
        } // solo kids
        else if((c.at(5) == "true") && (c.at(11) == "false" && c.at(17) == "false")){
            cliente = new kids(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(), dataNascitaTemp.month(), dataNascitaTemp.day(),
                               c.at(2).toStdString(),c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),
                               dataInizioAbbTemp.day(), c.at(26).toUInt(), c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toDouble(),
                               c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(), c.at(9).toUInt(), c.at(10)=="true" ? true:false);
        } // solo cinema
        else if((c.at(11) == "true") && (c.at(5) == "false" && c.at(17) == "false")){
            cliente = new cinema(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                 c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                 c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toDouble(), c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                                 c.at(15).toUInt(), c.at(16)=="true" ? true:false);
        } // solo sport
        else if((c.at(17) == "true") && (c.at(5) == "false" && c.at(11) == "false")){
            cliente= new sport(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                            c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(), dataInizioAbbTemp.day(), c.at(26).toUInt(),
                            c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                                      c.at(21).toUInt(), c.at(22)=="true" ? true:false);
        }
        datiTotali->push_back(cliente);
        emit clienteAggiunto();
    }
}

void model::modificaItem(const int indice, const QStringList c)
{
    modificato=true;

    deepPointer<nowqt> cliente;

    QDate dataNascitaTemp = QDate::fromString(c.at(3));
    QDate dataInizioAbbTemp = QDate::fromString(c.at(25));
    if ((c.at(5) == "true" && c.at(11) == "true") && (c.at(17) == "true")) {
        cliente = new allinclusive(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                   c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                   c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(),
                                   c.at(9).toUInt(), c.at(10)=="true" ? true:false, c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                                   c.at(15).toUInt(), c.at(16)=="true" ? true:false, c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                                    c.at(21).toUInt(), c.at(22)=="true" ? true:false);
    } // solo kids
    else if((c.at(5) == "true") && (c.at(11) == "false" && c.at(17) == "false")){
        cliente = new kids(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(), dataNascitaTemp.month(), dataNascitaTemp.day(),
                           c.at(2).toStdString(),c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),
                           dataInizioAbbTemp.day(), c.at(26).toUInt(), c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toDouble(),
                           c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(), c.at(9).toUInt(), c.at(10)=="true" ? true:false);
    } // solo cinema
    else if((c.at(11) == "true") && (c.at(5) == "false" && c.at(17) == "false")){
        cliente = new cinema(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                             c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                             c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                             c.at(15).toUInt(), c.at(16)=="true" ? true:false);
    } // solo sport
    else if((c.at(17) == "true") && (c.at(5) == "false" && c.at(11) == "false")){
            cliente= new sport(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
            c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(), dataInizioAbbTemp.day(), c.at(26).toUInt(),
            c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                      c.at(21).toUInt(), c.at(22)=="true" ? true:false);
    }
    datiTotali->replace_last(indice, cliente);
}

#include "model.h"
model::model(QString path) : path(path), datiTotali(new container<deepPointer<nowqt>>()), modificato(false)
{
}

model::~model()
{
    datiTotali->erase();
    delete datiTotali;
}

/*
QStringList model::getCampiCliente(const unsigned int indice) const
{
    QStringList temp;
    deepPointer<nowqt> clienteTemp = datiTotali->get_T_at_pos(indice);
    temp.push_back(QString::fromStdString(clienteTemp->getNome()));
    temp.push_back(QString::fromStdString(clienteTemp->getCognome()));
    temp.push_back(QString::fromStdString(clienteTemp->getCodFisc()));
    temp.push_back(clienteTemp->getDataN().toString());
    temp.push_back(QString::fromStdString(clienteTemp->getEMail()));
    tmp.push_back(QString::fromStdString(clienteTmp->getvia()));
    tmp.push_back(QString::fromStdString(clienteTmp->getnum()));
    tmp.push_back(QString::fromStdString(clienteTmp->getnumerotel()));
    tmp.push_back(QString::fromStdString(clienteTmp->getmail()));
    tmp.push_back(clienteTmp->getDataN().toString());
    tmp.push_back(clienteTmp->getstudent()? "true":"false");

    if(dynamic_cast<allinclusive*>(&(*(clienteTemp))) != nullptr){
        auto clienteai = dynamic_cast<allinclusive*>(&(*(clienteTemp)));
        temp.push_back(clienteai->getCostoAI().toString());
        tmp.push_back(QString::fromStdString(clientevip->getnomeistruttorepiscina()));
        tmp.push_back(clientevip->iscorsonuoto()? "true":"false");
        tmp.push_back(clientevip->getDataPalestra().toString());
        tmp.push_back(QString::fromStdString(clientevip->getnomeistruttorepalestra()));
        tmp.push_back(clientevip->isscheda()? "true":"false");
        tmp.push_back("true");
        tmp.push_back("true");
    }
    else if(dynamic_cast<kids*>(&(*(clienteTemp))) != nullptr){
        auto clientekids = dynamic_cast<kids*>(&(*(clienteTmp)));
        temp.push_back(clientekids->getDataPiscina().toString());
        tmp.push_back(QString::fromStdString(clientepis->getnomeistruttorepiscina()));
        tmp.push_back(clientepis->iscorsonuoto()? "true":"false");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("true");
        tmp.push_back("false");
    }
    else if(dynamic_cast<palestra*>(&(*(clienteTmp))) != nullptr){
        auto clientepal = dynamic_cast<palestra*>(&(*(clienteTmp)));
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back(clientepal->getDataPalestra().toString());
        tmp.push_back(QString::fromStdString(clientepal->getnomeistruttorepalestra()));
        tmp.push_back(clientepal->isscheda()? "true":"false");
        tmp.push_back("false");
        tmp.push_back("true");
    }
    else if(dynamic_cast<piscina*>(&(*(clienteTmp))) != nullptr){
        auto clientepis = dynamic_cast<piscina*>(&(*(clienteTmp)));
        tmp.push_back(clientepis->getDataPiscina().toString());
        tmp.push_back(QString::fromStdString(clientepis->getnomeistruttorepiscina()));
        tmp.push_back(clientepis->iscorsonuoto()? "true":"false");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("Non abbonato");
        tmp.push_back("true");
        tmp.push_back("false");
    }
    return temp;
}*/

deepPointer<nowqt> model::mostraCliente(const unsigned int i) const
{
    deepPointer<nowqt> clienteDaVisualizzare;
    clienteDaVisualizzare = (datiTotali->get_T_at_pos(i));
    return clienteDaVisualizzare;
}

bool model::getModificato() const
{
    return modificato;
}

QStringList model::getListaClientiT(QMap< int,  int>& indexMapper) const
{
    QStringList ret;
    QString cliente;
    auto it=datiTotali->begin();
    unsigned int count=0;
    if(!datiTotali->empty()){
        while(it!=datiTotali->end()){
            cliente = (QString::fromStdString((*(*it)).getNome() + " " + (*(*it)).getCognome()));
            indexMapper.insert((uint)ret.count(),count);
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
            cliente = new allinclusive(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                       c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                       c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(),
                                       c.at(9).toUInt(), c.at(9).toUInt(), c.at(10)=="true" ? true:false, c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                                       c.at(15).toUInt(), c.at(15).toUInt(), c.at(16)=="true" ? true:false, c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                                        c.at(21).toUInt(), c.at(21).toUInt(), c.at(22)=="true" ? true:false, c.at(27).toDouble());
        } // solo kids
        else if((c.at(5) == "true") && (c.at(11) == "false" && c.at(17) == "false")){
            cliente = new kids(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(), dataNascitaTemp.month(), dataNascitaTemp.day(),
                               c.at(2).toStdString(),c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),
                               dataInizioAbbTemp.day(), c.at(26).toUInt(), c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toDouble(),
                               c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toDouble(), c.at(9).toUInt(), c.at(9).toUInt(), c.at(10)=="true" ? true:false);
        } // solo cinema
        else if((c.at(11) == "true") && (c.at(5) == "false" && c.at(17) == "false")){
            cliente = new cinema(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                 c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                 c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toDouble(),
                                 c.at(15).toUInt(), c.at(15).toUInt(), c.at(16)=="true" ? true:false);
        } // solo sport
        else if((c.at(17) == "true") && (c.at(5) == "false" && c.at(11) == "false")){
        cliente= new sport(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(), dataInizioAbbTemp.day(), c.at(26).toUInt(),
                c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toDouble(), c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toDouble(),
                          c.at(21).toUInt(), c.at(21).toUInt(), c.at(22)=="true" ? true:false);
        }
        datiTotali->push_back(cliente);
        emit clienteAggiunto();
    }
}

void model::removeC(const int i)
{
    modificato=true;
    datiTotali->erase_pos(i);
    emit clienteRimosso();
}

#include "model.h"
model::model(): listaTClienti(new container<deepPointer<nowqt>>()) {}

model::~model()
{
    listaTClienti->erase();
    delete listaTClienti;
}

QStringList model::getCampiCliente(const int indice) const
{
    QStringList temp;
    deepPointer<nowqt> clienteTemp;
    clienteTemp = listaTClienti->get_T_at_pos(indice);

    temp.push_back(QString::fromStdString(clienteTemp->getNome()));
    temp.push_back(QString::fromStdString(clienteTemp->getCognome()));
    temp.push_back(QString::fromStdString(clienteTemp->getCodFisc()));
    temp.push_back(clienteTemp->getDataN().toString());
    temp.push_back(QString::fromStdString(clienteTemp->getEMail()));
    temp.push_back(clienteTemp->getDataInAbb().toString());
    QString m= QString::number(clienteTemp->getMesi());
    temp.push_back(m);
    temp.push_back(clienteTemp->isCodSconto()? "true":"false");
    temp.push_back(QString::fromStdString(clienteTemp->getCoupon()));
    QString t= QString::number(clienteTemp->getTot());
    temp.push_back(t);

    if(dynamic_cast<allinclusive*>(&(*(clienteTemp))) != nullptr){
        auto clienteai = dynamic_cast<allinclusive*>(&(*(clienteTemp)));
        temp.push_back("true");
        temp.push_back("true");
        temp.push_back("true");

        //kids
        temp.push_back(QString::fromStdString(clienteai->getTitoloK()));
        temp.push_back(QString::fromStdString(clienteai->getDescK()));
        QString cK= QString::number(clienteai->getCostoK());
        temp.push_back(cK);
        QString sK= QString::number(clienteai->getSchermiContK());
        temp.push_back(sK);
        temp.push_back(clienteai->isHdK()? "true":"false");

        // cinema
        temp.push_back(QString::fromStdString(clienteai->getTitoloC()));
        temp.push_back(QString::fromStdString(clienteai->getDescC()));
        QString cC= QString::number(clienteai->getCostoC());
        temp.push_back(cC);
        QString sC= QString::number(clienteai->getSchermiContC());
        temp.push_back(sC);
        temp.push_back(clienteai->isHdC()? "true":"false");

        // sport
        temp.push_back(QString::fromStdString(clienteai->getTitoloS()));
        temp.push_back(QString::fromStdString(clienteai->getDescS()));
        QString cS= QString::number(clienteai->getCostoS());
        temp.push_back(cS);
        QString sS= QString::number(clienteai->getSchermiContS());
        temp.push_back(sS);
        temp.push_back(clienteai->isSuperHdS()? "true":"false");
    }
    else if(dynamic_cast<kids*>(&(*(clienteTemp))) != nullptr){
        auto clientek = dynamic_cast<kids*>(&(*(clienteTemp)));

        //kids
        temp.push_back("true");
        temp.push_back("false");
        temp.push_back("false");
        temp.push_back(QString::fromStdString(clientek->getTitoloK()));
        temp.push_back(QString::fromStdString(clientek->getDescK()));
        QString cK= QString::number(clientek->getCostoK());
        temp.push_back(cK);
        QString sK= QString::number(clientek->getSchermiContK());
        temp.push_back(sK);
        temp.push_back(clientek->isHdK()? "true":"false");

    }
    else if(dynamic_cast<cinema*>(&(*(clienteTemp))) != nullptr){
        auto clientec = dynamic_cast<cinema*>(&(*(clienteTemp)));

        //cinema
        temp.push_back("true");
        temp.push_back("false");
        temp.push_back("false");
        temp.push_back(QString::fromStdString(clientec->getTitoloC()));
        temp.push_back(QString::fromStdString(clientec->getDescC()));
        QString cC= QString::number(clientec->getCostoC());
        temp.push_back(cC);
        QString sC= QString::number(clientec->getSchermiContC());
        temp.push_back(sC);
        temp.push_back(clientec->isHdC()? "true":"false"); // 16
    }
    else if(dynamic_cast<sport*>(&(*(clienteTemp))) != nullptr){
        auto clientes = dynamic_cast<sport*>(&(*(clienteTemp)));

        //sport
        temp.push_back("true");
        temp.push_back("false");
        temp.push_back("false");
        temp.push_back(QString::fromStdString(clientes->getTitoloS()));
        temp.push_back(QString::fromStdString(clientes->getDescS()));
        QString cS= QString::number(clientes->getCostoS());
        temp.push_back(cS);
        QString sS = QString::number(clientes->getSchermiContS());
        temp.push_back(sS);
        temp.push_back(clientes->isSuperHdS()? "true":"false");
    }
    return temp;
}

void model::removeC(const int i)
{
    listaTClienti->erase_pos(i);
    emit clienteRimosso();
}

deepPointer<nowqt> model::mostraCliente(const int i) const
{
    deepPointer<nowqt> clienteDaVisualizzare;
    clienteDaVisualizzare = (listaTClienti->get_T_at_pos(i));
    return clienteDaVisualizzare;
}

QStringList model::getListaClientiT(QMap<int, int>& indexMapper) const
{
    QStringList ret;
    QString cliente;
    auto it=listaTClienti->begin();
    int count=0;
    if(!listaTClienti->empty()){
        while(it!=listaTClienti->end()){
            cliente = (QString::fromStdString((*(*it)).getNome() + " " + (*(*it)).getCognome()));
            indexMapper.insert((int)ret.count(),count);
            ret.push_back(cliente);
            count++;
            ++it;
        }
    }
    return ret;
}

bool model::controlloC(const QString cf) const {
    QString codf;
    auto it=listaTClienti->begin();
    if(!listaTClienti->empty()){
        while(it!=listaTClienti->end()){
            codf = (QString::fromStdString((*(*it)).getCodFisc()));
            if(cf==codf) {
                return false;
            }
            ++it;
        }
        return true;
    }
    return true;
}

float model::applicaScontoAI(float t, unsigned int s) {
    float sconto=(t*s)/100;
    t=t-sconto;
    return t;
}

void model::addClientContainer(const QStringList c)
{
    deepPointer<nowqt> cliente;
    QString cf = QString::fromStdString(c.at(2).toStdString());
    if (!controlloC(cf)) {
        throw new std::runtime_error("Errore. Il cliente che si sta tentando di inserire è già presente nella lista dei clienti. Riprovare.");
    }
    else {
        QDate dataNascitaTemp = QDate::fromString(c.at(3));
        QDate dataInizioAbbTemp = QDate::fromString(c.at(25));
        if ((c.at(5) == "true" && c.at(11) == "true") && (c.at(17) == "true")) {
            float costoAI;
            costoAI=applicaScontoAI(c.at(27).toFloat(), 35);
            cliente = new allinclusive(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                       c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                       c.at(23)=="true" ? true:false, c.at(24).toStdString(), costoAI, c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toFloat(),
                                       c.at(9).toUInt(), c.at(10)=="true" ? true:false, c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toFloat(),
                                       c.at(15).toUInt(), c.at(16)=="true" ? true:false, c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toFloat(),
                                        c.at(21).toUInt(), c.at(22)=="true" ? true:false);
        } // solo kids
        else if((c.at(5) == "true") && (c.at(11) == "false" && c.at(17) == "false")){
            cliente = new kids(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(), dataNascitaTemp.month(), dataNascitaTemp.day(),
                               c.at(2).toStdString(),c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),
                               dataInizioAbbTemp.day(), c.at(26).toUInt(), c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toFloat(),
                               c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toFloat(), c.at(9).toUInt(), c.at(10)=="true" ? true:false);
        } // solo cinema
        else if((c.at(11) == "true") && (c.at(5) == "false" && c.at(17) == "false")){
            cliente = new cinema(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                 c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                 c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toFloat(), c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toFloat(),
                                 c.at(15).toUInt(), c.at(16)=="true" ? true:false);
        } // solo sport
        else if((c.at(17) == "true") && (c.at(5) == "false" && c.at(11) == "false")){
            cliente= new sport(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                            c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(), dataInizioAbbTemp.day(), c.at(26).toUInt(),
                            c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toFloat(), c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toFloat(),
                                      c.at(21).toUInt(), c.at(22)=="true" ? true:false);
        }
        listaTClienti->push_back(cliente);
        emit clienteAggiunto();
    }
}

void model::modificaCliente(const int indice, const QStringList c)
{
    deepPointer<nowqt> cliente;

    QDate dataNascitaTemp = QDate::fromString(c.at(3));
    QDate dataInizioAbbTemp = QDate::fromString(c.at(25));
    if ((c.at(5) == "true" && c.at(11) == "true") && (c.at(17) == "true")) {
        cliente = new allinclusive(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                                   c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                                   c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toFloat(), c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toFloat(),
                                   c.at(9).toUInt(), c.at(10)=="true" ? true:false, c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toFloat(),
                                   c.at(15).toUInt(), c.at(16)=="true" ? true:false, c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toFloat(),
                                    c.at(21).toUInt(), c.at(22)=="true" ? true:false);
    } // solo kids
    else if((c.at(5) == "true") && (c.at(11) == "false" && c.at(17) == "false")){
        cliente = new kids(c.at(0).toStdString(), c.at(1).toStdString(), dataNascitaTemp.year(), dataNascitaTemp.month(), dataNascitaTemp.day(),
                           c.at(2).toStdString(),c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),
                           dataInizioAbbTemp.day(), c.at(26).toUInt(), c.at(23)=="true" ? true:false, c.at(24).toStdString(), c.at(27).toFloat(),
                           c.at(6).toStdString(), c.at(7).toStdString(), c.at(8).toFloat(), c.at(9).toUInt(), c.at(10)=="true" ? true:false);
    } // solo cinema
    else if((c.at(11) == "true") && (c.at(5) == "false" && c.at(17) == "false")){
        cliente = new cinema(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
                             c.at(4).toStdString(),dataInizioAbbTemp.year(), dataInizioAbbTemp.month(),dataInizioAbbTemp.day(), c.at(26).toUInt(),
                             c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toFloat(), c.at(12).toStdString(), c.at(13).toStdString(), c.at(14).toFloat(),
                             c.at(15).toUInt(), c.at(16)=="true" ? true:false);
    } // solo sport
    else if((c.at(17) == "true") && (c.at(5) == "false" && c.at(11) == "false")){
            cliente= new sport(c.at(0).toStdString(),c.at(1).toStdString(), dataNascitaTemp.year(),dataNascitaTemp.month(),dataNascitaTemp.day(),c.at(2).toStdString(),
            c.at(4).toStdString(), dataInizioAbbTemp.year(), dataInizioAbbTemp.month(), dataInizioAbbTemp.day(), c.at(26).toUInt(),
            c.at(23)=="true" ? true:false, c.at(24).toStdString(),c.at(27).toFloat(), c.at(18).toStdString(), c.at(19).toStdString(), c.at(20).toFloat(),
                      c.at(21).toUInt(), c.at(22)=="true" ? true:false);
    }
    listaTClienti->replace_last(indice, cliente);
}

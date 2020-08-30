#include "controller.h"
controller::controller(QObject *parent) : QObject(parent), view(new mainwindow()), addClientW(new addClientWindow()), dettClientW(new dettClientWindow()), modClientW(new modClientWindow()), m(new model("data.xml"))
{
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    connect(view,SIGNAL(signOpenDettWindow(const int)),this,SLOT(openDettView(const int)));
    connect(view,SIGNAL(rimuoviCliente(const int)),this,SLOT(removeC(const int)));
    connect(view,SIGNAL(signOpenModWindow()),this,SLOT(openModView()));

    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(clienteRimShowBox()));
    connect(view, SIGNAL(elementFilter(const QString&)), this, SLOT(cFilter(const QString&)));

    connect(addClientW, SIGNAL(erroreInput(string)), this, SLOT(errInput(string)));
    connect(addClientW, SIGNAL(erroreData(string)),this , SLOT(errData(string)));
    connect(addClientW, SIGNAL(esitoCoupon(string)), this, SLOT(esitoCoup(string)));
    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));

    connect(modClientW, SIGNAL(erroreInput(string)), this, SLOT(errInput(string)));
    connect(modClientW, SIGNAL(erroreData(string)),this , SLOT(errData(string)));
    connect(modClientW, SIGNAL(rimpiazzaCliente(const int,const QStringList)), this, SLOT(rimpiazzaItem(const int, QStringList)));
    resetListaClienti();

   view->show();
}

controller::~controller()
{
}

void controller::openAddView() const
{
    addClientW->resettaInput();
    addClientW->setModal(true);
    addClientW->show();
}

void controller::openDettView(const int c) const {
    dettClientW->visualizzaDettagliCliente(m->mostraCliente(indexTranslate[c]));
    dettClientW->setModal(true);
    dettClientW->show();
}

void controller::openModView() const
{
    if(view->isSelected()){
        modClientW->caricaDati(m->getCampiCliente(view->getIndexSelected()), view->getIndexSelected());
        modClientW->setModal(true);
        modClientW->show();
    }
    else
        view->nessunSelezionato();
}

void controller::resetListaClientiF()
{
    view->mostraClienti(m->getListaClientiF(indexTranslate));
}

void controller::rimpiazzaItem(const int indice, const QStringList stringaCliente)
{
    m->modificaItem(indexTranslate[indice], stringaCliente);
    modClientW->close();
    modClientW->clienteModificato();
    resetListaClienti();
}

void controller::resetListaClienti()
{
    view->mostraClienti(m->getListaClientiT(indexTranslate));
}

void controller::errInput(string i)
{
    addClientW->mostraErroreInput(i);
}

void controller::errData(string d)
{
    addClientW->mostraErroreData(d);
}

void controller::esitoCoup(string e)
{
    addClientW->mostraEsitoC(e);
}

void controller::removeC(const int indice){
    m->removeC(indexTranslate[indice]);
}

void controller::cFilter(const QString& n)
{
    std::string temp=n.toStdString();
    m->actualFilter(temp);
    resetListaClientiF();
}

void controller::clienteRimShowBox(){
    QMessageBox clienteRimBox;
    clienteRimBox.information(view,"Cliente rimosso","Il cliente selezionato è stato rimosso con successo!");
}

void controller::aggClienteContainer(const QStringList dettagli)
{
    try{
    m->aggNelContainer(dettagli);
    addClientW->close();
    addClientW->successoCliente();
    }catch(std::exception *exc){
        addClientW->showErrorInsMessage(exc->what());
    }
}

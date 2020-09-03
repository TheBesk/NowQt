#include "controller.h"
controller::controller(QObject *parent) : QObject(parent), view(new mainwindow()), addClientW(new addClientWindow()), dettClientW(new dettClientWindow()), modClientW(new modClientWindow()), m(new model())
{
    connect(view,SIGNAL(segnApriAgg()),this,SLOT(apriFinAgg()));
    connect(view,SIGNAL(signOpenDettWindow(const int)),this,SLOT(openDettView(const int)));
    connect(view,SIGNAL(rimuoviCliente(const int)),this,SLOT(removeC(const int)));
    connect(view,SIGNAL(segnApriMod()),this,SLOT(apriFinMod()));

    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(clienteRimShowBox()));

    connect(addClientW, SIGNAL(erroreInput(string)), this, SLOT(errInput(string)));
    connect(addClientW, SIGNAL(erroreData(string)),this , SLOT(errData(string)));
    connect(addClientW, SIGNAL(esitoCoupon(string)), this, SLOT(esitoCoup(string)));
    connect(addClientW, SIGNAL(inviaDatiC(const QStringList)), this, SLOT(addInCont(const QStringList)));

    connect(modClientW, SIGNAL(erroreInput(string)), this, SLOT(errInput(string)));
    connect(modClientW, SIGNAL(erroreData(string)),this , SLOT(errData(string)));
    connect(modClientW, SIGNAL(substCliente(const int,const QStringList)), this, SLOT(modClienteSel(const int, QStringList)));

    resetListaClienti();
    view->show();
}

controller::~controller()
{
    delete m;
}

void controller::apriFinAgg() const
{
    addClientW->resettaInput();
    addClientW->setModal(true);
    addClientW->show();
}

void controller::openDettView(const int c) const {
    dettClientW->mostraDettCliente(m->mostraCliente(indexTranslate[c]));
    dettClientW->setModal(true);
    dettClientW->show();
}

void controller::apriFinMod() const
{
    if(view->isSelezionato()){
        modClientW->loadDCliente(m->getCampiCliente(view->getIndiceSel()), view->getIndiceSel());
        modClientW->setModal(true);
        modClientW->show();
    }
    else
        view->noSelected();
}

void controller::modClienteSel(const int indice, const QStringList stringaCliente)
{
    m->modificaCliente(indexTranslate[indice], stringaCliente);
    modClientW->close();
    modClientW->clienteModificato();
    resetListaClienti();
}

void controller::resetListaClienti()
{
    view->showLClienti(m->getListaClientiT(indexTranslate));
}

void controller::errInput(string i)
{
    addClientW->errInputShowBox(i);
}

void controller::errData(string d)
{
    addClientW->errDataShowBox(d);
}

void controller::esitoCoup(string e)
{
    addClientW->mostraEsitoC(e);
}

void controller::removeC(const int indice){
    m->removeC(indexTranslate[indice]);
}

void controller::clienteRimShowBox(){
    QMessageBox clienteRimBox;
    clienteRimBox.information(view, "Cliente rimosso", "Il cliente selezionato è stato rimosso con successo!");
}

void controller::addInCont(const QStringList dettagli)
{
    try {
        m->addClientContainer(dettagli);
        addClientW->close();
        addClientW->successoCliente();
        }
    catch(std::exception *exc){
        addClientW->showErrorInsMessage(exc->what());
        delete exc;
    }
}

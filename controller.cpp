#include "controller.h"
controller::controller(QObject *parent) : QObject(parent),view(new mainwindow()), addClientW(new addClientWindow()), dettClientW(new dettClientWindow()), m(new model("data.xml"))
{
    connect(view,SIGNAL(signOpenAddWindow()),this,SLOT(openAddView()));
    //connect(view, SIGNAL(signEsportaPDFClienti()), this, SLOT(esportaPDFClienti())); SLOT editclient
    connect(view,SIGNAL(signOpenDettWindow(const int)),this,SLOT(openDettView(const int)));
    //connect(view,SIGNAL(richiestaShowCliente(const unsigned int)),this,SLOT(mostraCliente(const unsigned int)));
    connect(m, SIGNAL(clienteAggiunto()), this, SLOT(resetListaClienti()));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(resetListaClienti()));
    connect(view,SIGNAL(rimuoviCliente(const int)),this,SLOT(removeC(const int)));
    connect(m, SIGNAL(clienteRimosso()), this, SLOT(clienteRimShowBox()));

    connect(addClientW, SIGNAL(erroreInput(string)), this, SLOT(errInput(string)));
    connect(addClientW, SIGNAL(erroreData(string)),this , SLOT(errData(string)));
    connect(addClientW, SIGNAL(esitoCoupon(string)), this, SLOT(esitoCoup(string)));
    connect(addClientW, SIGNAL(inviaStringaCliente(const QStringList)), this, SLOT(aggClienteContainer(const QStringList)));

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
    dettClientW->visualizzaDettagliCliente(m->mostraCliente(indexTranslate[c])); // è giusta
    //dettClientW->caricaDati(m->getCampiCliente(view->getIndexSelected()), view->getIndexSelected());
    dettClientW->setModal(true);
    dettClientW->show();
}

/*
void controller::mostraCliente(const unsigned int cliente){
    dettClientW->visualizzaDettagliCliente(m->mostraCliente(indexTranslate[cliente]));
}
*/

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

void controller::aggClienteContainer(const QStringList dettagli)
{
    //try{
    m->aggNelContainer(dettagli);
    addClientW->close();
    addClientW->successoCliente();
    /*}catch(std::exception *exc){
        addClientW->showErrorMessage(exc->what());
    }*/
}
void controller::removeC(const int indice){
    m->removeC(indexTranslate[indice]);
}

void controller::clienteRimShowBox(){
    QMessageBox clienteRimBox;
    clienteRimBox.information(view,"Cliente rimosso","Il cliente selezionato è stato rimosso con successo!");
}

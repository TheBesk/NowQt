#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QWidget(parent), listaClienti(new viewListaC(this))
{
    setWindowTitle("NowQT");
    setWindowIcon(QIcon(":/icone/nowqt_icon.ico"));
    mainLayout = new QVBoxLayout(this);

    QMenuBar* menubar = new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* exit = new QAction("Esci",menu);

    menu->addAction(exit);
    menubar->addMenu(menu);
    mainLayout->addWidget(menubar);

    // setMainWindowStyle();
    verticalSxLayout = new QVBoxLayout();

    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);

    setLayout(mainLayout);

    QHBoxLayout* imgLayout = new QHBoxLayout();

    QPixmap*  pix = new QPixmap(":/risorse/rsz_nowqt.jpg");
    QLabel* image = new QLabel(this);
    image->setPixmap(*pix);
    imgLayout->addWidget(image);
    verticalDxLayout->addLayout(imgLayout);

    QVBoxLayout* vPulsanti = new QVBoxLayout();
    verticalDxLayout->addLayout(vPulsanti);
    addButton = new QPushButton("Aggiungi cliente",this);
    addButton->setMinimumWidth(100);
    modButton = new QPushButton("Modifica cliente",this);
    modButton->setMinimumWidth(100);
    removeButton = new QPushButton("Rimuovi cliente",this);
    removeButton->setMinimumWidth(100);
    dettButton = new QPushButton("Dettagli cliente",this);
    dettButton->setMinimumWidth(100);

    vPulsanti->addWidget(addButton);
    vPulsanti->addWidget(modButton);
    vPulsanti->addWidget(dettButton);
    vPulsanti->addWidget(removeButton);

    QGroupBox *clientiGroup = new QGroupBox("Lista clienti");
    clientiGroup->setAlignment(Qt::AlignCenter);
    listaClienti->setSelectionMode(QAbstractItemView::SingleSelection);
    QVBoxLayout *layoutListaClienti = new QVBoxLayout();
    QHBoxLayout *layoutRicerca = new QHBoxLayout();
    lineCerca = new QLineEdit(this);
    lineCerca->setPlaceholderText("Cerca cliente");
    lineCerca->setMinimumWidth(250);

    layoutRicerca->addWidget(lineCerca);
    QLabel *filtroLabel = new QLabel(tr("Filtra per "));
    layoutRicerca->addWidget(filtroLabel);
    QComboBox* tipoP = new QComboBox();
    tipoP->addItem("Nessun filtro");
    tipoP->addItem("Kids");
    tipoP->addItem("Cinema");
    tipoP->addItem("Sport");
    tipoP->addItem("All inclusive");
    layoutRicerca->addWidget(tipoP);
    layoutListaClienti->addLayout(layoutRicerca);
    layoutListaClienti->addWidget(listaClienti);
    clientiGroup->setLayout(layoutListaClienti);
    verticalSxLayout->addWidget(clientiGroup);
    divH->addLayout(verticalDxLayout);

    connect(addButton, SIGNAL(clicked()), this, SIGNAL(signOpenAddWindow()));
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(dettButton, SIGNAL(clicked()), this, SLOT(showInfoCliente()));
    connect(removeButton, SIGNAL(clicked()),this, SLOT(richRimuoviC()));
    connect(modButton, SIGNAL(clicked()), this, SIGNAL(signOpenModWindow()));
    connect(tipoP, SIGNAL(currentTextChanged(const QString &)), this, SIGNAL(elementFilter(const QString&)));
}

void mainwindow::mostraClienti(const QStringList datiCliente)
{
    listaClienti->reset();
    listaClienti->clear();
    auto it = datiCliente.begin();
    while(it!=datiCliente.end()){
        listaClienti->addItem(*it);
        ++it;
    }
}

void mainwindow::nessunSelezionato()
{
    QMessageBox NonSelezionato;
    NonSelezionato.critical(this,"Nessun cliente selezionato","Selezionare un cliente");
}

bool mainwindow::isSelected() const
{
    return listaClienti->isSomeoneSelected();
}

void mainwindow::showInfoCliente(){
    if(listaClienti->isSomeoneSelected())
        emit signOpenDettWindow(listaClienti->getIndex());
    else {
        nessunSelezionato();
    }
}

void mainwindow::richRimuoviC()
{
    if(listaClienti->isSomeoneSelected())
        emit rimuoviCliente(listaClienti->getIndex());
    else
        nessunSelezionato();
}

int mainwindow::getIndexSelected() const
{
    return listaClienti->getIndex();
}


#include "mainwindow.h"

mainwindow::mainwindow(QWidget *parent) : QWidget(parent), listaClienti(new viewListaC(this))
{
    setMinimumSize(700,500);
    setWindowTitle("NowQT");
    setWindowIcon(QIcon(":/icone/nowqt_icon.ico"));

    mainLayout = new QVBoxLayout(this);

    QMenuBar* menubar = new QMenuBar(this);
    QMenu* menu= new QMenu("File", menubar);
    QAction* exit = new QAction("Esci", menu);

    menu->addAction(exit);
    menubar->addMenu(menu);
    mainLayout->addWidget(menubar);

    verticalSxLayout = new QVBoxLayout();
    verticalDxLayout = new QVBoxLayout();
    divH = new QHBoxLayout();

    mainLayout->addLayout(divH);
    divH->addLayout(verticalSxLayout);
    setLayout(mainLayout);

    QHBoxLayout* imgLayout = new QHBoxLayout();
    QPixmap pix;
    pix.load(":/risorse/rsz_nowqt.jpg");
    QLabel* image = new QLabel(this);
    image->setPixmap(pix);
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

    layoutListaClienti->addWidget(listaClienti);
    clientiGroup->setLayout(layoutListaClienti);
    verticalSxLayout->addWidget(clientiGroup);
    divH->addLayout(verticalDxLayout);    

    connect(addButton, SIGNAL(clicked()), this, SIGNAL(segnApriAgg()));
    connect(dettButton, SIGNAL(clicked()), this, SLOT(visualizzaCliente()));
    connect(modButton, SIGNAL(clicked()), this, SIGNAL(segnApriMod()));
    connect(removeButton, SIGNAL(clicked()),this, SLOT(richRimuoviC()));
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));
}

void mainwindow::showLClienti(const QStringList datiCliente)
{
    listaClienti->reset();
    listaClienti->clear();
    auto it = datiCliente.begin();
    while(it!=datiCliente.end()){
        listaClienti->addItem(*it);
        ++it;
    }
}

void mainwindow::noSelected()
{
    QMessageBox NonSelezionato;
    NonSelezionato.critical(this, "Nessun cliente selezionato", "Selezionare un cliente");
}

bool mainwindow::isSelezionato() const
{
    return listaClienti->isSomeoneSelected();
}

void mainwindow::visualizzaCliente(){
    if(listaClienti->isSomeoneSelected())
        emit signOpenDettWindow(listaClienti->getIndex());
    else {
        noSelected();
    }
}

void mainwindow::richRimuoviC()
{
    if(listaClienti->isSomeoneSelected())
        emit rimuoviCliente(listaClienti->getIndex());
    else
        noSelected();
}

int mainwindow::getIndiceSel() const
{
    return listaClienti->getIndex();
}

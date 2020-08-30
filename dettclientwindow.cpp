#include "dettclientwindow.h"

dettClientWindow::dettClientWindow(QWidget *parent) : QDialog(parent), pacchetto1Group(new QGroupBox(this)), pacchetto2Group(new QGroupBox(this)), pacchetto3Group(new QGroupBox(this)), nomeClienteLabel(new QLabel(this)), cognomeClienteLabel(new QLabel(this)), codiceFiscClienteLabel(new QLabel(this)), dataNascitaClienteLabel(new QLabel(this)), emailClienteLabel(new QLabel(this)), pacchClienteLabel(new QLabel(this)), offertaKidsCLabel(new QLabel(this)), descKidsLabel(new QLabel(this)), schermiContKLabel(new QLabel(this)), hdKidsLabel(new QLabel(this)), offertaCinemaCLabel(new QLabel(this)), descCinemaLabel(new QLabel(this)), schermiContCLabel(new QLabel(this)), hdCinemaLabel(new QLabel(this)), offertaSportCLabel(new QLabel(this)), descSportLabel(new QLabel(this)), schermiContSLabel(new QLabel(this)), hdSportLabel(new QLabel(this)), dataInizioALabel(new QLabel(this)), mesiAbbLabel(new QLabel(this)), dataFineALabel(new QLabel(this)), BcodiceScontoLabel(new QLabel(this)), tcouponLabel(new QLabel(this)), TcodiceScontoLabel(new QLabel(this)), totMeseAbbLabel(new QLabel(this)), totMesiAbbLabel(new QLabel(this))
 {
    setMinimumSize(1000,400);
    setWindowTitle("Finestra dettagli cliente");
    mainLayout = new QHBoxLayout(this);
    divH= new QHBoxLayout();

    QFormLayout *form1Layout = new QFormLayout();
    QVBoxLayout *pacchVLayout = new QVBoxLayout();
    QFormLayout *form3Layout = new QFormLayout();

    QGroupBox *daticlienteGroup = new QGroupBox("Dati cliente");
    daticlienteGroup->setAlignment(Qt::AlignCenter);
    // nome, cognome, data di nascita, codice fiscale, email,
    QLabel *nomeLabel = new QLabel(tr("Nome: "));
    QLabel *cognomeLabel = new QLabel(tr("Cognome: "));
    QLabel *codFiscLabel = new QLabel(tr("Codice fiscale: "));
    QLabel *dateNascitaLabel = new QLabel("Data di nascita: ");
    QLabel *emailLabel = new QLabel(tr("Indirizzo email: "));

    form1Layout->addRow(nomeLabel, nomeClienteLabel);
    form1Layout->addRow(cognomeLabel, cognomeClienteLabel);
    form1Layout->addRow(codFiscLabel, codiceFiscClienteLabel);
    form1Layout->addRow(dateNascitaLabel, dataNascitaClienteLabel);
    form1Layout->addRow(emailLabel, emailClienteLabel);

    daticlienteGroup->setLayout(form1Layout);
    divH->addWidget(daticlienteGroup);

    QLabel *pacchLabel= new QLabel(tr("Pacchetto scelto: ")); // "ALL INCLUSIVE - KIDS + CINEMA + SPORT" oppure "KIDS" oppure "CINEMA" oppure "SPORT"
    pacchLabel->setAlignment(Qt::AlignCenter);
    pacchVLayout->addWidget(pacchLabel);
    pacchClienteLabel->setAlignment(Qt::AlignCenter);
    pacchVLayout->addWidget(pacchClienteLabel);

    // pacchetti si / no,
    pacchVLayout->addWidget(pacchetto1Group);
    QFormLayout *formKLayout = new QFormLayout();

    QLabel *dPacch1= new QLabel(tr("Descrizione: "));
    QLabel *scPacch1= new QLabel(tr("Schermi in cont.: "));
    QLabel *hdPacch1= new QLabel(tr("HD: "));

    formKLayout->addRow(offertaKidsCLabel);
    formKLayout->addRow(dPacch1, descKidsLabel);
    formKLayout->addRow(scPacch1, schermiContKLabel );
    formKLayout->addRow(hdPacch1, hdKidsLabel);
    pacchetto1Group->setLayout(formKLayout);

    pacchVLayout->addWidget(pacchetto2Group);
    QFormLayout *formCLayout = new QFormLayout();

    QLabel *dPacch2= new QLabel(tr("Descrizione: ")); // string
    QLabel *scPacch2= new QLabel(tr("Schermi in cont.: ")); // unsigned int
    QLabel *hdPacch2= new QLabel(tr("HD: ")); // si / no

    formCLayout->addRow(offertaCinemaCLabel);
    formCLayout->addRow(dPacch2, descCinemaLabel);
    formCLayout->addRow(scPacch2, schermiContCLabel);
    formCLayout->addRow(hdPacch2, hdCinemaLabel);

    pacchetto2Group->setLayout(formCLayout);

    pacchVLayout->addWidget(pacchetto3Group);
    QFormLayout *formSLayout = new QFormLayout();

    QLabel *dPacch3= new QLabel(tr("Descrizione: "));
    QLabel *scPacch3= new QLabel(tr("Schermi in cont.: "));
    QLabel *hdPacch3= new QLabel(tr("Super HD: "));

    formSLayout->addRow(offertaSportCLabel);
    formSLayout->addRow(dPacch3, descSportLabel);
    formSLayout->addRow(scPacch3, schermiContSLabel);
    formSLayout->addRow(hdPacch3, hdSportLabel);

    offertaKidsCLabel->setAlignment(Qt::AlignCenter);
    offertaCinemaCLabel->setAlignment(Qt::AlignCenter);
    offertaSportCLabel->setAlignment(Qt::AlignCenter);

    pacchetto3Group->setLayout(formSLayout);
    divH->addLayout(pacchVLayout);
    QGroupBox *statoabbGroup = new QGroupBox("Stato dell'abbonamento");
    statoabbGroup->setAlignment(Qt::AlignCenter);
    // data scadenza , data inizio , totale.. sconto
    QLabel *dateInAbbLabel = new QLabel("Data inizio abbonamento: ");
    QLabel *dateFiAbbLabel = new QLabel("Data fine abbonamento: ");
    QLabel *mesiLabel = new QLabel(tr("Mesi: "));
    QLabel *bcouponLabel = new QLabel(tr("Codice sconto applicato: ")); // si / no
    tcouponLabel->setText("Nome codice: "); // UNIPD
    QLabel *totLabel = new QLabel(tr("Totale euro al mese: "));
    QLabel *totalepagLabel = new QLabel(tr("Totale euro per tutti i mesi: "));

    form3Layout->addRow(dateInAbbLabel, dataInizioALabel);
    form3Layout->addRow(dateFiAbbLabel, dataFineALabel);
    form3Layout->addRow(mesiLabel, mesiAbbLabel);
    form3Layout->addRow(bcouponLabel, BcodiceScontoLabel);
    form3Layout->addRow(tcouponLabel, TcodiceScontoLabel);
    form3Layout->addRow(totLabel, totMeseAbbLabel);
    form3Layout->addRow(totalepagLabel, totMesiAbbLabel);

    statoabbGroup->setLayout(form3Layout);
    divH->addWidget(statoabbGroup);

    closeButton = new QPushButton("Chiudi",this);
    closeButton->setFixedWidth(70);
    cHButton= new QHBoxLayout();
    cHButton->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    divV= new QVBoxLayout();

    divV->addLayout(divH);
    cHButton->addWidget(closeButton);
    divV->addLayout(cHButton);
    mainLayout->addLayout(divV);

    setLayout(mainLayout);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

}

void dettClientWindow::visualizzaDettagliCliente(deepPointer<nowqt> clienteDaVisualizzare) const
{
    QString nome = QString::fromStdString(clienteDaVisualizzare->getNome());
    nomeClienteLabel->clear();
    nomeClienteLabel->setText(nome);
    QString cognome = QString::fromStdString(clienteDaVisualizzare->getCognome());
    cognomeClienteLabel->clear();
    cognomeClienteLabel->setText(cognome);
    QString cf = QString::fromStdString(clienteDaVisualizzare->getCodFisc());
    codiceFiscClienteLabel->clear();
    codiceFiscClienteLabel->setText(cf);
    dataNascitaClienteLabel->clear();
    dataNascitaClienteLabel->setText(clienteDaVisualizzare->getDataN().toString("dd/MM/yyyy"));
    QString email =  QString:: fromStdString(clienteDaVisualizzare->getEMail());
    emailClienteLabel->clear();
    emailClienteLabel->setText(email);
    dataInizioALabel->clear();
    dataInizioALabel->setText(clienteDaVisualizzare->getDataInAbb().toString("dd/MM/yyyy"));
    dataFineALabel->clear();
    dataFineALabel->setText(clienteDaVisualizzare->CalcolaFineAbb().toString("dd/MM/yyyy"));
    mesiAbbLabel->clear();
    QString m= QString::number(clienteDaVisualizzare->getMesi());
    mesiAbbLabel->setText(m);
    BcodiceScontoLabel->clear();
    if (clienteDaVisualizzare->isCodSconto()) {
        BcodiceScontoLabel->setText("Sì");
        tcouponLabel->show();
        TcodiceScontoLabel->show();
        TcodiceScontoLabel->clear();
        TcodiceScontoLabel->setText(QString::fromStdString(clienteDaVisualizzare->getCoupon()));
    }
    else {
        BcodiceScontoLabel->setText("No");
        tcouponLabel->hide();
        TcodiceScontoLabel->hide();
    }

    totMeseAbbLabel->clear();
    QString t= QString::number(clienteDaVisualizzare->getTot());
    totMeseAbbLabel->setText(t);
    QString ta=QString::number(clienteDaVisualizzare->calcolaTotAbb());
    totMesiAbbLabel->clear();
    totMesiAbbLabel->setText(ta); // sistemare questa funzione

    pacchClienteLabel->clear();
    offertaKidsCLabel->clear();
    offertaCinemaCLabel->clear();
    offertaSportCLabel->clear();
    descKidsLabel->clear();
    descCinemaLabel->clear();
    descSportLabel->clear();
    schermiContKLabel->clear();
    schermiContCLabel->clear();
    schermiContSLabel->clear();
    hdKidsLabel->clear();
    hdCinemaLabel->clear();
    hdSportLabel->clear();

    if (dynamic_cast<allinclusive*>(&(*(clienteDaVisualizzare))) != nullptr) {
        auto abbai = dynamic_cast<allinclusive*>(&(*(clienteDaVisualizzare)));
        QString ai = QString::fromStdString((abbai->getTipoPacc()));
        QString k = QString::fromStdString(abbai->getTitoloK());
        QString c = QString::fromStdString(abbai->getTitoloC());
        QString s = QString::fromStdString(abbai->getTitoloS());

        pacchetto1Group->setVisible(true);
        pacchetto2Group->setVisible(true);
        pacchetto3Group->setVisible(true);

        pacchClienteLabel->setText(ai+": "+k+" + "+c+" + "+s);
        offertaKidsCLabel->show();
        offertaKidsCLabel->setText(k);
        descKidsLabel->setText(QString::fromStdString(abbai->getDescK()));
        schermiContKLabel->setText(QString::number(abbai->getSchermiContK()));
        if (abbai->isHdK()) {
            hdKidsLabel->setText("Sì");
        }
        else {
            hdKidsLabel->setText("No");
        }
        offertaCinemaCLabel->show();
        offertaCinemaCLabel->setText(c);
        descCinemaLabel->setText(QString::fromStdString(abbai->getDescC()));
        schermiContCLabel->setText(QString::number(abbai->getSchermiContC()));
        if (abbai->isHdC()) {
            hdCinemaLabel->setText("Sì");
        }
        else {
            hdCinemaLabel->setText("No");
        }
        offertaSportCLabel->show();
        offertaSportCLabel->setText(s);
        descSportLabel->setText(QString::fromStdString(abbai->getDescS()));
        schermiContSLabel->setText(QString::number(abbai->getSchermiContS()));
        if (abbai->isSuperHdS()) {
            hdSportLabel->setText("Sì");
        }
        else {
            hdSportLabel->setText("No");
        }
    }

    else if (dynamic_cast<kids*>(&(*(clienteDaVisualizzare))) != nullptr) {
        auto abbk = dynamic_cast<kids*>(&(*(clienteDaVisualizzare)));
        QString k = QString::fromStdString(abbk->getTipoPacc());
        pacchClienteLabel->setText(k);
        pacchetto1Group->setVisible(true);
        pacchetto2Group->setVisible(false);
        pacchetto3Group->setVisible(false);
        offertaKidsCLabel->hide();
        descKidsLabel->setText(QString::fromStdString(abbk->getDescK()));
        schermiContKLabel->setText(QString::number(abbk->getSchermiContK()));
        if (abbk->isHdK()) {
            hdKidsLabel->setText("Sì");
        }
        else {
            hdKidsLabel->setText("No");
        }

    }
    else if (dynamic_cast<cinema*>(&(*(clienteDaVisualizzare))) != nullptr) {
        auto abbc = dynamic_cast<cinema*>(&(*(clienteDaVisualizzare)));
        QString c = QString::fromStdString(abbc->getTipoPacc());
        pacchClienteLabel->setText(c);
        pacchetto1Group->setVisible(false);
        pacchetto2Group->setVisible(true);
        pacchetto3Group->setVisible(false);
        offertaCinemaCLabel->hide();
        descCinemaLabel->setText(QString::fromStdString(abbc->getDescC()));
        schermiContCLabel->setText(QString::number(abbc->getSchermiContC()));
        if (abbc->isHdC()) {
            hdCinemaLabel->setText("Sì");
        }
        else {
            hdCinemaLabel->setText("No");
        }

    }
    else if (dynamic_cast<sport*>(&(*(clienteDaVisualizzare))) != nullptr) {
        auto abbs = dynamic_cast<sport*>(&(*(clienteDaVisualizzare)));
        QString s = QString::fromStdString(abbs->getTipoPacc());
        pacchClienteLabel->setText(s);
        pacchetto1Group->setVisible(false);
        pacchetto2Group->setVisible(false);
        pacchetto3Group->setVisible(true);
        offertaSportCLabel->hide();
        descSportLabel->setText(QString::fromStdString(abbs->getDescS()));
        schermiContSLabel->setText(QString::number(abbs->getSchermiContS()));
        if (abbs->isSuperHdS()) {
            hdSportLabel->setText("Sì");
        }
        else {
            hdSportLabel->setText("No");
        }
    }
}

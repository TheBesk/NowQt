#include "addclientwindow.h"

addClientWindow::addClientWindow(QWidget *parent) : QDialog(parent), codiceSconto(false), introLabel(new QLabel(this)), personLabel(new QLabel(this)), avvertLabel(new QLabel(this)), scontoLabel(new QLabel(this)), totaleAbbLabel(new QLabel(this)), titoloPKidsLabel(new QLabel(this)), descPKidsLabel(new QLabel(this)), costoPKidsLabel(new QLabel(this)), titoloPCinemaLabel(new QLabel(this)), descPCinemaLabel(new QLabel(this)), costoPCinemaLabel(new QLabel(this)), titoloPSportLabel(new QLabel(this)), descPSportLabel(new QLabel(this)), costoPSportLabel(new QLabel(this)), pacchettoKidscb(new QCheckBox("Offerta Kids",this)), pacchettoCinemacb(new QCheckBox("Offerta Cinema",this)), pacchettoSportcb(new QCheckBox("Offerta Sport", this)), kidsGroup (new QGroupBox("Pacchetto 1",this)), cinemaGroup(new QGroupBox("Pacchetto 2",this)), sportGroup(new QGroupBox("Pacchetto 3",this))
{
    setMinimumSize(900, 600);
    setWindowTitle("Registrazione nuovo cliente");
    mainLayout = new QHBoxLayout(this);

    setLayout(mainLayout);
    introLabel->setText("Benvenuto. I campi contrassegnati con (*) sono obbligatori.");

    QLabel *nomeLabel = new QLabel(tr("Nome(*):"));
    nomeLineEdit = new QLineEdit();
    nomeLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,30}")));
    nomeLineEdit->setPlaceholderText("es. Mario");

    QLabel *cognomeLabel = new QLabel(tr("Cognome(*):"));
    cognomeLineEdit = new QLineEdit();
    cognomeLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,30}")));
    cognomeLineEdit->setPlaceholderText("es. Bianchi");

    QLabel *codFiscLabel = new QLabel(tr("Codice fiscale(*):"));
    codFiscLineEdit = new QLineEdit();
    codFiscLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Z0-9]{0,20}")));
    codFiscLineEdit->setPlaceholderText("es. MNLGFR78B63M297E");

    QLabel *dateNascitaLabel = new QLabel("Data di nascita(*): ");
    dateNascita = (new QDateEdit(QDate::currentDate(),this));
    dateNascita->setCalendarPopup(true);

    QLabel *emailLabel = new QLabel(tr("Indirizzo email(*):"));
    emailLineEdit = new QLineEdit();
    emailLineEdit->setPlaceholderText("es. mariobianchi@unipd.it");

    personLabel->setText("Puoi selezionare un pacchetto o tutti i pacchetti.");
    avvertLabel->setText("Selezionando tutti i pacchetti si attiverà automaticamente \nil pacchetto All inclusive ad un prezzo scontato. Lo sconto \nverrà applicato al termine della registrazione.");

    QLabel *dateInAbbLabel = new QLabel("Data inizio abbonamento(*):");
    dateInAbb = (new QDateEdit(QDate::currentDate(),this));
    dateInAbb->setCalendarPopup(true);

    QLabel *mesiLabel = new QLabel(tr("Mesi(*):"));
    mesiLineEdit= new QLineEdit();
    mesiLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{3}")));
    // 1 non deve essere valido
    QHBoxLayout *scontoHLayout= new QHBoxLayout();
    scontoLabel->setText("Hai un codice sconto? \nInseriscilo qui dopo aver personalizzato il tuo abbonamento a nowqt.");
    codicescLineEdit = new QLineEdit();
    verificacButton = new QPushButton("Verifica",this);
    scontoHLayout->addWidget(codicescLineEdit);
    scontoHLayout->addWidget(verificacButton);
    QLabel *totLabel = new QLabel(tr("Totale euro al mese:"));
    totaleAbbLabel->setText("0");
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(introLabel);
    formLayout->addRow(nomeLabel, nomeLineEdit);
    formLayout->addRow(cognomeLabel, cognomeLineEdit);
    formLayout->addRow(codFiscLabel, codFiscLineEdit);
    formLayout->addRow(dateNascitaLabel, dateNascita);
    formLayout->addRow(emailLabel, emailLineEdit);
    formLayout->addRow(personLabel);
    formLayout->addRow(pacchettoKidscb);
    formLayout->addRow(pacchettoCinemacb);
    formLayout->addRow(pacchettoSportcb);
    formLayout->addRow(avvertLabel);
    formLayout->addRow(dateInAbbLabel, dateInAbb);
    formLayout->addRow(mesiLabel, mesiLineEdit);
    formLayout->addRow(scontoLabel);
    formLayout->addRow(scontoHLayout);
    formLayout->addRow(totLabel, totaleAbbLabel);

    nomeLineEdit->setFixedWidth(250);
    cognomeLineEdit->setFixedWidth(250);
    codFiscLineEdit->setFixedWidth(250);
    dateNascita->setFixedWidth(250);
    emailLineEdit->setFixedWidth(250);
    codicescLineEdit->setFixedWidth(130);
    verificacButton->setFixedWidth(70);
    dateInAbb->setFixedWidth(250);
    mesiLineEdit->setFixedWidth(40);

    //************** PEZZO FORM KIDS ********************
    QFormLayout *formKidsLayout = new QFormLayout();
    QLabel *titoloKLabel = new QLabel("Titolo:");
    titoloPKidsLabel->setText("Offerta Kids");
    QLabel *descKLabel = new QLabel("Descrizione:");
    descPKidsLabel->setText("I programmi più amati da bambini e ragazzi.");

    QLabel *costoKLabel = new QLabel("Costo in euro:");
    costoPKidsLabel->setText("4");
    QHBoxLayout *schermiKHLayout = new QHBoxLayout();
    QLabel *schermiKLabel = new QLabel("Schermi in contemporanea:");
    rimuovisKButton = new QPushButton("-", this);
    rimuovisKButton->setStyleSheet("font-weight: bold;");

    // riquadro del numero di schermi
    schermiKLineEdit = new QLineEdit();
    schermiKLineEdit->setValidator(new QRegExpValidator(QRegExp("[2-4]{1}")));
    schermiKLineEdit->setText("2");

    aggiungisKButton = new QPushButton("+", this);
    aggiungisKButton->setStyleSheet("font-weight: bold;");

    schermiKHLayout->addWidget(schermiKLabel);
    schermiKHLayout->addWidget(rimuovisKButton);
    schermiKHLayout->addWidget(schermiKLineEdit);
    schermiKHLayout->addWidget(aggiungisKButton);
    kidsHDcheckBox = new QCheckBox("HD incluso",this);

    formKidsLayout->addRow(titoloKLabel, titoloPKidsLabel);
    formKidsLayout->addRow(descKLabel, descPKidsLabel);
    formKidsLayout->addRow(costoKLabel, costoPKidsLabel);
    formKidsLayout->addRow(schermiKHLayout);
    formKidsLayout->addRow(kidsHDcheckBox);

    kidsGroup->setLayout(formKidsLayout);

    //************** PEZZO FORM CINEMA ********************
    QFormLayout *formCinemaLayout = new QFormLayout();
    QLabel *titoloCLabel = new QLabel("Titolo:");
    titoloPCinemaLabel->setText("Offerta Cinema");
    QLabel *descCLabel = new QLabel("Descrizione:");
    descPCinemaLabel->setText("Film sempre nuovi da non perdere.");
    QLabel *costoCLabel = new QLabel("Costo in euro:");
    costoPCinemaLabel->setText("10");

    QHBoxLayout *schermiCHLayout = new QHBoxLayout();
    QLabel *schermiCLabel = new QLabel("Schermi in contemporanea:");
    rimuovisCButton = new QPushButton("-", this);
    rimuovisCButton->setStyleSheet("font-weight: bold;");

    // riquadro del numero di schermi
    schermiCLineEdit = new QLineEdit();
    schermiCLineEdit->setValidator(new QRegExpValidator(QRegExp("[2-4]{1}")));
    schermiCLineEdit->setText("2");
    aggiungisCButton = new QPushButton("+", this);
    aggiungisCButton->setStyleSheet("font-weight: bold;");

    schermiCHLayout->addWidget(schermiCLabel);
    schermiCHLayout->addWidget(rimuovisCButton);
    schermiCHLayout->addWidget(schermiCLineEdit);
    schermiCHLayout->addWidget(aggiungisCButton);
    cinemaHDcheckBox = new QCheckBox("HD incluso",this);

    formCinemaLayout->addRow(titoloCLabel, titoloPCinemaLabel);
    formCinemaLayout->addRow(descCLabel, descPCinemaLabel);
    formCinemaLayout->addRow(costoCLabel, costoPCinemaLabel);
    formCinemaLayout->addRow(schermiCHLayout);
    formCinemaLayout->addRow(cinemaHDcheckBox);

    cinemaGroup->setLayout(formCinemaLayout);

    //************** PEZZO FORM SPORT ********************

    QFormLayout *formSportLayout = new QFormLayout();
    QLabel *titoloSLabel = new QLabel("Titolo:");
    titoloPSportLabel->setText("Offerta Sport");
    QLabel *descSLabel = new QLabel("Descrizione:");
    descPSportLabel->setText("Calcio, MotoGP, Formula 1 e molto altro.");
    QLabel *costoSLabel = new QLabel("Costo in euro:");
    costoPSportLabel->setText("15");

    QHBoxLayout *schermiSHLayout = new QHBoxLayout();
    QLabel *schermiSLabel = new QLabel("Schermi in contemporanea:");
    rimuovisSButton = new QPushButton("-", this);
    rimuovisSButton->setStyleSheet("font-weight: bold;");

    // riquadro del numero di schermi
    schermiSLineEdit = new QLineEdit();
    schermiSLineEdit->setValidator(new QRegExpValidator(QRegExp("[2-4]{1}")));
    schermiSLineEdit->setText("2");
    aggiungisSButton = new QPushButton("+", this);
    aggiungisSButton->setStyleSheet("font-weight: bold;");

    schermiSHLayout->addWidget(schermiSLabel);
    schermiSHLayout->addWidget(rimuovisSButton);
    schermiSHLayout->addWidget(schermiSLineEdit);
    schermiSHLayout->addWidget(aggiungisSButton);
    sportsuperHDcheckBox = new QCheckBox("super HD incluso",this);

    formSportLayout->addRow(titoloSLabel, titoloPSportLabel);
    formSportLayout->addRow(descSLabel, descPSportLabel);
    formSportLayout->addRow(costoSLabel, costoPSportLabel);
    formSportLayout->addRow(schermiSHLayout);
    formSportLayout->addRow(sportsuperHDcheckBox);

    sportGroup->setLayout(formSportLayout);
    aggiungisKButton->setFixedWidth(25);
    rimuovisKButton->setFixedWidth(25);
    aggiungisCButton->setFixedWidth(25);
    rimuovisCButton->setFixedWidth(25);
    aggiungisSButton->setFixedWidth(25);
    rimuovisSButton->setFixedWidth(25);
    schermiKLineEdit->setFixedWidth(30);
    schermiCLineEdit->setFixedWidth(30);
    schermiSLineEdit->setFixedWidth(30);

    mainLayout->addLayout(formLayout);
    verticalDxLayout = new QVBoxLayout();
    mainLayout->addLayout(verticalDxLayout);

    verticalDxLayout->addWidget(kidsGroup);
    verticalDxLayout->addWidget(cinemaGroup);
    verticalDxLayout->addWidget(sportGroup);
    kidsGroup->setAlignment(Qt::AlignCenter);
    cinemaGroup->setAlignment(Qt::AlignCenter);
    sportGroup->setAlignment(Qt::AlignCenter);
    salvaButton = new QPushButton("Salva",this);
    annullaButton = new QPushButton("Annulla",this);
    salvaButton->setFixedWidth(70);
    annullaButton->setFixedWidth(70);

    hdestraBottoni = new QHBoxLayout();
    hdestraBottoni->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    verticalDxLayout->addLayout(hdestraBottoni);
    hdestraBottoni->addWidget(salvaButton);
    hdestraBottoni->addWidget(annullaButton);

    kidsGroup->setVisible(false);
    cinemaGroup->setVisible(false);
    sportGroup->setVisible(false);

    connect(annullaButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(salvaButton, SIGNAL(clicked()), this, SLOT(conferma()));
    connect(pacchettoKidscb,SIGNAL(clicked()), this, SLOT(mostraKids()));
    connect(pacchettoCinemacb,SIGNAL(clicked()), this, SLOT(mostraCinema()));
    connect(pacchettoSportcb,SIGNAL(clicked()), this, SLOT(mostraSport()));
    connect(aggiungisKButton, SIGNAL(clicked()), this, SLOT(buttonKplus()));
    connect(rimuovisKButton, SIGNAL(clicked()), this, SLOT(buttonKmin()));
    connect(aggiungisCButton, SIGNAL(clicked()), this, SLOT(buttonCplus()));
    connect(rimuovisCButton, SIGNAL(clicked()), this, SLOT(buttonCmin()));
    connect(aggiungisSButton, SIGNAL(clicked()), this, SLOT(buttonSplus()));
    connect(rimuovisSButton, SIGNAL(clicked()), this, SLOT(buttonSmin()));
    connect(verificacButton, SIGNAL(clicked()), this, SLOT(verificaCoupon()));
    connect(kidsHDcheckBox,SIGNAL(clicked()), this, SLOT(aggiornaCostoKHD()));
    connect(cinemaHDcheckBox,SIGNAL(clicked()), this, SLOT(aggiornaCostoCHD()));
    connect(sportsuperHDcheckBox,SIGNAL(clicked()), this, SLOT(aggiornaCostoSHD()));
}

void addClientWindow::aggiornaTotale(string s, float d) {
    float t=totaleAbbLabel->text().toFloat();
    if(s=="a") {
        t=t+d;
    }
    else if(s=="r") {
        t=t-d;
    }
    else if(s=="s") {
         float sconto=(t*d)/100;
         t=t-sconto;
    }
    totaleAbbLabel->setText(QString::number(t));
}

void addClientWindow::aggiornaCostoKHD() {
    float k=costoPKidsLabel->text().toFloat();
    if(kidsHDcheckBox->isChecked()==true) {
        k=k+1;
        aggiornaTotale("a", 1);
    }
    else {
        k=k-1;
        aggiornaTotale("r", 1);
    }
    costoPKidsLabel->setText(QString::number(k));
}

void addClientWindow::aggiornaCostoCHD() {
    float c=costoPCinemaLabel->text().toFloat();
    if(cinemaHDcheckBox->isChecked()==true) {
        c=c+3;
        aggiornaTotale("a", 3);
    }
    else {
        c=c-3;
        aggiornaTotale("r", 3);
    }
    costoPCinemaLabel->setText(QString::number(c));
}

void addClientWindow::aggiornaCostoSHD() {
    float s=costoPSportLabel->text().toFloat();
    if(sportsuperHDcheckBox->isChecked()==true) {
        s=s+5;
        aggiornaTotale("a", 5);
    }
    else {
        s=s-5;
        aggiornaTotale("r", 5);
    }
    costoPSportLabel->setText(QString::number(s));
}


void addClientWindow::mostraKids()
{
    if (pacchettoKidscb->isChecked()==true) {
        kidsGroup->setVisible(true);
        aggiornaTotale("a", costoPKidsLabel->text().toFloat());
    }
    else {
        kidsGroup->setVisible(false);
        aggiornaTotale("r", costoPKidsLabel->text().toFloat());
    }
}

void addClientWindow::mostraCinema()
{
    if (pacchettoCinemacb->isChecked()==true) {
        cinemaGroup->setVisible(true);
        aggiornaTotale("a", costoPCinemaLabel->text().toFloat());
    }
    else {
        cinemaGroup->setVisible(false);
        aggiornaTotale("r", costoPCinemaLabel->text().toFloat());
    }
}

void addClientWindow::mostraSport()
{
    if (pacchettoSportcb->isChecked()==true) {
        sportGroup->setVisible(true);
        aggiornaTotale("a", costoPSportLabel->text().toFloat());
    }
    else {
        sportGroup->setVisible(false);
        aggiornaTotale("r", costoPSportLabel->text().toFloat());
    }
}

void addClientWindow::errInputShowBox(string i)
{
    QMessageBox erroreInputBox;
    if (i== "mancaLineEdit")
        erroreInputBox.critical(this,"Input errato","Compilare tutti i campi obbligatori.");
    else if (i =="mancaCheckBox")
        erroreInputBox.critical(this,"Input errato","Nessun pacchetto selezionato. Selezionare almeno uno dei pacchetti.");
    else if (i=="mesiErrati")
        erroreInputBox.critical(this,"Input errato", "Il numero di mesi selezionato non è valido. Inserire un valore maggiore di 0.");
    else if(i=="troppiPacchetti")
        erroreInputBox.critical(this, "Input errato", "Sono stati selezionati 2 pacchetti. Selezionare un pacchetto oppure tutti i pacchetti.");
}

void addClientWindow::successoCliente()
{
    QMessageBox clienteAggiuntoBox;
    clienteAggiuntoBox.information(this,"Registrazione effettuata","Il cliente è stato aggiunto con successo!");
}

void addClientWindow::errDataShowBox(string d)
{
    QMessageBox erroreDataBox;
    if(d=="dataAbb") {
        erroreDataBox.critical(this,"Data inizio abbonamento non corretta", "La data selezionata non è valida. Selezionare una data di inizio abbonamento successiva o uguale a quella attuale");
    }
    else if (d=="dataNascita") {
        erroreDataBox.critical(this, "Data di nascita non corretta", "La data selezionata non è valida. Selezionare una data di nascita con anno inferiore a quello attuale.");
    }
}

void addClientWindow::verificaCoupon() {
    float t=totaleAbbLabel->text().toFloat();
    if ((pacchettoKidscb->isChecked() && pacchettoCinemacb->isChecked()) && !pacchettoSportcb->isChecked()) {
    // kids e cinema selezionato
    emit erroreInput("troppiPacchetti");
        return ;
    }
    else if((pacchettoKidscb->isChecked() && pacchettoSportcb->isChecked()) && !pacchettoCinemacb->isChecked()) {
        emit erroreInput("troppiPacchetti");
        return ;
    }
    else if((pacchettoCinemacb->isChecked() && pacchettoSportcb->isChecked()) && !pacchettoKidscb->isChecked()) {
        emit erroreInput("troppiPacchetti");
        return ;
    }
    if(t>0) {
        if(codicescLineEdit->text()=="UNIPD") {
            emit esitoCoupon("corretto");
            aggiornaTotale("s", 10);
            codiceSconto=true;
            verificacButton->setEnabled(false);
            codicescLineEdit->setEnabled(false);
            pacchettoKidscb->setEnabled(false);
            pacchettoCinemacb->setEnabled(false);
            pacchettoSportcb->setEnabled(false);
            aggiungisKButton->setEnabled(false);
            aggiungisCButton->setEnabled(false);
            aggiungisSButton->setEnabled(false);
            rimuovisKButton->setEnabled(false);
            rimuovisCButton->setEnabled(false);
            rimuovisSButton->setEnabled(false);
            kidsHDcheckBox->setEnabled(false);
            cinemaHDcheckBox->setEnabled(false);
            sportsuperHDcheckBox->setEnabled(false);
            schermiKLineEdit->setEnabled(false);
            schermiCLineEdit->setEnabled(false);
            schermiSLineEdit->setEnabled(false);
        }
        else {
            codicescLineEdit->setText("");
            emit esitoCoupon("errato");
        }
   }
    else {
        codicescLineEdit->setText("");
        emit esitoCoupon("carrellovuoto");
    }
}

void addClientWindow::buttonKplus(){
    int a=schermiKLineEdit->text().toInt();
    int b=4;
    if(a<b) {
        a=a+1;
        float c=costoPKidsLabel->text().toFloat();
        c=c+2;
        aggiornaTotale("a", 2);
        costoPKidsLabel->setText(QString::number(c));
        schermiKLineEdit->setText(QString::number(a));
    }
}

void addClientWindow::buttonKmin() {
    int a=2;
    int b=schermiKLineEdit->text().toInt();
    if(a<b) {
        b=b-1;
        float c=costoPKidsLabel->text().toFloat();
        c=c-2;
        aggiornaTotale("r", 2);
        costoPKidsLabel->setText(QString::number(c));
        schermiKLineEdit->setText(QString::number(b));
    }
}

void addClientWindow::buttonCplus(){
    int a=schermiCLineEdit->text().toInt();
    int b=4;
    if(a<b) {
        a=a+1;
        float c=costoPCinemaLabel->text().toFloat();
        c=c+2;
        aggiornaTotale("a", 2);
        costoPCinemaLabel->setText(QString::number(c));
        schermiCLineEdit->setText(QString::number(a));
    }
}

void addClientWindow::buttonCmin() {
    int a=2;
    int b=schermiCLineEdit->text().toInt();
    if(a<b) {
        b=b-1;
        float c=costoPCinemaLabel->text().toFloat();
        c=c-2;
        aggiornaTotale("r", 2);
        costoPCinemaLabel->setText(QString::number(c));
        schermiCLineEdit->setText(QString::number(b));
    }
}

void addClientWindow::buttonSplus(){
   int a=schermiSLineEdit->text().toInt();
   int b=4;
   if(a<b) {
        a=a+1;
        float c=costoPSportLabel->text().toFloat();
        c=c+4;
        aggiornaTotale("a", 4);
        costoPSportLabel->setText(QString::number(c));
        schermiSLineEdit->setText(QString::number(a));
    }
}

void addClientWindow::buttonSmin() {
   int a=2;
   int b=schermiSLineEdit->text().toInt();
   if(a<b) {
        b=b-1;
        float c=costoPSportLabel->text().toFloat();
        c=c-4;
        aggiornaTotale("r", 4);
        costoPSportLabel->setText(QString::number(c));
        schermiSLineEdit->setText(QString::number(b));
   }
}

void addClientWindow::mostraEsitoC(string e)
{
   QMessageBox esitoCouponBox;
   if(e=="corretto")
       esitoCouponBox.information(this,"Coupon inserito con successo", "Congratulazioni hai ottenuto uno sconto del 10% sul totale. Il totale è stato aggiornato.");
   else if (e=="errato")
       esitoCouponBox.critical(this, "Coupon errato", "Il coupon inserito non è corretto. Riprovare con un altro codice.");
   else if(e=="carrellovuoto")
       esitoCouponBox.critical(this, "Carrello vuoto", "Il carrello è vuoto quindi il coupon non può essere inserito. Aggiungere qualcosa nel carrello e riprovare.");
}


void addClientWindow::showErrorInsMessage(const QString &message)
{
   QDialog* errdialog= new QDialog(this);
   QVBoxLayout* errlayout= new QVBoxLayout(errdialog);
   errlayout->addWidget(new QLabel(message, errdialog));

   errdialog->show();
}

void addClientWindow::resettaInput()
{
   nomeLineEdit->setText("");
   cognomeLineEdit->setText("");
   codFiscLineEdit->setText("");
   dateNascita->setDate(QDate::currentDate());
   emailLineEdit->setText("");
   pacchettoKidscb->setChecked(false);
   costoPKidsLabel->setText("4");
   schermiKLineEdit->setText("2");
   kidsHDcheckBox->setChecked(false);
   pacchettoCinemacb->setChecked(false);
   costoPCinemaLabel->setText("10");
   schermiCLineEdit->setText("2");
   cinemaHDcheckBox->setChecked(false);
   pacchettoSportcb->setChecked(false);
   costoPSportLabel->setText("15");
   sportsuperHDcheckBox->setChecked(false);
   schermiSLineEdit->setText("2");
   dateInAbb->setDate(QDate::currentDate());
   mesiLineEdit->setText("");
   codicescLineEdit->setText("");
   kidsGroup->setVisible(false);
   cinemaGroup->setVisible(false);
   sportGroup->setVisible(false);
   totaleAbbLabel->setText("0");
   verificacButton->setEnabled(true);
   codicescLineEdit->setEnabled(true);
   codiceSconto=false;
   pacchettoKidscb->setEnabled(true);
   pacchettoCinemacb->setEnabled(true);
   pacchettoSportcb->setEnabled(true);
   aggiungisKButton->setEnabled(true);
   aggiungisCButton->setEnabled(true);
   aggiungisSButton->setEnabled(true);
   rimuovisKButton->setEnabled(true);
   rimuovisCButton->setEnabled(true);
   rimuovisSButton->setEnabled(true);
   kidsHDcheckBox->setEnabled(true);
   cinemaHDcheckBox->setEnabled(true);
   sportsuperHDcheckBox->setEnabled(true);
   schermiKLineEdit->setEnabled(true);
   schermiCLineEdit->setEnabled(true);
   schermiSLineEdit->setEnabled(true);
}

void addClientWindow::conferma()
{

    if(((dateInAbb->date().year() < QDate::currentDate().year()) || (dateInAbb->date().year() == QDate::currentDate().year() && dateInAbb->date().month() < QDate::currentDate().month()) || (dateInAbb->date().year() == QDate::currentDate().year() && dateInAbb->date().month() == QDate::currentDate().month() && dateInAbb->date().day() < QDate::currentDate().day()))) {
        emit erroreData("dataAbb");
    }
    else if(dateNascita->date().year() >= QDate::currentDate().year()) {
             emit erroreData("dataNascita");
    }
    else
        if(nomeLineEdit->text()=="" || cognomeLineEdit->text()=="" || codFiscLineEdit->text()=="" || emailLineEdit->text()=="" || mesiLineEdit->text()=="") {
            emit erroreInput("mancaLineEdit");
        }
        else if ((!pacchettoKidscb->isChecked() && !pacchettoCinemacb->isChecked()) && !pacchettoSportcb->isChecked()) {
            emit erroreInput("mancaCheckBox");
        }
        else if ((pacchettoKidscb->isChecked() && pacchettoCinemacb->isChecked()) && !pacchettoSportcb->isChecked()) {
            // kids e cinema selezionato
            emit erroreInput("troppiPacchetti");
        }
        else if((pacchettoKidscb->isChecked() && pacchettoSportcb->isChecked()) && !pacchettoCinemacb->isChecked()) {
                emit erroreInput("troppiPacchetti");
        }
        else if((pacchettoCinemacb->isChecked() && pacchettoSportcb->isChecked()) && !pacchettoKidscb->isChecked()) {
            emit erroreInput("troppiPacchetti");
        }

    else if(mesiLineEdit->text()=="0") {
        emit erroreInput("mesiErrati");
    }

    else {

        QStringList *temp = new QStringList();
        temp->push_back(nomeLineEdit->text());
        temp->push_back(cognomeLineEdit->text());
        temp->push_back(codFiscLineEdit->text());
        temp->push_back(dateNascita->date().toString());
        temp->push_back(emailLineEdit->text());

        temp->push_back(pacchettoKidscb->isChecked()? "true":"false");
        temp->push_back(titoloPKidsLabel->text());
        temp->push_back(descPKidsLabel->text());
        temp->push_back(costoPKidsLabel->text());
        temp->push_back(schermiKLineEdit->text());
        temp->push_back(kidsHDcheckBox->isChecked()? "true":"false");

        temp->push_back(pacchettoCinemacb->isChecked()? "true":"false");
        temp->push_back(titoloPCinemaLabel->text());
        temp->push_back(descPCinemaLabel->text());
        temp->push_back(costoPCinemaLabel->text());
        temp->push_back(schermiCLineEdit->text());
        temp->push_back(cinemaHDcheckBox->isChecked()? "true":"false");

        temp->push_back(pacchettoSportcb->isChecked()? "true":"false");
        temp->push_back(titoloPSportLabel->text());
        temp->push_back(descPSportLabel->text());
        temp->push_back(costoPSportLabel->text());
        temp->push_back(schermiSLineEdit->text());
        temp->push_back(sportsuperHDcheckBox->isChecked()? "true":"false");

        temp->push_back(codiceSconto? "true":"false");
        temp->push_back(codicescLineEdit->text());
        temp->push_back(dateInAbb->date().toString());
        temp->push_back(mesiLineEdit->text());

        temp->push_back(totaleAbbLabel->text());
        emit inviaDatiC(*temp);
        delete temp;
    }
}

#include "modclientwindow.h"

modClientWindow::modClientWindow(QWidget *parent): addClientWindow(parent) {
    setMinimumSize(900, 600);
    setWindowTitle("Modifica cliente selezionato");

    introLabel->setText("Modifica i dati del cliente. I campi con (*) sono obbligatori.\nIl codice fiscale non può essere modificato.");
    personLabel->setText("Non è possibile modificare i pacchetti dell'abbonamento. \nRimuovere il cliente e sottoscrivere un nuovo abbonamento.");
    pacchettoKidscb->setEnabled(false);
    pacchettoCinemacb->setEnabled(false);
    pacchettoSportcb->setEnabled(false);
    avvertLabel->hide();
    scontoLabel->setText("Lo sconto può essere applicato solo in fase di registrazione.");
    codicescLineEdit->setEnabled(false);
    verificacButton->setVisible(false);
    aggiungisKButton->setVisible(false);
    aggiungisCButton->setVisible(false);
    aggiungisSButton->setVisible(false);
    rimuovisKButton->setVisible(false);
    rimuovisCButton->setVisible(false);
    rimuovisSButton->setVisible(false);
    kidsHDcheckBox->setEnabled(false);
    cinemaHDcheckBox->setEnabled(false);
    sportsuperHDcheckBox->setEnabled(false);
    schermiKLineEdit->setEnabled(false);
    schermiCLineEdit->setEnabled(false);
    schermiSLineEdit->setEnabled(false);
}

void modClientWindow::loadDCliente(const QStringList& c, const int i){
    ind = i;
    nomeLineEdit->setText(c.at(0));
    cognomeLineEdit->setText(c.at(1));
    codFiscLineEdit->setText(c.at(2));
    codFiscLineEdit->setEnabled(false);
    dateNascita->setDate(QDate::fromString(c.at(3)));
    emailLineEdit->setText(c.at(4));
    dateInAbb->setDate(QDate::fromString(c.at(5)));
    mesiLineEdit->setText(c.at(6));
    if(c.at(7)=="true") {
        codiceSconto=true;
        codicescLineEdit->setText(c.at(8));
    }
    else {
        codiceSconto=false;
        codicescLineEdit->clear();
    }
    totaleAbbLabel->setText(c.at(9)); //totale , costo aggiornato dei pacchetti

    //ALLINCUSIVE
    if((c.at(10)=="true" && c.at(11)=="true") && c.at(12)=="true") {
        pacchettoKidscb->setChecked(true);
        pacchettoCinemacb->setChecked(true);
        pacchettoSportcb->setChecked(true);
        kidsGroup->setVisible(true);
        cinemaGroup->setVisible(true);
        sportGroup->setVisible(true);

        //kids
        titoloPKidsLabel->setText(c.at(13));
        descPKidsLabel->setText(c.at(14));
        costoPKidsLabel->setText(c.at(15));
        schermiKLineEdit->setText(c.at(16));
        if(c.at(17)=="true"? true:false) {
            kidsHDcheckBox->setChecked(true);
        }
        else {
            kidsHDcheckBox->setChecked(false);
        }
        //cinema
        titoloPCinemaLabel->setText(c.at(18));
        descPCinemaLabel->setText(c.at(19));
        costoPCinemaLabel->setText(c.at(20));
        schermiCLineEdit->setText(c.at(21));
        if(c.at(22)=="true"? true:false) {
            cinemaHDcheckBox->setChecked(true);
        }
        else {
            cinemaHDcheckBox->setChecked(false);
        }
        //SPORT
        titoloPSportLabel->setText(c.at(23));
        descPSportLabel->setText(c.at(24));
        costoPSportLabel->setText(c.at(25));
        schermiSLineEdit->setText(c.at(26));
        if(c.at(27)=="true"? true:false) {
            sportsuperHDcheckBox->setChecked(true);
        }
        else {
            sportsuperHDcheckBox->setChecked(false);
        }
    }

    //KIDS
    if((c.at(10)=="true" && c.at(11)=="false") && c.at(12)=="false") {
        pacchettoKidscb->setChecked(true);
        pacchettoCinemacb->setChecked(false);
        pacchettoSportcb->setChecked(false);
        kidsGroup->setVisible(true);
        cinemaGroup->setVisible(false);
        sportGroup->setVisible(false);

        titoloPKidsLabel->setText(c.at(13));
        descPKidsLabel->setText(c.at(14));
        costoPKidsLabel->setText(c.at(15));
        schermiKLineEdit->setText(c.at(16));
        if(c.at(17)=="true"? true:false) {
            kidsHDcheckBox->setChecked(true);
        }
        else {
            kidsHDcheckBox->setChecked(false);
        }
    }

    //CINEMA
    if((c.at(10)=="false" && c.at(11)=="true") && c.at(12)=="false") {
        pacchettoKidscb->setChecked(false);
        pacchettoCinemacb->setChecked(true);
        pacchettoSportcb->setChecked(false);
        kidsGroup->setVisible(false);
        cinemaGroup->setVisible(true);
        sportGroup->setVisible(false);

        titoloPCinemaLabel->setText(c.at(13));
        descPCinemaLabel->setText(c.at(14));
        costoPCinemaLabel->setText(c.at(15));
        schermiCLineEdit->setText(c.at(16));
        if(c.at(17)=="true"? true:false) {
            cinemaHDcheckBox->setChecked(true);
        }
        else {
            cinemaHDcheckBox->setChecked(false);
        }
    }

    //SPORT
    if((c.at(10)=="false" && c.at(11)=="false") && c.at(12)=="true") {
        pacchettoKidscb->setChecked(false);
        pacchettoCinemacb->setChecked(false);
        pacchettoSportcb->setChecked(true);
        kidsGroup->setVisible(false);
        cinemaGroup->setVisible(false);
        sportGroup->setVisible(true);

        titoloPSportLabel->setText(c.at(13));
        descPSportLabel->setText(c.at(14));
        costoPSportLabel->setText(c.at(15));
        schermiSLineEdit->setText(c.at(16));
        if(c.at(17)=="true"? true:false) {
            sportsuperHDcheckBox->setChecked(true);
        }
        else {
            sportsuperHDcheckBox->setChecked(false);
        }
    }
}

void modClientWindow::clienteModificato()
{
    QMessageBox clienteModificatoBox;
    clienteModificatoBox.information(this,"Modifica effettuata","Il cliente è stato modificato con successo!");
}

void modClientWindow::conferma(){
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

    else if(mesiLineEdit->text()=="0") {
      emit erroreInput("mesiErrati");
    }

    else
    {
        QStringList *temp = new QStringList();
        temp->push_back(nomeLineEdit->text()); // 0
        temp->push_back(cognomeLineEdit->text()); // 1
        temp->push_back(codFiscLineEdit->text()); // 2
        temp->push_back(dateNascita->date().toString()); // 3
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

        temp->push_back(totaleAbbLabel->text()); //totale , costo aggiornato dei pacchetti
        emit substCliente(ind, *temp);
        delete temp;
    }
}

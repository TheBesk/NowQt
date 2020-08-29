#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include "viewlistac.h"
#include "nowqt.h"
#include "kids.h"
#include "cinema.h"
#include "sport.h"
#include "allinclusive.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QDate>
#include <QPushButton>
#include <QStringList>
#include <QMessageBox>

using std::string;

class addClientWindow : public QDialog
{
    Q_OBJECT
public:
    addClientWindow(QWidget *parent =nullptr);
    void mostraErroreInput(string);
    void successoCliente();
    void mostraErroreData(string);
    void mostraEsitoC(string);
    void showErrorMessage(const QString& message);a
    bool codiceSconto;

public slots:
    virtual void conferma();
    void mostraKids();
    void mostraCinema();
    void mostraSport();
    void resettaInput(); // resetta
    void buttonKplus();
    void buttonKmin();
    void buttonCplus();
    void buttonCmin();
    void buttonSplus();
    void buttonSmin();
    void verificaCoupon();
    void aggiornaTotale(string, double);
    void aggiornaCostoKHD();
    void aggiornaCostoCHD();
    void aggiornaCostoSHD();

signals:
    void esitoCoupon(string);
    void erroreData(string);
    void erroreInput(string);
    void inviaStringaCliente(const QStringList);
    
protected:
    QVBoxLayout* verticalDxLayout;
    QHBoxLayout* mainLayout, *hdestraBottoni, *schermiKHLayout, *schermiCHLayout, *schermiSHLayout, *scontoHLayout;
    QCheckBox *pacchettoKidscb, *pacchettoCinemacb, *pacchettoSportcb, *kidsHDcheckBox, *cinemaHDcheckBox, *sportsuperHDcheckBox;
    QLineEdit *nomeLineEdit, *cognomeLineEdit, *codFiscLineEdit, *emailLineEdit, *mesiLineEdit, *codicescLineEdit, *schermiKLineEdit, *schermiCLineEdit, *schermiSLineEdit;
    QLabel *totaleAbbLabel, *titoloPKidsLabel, *descPKidsLabel, *costoPKidsLabel, *titoloPCinemaLabel, *descPCinemaLabel, *costoPCinemaLabel, *titoloPSportLabel, *descPSportLabel, *costoPSportLabel;
    QDateEdit *dateInAbb, *dateNascita;
    QPushButton* salvaButton, *annullaButton, *aggiungisKButton, *rimuovisKButton, *aggiungisCButton, *rimuovisCButton, *aggiungisSButton, *rimuovisSButton, *verificacButton;
    QGroupBox *kidsGroup, *cinemaGroup, *sportGroup;
};

#endif // ADDCLIENTWINDOW_H

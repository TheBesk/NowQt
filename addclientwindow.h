#ifndef ADDCLIENTWINDOW_H
#define ADDCLIENTWINDOW_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QGroupBox>
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
    virtual void mostraErroreInput(string);
    virtual void mostraErroreData(string);
    void mostraEsitoC(string);
    void successoCliente();
    void showErrorInsMessage(const QString& message);
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
    virtual void erroreInput(string);
    void esitoCoupon(string);
    virtual void erroreData(string);
    void inviaStringaCliente(const QStringList);

protected:
    QVBoxLayout* verticalDxLayout;
    QHBoxLayout* mainLayout, *hdestraBottoni, *schermiKHLayout, *schermiCHLayout, *schermiSHLayout, *scontoHLayout;
    QLabel *introLabel, *personLabel, *avvertLabel, *scontoLabel;
    QLineEdit *nomeLineEdit, *cognomeLineEdit, *codFiscLineEdit, *emailLineEdit, *mesiLineEdit, *codicescLineEdit, *schermiKLineEdit, *schermiCLineEdit, *schermiSLineEdit;
    QLabel *totaleAbbLabel, *titoloPKidsLabel, *descPKidsLabel, *costoPKidsLabel, *titoloPCinemaLabel, *descPCinemaLabel, *costoPCinemaLabel, *titoloPSportLabel, *descPSportLabel, *costoPSportLabel;
    QCheckBox *pacchettoKidscb, *pacchettoCinemacb, *pacchettoSportcb, *kidsHDcheckBox, *cinemaHDcheckBox, *sportsuperHDcheckBox;
    QDateEdit *dateInAbb, *dateNascita;
    QGroupBox *kidsGroup, *cinemaGroup, *sportGroup;
    QPushButton* salvaButton, *annullaButton, *aggiungisKButton, *rimuovisKButton, *aggiungisCButton, *rimuovisCButton, *aggiungisSButton, *rimuovisSButton, *verificacButton;

};

#endif // ADDCLIENTWINDOW_H

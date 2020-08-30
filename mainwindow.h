#ifndef GUI_H
#define GUI_H
#include <QWidget>

#include"viewlistac.h"
#include "nowqt.h"
#include "kids.h"
#include "cinema.h"
#include "sport.h"
#include "allinclusive.h"
#include "container.h"
#include"deeppointer.h"

#include <QMenuBar>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    bool isSelected() const;
    unsigned int getIndexSelected() const;
    void mostraClienti(const QStringList);
    //    void mostraClienti(const QStringList);
    // QString getParolaCercata() const;
    void nessunSelezionato();
      // void visualizzaDettagliCliente(deepPointer<cliente>) const;
      // void resetDettCliente() const;


public slots:
   // void richiesta(string);
    void showInfoCliente();
    void richRimuoviC();
private:

    QComboBox * tipoP;
    QVBoxLayout *mainLayout, *verticalDxLayout, *verticalSxLayout, *vPulsanti;
    QHBoxLayout *divH, *layoutRicerca;
    QLineEdit* lineCerca;
    QPushButton* addButton,*modButton,*removeButton, *dettButton;

  viewListaC *listaClienti;
  QPixmap *pix;
  QLabel *filtroLabel, *image; //*cognomeClienteLabel,*codiceFClienteLabel,* LuogoDNLabel,*residenzaClienteLabel,*viaClienteLabel, *telefonoClienteLabel, *mailClienteLabel, *datadNClienteLabel,*studenteClienteLabel,*AbbonamentoPiscinaLabel, *nomeIstruttorePiscinaLabel,*corsoNuotoClienteLabel, *AbbonamentoPalestraLabel,*nomeIstruttorePalestraLabel,*schedaPalestraClienteLabel;
    QGroupBox* clientiGroup; //piscinaGroup,* palestraGroup, *filtriGroup;
   // void setMainWindowStyle();
 //   void closeEvent(QCloseEvent*) override;

signals:
    void signOpenAddWindow();
    void signOpenDettWindow(const int);
    void rimuoviCliente(const int);
    void elementFilter(const QString&); //oppure const string?
    /*void infoWindow();
    void signOpenModWindow();
    void cercaRuntime();
    void salvaFileMenu();
    void richiestaRimozCliente(const unsigned int);
    void richiestaShowCliente(const unsigned int);

    void controllaModificato();
    void filtroKids();
    void filtroCinema();
    void filtroSport();
    void filtroAllInclusive(); */
};

#endif // GUI_H

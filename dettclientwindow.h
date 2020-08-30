#ifndef DETTCLIENTWINDOW_H
#define DETTCLIENTWINDOW_H


#include <QDialog>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QLabel>
#include<QFormLayout>
#include<QPushButton>
#include<QFile>
#include <QString>
#include<QMessageBox>
#include"viewlistac.h"
#include"nowqt.h"
#include"kids.h"
#include"cinema.h"
#include"sport.h"
#include "mainwindow.h"
#include "allinclusive.h"
#include "deeppointer.h"
using std::string;

class dettClientWindow : public QDialog
{
    Q_OBJECT

public:
    dettClientWindow(QWidget *parent =nullptr);
    void visualizzaDettagliCliente(deepPointer<nowqt>) const;

protected:
    QHBoxLayout* mainLayout, *titHLayout, *divH, *cHButton;
    QVBoxLayout *pacchVLayout, *divV;
    QPushButton *closeButton;
    QGroupBox* daticlienteGroup, *statoabbGroup, *pacchetto1Group, *pacchetto2Group, *pacchetto3Group;
    QLabel *nomeClienteLabel, *cognomeClienteLabel, *codiceFiscClienteLabel, *dataNascitaClienteLabel, *emailClienteLabel, *pacchClienteLabel, *tPacch1, *offertaKidsCLabel, *descKidsLabel, *schermiContKLabel, *hdKidsLabel, *tPacch2, *offertaCinemaCLabel, *descCinemaLabel, *schermiContCLabel, *hdCinemaLabel, *tPacch3, *offertaSportCLabel, *descSportLabel, *schermiContSLabel, *hdSportLabel, *dataInizioALabel, *mesiAbbLabel, *dataFineALabel, *BcodiceScontoLabel, *tcouponLabel, *TcodiceScontoLabel, *totMeseAbbLabel, *totMesiAbbLabel;

};

#endif // DETTCLIENTWINDOW_H

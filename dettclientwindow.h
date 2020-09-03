#ifndef DETTCLIENTWINDOW_H
#define DETTCLIENTWINDOW_H

#include <QDialog>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QLabel>
#include<QFormLayout>
#include<QPushButton>
#include <QString>

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
    void mostraDettCliente(deepPointer<nowqt>) const;

protected:
    QHBoxLayout *mainLayout, *titHLayout, *cHButton;
    QVBoxLayout *pacchVLayout, *divV;
    QPushButton *closeButton;
    QGroupBox *daticlienteGroup, *statoabbGroup, *pacchetto1Group, *pacchetto2Group, *pacchetto3Group;
    QLabel *nomeClienteLabel, *cognomeClienteLabel, *codiceFiscClienteLabel, *dataNascitaClienteLabel, *emailClienteLabel, *pacchLabel, *pacchClienteLabel, *descKidsLabel, *schermiContKLabel, *hdKidsLabel, *descCinemaLabel, *schermiContCLabel, *hdCinemaLabel, *descSportLabel, *schermiContSLabel, *hdSportLabel, *dataInizioALabel, *mesiAbbLabel, *dataFineALabel, *BcodiceScontoLabel, *tcouponLabel, *TcodiceScontoLabel, *totMeseAbbLabel, *totMesiAbbLabel;

};

#endif // DETTCLIENTWINDOW_H

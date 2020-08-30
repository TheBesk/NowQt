#ifndef GUI_H
#define GUI_H

#include "viewlistac.h"
#include "nowqt.h"
#include "kids.h"
#include "cinema.h"
#include "sport.h"
#include "allinclusive.h"
#include "container.h"
#include"deeppointer.h"

#include <QWidget>
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
#include <QIcon>

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    bool isSelected() const;
    int getIndexSelected() const;
    void mostraClienti(const QStringList);
    void nessunSelezionato();
public slots:
    void richRimuoviC();
    void showInfoCliente();

private:
    QComboBox * tipoP;
    QVBoxLayout *mainLayout, *verticalDxLayout, *verticalSxLayout, *vPulsanti;
    QHBoxLayout *divH, *layoutRicerca;
    QLineEdit* lineCerca;
    QPushButton* addButton,*modButton,*removeButton, *dettButton;
    viewListaC *listaClienti;
    QLabel *filtroLabel, *image;
    QGroupBox* clientiGroup; // *filtriGroup;
    // void setMainWindowStyle();
    // void closeEvent(QCloseEvent*) override;

signals:
    void signOpenAddWindow();
    void signOpenDettWindow(const int);
    void signOpenModWindow();
    void rimuoviCliente(const int);
    void elementFilter(const QString&); //oppure const string?
    /*
    void filtroKids();
    void filtroCinema();
    void filtroSport();
    void filtroAllInclusive(); */
};

#endif // GUI_H

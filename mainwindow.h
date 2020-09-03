#ifndef GUI_H
#define GUI_H

#include "viewlistac.h"
#include"model.h"

#include <QWidget>
#include <QMenuBar>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QIcon>
#include <QString>

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    bool isSelezionato() const;
    int getIndiceSel() const;
    void showLClienti(const QStringList);
    void noSelected();

public slots:
    void richRimuoviC();
    void visualizzaCliente();

private:
    QComboBox *tipoP;
    QVBoxLayout *mainLayout, *verticalDxLayout, *verticalSxLayout, *vPulsanti;
    QHBoxLayout *divH;
    QPushButton *addButton, *modButton, *removeButton, *dettButton;
    viewListaC *listaClienti;
    QLabel *image;
    QGroupBox* clientiGroup;

signals:
    void segnApriAgg();
    void signOpenDettWindow(const int);
    void segnApriMod();
    void rimuoviCliente(const int);
};

#endif // GUI_H

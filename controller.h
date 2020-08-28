#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMessageBox>
#include <iostream>
#include<fstream>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include "mainwindow.h"
#include "addclientwindow.h"
#include "dettclientwindow.h"
#include "model.h"
#include "container.h"
#include "deeppointer.h"
#include <stdexcept>

using std::ofstream;
using std::endl;

class controller : public QObject
{
    Q_OBJECT

public:
    explicit controller(QObject *parent = nullptr);
    ~controller();
public slots:
    void openAddView() const;
    void errInput(string);
    void errData(string);
    void esitoCoup(string);
    void aggClienteContainer(const QStringList);
    void openDettView(const int) const;
    void resetListaClienti();
    void removeC(const int);
    void clienteRimShowBox();

private:
    mainwindow* view;
    addClientWindow *addClientW;
    dettClientWindow *dettClientW;
    model* m;
    QMap<int, int> indexTranslate;
};

#endif // CONTROLLER_H

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMessageBox>
#include "mainwindow.h"
#include "addclientwindow.h"
#include "dettclientwindow.h"
#include "modclientwindow.h"
#include "model.h"
#include <stdexcept>

class controller : public QObject
{
    Q_OBJECT

public:
    explicit controller(QObject *parent = nullptr);
    ~controller();

public slots:
    void apriFinAgg()const;
    void errInput(string);
    void errData(string);
    void esitoCoup(string);
    void addInCont(const QStringList);
    void openDettView(const int)const;
    void apriFinMod() const;
    void resetListaClienti();
    void removeC(const int);
    void clienteRimShowBox();
    void modClienteSel(const int, const QStringList);

private:
    mainwindow* view;
    addClientWindow *addClientW;
    dettClientWindow *dettClientW;
    modClientWindow *modClientW;
    model* m;
    QMap<int, int> indexTranslate;
};

#endif // CONTROLLER_H

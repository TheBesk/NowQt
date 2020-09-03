#ifndef MODCLIENTWINDOW_H
#define MODCLIENTWINDOW_H

#include "addclientwindow.h"

class modClientWindow : public addClientWindow
{
    Q_OBJECT
private:
    int ind;

public:
    explicit modClientWindow(QWidget *parent = nullptr);
    void loadDCliente(const QStringList &,const int);
    void clienteModificato();

public slots:
    void conferma() override;

signals:
    void substCliente(const int, const QStringList);

};

#endif // MODCLIENTWINDOW_H




#ifndef MODEL_H
#define MODEL_H

#include "container.h"
#include "deeppointer.h"
#include "nowqt.h"
#include "kids.h"
#include "cinema.h"
#include "sport.h"
#include "allinclusive.h"

#include <QString>
#include <QMap>
#include <QFile>
#include <stdexcept>

class model : public QObject
{

    Q_OBJECT

public:
    model();
    ~model();
    deepPointer<nowqt> mostraCliente(const int) const;
    QStringList getListaClientiT(QMap<int, int> &) const;
    void removeC(const int);
    QStringList getCampiCliente(const int) const;
    bool controlloC(const QString) const;
    float applicaScontoAI(float, unsigned int);

public slots:
    void addClientContainer(const QStringList);
    void modificaCliente(const int, const QStringList);

signals:
    void clienteAggiunto();
    void clienteRimosso();
    void clienteModificato();

private:
    container<deepPointer<nowqt>> *listaTClienti;
};

#endif

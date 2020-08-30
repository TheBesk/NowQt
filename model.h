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
#include <QFile>
#include <QMap>
#include <stdexcept>

class model : public QObject
{

    Q_OBJECT

public:
    model(QString path);
    ~model();
    deepPointer<nowqt> mostraCliente(const int) const;
    QStringList getListaClientiT(QMap<int, int> &) const;
    void removeC(const int);
    bool getModificato() const;
    QStringList getCampiCliente(const int) const;
    bool controlloCliente(const QString) const;
    double applicaScontoAI(double, unsigned int);
    QStringList getListaClientiF(QMap< int, int> &) const;
    void actualFilter(const std::string);

public slots:
    void aggNelContainer(const QStringList);
    void modificaItem(const int,const QStringList);

signals:
    void clienteAggiunto();
    void clienteRimosso();
    void clienteModificato();

private:
    QString path;
    container<deepPointer<nowqt>> *datiTotali;
    container<deepPointer<nowqt>> *datiParziali;
    bool modificato;

};

#endif

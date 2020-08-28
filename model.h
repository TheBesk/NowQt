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
    QStringList getCampiCliente(const unsigned int) const;
    deepPointer<nowqt> mostraCliente(const unsigned int) const;
    QStringList getListaClientiT(QMap< int, int> &) const;
    bool getModificato() const;
//    QStringList getListaClientiPDF() const;
    bool controlloCliente(const QString) const;

public slots:
    void aggNelContainer(const QStringList);
    void removeC(const int);
    
signals:
    void clienteAggiunto();
    void clienteRimosso();
    
private:
    QString path;
    container<deepPointer<nowqt>> *datiTotali;
    bool modificato;

};

#endif

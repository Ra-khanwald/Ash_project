#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class FACTURE
{
public:
    int NUMFA,TELEPHONE;
    float MONTANT,TOTAL;
    QString DATE_FACTURE,TYPE_FACTURE,TVA,DESCREPTION,EMAIL,TRANSPORT;
public:
    FACTURE();
    FACTURE(int,QString,QString,QString,QString,QString,float,int,QString,float);
    bool ajouterFA();
    QSqlQueryModel * afficherFA();
    bool modifierFA(int,QString,QString,QString,QString,QString,float,int,QString,float);
    QSqlQueryModel * afficheroncomboFA();
    bool  rechercher(int id );
    QSqlQueryModel * trides();
       QSqlQueryModel * triasc();
     bool supprimerFA(int);
    void genererPDF();
      QString showold(QString);
};

#endif // FACTURE_H

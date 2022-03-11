#include "facture.h"
#include<QSqlRecord>
#include<QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>



FACTURE::FACTURE(){}
FACTURE::FACTURE(int NUMFA,QString DATE_FACTURE ,QString TYPE_FACTURE,QString TVA ,QString DESCREPTION ,QString EMAIL ,float MONTANT ,int TELEPHONE,QString TRANSPORT ,float TOTAL)
{
    this->NUMFA=NUMFA;
    this->DATE_FACTURE=DATE_FACTURE;
    this->TYPE_FACTURE=TYPE_FACTURE;
    this->TVA=TVA;
    this->DESCREPTION=DESCREPTION;
    this->EMAIL=EMAIL;
    this->MONTANT=MONTANT;
    this->TELEPHONE=TELEPHONE;
    this->TRANSPORT=TRANSPORT;
    this->TOTAL=TOTAL;
}

bool FACTURE::ajouterFA()
{
QSqlQuery query;
    //QString id= QString::number(ID);
    query.prepare("INSERT INTO FACTURE (NUMFA,DATE_FACTURE,TYPE_FACTURE,TVA,DESCREPTION,EMAIL,MONTANT,TELEPHONE,TRANSPORT ,TOTAL) "
                        "VALUES (:NUMFA, :DATE_FACTURE, :TYPE_FACTURE, :TVA, :DESCREPTION, :EMAIL, :MONTANT, :TELEPHONE, :TRANSPORT, :TOTAL)");
    query.bindValue(":NUMFA",NUMFA);
    query.bindValue(":DATE_FACTURE",DATE_FACTURE);
    query.bindValue(":TYPE_FACTURE",TYPE_FACTURE);
    query.bindValue(":TVA",TVA);
    query.bindValue(":DESCREPTION",DESCREPTION);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":MONTANT",MONTANT);
    query.bindValue(":TELEPHONE",TELEPHONE);
    query.bindValue(":TRANSPORT",TRANSPORT);
    query.bindValue(":TOTAL",TOTAL);
return    query.exec();
}
QSqlQueryModel * FACTURE ::afficherFA()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURE ");

        return model;
}

QSqlQueryModel * FACTURE::afficheroncomboFA() //combo TVA
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select TELF  from fournisseur");
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID"));

        return model;
}

bool FACTURE::modifierFA(int NUMFA, QString DATE_FACTURE , QString TYPE_FACTURE , QString TVA ,QString DESCREPTION ,QString EMAIL ,float  MONTANT, int TELEPHONE , QString TRANSPORT , float TOTAL )

{
     QSqlQuery query;

    query.prepare("UPDATE FACTURE SET  DATE_FACTURE= :DATE_FACTURE, TYPE_FACTURE = :TYPE_FACTURE  , TVA = :TVA  , DESCREPTION= :DESCREPTION,EMAIL= :EMAIL,MONTANT= :MONTANT, TELEPHONE= :TELEPHONE,TRANSPORT= :TRANSPORT,TOTAL= :TOTAL where NUMFA= :NUMFA ");
    query.bindValue(":NUMFA", NUMFA);
    query.bindValue(":DATE_FACTURE", DATE_FACTURE);
    query.bindValue(":TYPE_FACTURE",TYPE_FACTURE);
    query.bindValue(":TVA", TVA);
    query.bindValue(":DESCREPTION", DESCREPTION);
    query.bindValue(":EMAIL",EMAIL);
    query.bindValue(":MONTANT", MONTANT);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":TRANSPORT",TRANSPORT);
    query.bindValue(":TOTAL",TOTAL);
            return    query.exec();

}

bool FACTURE::supprimerFA(int IDD)
{
    QString ident3= QString ::number(IDD);
    QSqlQuery query;
    query.prepare("Delete from FACTURE where NUMFA = :NUMFA");
    query.bindValue(":NUMFA",ident3);
    return    query.exec();

}

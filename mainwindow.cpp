#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextBrowser>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_fournis->setModel(fo.afficher());
    ui->comboBox->setModel(fo.afficheroncombo());
    ui->tableView_facture->setModel(Fa.afficherFA());
    ui->comboBoxP_3->setModel(Pa.afficheroncomboP());
    ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());
    ui->tableView_Pai->setModel(Pa.afficherP());
    ui->comboBoxPrecherche->setModel(Pa.afficheroncomboPT());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajF_clicked()
{
    Fournisseur f(ui->lineEdit_numF->text().toInt(),ui->lineEdit_nomF->text(),ui->lineEdit_prenF->text(),ui->lineEdit_addF->text(),ui->lineEdit_telF->text().toInt(),ui->comboBox_typeF->currentText());
       bool test= f.ajouter();




       if (test)
       {ui->tableView_fournis->setModel(fo.afficher());//actualisation taa afficher
  ui->comboBox->setModel(fo.afficheroncombo());
           //notifyIcon->showMessage("GESTION DES  EMPLYOES ","Liste employe pret dans PDF",QSystemTrayIcon::Information,15000);
                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView_fournis->setModel(fo.afficher());
}



void MainWindow::on_pushButton_numF_clicked()
{
    bool test=fo.supprimer(ui->comboBox->currentText().toInt());
    if(test)
    {ui->tableView_fournis->setModel(fo.afficher());
         ui->comboBox->setModel(fo.afficheroncombo());//actualisation taa afficher
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    int a;
        a=index;
    ui->comboBox->currentText();
}

void MainWindow::on_pushButton_mdF_clicked()
{
    bool    test=fo.modifier(ui->lineEdit_numF->text().toInt(),ui->lineEdit_nomF->text(),ui->lineEdit_prenF->text(),ui->lineEdit_addF->text(),ui->lineEdit_telF->text().toInt(),ui->comboBox_typeF->currentText()) ;
          if (test)
          {
                ui->tableView_fournis->setModel(fo.afficher());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_ajF_2_clicked()
{
    Paiement  Pay(ui->comboBoxP_3->currentText().toInt(),ui->lineEditfa->text().toInt(),ui->lineEdit_PFA_2->text().toInt(),ui->dateEditP->text(),ui->lineEdit_numP_3->text().toInt());
       bool test= Pay.ajouterP();

     if (test)
       {ui->tableView_Pai->setModel(Pa.afficherP());//actualisation taa afficher
  ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());

                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView_Pai->setModel(Pa.afficherP());

}

void MainWindow::on_comboBoxP_3_currentIndexChanged(int index)
{

    int a;
        a=index;
    ui->comboBoxP_3->currentText();
}

void MainWindow::on_pushButton_mdF_2_clicked()
{
    bool    test=Pa.modifierP(ui->comboBoxP_3->currentText().toInt(),ui->lineEditfa->text().toInt(),ui->lineEdit_PFA_2->text().toInt(),ui->dateEditP->text(),ui->lineEdit_numP_3->text().toInt()) ;
          if (test)
          {
                ui->tableView_Pai->setModel(Pa.afficherP());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}


void MainWindow::on_pushButton_numF_2_clicked()
{
    bool test=Pa.supprimerP(ui->comboBoxPP_2->currentText().toInt());
    if(test)
    {ui->tableView_Pai->setModel(Pa.afficherP());
         ui->comboBoxPP_2->setModel(Pa.afficheroncomboPT());//actualisation  affichage
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);
}









void MainWindow::on_comboBox_2_currentIndexChanged(int index2)
{
    int b;
        b=index2;
    ui->comboBoxPP_2->currentText();
}


void MainWindow::on_pushButton_ajFA_clicked()
{
float Total;
int T_Transport=0;
QString TYPE;
if(ui->radioButtonA->isChecked())
{
    Fa.TYPE_FACTURE="Actif";
}
else  if(ui->radioButtonP->isChecked())
{
    Fa.TYPE_FACTURE="Pasif";
}
else
{
    QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                            QObject::tr("click cancel to exist"),
                            QMessageBox::Cancel);

}
QString TRANSPORT;

if(ui->radioButtonV->isChecked())
{
    TRANSPORT="VAN";
    T_Transport=40;
}
if(ui->radioButtonP->isChecked())
{
    TRANSPORT="PLANE";
    T_Transport=500;

}
if(ui->radioButtonT->isChecked())
{
    TRANSPORT="Truck";
     T_Transport=100;
}

    else{
    QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                            QObject::tr("click cancel to exist"),
                            QMessageBox::Cancel);

}

int NUMFF=ui->lineEdit_numFA->text().toInt();
QString DATEE=ui->dateFAEdit->text();
QString TVAA=ui->comboBox_TVA->currentText();
QString TEXTE=ui->textBrowserA->text();
QString EMAILL=ui->lineEdit_Email->text();
float MONTANTT=ui->lineEdit_Montant->text().toFloat();
int TELL=ui->lineEdit_telFone->text().toInt();

 //FACTURE  Fa(NUMFF,DATEE,TYPE,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,5);
    FACTURE  Fa(5,"25/58/8952","TYPE","vvvv","TEXTE","EMAILL",58.2,96,"TRANSPORT",5.2);

    bool test= Fa.ajouterFA();




       if (test)
       {ui->tableView_facture->setModel(Fa.afficherFA());//actualisation  afficher


                   QMessageBox::information(nullptr,QObject::tr("ok"),
                                            QObject::tr("ajout succful .\n"),
                           QMessageBox::Cancel);
               }

               else
                   QMessageBox::critical(nullptr,QObject::tr("ajout not open"),
                                           QObject::tr("click cancel to exist"),
                                           QMessageBox::Cancel);



        ui->tableView_facture->setModel(Fa.afficherFA());




}




void MainWindow::on_pushButton_mdFA_clicked()
{

    float Total;
    int T_Transport=0;
    QString TYPE;
    if(ui->radioButtonA->isChecked())
    {
        TYPE="Actif";
    }
    else  if(ui->radioButtonP->isChecked())
    {
        TYPE="Pasif";
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                                QObject::tr("click cancel to exist"),
                                QMessageBox::Cancel);

    }
    QString TRANSPORT;

    if(ui->radioButtonV->isChecked())
    {
        TRANSPORT="VAN";
        T_Transport=40;

    }
    else if(ui->radioButtonP->isChecked())
    {
        TRANSPORT="PLANE";
        T_Transport=500;

    }
    else if(ui->radioButtonT->isChecked())
    {
        TRANSPORT="TRUCK";
          T_Transport=100;
    }

        else{
        QMessageBox::critical(nullptr,QObject::tr("champ vide !"),
                                QObject::tr("click cancel to exist"),
                                QMessageBox::Cancel);

    }

    int NUMFF=ui->lineEdit_numFA->text().toInt();
    QString DATEE=ui->dateFAEdit->text();
    QString TVAA=ui->comboBox_TVA->currentText();
    QString TEXTE=ui->textBrowserA->text();
    QString EMAILL=ui->lineEdit_Email->text();
    float MONTANTT=ui->lineEdit_Montant->text().toFloat();
    int TELL=ui->lineEdit_telFone->text().toInt();
    Total=MONTANTT+T_Transport;
    bool    test=Fa.modifierFA(NUMFF,DATEE,TYPE,TVAA,TEXTE,EMAILL,MONTANTT,TELL,TRANSPORT,Total) ;
          if (test)
          {
                ui->tableView_facture->setModel(Fa.afficherFA());
              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}

}

void MainWindow::on_pushButton_supp_clicked()
{
    bool test=Fa.supprimerFA(ui->lineEdit_numFA->text().toInt());
    if(test)
    {ui->tableView_facture->setModel(Fa.afficherFA());
         //ui->comboBoxPP_2->setModel(Fa.afficheroncomboPT());//actualisation  affichage
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression succful .\n"),
                    QMessageBox::Cancel);
        }

        else
            QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                                    QObject::tr("click cancel to exist"),
                                    QMessageBox::Cancel);

}

void MainWindow::on_pushButton_recherche_clicked()
{

  QString Nom;
  Nom=ui->lineEdit_recherche->text();
 ui->tableView_fournis->setModel(fo.recherche(Nom));
}

void MainWindow::on_comboBoxPrecherche_currentIndexChanged(int index3)
{
    int b;
        b=index3;
    ui->comboBoxPrecherche->currentText();
}

void MainWindow::on_pushButton_recherche_ID_clicked()
{
    int ID;
    ID=ui->comboBoxPrecherche->currentText().toInt();
   ui->tableView_Pai->setModel(Pa.rechercherP(ID));
}

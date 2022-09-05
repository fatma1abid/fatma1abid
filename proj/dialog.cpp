#include "dialog.h"
#include "ui_dialog.h"
#include "client_dialog.h"
#include <QVector>
#include <QDebug>

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmp.afficher());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_ajouter_E_clicked()
{
    client_dialog c;
        int code = ui->lineEdit_code->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        int telephone= ui->lineEdit_telephone->text().toInt();

       client_dialog C (code,nom,prenom,telephone);
      bool test=C.ajouter();

      if(test)
    {
          ui->tableView->setModel(tmp.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","client ajouté");
               ui->lineEdit_code->setText("");
               ui->lineEdit_nom->setText("");
               ui->lineEdit_prenom->setText("");
               ui->lineEdit_telephone->setText("");
  }

  else

  {
  QMessageBox msgBox ;
    msgBox.setText("client non ajouté ");

  }
}

void Dialog::on_pushButton_modifier_E_clicked()
{
    int code = ui->lineEdit_code->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int telephone= ui->lineEdit_telephone->text().toInt();


          bool test=tmp.modifier(code,nom,prenom,telephone);

             if (test)
             {
                  ui->tableView->setModel(tmp.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","client bien Modifié");
           ui->lineEdit_code->setText("");
           ui->lineEdit_nom->setText("");
           ui->lineEdit_prenom->setText("");
           ui->lineEdit_telephone->setText("");

                }
}

void Dialog::on_pushButton_rafraichir_E_clicked()
{
    ui->lineEdit_code->setText("");
    ui->lineEdit_nom->setText("");
    ui->lineEdit_prenom->setText("");
    ui->lineEdit_telephone->setText("");
}
void Dialog::on_pushButton_quitter_clicked()
{
     close();
}

void Dialog::on_pushButton_tri_codee_clicked()
{
    ui->tableView->setModel(tmp.trier_code());

}

void Dialog::on_pushButton_tri_nom_clicked()
{
    ui->tableView->setModel(tmp.trier_nom());

}





void Dialog::on_pushButton_supprimer_E_clicked()

{
    int code = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(code);
    if(test)
    {
        ui->tableView->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","client supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("client non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void Dialog::on_pushButton_rafraichir_clicked()
{
    ui->tableView->setModel(tmp.afficher());

}

void Dialog::on_pushButton_chercher_code_clicked()
{
    QString valeur=ui->lineEdit_chercher_code->text();
        client_dialog *c=new client_dialog();
        ui->tableView->setModel(c->chercher_code(valeur));
}

void Dialog::on_pushButton_chercher_telephone_clicked()
{
    QString valeur=ui->lineEdit_chercher_telephone->text();
        client_dialog *c=new client_dialog();
        ui->tableView->setModel(c->chercher_telephone(valeur));

}

void Dialog::on_pushButton_tri_prenom_clicked()
{

    ui->tableView->setModel(tmp.trier_prenom());

}


void Dialog::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_code->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_telephone->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());

}


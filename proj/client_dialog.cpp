#include "client_dialog.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

client_dialog::client_dialog()

    {
        code=0;
        nom="";
        prenom="";
        telephone=0;
    }

client_dialog::client_dialog(int code,QString nom,QString prenom ,int telephone)
{
  this->code=code;
  this->nom=nom;
  this->prenom=prenom;
    this->telephone=telephone;
}

int client_dialog::get_code(){return code;}
QString client_dialog::get_nom(){return nom;}
QString client_dialog::get_prenom(){return prenom ;}
int client_dialog::get_telephone(){return telephone;}


bool client_dialog::ajouter()
{
QSqlQuery query;

QString res= QString::number(code);

query.prepare("INSERT INTO client_dialog (code,nom,prenom,telephone) "
                    "VALUES (:code,:nom,:prenom,:telephone)");

query.bindValue(":code",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":telephone",telephone);

return    query.exec();
}

QSqlQueryModel * client_dialog::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client_dialog");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
return model;
}

bool client_dialog::supprimer(int code)
{
    QSqlQuery query;


    QString res= QString::number(code);

    query.prepare("Delete from client_dialog where code= :code");
    query.bindValue(":code", res);
    return    query.exec();
}




bool client_dialog::modifier(int code,QString nom,QString prenom ,int telephone)
{ QSqlQuery query;
    QString res= QString::number(code);

    query.prepare("update client_dialog set code=:code,nom=:nom,prenom=:prenom,telephone=:telephone where code=:code");
    query.bindValue(":code",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":telephone",telephone);


    return    query.exec();

}

QSqlQueryModel * client_dialog::chercher_code(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM client_dialog WHERE code ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));

    return model ;
}
QSqlQueryModel * client_dialog::chercher_telephone(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM client_dialog WHERE telephone ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));

    return model ;
}
QSqlQueryModel * client_dialog::trier_code()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client_dialog ORDER BY code asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));


    return model;
}
QSqlQueryModel * client_dialog::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client_dialog ORDER BY nom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
    return model;


}
QSqlQueryModel * client_dialog::trier_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client_dialog ORDER BY prenom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));

    return model;
}



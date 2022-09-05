#ifndef CLIENT_DIALOG_H
#define CLIENT_DIALOG_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client_dialog
{
public:
    client_dialog();
    client_dialog(int,QString,QString,int);
    int get_code();
    QString get_nom();
    QString get_prenom();
    int get_telephone();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);

    QSqlQueryModel * chercher_code(QString);
    QSqlQueryModel * chercher_telephone(QString);
    QSqlQueryModel * trier_code();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_prenom();




private:
    QString nom,prenom;
    int code,telephone;
};

#endif // CLIENT_DIALOG_H

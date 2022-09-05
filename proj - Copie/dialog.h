#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "client_dialog.h"
#include <QDialog>
#include <QObject>
#include <QMainWindow>

#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

#include <QVector>
#include <QMainWindow>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_ajouter_E_clicked();

    void on_pushButton_modifier_E_clicked();

    void on_pushButton_rafraichir_E_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_tri_codee_clicked();

    void on_pushButton_tri_nom_clicked();

    void on_pushButton_tri_telephone_clicked();

    void on_tableView_clicked(const QModelIndex &index);


    void on_pushButton_supprimer_E_clicked();

    void on_pushButton_rafraichir_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_chercher_code_clicked();

    void on_pushButton_chercher_telephone_clicked();

    void on_pushButton_tri_prenom_clicked();

private:
    Ui::Dialog *ui;
     client_dialog tmp;
};

#endif // DIALOG_H

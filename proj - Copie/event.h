#ifndef EVENT_H
#define EVENT_H

#include "evenement.h"
#include <QDialog>
#include <QObject>
#include <QMainWindow>

#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

#include <QVector>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class event;
}

class event : public QDialog
{
    Q_OBJECT

public:
    explicit event(QWidget *parent = nullptr);
    ~event();
private slots:
    void on_pushButton_ajouter_E_clicked();

    void on_pushButton_supprimer_E_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_modifier_E_clicked();

    void on_pushButton_rafraichir_E_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_rafraichir_clicked();

    void on_pushButton_2_quitter_clicked();

    void on_pushButton_tri_codee_clicked();

    void on_pushButton_tri_nom_clicked();

    void on_pushButton_tri_prix_clicked();

    void on_pushButton_chercher_type_clicked();

    void on_pushButton_chercher_ville_clicked();

    void on_pushButton_pdf_clicked();

    void makePlot();
    QVector<double> Statistique();

    void on_pushButton_statistique_clicked();


private:
    Ui::event *ui;
    evenement tmp;

};

#endif // EVENT_H

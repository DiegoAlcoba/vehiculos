#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "vehiculo.h"

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_introNombre_windowIconTextChanged(const QString &iconText);

    void on_nRuedas_valueChanged(int arg1);

    void on_MotorCheck_clicked(bool checked);

    void on_combustible_clicked(bool checked);

    void on_tipoCombustible_currentTextChanged(const QString &arg1);

    void on_SelectColor_currentTextChanged(const QString &arg1);

    void on_alas_clicked(bool checked);

    void on_reactores_clicked(bool checked);

    void on_trenAterrizaje_clicked(bool checked);

    void on_locomotora_clicked(bool checked);

    void on_nVagones_valueChanged(int arg1);

    void on_pinchazo_currentTextChanged(const QString &arg1);

    void on_generaMatricula_clicked();

    void on_matricula_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString name = "";
    QString fuelType = "";
    QString color = "";
    QString  licensePlate = "";
    int nWheels= 0;
    int hp = 0;
    int wagons = 0;
    bool motor = false;
    bool fuel = false;
    bool wings = false;
    bool reactors = false;
    bool  undercarriage = false;
    bool locomotive = false;
    bool replaceWheel = false;
    bool punctureKit = false;
};
#endif // MAINWINDOW_H

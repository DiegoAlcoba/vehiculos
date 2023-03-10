#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 *  HAY QUE AÑADIR LAS SEÑALES ENTRE SLOTS (SI NO SE PULSA QUE TIENE LOCOMOTORA NO SE PUEDE ELEGIR EL Nº DE VAGONES)
 *  A partir de ahí solo es ir programando y puliendo la interfaz
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_introNombre_currentTextChanged(const QString &iconText)
{
    this->name = iconText;
}


void MainWindow::on_nRuedas_valueChanged(int arg1)
{
    this->nWheels = arg1;
}


void MainWindow::on_MotorCheck_clicked(bool checked)
{
    this->motor = checked;
}


void MainWindow::on_combustible_clicked(bool checked)
{
    this->fuel = checked;
}


void MainWindow::on_tipoCombustible_currentTextChanged(const QString &arg1)
{
    if (this->fuel == true) {
        this->fuelType = arg1;
    }
}


void MainWindow::on_SelectColor_currentTextChanged(const QString &arg1)
{
    this->color = arg1;
}


void MainWindow::on_alas_clicked(bool checked)
{
    this->wings = checked;
}


void MainWindow::on_reactores_clicked(bool checked)
{
    this->reactors = checked;
}


void MainWindow::on_trenAterrizaje_clicked(bool checked)
{
    this->undercarriage = checked;
}

void MainWindow::on_locomotora_clicked(bool checked)
{
    this->locomotive = checked;
}


void MainWindow::on_nVagones_valueChanged(int arg1)
{
    if (this->locomotive == true) {
        this->wagons = arg1;
    }
}


void MainWindow::on_pinchazo_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Rueda de Repuesto") {
        this->replaceWheel = true;
    }
    else {
        this->punctureKit = true;
    }
}


void MainWindow::on_generaMatricula_clicked()
{
    /*Cuando se clica se genera la matrícula aleatoriamente, esa matrícula se guarda en this->licensePlate*/
}


void MainWindow::on_matricula_textChanged(const QString &arg1)
{
    /*  Es posible que no haga falta señal alguna, probar con arg1 = this->licensePlate y si se muestra */
}


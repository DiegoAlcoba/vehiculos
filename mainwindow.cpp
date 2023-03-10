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
    ui->matricula->setReadOnly(true);
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
    QString plate;
    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int num = rand() % 10;
        plate.append(QString::number(num));
    }

    for (int i = 0; i < 3; i++) {
        char letra = 'A' + rand() % 26;

        if (letra != 'A' && letra != 'E' && letra != 'I' && letra != 'O' && letra != 'U') {
            plate.append(letra);
        }
        else {
            i--;
        }
    }

    ui->matricula->setText(plate);
    this->licensePlate = plate;
}

/*Un botón para verificar y otro para guardar el vehículo en el garaje, señal entre los dos, si no se verifica o configuración incorrecta no deja guardarlo*/

/*Una vez guardado el vehículo, se resetean las opciones de creación del vehículo*/

/*Para mostrar el garaje ->
 *  1. Botón garaje, que abra una ventana con todos los vehículos guardados
 *  2. Una lista directamente con los vehículos y que se muestren a medida que se vayan guardando
 *  3. ComboBox en la que se van añadiendo los vehiculos, dependiendo del vehiculo elegido, se muestra en un cuadrado (LineEdit?) los datos del vehículo seleccionado
 */


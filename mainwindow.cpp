#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->matricula->setReadOnly(true);
    ui->introNombre->setText("");
    ui->nRuedas->setValue(0);
    ui->MotorCheck->setChecked(false);
    ui->spinBoxPotencia->setDisabled(ui->MotorCheck);/////////////////////////////////////////7
    ui->combustible->setChecked(false);
    ui->tipoCombustible->setDisabled(ui->combustible);
    ui->alas->setChecked(false);
    ui->reactores->setChecked(false);
    ui->trenAterrizaje->setChecked(false);
    ui->locomotora->setChecked(false);
    ui->nVagones->setDisabled(ui->locomotora);
    ui->matricula->setText("");
    ui->contVehics->setText("0");
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

    if (checked == false) {
        this->hp = 0;
        ui->spinBoxPotencia->setValue(0);
    }
}

void MainWindow::on_spinBoxPotencia_valueChanged(int arg1)
{
    if (this->motor) {
        this->hp = arg1;
    }
}

void MainWindow::on_combustible_clicked(bool checked)
{
    this->fuel = checked;
}


void MainWindow::on_tipoCombustible_currentTextChanged(const QString &arg1)
{
    if (this->fuel) {
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

    if (checked == false) {
        this->wagons = 0;
        //ui->nVagones->setValue(0);
    }
}


void MainWindow::on_nVagones_valueChanged(int arg1)
{
    if (this->locomotive) {
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

void MainWindow::on_buttonVerifica_clicked()
{
    /*Verificar que el objeto creado es una configuración válida*/
    vehiculo *a = new vehiculo(this->name, this->nWheels, this->motor, this->hp, this->fuel, this->fuelType, this->color, this->wings, this->reactors, this->undercarriage, this->locomotive, this->wagons, this->replaceWheel, this->punctureKit, this->licensePlate);

        if (ui->introNombre->text() != "" || ui->matricula->text() != "") {

            if (a->isBicycle() && this->verifLicense(a)) {
                QMessageBox::information(this, "Bicicleta creada", "Tu bicicleta se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Bicicleta");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isTricycle() && this->verifLicense(a)) {
                QMessageBox::information(this, "Triciclo creado", "Tu triciclo se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Triciclo");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isMotorcycle() && this->verifLicense(a)) {
                QMessageBox::information(this, "Motocicleta creada", "Tu motocicleta se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Motocicleta");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isCar() && this->verifLicense(a)) {
                QMessageBox::information(this, "Coche creado", "Tu coche se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Coche");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isSportsCar() && this->verifLicense(a)) {
                QMessageBox::information(this, "Deportivo creado", "Tu deportivo se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Deportivo");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isPlane() && this->verifLicense(a)) {
                QMessageBox::information(this, "Avión creado", "Tu avión se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Avion");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else if (a->isTrain() && this->verifLicense(a)) {
                QMessageBox::information(this, "Tren creado", "Tu tren se ha guardado en el garage",QMessageBox::Ok);
                a->setType("Tren");
                this->saveVehicle(a);
                this->garaje.push_back(a);
                this->nVehicles++;
                ui->contVehics->setText(QString::number(this->nVehicles));
                this->reset();

            } else {
                QMessageBox::warning(this, "Error", "La configuración introducida no es válida para ningún vehículo",QMessageBox::Ok);
                return;
            }

        } else {
            QMessageBox::warning(this, "Error", "Por favor, rellene todos los campos con información correcta",QMessageBox::Ok);
            return;
        }




}

/*Cuando un vehículo se guarda se resetean los cuadros de configuración*/
void MainWindow::reset() {

    ui->introNombre->setText("");
    ui->nRuedas->setValue(0);
    ui->MotorCheck->setChecked(false);
    ui->spinBoxPotencia->setValue(0);
    ui->spinBoxPotencia->setDisabled(ui->MotorCheck);
    ui->combustible->setChecked(false);
    ui->tipoCombustible->setDisabled(ui->combustible);
    ui->alas->setChecked(false);
    ui->reactores->setChecked(false);
    ui->trenAterrizaje->setChecked(false);
    ui->locomotora->setChecked(false);
    ui->nVagones->setDisabled(ui->locomotora);
    ui->nVagones->setValue(0);
    ui->matricula->setText("");

//    this->name = "";
//    this->fuelType = "";
//    this->color = "";
//    this->licensePlate = "";
//    this->type = "";
//    this->nWheels= 0;
//    this->hp = 0;
//    this->wagons = 0;
//    this->motor = false;
//    this->fuel = false;
//    this->wings = false;
//    this->reactors = false;
//    this->undercarriage = false;
//    this->locomotive = false;
//    this->replaceWheel = false;
//    this->punctureKit = false;
}

bool MainWindow::verifLicense(vehiculo* vehic) {
    for (int i = 0; i < (int)garaje.size(); i++) {
        if (garaje[i]->getLicensePlate() == vehic->getLicensePlate()) {

            QMessageBox::warning(this, "Error", "No se pueden guardar 2 vehículos con la misma matrícula",QMessageBox::Ok);
            return false;
        }
    }

    return true;
}

void MainWindow::saveVehicle(vehiculo *vehic) {

    QStringList headers = {"TIPO DE VEHÍCULO" , "NOMBRE", "MATRÍCULA"};
    ui->guardados->setHorizontalHeaderLabels(headers);

    ui->guardados->insertRow(rowCount);

    QTableWidgetItem *vehiculoNombre = new QTableWidgetItem(vehic->getName());
    QTableWidgetItem *vehiculoTipo = new QTableWidgetItem(vehic->getType());
    QTableWidgetItem *vehiculoMatricula= new QTableWidgetItem(vehic->getLicensePlate());

    ui->guardados->setItem(rowCount, 0, vehiculoTipo);
    ui->guardados->setItem(rowCount, 1, vehiculoNombre);
    ui->guardados->setItem(rowCount, 2, vehiculoMatricula);

    rowCount++;
}



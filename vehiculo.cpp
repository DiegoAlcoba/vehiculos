#include "vehiculo.h"

/*Constructor*/ /*Añadir tipo de vehículo, el nombre no es el tipo*/
vehiculo::vehiculo(QString name, int nWheels, bool motor, int hp, bool fuel, QString fuelType, QString color, bool wings, bool reactors, bool undercarriage, bool locomotive, int wagons, bool replaceWheel, bool punctureKit, QString licensePlate) {

    this->name = name;
    this->nWheels = nWheels;
    this->motor = motor;
    this->hp = hp;
    this->fuel = fuel;
    this->fuelType = fuelType;
    this->color = color;
    this->wings = wings;
    this->reactors = reactors;
    this->undercarriage = undercarriage;
    this->locomotive = locomotive;
    this->wagons = wagons;
    this->replaceWheel = replaceWheel;
    this->punctureKit = punctureKit;
    this->licensePlate = licensePlate;
}

/*Getters*/ /*Preguntar si los setters son necesarios, es posible que sí ya en la interfaz se dan valores, pero no se asignan a ninguna variable, en principio*/
QString vehiculo::getName() {
    return this->name;
}

void vehiculo::setName(QString value) { //Setter del nombre del vehiculo (bicicleta, coche, etc)
    this->name = value;
}

int vehiculo::getWheels() {
    return this->nWheels;
}

void vehiculo::setWheels(int value) {
    this->nWheels = value;
}

bool vehiculo::getMotor() {
    return this->motor;
}

void vehiculo::setMotor(bool value) {
    this->motor = value;
}

int vehiculo::getHp() {
    return this->hp;
}

void vehiculo::setHp(int value) {
    this->hp = value;
}

bool vehiculo::getFuel() {
    return this->fuel;
}

void vehiculo::setFuel(bool value) {
    this->fuel = value;
}

QString vehiculo::getFuelType() {
    return this->fuelType;
}

void vehiculo::setFuelType(QString value) {
    this->fuelType = value;
}

QString vehiculo::getColor() {
    return this->color;
}

void vehiculo::setColor(QString value) {
    this->color = value;
}

bool vehiculo::getWings() {
    return this->wings;
}

void vehiculo::setWings(bool value) {
    this->wings = value;
}

bool vehiculo::getReactors() {
    return this->reactors;
}

void vehiculo::setReactors(bool value) {
    this->reactors = value;
}

bool vehiculo::getUndercarriage() {
    return this->undercarriage;
}

void vehiculo::setUndercarriage(bool value) {
    this->undercarriage = value;
}

bool vehiculo::getLocomotive() {
    return this->locomotive;
}

void vehiculo::setLocomotive(bool value) {
    this->locomotive = value;
}

int vehiculo::getWagons() {
    return this->wagons;
}

void vehiculo::setWagons(int value) {
    this->wagons = value;
}

bool vehiculo::getReplaceWheel() {
    return this->replaceWheel;
}

void vehiculo::setReplaceWheel(bool value) {
    this->replaceWheel = value;
}

bool vehiculo::getPunctureKit() {
    return this->punctureKit;
}

void vehiculo::setPunctureKit(bool value) {
    this->punctureKit = value;
}

QString vehiculo::getLicensePlate() {
    return this->licensePlate;
}

void vehiculo::setLicensePlate(QString value) {
    this->licensePlate = value;
}

QString vehiculo::getType() {
    return this->type;
}

void vehiculo::setType(QString value) {
    this->type = value;
}

/*Tipos de vehiculos*/
bool vehiculo::isBicycle() {

    if (this->nWheels == 2) {
        if (this->motor == false) {
            if (this->fuel == false) {
                if (this->fuelType == "") {
                    if (this->wings == false) {
                        if (this->reactors == false) {
                            if (this->undercarriage == false) {
                                if (this->locomotive == false) {
                                    if (this->wagons == 0) {
                                        if (this->punctureKit == true) {
                                            return true; //Si se cumplen todos, es verdadero
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false; //Si alguno no se cumple, es falso
}

bool vehiculo::isTricycle() {

    if (this->nWheels == 3) {
        if (this->motor == false) {
            if (this->fuel == false) {
                if (this->fuelType == "") {
                    if (this->wings == false) {
                        if (this->reactors == false) {
                            if (this->undercarriage == false) {
                                if (this->locomotive == false) {
                                    if (this->wagons == 0) {
                                        if (this->punctureKit == true) {
                                            return true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                }
        }
    }
    return false;
}

bool vehiculo::isMotorcycle() {

    if (this->nWheels == 2) {
        if (this->motor == true) {
            if (this->hp >= 80 && this->hp <= 450) {
                if (this->fuel == true) {
                    if (this->fuelType == "Electrico" || this->fuelType == "Gasolina" || this->fuelType == "Diesel" || this->fuelType == "Hibrido") {
                        if (this->wings == false) {
                            if (this->reactors == false) {
                                if (this->undercarriage == false) {
                                    if (this->locomotive == false) {
                                        if (this->wagons == 0) {
                                            if (this->punctureKit == true) {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool vehiculo::isCar() {

    if (this->nWheels == 4) {
        if (this->motor == true) {
            if (this->hp >= 80 && this->hp <= 250) {
                if (this->fuel == true) {
                    if (this->fuelType == "Electrico" || this->fuelType == "Gasolina" || this->fuelType == "Diesel" || this->fuelType == "Hibrido") {
                        if (this->wings == false) {
                            if (this->reactors == false) {
                                if (this->undercarriage == false) {
                                    if (this->locomotive == false) {
                                        if (this->wagons == 0) {
                                            if (this->replaceWheel == true) {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool vehiculo::isSportsCar() {

    if (this->nWheels == 4) {
        if (this->motor == true) {
            if (this->hp >= 250 && this->hp <= 450) {
                if (this->fuel == true) {
                    if (this->fuelType == "Electrico" || this->fuelType == "Gasolina") {
                        if (this->wings == false) {
                            if (this->reactors == false) {
                                if (this->undercarriage == false) {
                                    if (this->locomotive == false) {
                                        if (this->wagons == 0) {
                                            if (this->punctureKit == true) {
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool vehiculo::isPlane() {

    if (this->nWheels == 6) {
        if (this->motor == true) {
            if (this->hp == 450) {
                if (this->fuel == true) {
                    if (this->fuelType == "Queroseno") {
                        if (this->color == "Blanco"){
                            if (this->wings == true) {
                                if (this->reactors == true) {
                                    if (this->undercarriage == true) {
                                        if (this->locomotive == false) {
                                            if (this->wagons == 0) {
                                                if (this->replaceWheel == true) {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool vehiculo::isTrain() {

    if (this->nWheels == 40) {
        if (this->motor == true) {
            if (this->hp == 450) {
                if (this->fuel == true) {
                    if (this->fuelType == "Electrico" || this->fuelType == "Diesel") {
                        if (this->color == "Negro"){
                            if (this->wings == false) {
                                if (this->reactors == false) {
                                    if (this->undercarriage == false) {
                                        if (this->locomotive == true) {
                                            if (this->wagons >= 5 && this->wagons <= 20) {
                                                if (this->replaceWheel == true) {
                                                    return true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

#ifndef VEHICULO_H
#define VEHICULO_H

#include <QString>

class vehiculo
{
public:
    vehiculo(QString name, int nWheels, bool motor, int hp, bool fuel, QString fuelType, QString color, bool wings, bool reactors, bool undercarriage, bool locomotive, int wagons, bool replaceWheel, bool punctureKit, QString licensePlate);

    QString name, fuelType, color, licensePlate;
    int nWheels, hp, wagons;
    bool motor, fuel, wings, reactors, undercarriage, locomotive, replaceWheel, punctureKit;

    QString getName();
    void setName(QString value);
    int getWheels();
    void setWheels(int value);
    bool getMotor();
    void setMotor(bool value);
    int getHp();
    void setHp(int value);
    bool getFuel();
    void setFuel(bool value);
    QString getFuelType();
    void setFuelType(QString value);
    QString getColor();
    void setColor(QString value);
    bool getWings();
    void setWings(bool value);
    bool getReactors();
    void setReactors(bool value);
    bool getUndercarriage();
    void setUndercarriage(bool value);
    bool getLocomotive();
    void setLocomotive(bool value);
    int getWagons();
    void setWagons(int value);
    bool getReplaceWheel();
    void setReplaceWheel(bool value);
    bool getPunctureKit();
    void setPunctureKit(bool value);
    QString getLicensePlate();
    void setLicensePlate(QString value);

    bool isBicycle();
    bool isTricycle();
    bool isMotorcycle();
    bool isCar();
    bool isSportsCar();
    bool isPlane();
    bool isTrain();
};

#endif // VEHICULO_H

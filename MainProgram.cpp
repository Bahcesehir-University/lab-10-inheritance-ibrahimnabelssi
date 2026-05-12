#include <iostream>
#include <string>
#include <sstream>

class Vehicle {
protected:
    std::string make;
    int year;
    double fuelLevel;

public:
    Vehicle(std::string make, int year, double fuelLevel);

    std::string getMake() const;
    int getYear() const;
    double getFuelLevel() const;

    void refuel(double amount);

    virtual std::string describe() = 0;

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(std::string make, int year, double fuelLevel, int numDoors);

    int getNumDoors() const;

    std::string describe() override;
};

class Truck : public Vehicle {
private:
    double payloadTons;

public:
    Truck(std::string make, int year, double fuelLevel, double payloadTons);

    double getPayloadTons() const;

    std::string describe() override;
};

// Vehicle implementations

Vehicle::Vehicle(std::string make, int year, double fuelLevel)
    : make(make), year(year), fuelLevel(fuelLevel) {
}

std::string Vehicle::getMake() const {
    return make;
}

int Vehicle::getYear() const {
    return year;
}

double Vehicle::getFuelLevel() const {
    return fuelLevel;
}

void Vehicle::refuel(double amount) {
    if (amount <= 0) {
        return;
    }

    fuelLevel += amount;

    if (fuelLevel > 100.0) {
        fuelLevel = 100.0;
    }
}

// Car implementations

Car::Car(std::string make, int year, double fuelLevel, int numDoors)
    : Vehicle(make, year, fuelLevel), numDoors(numDoors) {
}

int Car::getNumDoors() const {
    return numDoors;
}

std::string Car::describe() {
    std::ostringstream oss;

    oss << "Car: " << make << " (" << year << "), "
        << numDoors << " doors, fuel:" << fuelLevel << "%";

    return oss.str();
}

// Truck implementations

Truck::Truck(std::string make, int year, double fuelLevel, double payloadTons)
    : Vehicle(make, year, fuelLevel), payloadTons(payloadTons) {
}

double Truck::getPayloadTons() const {
    return payloadTons;
}

std::string Truck::describe() {
    std::ostringstream oss;

    oss << "Truck: " << make << " (" << year << "), payload: "
        << payloadTons << ", fuel:" << fuelLevel << "%";

    return oss.str();
}

int main() {
    Car c("Toyota", 2020, 75.5, 4);
    Truck t("Ford", 2018, 60.0, 5.5);

    std::cout << c.describe() << "\n";
    std::cout << t.describe() << "\n";

    Vehicle* v1 = &c;
    Vehicle* v2 = &t;

    std::cout << v1->describe() << "\n";
    std::cout << v2->describe() << "\n";

    c.refuel(20.0);
    std::cout << "After refuel: " << c.getFuelLevel() << "%\n";

    return 0;
}

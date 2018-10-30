#include "StandardCar.h"

StandardCar::StandardCar(string modelType_) : Car("StandardCar " + modelType_) {

}

StandardCar::StandardCar(const Car &car_, bool flag_) : Car(car_, flag_) {

}

string StandardCar::getDescription() {
    return Car::getDescription();
}



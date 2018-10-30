#include "State.h"

void Ready::racing(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Ready => Racing\n";
    car->setState(new Racing());
    delete this;
}
void Ready::stopped(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Ready => Stopped\n";
    car->setState(new Stopped());
    delete this;
}

void Racing::ready(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Racing => Ready\n";
    car->setState(new Ready());
    delete this;
}

void Racing::stopped(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Racing => Stopped\n";
    car->setState(new Stopped());
    delete this;
}

void Stopped::ready(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Stopped => Ready\n";
    car->setState(new Ready());
    delete this;
}

void Stopped::racing(Car *car) {
    cout << "Car: "<<car->getCarID()<<" Stopped => Racing\n";
    car->setState(new Racing());
    delete this;
}
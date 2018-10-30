/**
 *  @author israel Sekhwela
 *  @file ElectricGoKart.h
 *  @class ElectricGoKart
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */
#ifndef ELECTRICGOKART_H
#define ELECTRICGOKART_H

#include "ElectricCar.h"

class ElectricGoKart : public ElectricCar{
public:
    /**
    *  Constructor for ElectricGoKart, calls Constructor of ElectricCar
    */
    ElectricGoKart() : ElectricCar("GoKart"){
        setAcceleration(75);
        setSpeed(40);
        setHandling(50);

        cout << "Constructing an Electric GoKart ...\n" << toString() << endl;
    };
    /**
        * Copy constructor used for cloning
        * @param car_  car object for copying
        * @param flag_ to determine if must be full clone or basic clone
        */
    ElectricGoKart(const Car& car_, bool flag_) : ElectricCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(75);
            setSpeed(40);
            setHandling(50);
        }

        string out = "Cloning ";
        if (flag_ == false){
            out += "Original Car ...\n";
        }
        else{
            out += "Customized Car ...\n";
        }
        cout << out;
        cout << toString() << endl;
    };

    /**
     * implementation of clone function
     * @param flag_ determines if must be full clone or basic clone
     * @return a copied car object
     */
    virtual Car* clone(bool flag_ = false){
        return new ElectricGoKart(*this, flag_);
    };
};

#endif

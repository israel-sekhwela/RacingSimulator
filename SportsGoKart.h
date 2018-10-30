/**
 *  @author Israel Sekhwela
 *  @file SportsGoKart.h
 *  @class SportsGoKart
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */

#ifndef SPORTSGOKART_H
#define SPORTSGOKART_H

#include "SportsCar.h"

class SportsGoKart : public SportsCar{
public:
    /**
    * Constructor for SportsGoKart, calls Constructor of SportsCar
    */
    SportsGoKart() : SportsCar("GoKart"){
        setAcceleration(50);
        setSpeed(75);
        setHandling(45);

        cout << "Constructing a Sports GoKart ...\n" << toString() << endl;
    };
    /**
    * Copy constructor used for cloning
    * @param car_  car object for copying
    * @param flag_ to determine if must be full clone or basic clone
    */
    SportsGoKart(const Car& car_, bool flag_) : SportsCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(50);
            setSpeed(75);
            setHandling(45);
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
        return new SportsGoKart(*this, flag_);
    };
};

#endif

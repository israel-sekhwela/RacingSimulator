/**
 *  @author Israel Sekhwela
 *  @file ElectricRoadster.h
 *  @class ElectricRoadster
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */
#ifndef ELECTRICROADSTER_H
#define ELECTRICROADSTER_H

#include "ElectricCar.h"

class ElectricRoadster : public ElectricCar{
public:
    /**
     * Constructor for ElectricFormulaOne, calls Constructor of ElectricCar
     */
    ElectricRoadster() : ElectricCar("Roadster"){
        setAcceleration(150);
        setSpeed(75);
        setHandling(110);

        cout << "Constructing an Electric Roadster ...\n" << toString() << endl;
    };
    /**
     * Copy constructor used for cloning
     * @param car_  car object for copying
     * @param flag_ to determine if must be full clone or basic clone
     */
    ElectricRoadster(const Car& car_, bool flag_) : ElectricCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(150);
            setSpeed(75);
            setHandling(110);
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
        return new ElectricRoadster(*this, flag_);
    };
};

#endif

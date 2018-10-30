/**
*  @author Israel Sekhwela
*  @file StandardRoadster.h
*  @class StandardRoadster
*  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
*/

#ifndef STANDARDROADSTER_H
#define STANDARDROADSTER_H

#include "StandardCar.h"

class StandardRoadster : public StandardCar{
public:
    /**
     * Constructor for StandardRoadster, calls Constructor of StandardCar
     */
    StandardRoadster() : StandardCar("Roadster"){
        setAcceleration(75);
        setSpeed(110);
        setHandling(85);

        cout << "Constructing a Standard Roadster ...\n" << toString() << endl;
    };
    /**
     * Copy constructor used for cloning
     * @param car_  car object for copying
     * @param flag_ to determine if must be full clone or basic clone
     */
    StandardRoadster(const Car& car_, bool flag_) : StandardCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(75);
            setSpeed(110);
            setHandling(85);
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
        return new StandardRoadster(*this, flag_);
    };
};

#endif

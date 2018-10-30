/**
 *  @author Israel Sekhwela
 *  @file SportsRoadster.h
 *  @class SportsRoadster
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */


#ifndef SPORTSROADSTER_H
#define SPORTSROADSTER_H

#include "SportsCar.h"

class SportsRoadster : public SportsCar{
public:
    /**
    * Constructor for SportsRoadster, calls Constructor of SportsCar
    */
    SportsRoadster() : SportsCar("Roadster"){
        setAcceleration(110);
        setSpeed(150);
        setHandling(75);

        cout << "Constructing a Sports Roadster ...\n" << toString() << endl;
    };

    /**
     * Copy constructor used for cloning
     * @param car_  car object for copying
     * @param flag_ to determine if must be full clone or basic clone
     */
    SportsRoadster(const Car& car_, bool flag_) : SportsCar(car_, flag_){
        if (flag_ == false) {
            setAcceleration(110);
            setSpeed(150);
            setHandling(75);
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
        return new SportsRoadster(*this, flag_);
    };
};

#endif

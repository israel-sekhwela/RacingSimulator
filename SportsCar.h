/**
 *  @author Israel Sekhwela
 *  @file SportsCar.h
 *  @class SportsCar
 *  @author Israel Sekhwela
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */

#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "Car.h"

class SportsCar : public Car{

public:
    /**
     * Constructor for SportsCar
     * @param modelType_ states whether car is Electric/Sports/Standard
     */
    SportsCar(string modelType_);

    /**
    * The copy constructor for SportsCar
    * @param car_ is a Car object that will be copied
    */
    SportsCar(const Car& car_, bool flag_);

    /**
    * The virtual destructor for SportsCar
    */
    virtual ~SportsCar(){

    };

    /**
     * a getDescription Function
     * @return a string that states the info about the car
     */
    virtual string getDescription();

    /**
    * a abstract clone function for the prototype design pattern
    * @return a pointer to car object
    */
    virtual Car* clone(bool flag_){

    };

    /**
     * implementation of Fullclone in Car
     * @return Car object with all decorated
     */
    virtual Car* FullClone(){

    };
};

#endif

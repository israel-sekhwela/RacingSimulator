/**
 *  @author Israel Sekhwela
 *  @file ElectricCar.h
 *  @class ElectricCar
 *  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
 */

#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "Car.h"

class ElectricCar : public Car{

public:
    /**
     * Constructor for ElectricCar
     * @param modelType_ states whether car is Electric/Sports/Standard
     */
    ElectricCar(string modelType_);

    /**
    * The copy constructor for ElectricCar
    * @param car_ is a Car object that will be copied
    */
    ElectricCar(const Car& car_, bool flag_);

    /**
     * The virtual destructor for ElectricCar
     */
    virtual ~ElectricCar(){};

    /**
     * a getDescription Function
     * @return a string that states the info about the car
     */
    virtual string getDescription();

    /**
     * clone function for the prototype design pattern
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

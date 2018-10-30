/**
*  @author Israel Sekhwela
*  @file StandardCar.h
*  @class StandardCar
*  @brief Concrete Product for Abstract Factory Pattern and Concrete Component for Decorator Pattern
*/

#ifndef STANDARDCAR_H
#define STANDARDCAR_H

#include "Car.h"

class StandardCar : public Car{

public:

    /**
     * The base Constructor for StandardCar
     * @param modelType_ states whether the car is FormulaOne/Roadster/GoKart
     */
    StandardCar(string modelType_);

    /**
     * The copy constructor for StandardCar
     * @param car_ is a Car object that will be copied
     */
    StandardCar(const Car& car_, bool flag_);

    /**
     * The virtual destructor for StandardCar
     */
    virtual ~StandardCar(){

    };

    /**
     * a getDescription Function
     * @return a string that states the info about the car
     */
    virtual string getDescription();

    /**
     * a abstract clone function for the prototype design pattern
     * @return a Car object
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

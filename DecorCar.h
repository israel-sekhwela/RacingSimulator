/**
 *  @author Israel Sekhwela
 *  @file DecorCar.h
 *  @class DecorCar
 *  @brief Decorcator for Decorator Pattern
 */

#ifndef DecorCar_H
#define DecorCar_H

#include "Car.h"

class DecorCar: public Car
{
public:
    /**
     * @brief a car object that will be decorated
     */
    Car* car;

    /**
    * Defualt constructor used for DecorCar
    */
    DecorCar(){
        car=0;
    }

    /**
     * The destructor for Car
     */
    ~DecorCar(){

    }

    /**
     * add function for decorator
     * @param c is car object
     */
    virtual void add(Car* _car)
    {
        if(car==0)
            car=_car;
        else
            car->add(_car);
    }

    /**
     * for clone for prototype pattern
     * @param flag_ to determine if must be full clone or basic
     * @return Car object
     */
    virtual Car* clone(bool flag_){

    };

    /**
     * showCarStats function to show the stats of a car
     * @return string stating the stats
     */
    virtual string showCarStats(){
        if(car!=0)
            return getDescription() + car->showCarStats();
        else
            return getDescription();
    }
    /**
    * for Fullclone for prototype pattern of decorator
    * @return Car object
    */
    virtual Car* FullClone(){
        car->FullClone();
    };
};

#endif

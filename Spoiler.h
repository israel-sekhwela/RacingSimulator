/**
 *  @author Israel Sekhwela
 *  @file Spoiler.h
 *  @class Spoiler
 *  @brief Concrete Decorcator for Decorator Pattern
 */

#ifndef SPOILER_H
#define SPOILER_H

#include "DecorCar.h"

class Spoiler: public DecorCar
{
public:
    /**
    * constructor which assigns description and alters behaviour of car
    * @param Decorate the car in which the behaviours are added
    */
    Spoiler(Car* Decorate):DecorCar()
    {
        setDescription("Pedestal Spoiler\n");
        Decorate->setHandling(Decorate->getHandling()+20);
        Decorate->setSpeed(Decorate->getSpeed()-10);
    }

    /**
    * destructor for Spoiler
    */
    ~Spoiler(){

    };

    /**
     * copy constructor used for cloning the decorators
     * @param _Car the car it copies
     * @param dummy just there to use instead of defualt constructor
     */
    Spoiler(Spoiler _Car,bool dummy)
    {
        setDescription(_Car.getDescription());
        if(_Car.car!=0)
        {
            add(_Car.car->FullClone());
        }
    }

    /**
     * implementation of FullClone to deep copy the decorater
     * @return Car object which is the decorator
     */
    virtual Car* FullClone(){
        return new Spoiler(*this,true);
    }
};

#endif

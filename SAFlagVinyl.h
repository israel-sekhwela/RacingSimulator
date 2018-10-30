/**
 *  @author israel Sekhwela
 *  @file SAFlagVinyl.h
 *  @class SAFlagVinyl
 *  @brief Concrete Decorcator for Decorator Pattern
 */

#ifndef SAFlagVinyl_H
#define SAFlagVinyl_H

#include "DecorCar.h"

class SAFlagVinyl: public DecorCar
{
public:
    /**
     * constructor to set description
     */
    SAFlagVinyl():DecorCar()
    {
        setDescription("SAFlagVinyl\n");
    }
    /**
     * destructor to delete the vinyl
     */
    ~SAFlagVinyl(){

    };

    /**
 * copy constructor used for cloning the decorators
 * @param _Car the car it copies
 * @param dummy just there to use instead of defualt constructor
 */
    SAFlagVinyl(SAFlagVinyl _Car,bool dummy)
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
        return new SAFlagVinyl(*this,true);
    }
};

#endif
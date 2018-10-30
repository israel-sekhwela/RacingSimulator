/**
 *  @author Israel Sekhwela
 *  @file BlueLineVinly.h
 *  @class BlueLineVinly
 *  @brief Concrete Decorcator for Decorator Pattern
 */

#ifndef BlueLineVinly_H
#define BlueLineVinly_H

#include "DecorCar.h"

class BlueLineVinly: public DecorCar
{
public:
    /**
     * constructor to set description
     */
    BlueLineVinly():DecorCar()
    {
        setDescription("BlueLineVinyl\n");
    }
    /**
    * destructor to delete the vinyl
    */
    ~BlueLineVinly(){
    	
    };

    /**
 * copy constructor used for cloning the decorators
 * @param _Car the car it copies
 * @param dummy just there to use instead of defualt constructor
 */
    BlueLineVinly(BlueLineVinly _Car,bool dummy)
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
        return new BlueLineVinly(*this,true);
    }
};

#endif

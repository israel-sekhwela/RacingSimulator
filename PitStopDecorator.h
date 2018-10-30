/**
 *  @author Israel Sekhwela
 *  @file PitStopDecorator.h
 *  @class PitStopDecorator
 *  @brief ConcreteDecorator for Decorator design pattern
 */

#ifndef PITSTOPDECORATOR_H
#define PITSTOPDECORATOR_H

#include "DecorTrack.h"

class PitStopDecorator: public DecorTrack
{
public:
    /**
     * Constructor that calls constructor of DecorTrack and has a desciption
     */
    PitStopDecorator():DecorTrack(){
    	setDescription("Pitstop!");
    }
    /**
    * destructor
    */
    ~PitStopDecorator(){

    };
};

#endif

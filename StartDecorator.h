/**
 *  @author Israel Sekhwela
 *  @file StartDecorator.h
 *  @class StartDecorator
 *  @version 1.0.0
 *  @brief ConcreteDecorator for Decorator design pattern
 */

#ifndef STARTDECORATOR_H
#define STARTDECORATOR_H

#include "DecorTrack.h"

class StartDecorator: public DecorTrack
{
public:
    /**
     * Constructor that calls constructor of DecorTrack and has a desciption
     */
    StartDecorator():DecorTrack()
    {
    	setDescription("Start Line!");
    }
    /**
    * destructor
    */
    ~StartDecorator(){

    };

};

#endif

/**
 *  @author Israel Sekhwela
 *  @file FinishDecorator.h
 *  @class FinishDecorator
 *  @brief ConcreteDecorator for Decorator design pattern
 */
#ifndef FINISHDECORATOR_H
#define FINISHDECORATOR_H

#include "DecorTrack.h"
class FinishDecorator: public DecorTrack
{
public:
    /**
     * Constructor that calls constructor of DecorTrack and has a desciption
     */
    FinishDecorator():DecorTrack(){
    	setDescription("Finish Line!");
    }
    /**
     * destructor
     */
    ~FinishDecorator(){

    };

};

#endif

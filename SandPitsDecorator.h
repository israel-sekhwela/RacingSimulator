/**
 *  @author Israel Sekhwela
 *  @file SandPitsDecorator.h
 *  @class SandPitsDecorator
 *  @brief ConcreteDecorator for Decorator design pattern
 */
#ifndef SANDPITSDECORATOR_H
#define SANDPITSDECORATOR_H

#include "DecorTrack.h"
class SandPitsDecorator: public DecorTrack{
    public:
        /**
         * Constructor that calls constructor of DecorTrack and has a desciption
         */
        SandPitsDecorator():DecorTrack(){
            setDescription("Sand Pits");
        }
        /**
        * destructor
        */
        ~SandPitsDecorator(){

        };
};

#endif

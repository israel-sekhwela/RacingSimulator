/**
 *  @author Israel Sekhwela
 *  @file AggressiveDriver.h
 *  @class AggressiveDriver
 *  @brief concreteStratey for strategy design pattern
 */

#ifndef PASSIVEDRIVER_H
#define PASSIVEDRIVER_H

#include "Driver.h"

class PassiveDriver:public Driver
{
public:
    /**
    * constructor to set fuel, tyre and driving ability
    */
    PassiveDriver(){

        int amount= rand()%80+100;
        double ability = (amount*1.0)/100;
        setAbility(ability);

        amount= rand()%80+10;
        ability = (amount*1.0)/100;
        setFuelAbility(ability);

        amount= rand()%80+10;
        ability = (amount*1.0)/100;
        setTyreAbility(ability);
    };
};

#endif

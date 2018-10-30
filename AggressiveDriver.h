/**
 *  @author Israel Sekhwela
 *  @file AggressiveDriver.h
 *  @class AggressiveDriver
 *  @brief concreteStratey for strategy design pattern
 */

#ifndef AGGRESSIVEDRIVER_H
#define AGGRESSIVEDRIVER_H

#include "Driver.h"

class AggressiveDriver:public Driver
{
public:
    /**
     * constructor to set fuel, tyre and driving ability
     */
    AggressiveDriver(){

        int amount= rand()%80+10;
        double ability = (amount*1.0)/100;
        setAbility(ability);

        amount= rand()%80+100;
        ability = (amount*1.0)/100;
        setFuelAbility(ability);

        amount= rand()%80+100;
        ability = (amount*1.0)/100;
        setTyreAbility(ability);
    };
};

#endif

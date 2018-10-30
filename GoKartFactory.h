/**
 *  @author Israel Sekhwela
 *  @file GoKartFactory.h
 *  @class GoKartFactory
 *  @brief Concrete Factory for Abstract Factory Pattern
 */

#ifndef GOKARTFACTORY_H
#define GOKARTFACTORY_H

#include "CarFactory.h"
#include "SportsGoKart.h"
#include "StandardGoKart.h"
#include "ElectricGokart.h"

class GoKartFactory:public CarFactory
{
public:
    /**
     * Implemented Function to produce an ElectricCar
     * @return ElectricCar*
     */
    virtual ElectricCar* produceElectric()
    {
        return new ElectricGoKart();
    }


    /**
    * Implemented Function to produce an SportsCar
    * @return SportsCar*
    */
    virtual SportsCar*   produceSports()
    {
        return new SportsGoKart();
    }

    /**
    * Implemented Function to produce an StandardCar
    * @return StandardCar*
    */
    virtual StandardCar* produceStandard()
    {
        return new StandardGoKart();
    }
     //concrete Factory For Abstract Factory, returns appropriate car for which function called
};

#endif

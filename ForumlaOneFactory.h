/**
 *  @author Israel Sekhwela
 *  @file FormulaOneFactory.h
 *  @class FormulaOneFactory
 *  @brief Concrete Factory for Abstract Factory Pattern
 */

#ifndef FORUMLAONEFACTORY_H
#define FORUMLAONEFACTORY_H

#include "CarFactory.h"
#include "SportsFormulaOne.h"
#include "StandardFormulaOne.h"
#include "ElectricFormulaOne.h"

class FormulaOneFactory: public CarFactory
{
public:
    /**
     * Implemented Function to produce an ElectricCar
     * @return ElectricCar*
     */
    virtual ElectricCar* produceElectric(){
        return new ElectricFormulaOne();
    }

    /**
     * Implemented Function to produce an SportsCar
     * @return SportsCar*
     */
    virtual SportsCar*   produceSports(){
        return new SportsFormulaOne();
    }

    /**
     * Implemented Function to produce an StandardCar
     * @return StandardCar*
     */
    virtual StandardCar* produceStandard(){
        return new StandardFormulaOne();
    }
    //concrete Factory For Abstract Factory, returns appropriate car for which function called
};

#endif

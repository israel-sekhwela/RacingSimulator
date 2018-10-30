/**
 *  @author Israel Sekhwela
 *  @file RoadsterFactory.h
 *  @class RoadsterFactory
 *  @brief Concrete Factory for Abstract Factory Pattern
 */

#ifndef ROADSTERFACTORY_H
#define ROADSTERFACTORY_H

#include "CarFactory.h"
#include "ElectricRoadster.h"
#include "SportsRoadster.h"
#include "StandardRoadster.h"

class RoadsterFactory: public CarFactory{
    public:
        /**
         * Implemented Function to produce an ElectricCar
         * @return ElectricCar*
         */
        virtual ElectricCar* produceElectric(){
            return new ElectricRoadster();
        }

        /**
         * Implemented Function to produce an SportsCar
         * @return SportsCar*
         */
        virtual SportsCar*   produceSports(){
            return new SportsRoadster();
        }

        /**
        * Implemented Function to produce an StandardCar
        * @return StandardCar*
        */
        virtual StandardCar* produceStandard(){
            return new StandardRoadster();
        }
        //concrete Factory For Abstract Factory, returns appropriate car for which function called
};

#endif

/**
 *  @author Israel Sekhwela
 *  @file Driver.h
 *  @class Driver
 *  @brief Stratey for strategy design pattern
 */
#ifndef DRIVER_H
#define DRIVER_H

#include <stdlib.h>
#include <time.h>

class Driver{

private:
    /**
     * fraction to hold driver ability
     */
    double driverAbility;
    /**
     * fraction to hold driverFuel
     */
    double driverFuel;
    /**
     * fraction to hold driverTyre
     */
    double driverTyre;
public:
    /**
     * sets the driving ability of the driver
     * @param ability
     */
    void setAbility(double ability){
        driverAbility=ability;
    };
    /**
     * returns the driving ability of the driver
     * @return
     */
    double getDriverAbilty(){ 
        return driverAbility;
    };
    /**
     * sets the fuel ability of the driver
     * @param ability
     */
    void setFuelAbility(double ability){
        driverFuel=ability;
    };
    /**
     * returns the fuel ability of the driver
     * @return
     */
    double getFuelAbilty(){ 
        return driverFuel;
    };
    /**
     * returns the tyre ability of the driver
     * @param ability
     */
    void setTyreAbility(double ability){
        driverTyre=ability;
    };
    /**
     * returns the tyre ability of the driver
     * @return
     */
    double getTyreAbilty(){ 
        return driverTyre;
    };
};

#endif

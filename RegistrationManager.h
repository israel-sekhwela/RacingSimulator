/**
 *  @author Israel Sekhwela
 *  @file RegistratcionManager.h
 *  @class ConcreteRegistrationManager
 *  @brief AbstractMediator for mediator design pattern
 */

#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include "Car.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Avoid Circular Depedency!
*/
class RaceTrackComponent;
class Car;

class RegistratcionManager{
public:
    /**
    * abstract function to add cars into mediator
    */
    virtual void addCar(Car* _car, int track)=0;
    /**
    * abstract function to add trackComponents into mediator
    */
    virtual void addTrack(RaceTrackComponent* _racetrack)=0;
    /**
     * returns the cars on a certain racetrack
     * @param racetrack
     * @return
     */
    virtual vector<Car*> getCars(int racetrack)=0;
    /**
     * returns the race track for a track number
     * @param trackNo
     * @return
     */
    virtual RaceTrackComponent* getTrack(int trackNo)=0;

};

#endif

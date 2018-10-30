/**
 *  @author Israel Sekhwela
 *  @file Facade.h
 *  @class Facade
 *  @brief Facade pattern
 */

#ifndef FACADE_H
#define FACADE_H

#include "includes.h"

class Facade
{
private:
    /**
     * the list of all the cars
     */
    vector<Car*>cars;
    /**
     * the list of all the tracks
     */
    vector<RaceTrackComponent*>racetracks;
    /**
     * the different factories
     */
    CarFactory **Factories;
    /**
     *  the racemanager of the track
     */
    RaceManager* raceManager;
    /**
     * registration manager for the track
     */
    RegistratcionManager* registratcionManager;
public:
    /**
     * constructor that creates the necessary registration objects
     */
    Facade();
    /**
     * destructor to delete all necessary things
     */
    ~Facade();
    /**
     * function to create a new team
     * @return a pitstop object
     */
    PitStop* createTeam();

    /**
     * create a custom car, will ask all options
     * @return the created car
     */
    Car* createCustomCar();
    /**
     * create a custom track
     * @return the custom track
     */
    RaceTrackComponent* createCustomeRacetrack();
    /**
     * register car to the track with the registration manager
     * @param c the car to add
     * @param i the track number
     */
    void registerCar(Car* c);

     /**
      * overloaded parameter to state which car you want to register
      */
    void registerCar();

    /**
    *  register the track with registration manager
    * @param rt
    */
    void registerTrack(RaceTrackComponent* rt);

    /**
     *  prepare the race by getting all the necessary info from the registration manager
     *  @param rt
     *  @return returns if you chose to go back
     */
    bool prepRace();

    /**
     * will start the race
     */
    void StartRace();

    /**
     * create a driver, asking which driver the user wants
     * @return the driver
     */
    Driver* createDriver();

    /**
     * function to clone a car
     * @return the cloned car
     */
    Car* copyCar();

};


#endif
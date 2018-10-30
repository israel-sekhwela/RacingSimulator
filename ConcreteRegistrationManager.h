/**
 *  @author Israel Sekhwela
 *  @file ConcreteRegistrationManager.h
 *  @class ConcreteRegistrationManager
 *  @brief ConcreteMediator for mediator design pattern
 */

#ifndef CONCRETEREGISTRATIONMANAGER_H
#define CONCRETEREGISTRATIONMANAGER_H

#include <vector>
#include "RegistrationManager.h"

class ConcreteRegistrationManager:public RegistratcionManager
{

private:

    /**
     * cars array holds tracks and the cars
     */
    vector<vector<Car*> > cars;

    /**
     * resizes the track number of cars to fit more cars in
     * @param trackNo the track no to be resized
     */
    void resize(int trackNo);

    /**
     * holds all the registered tracks
     */
    vector<RaceTrackComponent*> tracks;
public:
    /**
     * constructor for ConcreteRegistrationManager
     * @param _numTracks determines how many racetracks there are
     */
    ConcreteRegistrationManager();

    /**
     * destructor for manager
     */
    ~ConcreteRegistrationManager();

    /**
     * implementation of absrtact function to add car into the cars array
     * @param _car car object to be placed in the array
     * @param track specifies which track the car will be racing
     */
    virtual void addCar(Car* _car, int track);

    /**
    * implementation of absrtact function to add car into the cars array
    * @param _racetrack racetrack object to be placed in the array
    */
    virtual void addTrack(RaceTrackComponent* _racetrack);

    virtual vector<Car*> getCars(int racetrack){
        int track= tracks.size();
        if(tracks.size()<=racetrack){
            cout<<"Track not available as yet.\n";
            vector<Car*> a;
            return a;
        }
        else{
            return cars[racetrack];
        }
    }

    virtual RaceTrackComponent* getTrack(int trackNo){
        if(trackNo>=tracks.size()){
            cout<<"Track not available as yet.\n";
            return NULL;
        }
        return tracks[trackNo];
    }
};

#endif

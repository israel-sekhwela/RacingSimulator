/**
 *  @author Israel Sekhwela
 *  @file RaceTrackComponent.h
 *  @class RaceTrackComponent
 *  @brief abstract leaf class for composite pattern
 */

#ifndef RACETRACKCOMPONENT_H
#define RACETRACKCOMPONENT_H
using namespace std;

#include "Car.h"
#include "Decider.h"
#include <string>
#include <vector>
#include <iostream>

class RaceTrackComponent
{
    private:
    /**
     * description for the track part
     */
    string description;

public:
    /**
     * Parent Constructor for the racetrack parys
     */
    RaceTrackComponent(){
        decorate=0;
    }
    /**
     * dectorates the track with passed in paramater
     * @param R
     */
    virtual void decorateTrack(RaceTrackComponent* R){
        if(decorate==0)
            decorate=R;
        else{
            decorate->decorateTrack(R);
        }
    }
    /**
     * @return the decorators string
     */
    virtual string getDecorator(){
        if(decorate->decorate==0)
            return decorate->getDescription();
        if(decorate!=0)
            return decorate->getDescription()+", "+decorate->getDecorator();
        return "";

    }
    /**
     * add car to the race track component
     * @param _car the car to add
     */
    void addCar(Car* _car)
    {
        cars.push_back(_car);
    }
    /**
     * remove a car from the track component
     * @param _car the car to remove
     */
    void removeCar(Car* _car){
        cars.erase(cars.begin());
    }

    /**
    * returns the number of components
    * @return
    */
    virtual int getNumComponents(){

    };
    /**
     * add the cars to the racetrack
     * @param _car
     * @param rt
     */
    virtual void addAllCars(vector<Car*> _car,int rt){

    }
    /**
     * removes the cars from the racetrack
     * @param _car
     * @param rt
     */
    virtual void removeAllCars(vector<Car*>_car, int rt){

    }
    /**
     * returns all the cars on a racetrack
     * @param rt
     * @return
     */
    virtual vector<Car*> getAllCars(int rt){

    }
    /**
     * accept of vistor class
     * @param v
     * @param rt
     */
    virtual void makeAccept(Decider*v,int rt){

    }
    /**
     * move car to certain track part
     * @param _car
     * @param rt
     */
    virtual void moveCar(Car* _car,int rt){

    };
    /**
     * empty implementation of show
     */
    virtual void show(){

    };
    /**
     * pure virtual implementation of print
     */
    virtual void print()=0;
    /**
    * pure virtual implementation of add
    */
    virtual void add(RaceTrackComponent*)=0;
    /**
     * destructor
     */
    virtual ~RaceTrackComponent(){};
    /**
     * sets the description
     * @param d the string to set the description
     */
    void setDescription(string d){
        description=d;
    };
    /**
     * @return the description
     */
    string getDescription(){ 
        return description;
    };

    /**
     * the decorate for the track component
     */
    RaceTrackComponent* decorate;
    /**
     *add time to car
     */
    virtual void addTime()=0;
    /**
     * accept visitor
     * @param v
     */
    virtual void accept(Decider* v)=0;
    /**
     *return the cars
     * @return
     */
    vector<Car*> getCars(){ 
        return cars;
    }
    /**
     * vector of cars on the track part
     */
    vector<Car*> cars;
};

#include "Decider.h"

#endif


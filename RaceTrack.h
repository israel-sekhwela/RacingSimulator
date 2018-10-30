/**
 *  @author Israel Sekhwela
 *  @file RaceTrack.h
 *  @class RaceTrack
  *  @brief composite class for composite pattern
 */

#ifndef RACETRACK_H
#define RACETRACK_H

#include <vector>
#include "RaceTrackComponent.h"

class RaceTrack: public RaceTrackComponent
{
    private:
    /**
     * contains the components of the track
     */
    vector<RaceTrackComponent*> components;
    /**
     * component ID
     */
    int RaceTrackID;
    /**
     * to keep track of component ID
     */
    static int trackNumber;
public:
    /**
     * constructor calls parent constructor
     */
    RaceTrack():RaceTrackComponent(){RaceTrackID=trackNumber++;
 };
    /**
     * starts iteration of printing the race track
     */
    virtual void print()
    {
        vector<RaceTrackComponent*>::iterator it;
        for(it=components.begin();it!=components.end();it++)
        {
            (*it)->print();
        }
    };
    /**
     * implementation of adding racetrack component to the track
     * @param Ra
     */
    virtual void add(RaceTrackComponent* Ra)
    {
        components.push_back(Ra);
    }
    /**
     * destructor that deletes the racetrack parts
     */
    virtual ~RaceTrack(){
        vector<RaceTrackComponent*>:: iterator it;

        for (it = components.begin(); it != components.end(); ++it)
            delete *it;
    };
    /**
     * prints the race track parts nicely
     */
    void show(){
        string star="==========================================\n";
            
        cout<<"Race Track: " +to_string(getRaceTrackID())+"\n"
            <<star;
        print();
        cout<<star;
    }

    void moveCar(Car* _car,int rt)
    {
        components[rt]->addCar(_car);
    }

    /**
     * @return the RacetrackID
     */
    int getRaceTrackID(){ return RaceTrackID;};

    /**
     * returns the number of track components in the track
     * @return
     */
    int getNumComponents(){ return components.size();};

    /**
     * adds all the cars to the track part
     * @param _car
     * @param rt
     */
    void addAllCars(vector<Car*> _car,int rt)
    {
        for(int i=0;i<_car.size();i++)
        {
            components[rt]->addCar(_car[i]);
        }
    }

    /**
     * removes all the cars from the race track component
     * @param _car
     * @param rt
     */
    void removeAllCars(vector<Car*>_car, int rt)
    {
        for(int i=0;i<_car.size();i++)
        {
            components[rt]->removeCar(_car[i]);
        }
    }

    /**
     * returns all the cars as a wector
     * @param rt
     * @return car vector
     */
    vector<Car*> getAllCars(int rt)
    {
        return components[rt]->getCars();
    }
    /**
     * empty implementation of abstract class
     * @param v
     */
    virtual void accept(Decider* v){}

    /**
     * element accepts the visitor
     * @param v
     * @param rt
     */
    void makeAccept(Decider* v,int rt){
        components[rt]->accept(v);
    }
    /**
     * adds the time onto the car
     */
    virtual void addTime(){

    }
};

#endif

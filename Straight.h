/**
 *  @author Israel Sekhwela
 *  @file Straight.h
 *  @class Straight
 *  @brief Leaf for Composite design pattern
 */

#ifndef STRAIGHT_H
#define STRAIGHT_H

#include "Decider.h"
#include "RaceTrackComponent.h"

class Straight:public RaceTrackComponent{
    private:
    /**
     * average time for completing a track component
     */
    int averageTime = 20;
    /**
     * average fuel used for the track part
     */
    int averageFuel = 10;
    /**
     * average tyre wear for the track part
     */
    int averageTyre = 10;
public:
    /**
    *  constructor calls RaceTrackComponent and sets description
    */
    Straight():RaceTrackComponent(){
        setDescription("Straight");
    }
    /**
     * destructor
     */
    virtual ~Straight(){

    };
    /**
    * implentation of add function, used by decorator
    * @param R
    */
    virtual void add(RaceTrackComponent*R){

    };
    /**
    * prints the description of the race track component /with decorators if it has
    */
    virtual void print(){ if(decorate==0)
            cout<<getDescription()+"\n";
        else
            cout<<getDescription()+"\tWITH ADDED: "+getDecorator()+"\n";
    };
    /**
     * returns the average time for the track
     * @return
     */
    int getAverageTime(){ return averageTime;};
    /**
     * accepts the visitor to go to the correct part of the visitor
     * @param v
     */
    virtual void accept(Decider* v)
    {
        v->visit(this);
    }
    /**
    *adds the time and fuel and tyre conditions to the car
    */
    virtual void addTime()
    {
        double driver;
        double fuel;
        double tyre;
        for(int i =0;i<cars.size();i++)
        {
            if(cars[i]->getDriver()!=NULL)
            {

                driver=cars[i]->getDriver()->getDriverAbilty();
                fuel= cars[i]->getDriver()->getFuelAbilty();
                tyre=cars[i]->getDriver()->getTyreAbilty();

            } else
            {
                driver=1;
                fuel=1;
                tyre=1;
            }
            cars[i]->setTrackTime(cars[i]->getTrackTime()+(int)(getAverageTime()*driver+0.5));
            cars[i]->setCarFuel(cars[i]->getCarFuel()-(int)(averageFuel*fuel+0.5));
        }
    }
};

#endif

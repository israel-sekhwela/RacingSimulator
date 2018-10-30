/**
 *  @author Israel Sekhwela
 *  @file State.h
 *  @class State
 */


#ifndef STATE_H
#define STATE_H

#include "Car.h"

class State {
public:

    /**
     * Change car to ready state
     * @param car
     */
    virtual void ready(Car* car){
        cout << "Car "<<car->getCarID()<<" State: Ready!\n";
    };

    /**
     * Change car to racing state
     * @param car
     */
    virtual void racing(Car* car){
        cout << "Car "<<car->getCarID()<<" State: Racing!\n";
    };

    /**
     * Change car to stopped state
     * @param car
     */
    virtual void stopped(Car* car){
        cout << "Car "<<car->getCarID()<<" State: Stopped!\n";
    };

    /**
     * Print the current state to the screen
     * @return
     */
    virtual string toString() = 0;
};

class Ready : public State{
    void racing(Car* car);
    void stopped(Car* car);
    string toString(){
        return "Ready\n";
    };
};

class Racing : public State{
    void ready(Car* car);
    void stopped(Car* car);
    string toString(){
        return "Racing\n";
    };
};

class Stopped : public State{
    void ready(Car* car);
    void racing(Car* car);
    string toString(){
        return "Stopped \n";
    };
};


#endif

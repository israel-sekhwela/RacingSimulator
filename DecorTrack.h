/**
 *  @authors Israel Sekhwela
 *  @file DecorTrack.h
 *  @class DecorTrack
 *  @brief Abstract Decorator for Decorator design pattern
 */

#ifndef DecorTrack_H
#define DecorTrack_H

#include "RaceTrackComponent.h"

class DecorTrack: public RaceTrackComponent
{
public:
    /**
     * constructor calls parent constructor
     */
    DecorTrack():RaceTrackComponent(){

    };
    /**
     * destuctor
     */
    ~DecorTrack(){

    };
    /**
     * empty implementation of print
     */
    virtual void print(){

    };
    /**
     *  empty implementation of add
     */
    virtual void add(RaceTrackComponent*){

    }
    /**
     * empty implementation of add time
     */
    virtual void addTime(){

    };
    /**
     * empty implementation of accept
     * @param v
     */
    virtual void accept(Decider* v){

    };
};

#endif

/**
 *  @author Israel Sekhwela
 *  @file Team.h
 *  @class Team
 */

#ifndef TEAM_H
#define TEAM_H

#include "PitStop.h"

class Team : public PitStop{
public:
    /**
     * default constructor for when a team is created, calls pitstop constructor
     * @param name_ the name of the team
     */
    Team(string name);

    /**
     * Function to get the car stats
    */
    virtual void getCarStats();
};


#endif

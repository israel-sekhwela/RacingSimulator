/**
 *  @author Israel Sekhwela
 *  @file PitStop.h
 *  @class PitStop
 */

#ifndef PITSTOP_H
#define PITSTOP_H

#include "PitCrew.h"

using namespace std;

class PitStop {
private:
    /**
     * @brief vector to hold the crewMembers for a team/pitstop
     */
    vector<PitCrew*> pitCrew;

    /**
     * @brief pointer to hold the manager for a team/pitstop
     */
    PitCrew* manager;

    /**
     * @brief pointer to hold the car for a team/pitstop
     */
    Car* car;

    int numMembers;

    /**
     * @brief bool array to see if there is any problems for all the tyres
     */
    bool* tyreCondition;

    /**
     * @brief bool to see if the fuel level is too low
     */
    bool fuelLevel;

    /**
     * @brief bool to see if the total amount of damage is too high
     */
    bool damage;

    /**
     * @brief name of the team
     */
    string name;
public:
    /**
     * default constructor for a pitstop
     * @param name of the team/pitstop
     */
    PitStop(string name);

    /**
     * destructor for the pitstop class, also detaches all members from the pitcrew vector
     */
    ~PitStop();

    /**
     * function for adding PitCrew members to the team/pitstop
     * @param member added to the pitcrew vector
     * */
    void attach(PitCrew* member);

    /**
    * function for adding PitCrew manager to the team/pitstop
    * @param manager added to the pitcrew vector
    */
    void attachManager(PitCrew* manager);

    /**
     * function for adding PitCrew members to the team/pitstop
     * @param member added to the pitcrew vector
     */
    void detach(PitCrew* member);

    /**
     * function that will notify the manager if the condition of the car changed
     * @param index the index of the car
     */
    void notify();

    /**
     * function that sets the condtion for all the tyres to true or false depending if they need change or not
     * @param status a bool array describing the status of each car
     */
    void setTyreCondition(bool* status);

    /**
     * function that sets the condition of the fuel level of a car depending if it needs to be filled or not
     * @param status a bool describing the status of the fuel level
     */
    void setFuelLevel(bool status);

    /**
     * function that sets the condition of the cars damage depending if needs to be repaired or not
     * @param status a bool describing the status of the damage of the car
     */
    void setDamage(bool status);

    /**
     * function that adds a new car to the cars vector for a specific team
     * @param car to be added
     */
    virtual void addCar(Car* car);

    /**
     * function that gets a car from the cars vector for a specific team
     */
    virtual Car* getCar();

    /**
     * function that gets the manager from the cars vector for a specific team
     */
    PitCrew* getManager();

    /**
     * function that gets the member with the index sent through
     * @param index
     * @return
     */
    PitCrew* getMember(int index){
        return pitCrew[index];
    };

    /**
     * function to get the number of members in the team
     * @return
     */
    int getNumMembers(){
        return numMembers;
    };

    /**
     * function that lists all the cars in the cars vector for the team
     * @return a string with all the cars
     */
    string showCar();

    /**
     * function that gets the managers of the team
     * @return a description of the manager
     */
    string showManager();

    /**
     * function that gets the crew of the team
     * @return a description of the crew
     */
    string showCrew();

    /**
     * Abstract method to get the car stats
     */
    virtual void getCarStats() = 0;

    /**
     * getter function to return the name of the team/pitstop
     * @return name of the team/pitstop
     */
    string getName();

    /**
     * function to print the team in detail to see who is in the team
     * @return string description of the team
     */
    string toString();
};


#endif

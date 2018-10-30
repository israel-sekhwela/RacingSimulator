/**
 *  @author Israel Sekhwela
 *  @file ConcreteRaceManager.h
 *  @class ConcreteRaceManager
 *  @brief concrete Observer in observer pattern
 */
#ifndef CONCRETERACEMANAGER_H
#define CONCRETERACEMANAGER_H

#include "RaceManager.h"
#include "Car.h"
#include "Decider.h"
#include "ConcreteDecider.h"
#include <vector>
#include <unistd.h>
#include <limits>

using namespace std;
class ConcreteRaceManager: public RaceManager
{
private:
    /**
     *  vector of cars for the race
     */
    vector<Car*> cars;
    /**
     *  the racetrack for the cars
     */
    RaceTrackComponent* RaceTrack;
    /**
     *  the current lap
     */
    int lapCount;
    /**
     *  the max number of laps
     */
    int LapMax=1;
    /**
     *  the size of the race track
     */
    int racetrackSize;
    /**
     * the visitor that visits each track component
     */
    Decider* raceVisitor;
public:
    /**
     * Moves all cars to starting point of track and sets the times to 0
     */
    virtual void readyRace(){
        if(cars.size()==0){
            cout<<"\nThere are no cars to race. Please select a car to race on the race track.\n";
            return;
        }
        for (int i=0; i<cars.size(); i++){
            cars[i]->setLap(0);
            cars[i]->setTrackPart(0);
            cars[i]->setTrackTime(0);
            cars[i]->ready();
            RaceTrack->moveCar(cars[i],0);
        }
        cout<<"Cars Are Ready to race!\n";
        lapCount=0;

    }
    /**
     * starts to move the cars along the racetrack
     */
    virtual void startRace(){
        if(cars.size()==0){
            return;
        }
        raceVisitor= new ConcreteDecider();
         cout<<"Choose Laps 1-25: ";
        cin>>LapMax;
        racetrackSize=RaceTrack->getNumComponents();
        cout<<endl;
        cout<<"Press ENTER to proceed....\n";
        fgetc(stdin);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for(int i =3;i>=1;i--){
            cout<<to_string(i)<<endl;
            usleep(1000000);
        }

        for(int k=0;k<cars.size();k++){
            cars[k]->racing();
        }
        RaceTrack->removeAllCars(cars,0);
        cout<<"RACE IS STARTING....!\n\n";
        usleep(1000000);
        for(lapCount=1;lapCount<=LapMax;lapCount++){
            for(int i =0;i<racetrackSize;i++){
                RaceTrack->addAllCars(cars,i);
                RaceTrack->makeAccept(raceVisitor,i);
                RaceTrack->removeAllCars(cars,i);
            }
            cout<<"LAP: "+to_string(lapCount)+" ended.\n";
            printLeaderBoard();
            usleep(1000000);

        }
        stopRace();

    }
    /**
     * announces when the race is finished and prints the final leaderboard
     */
    virtual void stopRace(){
        cout<<"\nAll race laps completed!\n";
        cout<<"Results:\n";
        printLeaderBoard();

    }
    /**
     * pauses the race
     * @param numComponent
     */
    virtual void pauseRace(int numComponent)
    {
        cout<<"Race is now Paused\n";
    }
    /**
     * resumes the race according to where it left
     * @param numComponent
     */
    virtual void resumeRace(int numComponent)
    {
        cout<<"Race will now continue\n";

        for(int i =numComponent;i<racetrackSize;i++)
        {
            RaceTrack->addAllCars(cars,i);
            RaceTrack->makeAccept(raceVisitor,i);
            RaceTrack->removeAllCars(cars,i);
        }
        cout<<"LAP: "+to_string(lapCount)+" ended.\n";
        printLeaderBoard();
        usleep(1000000);
        lapCount++;


        for(lapCount=lapCount;lapCount<=LapMax;lapCount++)
        {
            for(int i =0;i<racetrackSize;i++)
            {
                RaceTrack->addAllCars(cars,i);
                RaceTrack->makeAccept(raceVisitor,i);
                RaceTrack->removeAllCars(cars,i);
            }
            cout<<"LAP: "+to_string(lapCount)+" ended.\n";
            printLeaderBoard();
            usleep(1000000);

        }
        stopRace();
    }
    /**
     * prints the cars in order according to track times
     */
    virtual void printLeaderBoard()
    {
        if(cars.size()==0){
            return;
        }
       string stars="==========================================\n";
        int carIDs [cars.size()];
        int carTimes[cars.size()];
        int time;
        int id;
        for (int i=0; i<cars.size(); i++)
        {
            time=cars[i]->getTrackTime();
            id = cars[i]->getCarID();
            carIDs[i]=id;
            carTimes[i]=time;
        }
        int n=cars.size();
        int i, j;
        for (i = 0; i < n-1; i++)
        {
            // Last i elements are already in place
            for (j = 0; j < n-i-1; j++)
                if (carTimes[j] > carTimes[j+1])
                {
                    int temp;
                    temp= carTimes[j+1];
                    carTimes[j+1]=carTimes[j];
                    carTimes[j]=temp;
                    temp= carIDs[j+1];
                    carIDs[j+1]=carIDs[j];
                    carIDs[j]=temp;
                }
        }

        string output="\nLeader Board\n";
        output+=stars;

        for(int k=0;k<cars.size();k++)
        {
            for(int h=0;h<cars.size();h++)
            {
                if(carTimes[k]==cars[h]->getTrackTime()&&carIDs[k]==cars[h]->getCarID())
                {
                    output+=getCarInfo(cars[h]);
                }
            }
        }
        output+=stars;
        cout<<output;
    }
    /**
     * gets the car info and returns a string
     * @param _car
     * @return
     */
    string getCarInfo(Car*_car){
        string r= "Car: "+to_string(_car->getCarID()+1)+" \t\tTime: "+to_string(_car->getTrackTime())+" Seconds\n";
        return r;
    }
    /**
     *add cars to the race manager
     * @param _cars
     */
    virtual void addCars(vector<Car*> _cars){
        if(_cars.size()==0){
            cout<<"No cars added to the track.\n";
            return;
        }
        for (int i=0; i<_cars.size(); i++){
            cars.push_back(_cars[i]);
        }
        cout<<"Cars added to the Race Track.\n";
    }
    /**
     * adds the race
     * @param raceTrackComponent
     */
    virtual void addRacetrack(RaceTrackComponent* raceTrackComponent)
    {
        RaceTrack=raceTrackComponent;
    }
    /**
     *  sets the max amount of laps
     * @param i
     */
    void setLapMax(int i){
        LapMax=i;
    };
    /**
     *  returns the max laps
     * @return
     */
    int getLapMax(){ 
        return LapMax;
    };
    /**
     *  sets the lap currently on
     * @param i
     */
    void setLapCount(int i){
        lapCount=i;
    };
    /**
     *  returns the lap
     * @return
     */
    int getLap(){ 
        return lapCount;
    };
};

#endif

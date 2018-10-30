#include <iostream>

#include "includes.h"

int main() {
    srand(time(NULL));
    int choice;

    cout<<"\n====================== COS 214 The Racing Simulation Project ======================\n";
    
    Facade* facade = new Facade();
    while(choice!=5){

        cout<<"\n1:Construct a Team\n";
        cout<<"2:Construct a Race Track\n";
        cout<<"3:Register a car\n";
        cout<<"4:Start a race\n";
        cout<<"5:Quit\n\n";
        cout<<"Please select only from 1-5: ";


        cin>>choice;
        cout<<endl;

        if(choice == 1){
            facade->createTeam();
        }else
        if (choice == 2){
            facade->createCustomeRacetrack();
        }else
        if (choice == 3){
            facade->registerCar();
        }else
        if (choice == 4){
            facade->StartRace();
        }
    }

    return (0);
}
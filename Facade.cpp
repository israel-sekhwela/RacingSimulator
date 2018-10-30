#include <limits>
#include "Facade.h"

Facade::Facade() {
    raceManager = new ConcreteRaceManager();
    registratcionManager= new ConcreteRegistrationManager();
    Factories = new CarFactory *[3];
    Factories[0] = new GoKartFactory();
    Factories[1] = new RoadsterFactory();
    Factories[2] = new FormulaOneFactory();
}

PitStop *Facade::createTeam() {
    int choice=-1;
    cout<<"\n====================== Team Creation ======================\n";
    string name;
    cout<<"Enter Team name: ";
    cin>>name;

    cout << "\nTeam chosen: " << name << endl;
    while(choice<0||choice>1)
    {
        cout<<"\n1: Construct a new car\n";
        cout<<"2: Make a copy of a car\n\n";
        cout<<"Please select only from 1-2: ";
        cin>>choice;
    }
    Car* car;
    if(choice==1){
        car=createCustomCar();
    }
    else{
        car=copyCar();
    }
    cout<<"Lets Finish Making your team! Give me a second to get everything together!\n";
    usleep(3000000);
    Mediator* teamMediator = new ConcreteMediator();
    PitStop* team = new Team(name);
    team->addCar(car);
    team->attachManager(new Manager(teamMediator, team->getCar()));
    team->attach(new Refueller(teamMediator, team->getCar()));
    team->attach(new Mechanic(teamMediator, team->getCar()));
    for (int i = 0; i < 4; ++i) {
        team->attach(new TyreChanger(teamMediator, i, team->getCar()));
    }

    for (int i = 0; i < team->getNumMembers(); ++i){
        teamMediator->addMember(team->getMember(i));
    }
    teamMediator->addMember(team->getManager());

    car->setManager(team->getManager());
    car->setTeam(team);
    cout <<"Here is your Team!\n"<< team->toString()<<endl;
    return team;
}

Car *Facade::createCustomCar() {
    int carSelect;
    int carType;
    int decorateSelect=-1;
    Car* car;
    cout<<"\n====================== Construnction of a new Vehicle ======================\n";
    while(true)
    {
        cout<<"1:Go Kart\n2:Roadster\n3:Formula One\n\n";
        cout<<"Please select only from 1-3: ";
        cin>>carSelect;
        if(carSelect>=0&& carSelect<=3)
        {
            break;
        }
    }
    while(true)
    {
        cout<<"\nSelect type of vehicle from the list below:\n";
        cout<<"1:Electric\n2:Sport\n3:Standard\n\n";
        cout<<"Please select only from 1-3: ";
        cin>>carType;
        if(carType>=0&& carType<=3)
        {
            break;
        }
    }
    if(carType==0)
    {
        car=Factories[carSelect]->produceElectric();
    }else if(carType==1)
    {
        car= Factories[carSelect]->produceSports();
    }else if (carType==2)
    {
        car= Factories[carSelect]->produceStandard();
    }

    while(decorateSelect!=6){
        cout<<"\n=========== Car Customization ===========\n";
        cout<<"1:SAFlagVinly \n";
        cout<<"2:BlueLineVinyl\n";
        cout<<"3:Nitro x4 [last longer]\n";
        cout<<"4:Slick Tyres\n";
        cout<<"5:Spoiler\n";
        cout<<"6:Finish\n\n";
        cout<<"Please select only from 1-6:";
        
        cin>>decorateSelect;
        if(decorateSelect==1){
            // car->add(new SAFlagVinly());
        }else 
        if(decorateSelect==2){
            // car->add(new BlueLineVinyl());
        }else
        if (decorateSelect==3){
            car->add(new Nitro(car));
        }else 
        if (decorateSelect==4){
            car->add(new Slick(car));
        } else 
        if (decorateSelect==5){
            car->add(new Spoiler(car));
        }
    }

    cout<<"\n=========== Car Details ===========\n"<<car->toString()<<endl;
    cout<<"\nNext step, create a driver.\n";
    car->setDriver(createDriver());
    cout<<"Your car will be added to the list of cars!\n";
    cars.push_back(car);
    registerCar(car);
    return car;

}

RaceTrackComponent *Facade::createCustomeRacetrack() {
    cout<<"\n====================== Track Creation ======================\n";
    cout<<"(Your first piece will be the start line and last piece will be finish line)\n";
    RaceTrackComponent* raceTrack = new RaceTrack();
    int finish=-1;
    int count=0;
    int piece=-1;
    bool noMore=false;
    RaceTrackComponent* add;
    while(finish!=3) {
        while (true)
        {
            cout << "\n=========== Part Selection ===========\n";
            cout << "0:Straight\n1:Left Eighth\n2:Right Eighth\n3:Left Peel On\n4:Left Peel off\n5:Right Peel On\n6:Right Peel Off\n\n";
            cout << "Please select the piece you want to add (0-6) > ";
            cin >> piece;
            if (piece == 0) {
                add= new Straight();
                break;
            } else if (piece == 1) {
                add= new LeftEighth();
                break;
            } else if (piece == 2) {
                add= new RightEighth();
                break;
            } else if (piece == 3) {
                add= new LeftPeelOn();
                break;
            } else if (piece == 4) {
                add= new LeftPeelOff();
                break;
            } else if (piece == 5) {
                add= new RightPeelOn();
                break;
            } else if (piece == 6) {
                add= new RightPeelOff();
                break;
            }
        }
        while(true)
        {
            if(count==0)
            {
                add->decorateTrack(new StartDecorator());
                count++;
                break;
            } else
            {
                cout << "\n=========== Part Decoration ===========\n";
                cout << "0:Nothing\n1:PitStop\n2:SandPits\n3:Finish Line\n\n";
                cout << "Please select the decoration you want to add (0-3) > ";
                cin>>finish;
                if (finish == 0) {
                    break;
                } else if (finish == 1) {
                    add->decorateTrack(new PitStopDecorator());
                    break;
                } else if (finish == 2) {
                    add->decorateTrack(new SandPitsDecorator());
                    break;
                } else if (finish == 3) {
                    add->decorateTrack(new FinishDecorator());
                    break;
                }
            }
        }
        raceTrack->add(add);
    }
    cout<<"\n*********** Here is you RaceTrack ***********\n";
    raceTrack->show();
    cout<<"Your racetrack will be added to the racetracks!\n";
    racetracks.push_back(raceTrack);
    cout<<"We will now register your racetrack to the registration manager!\n";
    registratcionManager->addTrack(raceTrack);
    return raceTrack;
}

void Facade::registerCar(Car *c) {
    int tn;
    int again=-1;
    cout<<"\n=========== Car Registration ===========\n";
    while(again!=1)
    {
        cout<<"Register Track from 1-5: ";
        cin>>tn;
        if(tn>=0)
        registratcionManager->addCar(c,tn);
        cout<<"\n0: Register car for another track\n1: Done\n";
        cout<<"Please select only from 0-1: ";
        
        cin>>again;
    }
}

void Facade::registerTrack(RaceTrackComponent *rt) {
    registratcionManager->addTrack(rt);
}

bool Facade::prepRace() {
    cout<<"\n====================== Race Preparation ======================\n";
    int trackNum;
    RaceTrackComponent* test=NULL;
    while(test==NULL)
    {
        cout<<"\nWhich track would you like to race? (enter -1 to go back) >";
        cin>>trackNum;
        if(trackNum==-1)
            return false;
        test=registratcionManager->getTrack(trackNum);
    }
    raceManager->addRacetrack(test);
    raceManager->addCars(registratcionManager->getCars(trackNum));
    raceManager->readyRace();
    raceManager->printLeaderBoard();
    return true;

}

void Facade::StartRace() {

    if(!prepRace())
    {
        return;
        cout<<"Returning to the main Menu!\n";
    }

    cout<<"\n====================== Race Start ======================\n";
    raceManager->startRace();
}

Driver *Facade::createDriver() {
    int num;
    while(true)
    {
        cout<<"\n====================== Driver Selection ======================\n";
        cout<<"1:Passive Driver\n2:Average Driver\n3:Aggressive Driver\n\n";
        cout<<"Please select only from 1-3: ";
        cin>>num;
        if(num==1)
        {
            cout<<"Choice: Passive Driver\n";
            return new PassiveDriver();
        }
        else if (num==2)
        {
            cout<<"Choice: Average Driver\n";
            return new AverageDriver();
        }
        else if (num==3)
        {
            cout<<"Choice: Aggressive Driver\n";
            return new AggressiveDriver();
        }
    }
}

Facade::~Facade() {

    for (int i = 0; i < 3; i++)
    {
        delete Factories[i];
    }
    delete []Factories;
}

Car *Facade::copyCar() {
    cout<<"\n====================== Car Copying ======================\n";
    if(cars.size()==0)
    {
        cout<<"There are currently no cars available to copy, we will pass you onto car creation!\n";
        return createCustomCar();
    } else
    {
        int numcars= cars.size();
        int carNum=-1;
        int type=-1;
        for(int i=0;i<numcars;i++)
        {
            cout<<"Car: "<<to_string(i)<<endl;
            cout<<cars[i]->toString()<<endl;
        }
        while(carNum<0||carNum>=numcars)
        {
            cout<<"\nPlease Select which car you would like to clone (0-"<<to_string(numcars-1)<<") > ";
            cin>>carNum;
            cout<<endl;
        }
        while(type<0|| type>1)
        {
            cout<<"\n0:Clone Base Car\n1:Clone Upgraded Car\n";
            cout<<"\nPlease Select the type of clone you would like to make (0-1) > ";

            cin>>type;
            cout<<endl;
        }
        int decorateSelect=-1;
        Car* car= cars[carNum]->clone(type);
        while(decorateSelect!=6)
        {
            cout<<"\n=========== Car Customization(s) ===========\n";
            cout<<"1:SAFlagVinly\n";
            cout<<"2:BlueLineVinyl\n";
            cout<<"3:Nitro\n";
            cout<<"4:Slick Tyres\n";
            cout<<"5:Spoiler\n";
            cout<<"6:Finish\n\n";
            cout<<"Please select the Decoration you would like to add to your car (0-5) > ";
            cin>>decorateSelect;
            if(decorateSelect==1){
                // car->add(new SAFlagVinly());
            }else 
            if(decorateSelect==2){
                // car->add(new BlueLineVinyl());
            } else 
            if (decorateSelect==3){
                car->add(new Nitro(car));
            } else 
            if (decorateSelect==4){
                car->add(new Slick(car));
            } else if (decorateSelect==5){
                car->add(new Spoiler(car));
            }
        }
        cout<<"\n*********** Here is your copied car ***********\n"<<car->toString()<<endl;
        cout<<"\nWe will now take you to create your driver for the car!\n";
        car->setDriver(createDriver());
        cout<<"Your car will be added to the list of cars!\n";
        cars.push_back(car);
        registerCar(car);
        return car;
    }
}

void Facade::registerCar() {
    int numcars;
    if(cars.size()==0)
    {
        cout<<"\nThere are No cars to register, please create a car before registering!\n";
        return;
    }
    cout<<"\n====================== Car Registering ======================\n";
    numcars= cars.size();
    int carNum=-1;
    for(int i=0;i<numcars;i++)
    {
        cout<<"Car: "<<to_string(i)<<endl;
        cout<<cars[i]->toString()<<endl;
    }
    while(carNum<0||carNum>=numcars)
    {
        cout<<"\nPlease Select which car you would like to Register (0-"<<to_string(numcars-1)<<") > ";
        cin>>carNum;
        cout<<endl;
    }
    registerCar(cars[carNum]);

}

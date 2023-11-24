#include <iostream>
#include <string>
#include <fstream>


class Pet
{
    public:
    Pet(std::string Name , int Hunger , int Happiness , int Energy);
    ~Pet();

    public:
    std::string Name;
    std::string Species;
    int Age             = 0;
    int Max_Age;
    int Age_Factor      = (this -> Age)*5;
    int Hunger;
    int Max_Hunger      = 100;
    int Happiness;
    int Max_Happiness   = 100;
    int Energy;
    int Max_Energy      = 100;
    int Counter         = 0;

    public:
    void Feed();
    void Play();
    void Rest();
    void Query();
    void Time_Skip();

    public:
    bool Species_selection(std::string& Entered_species);
    bool Interaction();
    void Save();
    void Quit();
};

Pet::Pet(std::string Name, int Hunger, int Happiness, int Energy)
{
    this -> Name        = Name;
    this -> Hunger      = Hunger;
    this -> Happiness   = Happiness;
    this -> Energy      = Energy;
}

Pet::~Pet()
{
    // Class Destructor
}

void Pet::Feed()
{
    if (this -> Hunger <= 10) std::cout << this -> Name << " is not feeling hungry right now." << std::endl;
    else
    {
        this -> Hunger = 0;
        this -> Happiness = (this -> Happiness > this -> Max_Happiness - 20) ? this -> Max_Happiness : this -> Happiness + 20;
        this -> Energy = (0 > this -> Energy - 20) ? 0 : this -> Energy - 20;
        std::cout << this -> Name << " had food and is rolling on floor, lol.\n" << std::endl;
    }
}

void Pet::Play()
{
    if (this -> Energy <= 30)       std::cout << this -> Name << " is tired right now to play with you.\n" << std::endl;
    else if (this -> Hunger > this -> Max_Hunger - 30)  std::cout << this -> Name << " is too hungry to play with you.\n" << std::endl;
    else
    {
        this -> Energy = (0 >= this -> Energy - 50) ? 0 : this -> Energy - 50;
        this -> Hunger += 30;
        this -> Happiness = (this -> Happiness > this -> Max_Happiness - 50) ? this -> Max_Happiness : this -> Happiness + 50;
        std::cout << this -> Name << " had fun playing with you!\n" << std::endl;

        this -> Counter +=1;
    }
}

void Pet::Rest()
{
    if (this -> Energy >= 50)       std::cout << this -> Name << " is rocking and don't need sleep!\n" << std::endl;
    else if (this -> Hunger >= 80)  std::cout << this -> Name << " is too hungry and need food before going to sleep...\n" << std::endl;
    else
    {
        this -> Energy = Max_Energy;
        this -> Happiness = (this -> Happiness > 30) ? this -> Happiness - 30 : 0;
        std::cout << this -> Name << " had a peaceful sleep... and is now full of energy!\n" << std::endl;

        this -> Counter +=1;
        Time_Skip();
    }
}

void Pet::Time_Skip()
{
    if (((this -> Counter)/5) - (this -> Age) > 0)
    {
        this -> Age += 1;
        this -> Max_Hunger -= Age_Factor;
        this -> Max_Happiness += Age_Factor;
        this -> Max_Energy -= Age_Factor;
        std::cout << "\n\tHappy Birthday " << this -> Name << "!!\n" << std::endl;
    }
}

void Pet::Query()
{
    std::cout << "Name:        " << this -> Name << std::endl;
    std::cout << "Species:     " << this -> Species << std::endl;
    std::cout << "Age:         " << this -> Age << std::endl;
    std::cout << "Hunger:      " << this -> Hunger << std::endl;
    std::cout << "Energy:      " << this -> Energy << std::endl;
    std::cout << "Happiness:   " << this -> Happiness << "\n" << std::endl;
}

bool Pet::Species_selection(std::string& Entered_species)
{
    if (Entered_species == "Capybara"    || Entered_species == "capybara")
    {
        this -> Species = "Capybara";
        this -> Max_Age = 6;
        return false;
    }
    else if (Entered_species == "Cat"    || Entered_species == "cat"){
        this -> Species = "Cat";
        this -> Max_Age = 12;
        return false;
    }
    else if (Entered_species == "Dog"    || Entered_species == "dog")
    {
        this -> Species = "Dog";
        this -> Max_Age = 12;
        return false;
    }
    else if (Entered_species == "Duck"   || Entered_species == "duck")
    {
        this -> Species = "Duck";
        this -> Max_Age = 8;
        return false;
    }
    else if (Entered_species == "Parrot" || Entered_species == "parrot")
    {
        this -> Species = "Parrot";
        this -> Max_Age = 50;
        return false;
    }
    else if (Entered_species == "Rabbit" || Entered_species == "rabbit")
    {
        this -> Species = "Rabbit";
        this -> Max_Age = 8;
        return false;
    }
    else{
        std::cout << "Please enter from the species provided." << std::endl;
        return true;
    }
}

bool Pet::Interaction()
{
    std::string *Command = new std::string;
    std::cin >> *Command;
    if      (*Command == "Feed"  || *Command == "feed") this -> Feed();
    else if (*Command == "Play"  || *Command == "play") this -> Play();
    else if (*Command == "Rest"  || *Command == "rest") this -> Rest();
    else if (*Command == "Stats" || *Command == "stats") this -> Query();
    else if (*Command == "Stats" || *Command == "stats") this -> Query();
    else if (*Command == "Save"  || *Command == "save") this -> Save();
    else if (*Command == "Quit"  || *Command == "quit") this -> Quit();
    else std::cout << "Enter a valid command.\n" << std::endl;

    if (this -> Age == Max_Age)
    {
        std::cout << "It is dipleasure to announce that your pet had passed away..." << std::endl;
        if      (this -> Happiness > 70) std::cout << "But, it seems he/she was very happy with the relationship and enjoyed your company till the very end. You were a good master, no more like family to him/her.\n" << std::endl;
        else if (this -> Happiness > 30 && this -> Happiness <=70) std::cout << "But, it seems he/she was pleased with the relationship till the very end. You were a good master.\n" << std::endl;
        else if (this -> Happiness <= 30) std::cout << "But, it seems he/she was not very happy with the relationship. If only you had treated him/her better.\n" << std::endl;
        return false;
    }

    delete Command;

    return true;
}

void Pet::Save()
{
    std::ofstream data("data.txt");
    data << this -> Name << std::endl;
    data << this -> Species << std::endl;
    data << this -> Age << std::endl;
    data << this -> Max_Age << std::endl;
    data << this -> Hunger << std::endl;
    data << this -> Max_Hunger << std::endl;
    data << this -> Happiness << std::endl;
    data << this -> Max_Happiness << std::endl;
    data << this -> Energy << std::endl;
    data << this -> Max_Energy << std::endl;
    data << this -> Counter;

    std::cout << "Data saved successfully.\n" << std::endl;
}

void Pet::Quit()
{
    std::cout << "Do you want to save the pet state before quitting?" << std::endl;
    std::string *quit_save;
    std::cin >> *quit_save;

    if      (*quit_save == "Yes"  || *quit_save == "yes" || *quit_save == "Save" || *quit_save == "save")
    {
        this -> Save();
        exit(0);
    }
    else if (*quit_save == "No"   || *quit_save == "no"  || *quit_save == "Quit" || *quit_save == "quit")
    {
        exit(0);
    }
}

void New_Simulation()
{
    std::cout << "\nLet's start by choosing your Pet!\nHere is the list of available pet species:" << std::endl;
    std::cout <<"Capybara, Cat, Dog, Duck, Parrot, and Rabbit" << std::endl;
    std::string *temp_species = new std::string;
    std::cin >> *temp_species;

    std::string *temp_name = new std::string;
    std::cout << "Enter the name of your pet:" << std::endl;
    std::cin >> *temp_name;

    Pet MyPet(*temp_name, 50, 50, 50);
    if(MyPet.Species_selection(*temp_species)) return;
    delete temp_species;
    delete temp_name;

    std::cout << "\nNow, Interact with your pet and build a good relationship UwU.\nThese are the commands:" << std::endl;
    std::cout << "Feed\tFeeds the Pet\tHunger =0, Happiness +20" << std::endl;
    std::cout << "Play\tYou play with your pet\tEnergy -50, Hunger +30, Happiness +50" << std::endl;
    std::cout << "Rest\tPet rest and restores energy\tMaximum Energy, Happiness -30" << std::endl;
    std::cout << "Stats\tShows statistics of your pet, i.e. Name, Age, Hunger, Energy, Happiness" << std::endl;
    std::cout << "Save\tSaves current state of your pet externally and can be any time.\n" << std::endl;
    std::cout << "Quit\tExits the program...\n" << std::endl;
    std::cout << "Your pet will age with activities and time you spend with him.\tUnfortunately, Average Lives of different Pets will be Considered." << std::endl;

    std::cout << "\nSo, Start Interacting with your pet " << MyPet.Name << "!\n" << std::endl;
    while (MyPet.Interaction());

    MyPet.~Pet();
}

void Prev_Simulation()
{
    std::ifstream loaded_data("data.txt");
    if(loaded_data.good())
    {
        std::string Name, Species, Age, Max_Age, Hunger, Max_Hunger, Happiness, Max_Happiness, Energy, Max_Energy, Counter;
        std::getline(loaded_data, Name);
        std::getline(loaded_data, Species);
        std::getline(loaded_data, Age);
        std::getline(loaded_data, Max_Age);
        std::getline(loaded_data, Hunger);
        std::getline(loaded_data, Max_Hunger);
        std::getline(loaded_data, Happiness);
        std::getline(loaded_data, Max_Happiness);
        std::getline(loaded_data, Energy);
        std::getline(loaded_data, Max_Energy);
        std::getline(loaded_data, Counter);
        loaded_data.close();

        int temp_Age             = std::stoi(Age);
        int temp_Max_Age         = std::stoi(Max_Age);
        int temp_Hunger          = std::stoi(Hunger);
        int temp_Max_Hunger      = std::stoi(Max_Hunger);
        int temp_Happiness       = std::stoi(Happiness);
        int temp_Max_Happiness   = std::stoi(Max_Happiness);
        int temp_Energy          = std::stoi(Energy);
        int temp_Max_Energy      = std::stoi(Max_Energy);
        int temp_Counter         = std::stoi(Counter);

        Pet MyPet(Name, temp_Hunger, temp_Happiness, temp_Energy);
        MyPet.Species       = Species;
        MyPet.Age           = temp_Age;
        MyPet.Max_Age       = temp_Max_Age;
        MyPet.Max_Hunger    = temp_Max_Hunger;
        MyPet.Max_Happiness = temp_Max_Happiness;
        MyPet.Max_Energy    = temp_Max_Energy;
        MyPet.Counter       = temp_Counter;

        std::cout << "\nSo, Start Interacting with your pet " << MyPet.Name << "!\n" << std::endl;
        while (MyPet.Interaction());

        MyPet.~Pet();
    }
    
    else{
        std::cout << "No previous data found.\nStarting new simulation...\n" << std::endl;
        New_Simulation();
    }
}

int main()
{
    std::cout << "Welcome to Pet Simulator!\n" << std::endl;

    std::string *temp_cnf = new std::string;
    std::cout << "Do you want to load previous saved data?" << std::endl;
    std::cin >> *temp_cnf;

    if (*temp_cnf == "Y" || *temp_cnf == "y" || *temp_cnf == "Yes" || *temp_cnf == "yes" || *temp_cnf == "YES") Prev_Simulation();

    else if (*temp_cnf == "N" || *temp_cnf == "n" || *temp_cnf == "No" || *temp_cnf == "no" || *temp_cnf == "NO") New_Simulation();

    else std::cout << "Reply only in yes or no." << std::endl;

    delete temp_cnf;

    return 0;
}
#include <iostream>
#include <string>

class Character {
    
    
    public:
    Character(std::string name_, double ID_,
    double intelegience_,
    double speed_,
    double strength_) {
        
        
        name = name_;
        
        
        ID = ID_;
        
        
        intelegience = intelegience_;
        
        
        speed = speed_;
        
        
        strength = strength_;
        
        
        
    }
    
    void setID(double ID_) {
        
        ID = ID_;
        
        
    }
    
    void setIntelegience(double intelegience_) {
        
        intelegience = intelegience_;
        
        
    }
    
    void setSpeed(double speed_) {
        
        speed = speed_;
        
        
    }
    
    void setStrength(double strength_) {
        
        strength = strength_;
        
        
    }
    
    void setName(std::string name_) {
        
        name = name_;
        
        
    }
    
    double  getID() {
        
        return ID;
        
        
    }
    
    
    double getIntellegence() {
        
        return intelegience;
        
        
    }
    
    
    double getSpeed() {
        
        return speed;
        
        
    }
    
    
    double getStrength() {
        
        return strength;
        
        
    }
    
    
    std::string getName() {
        
        return name;
        
        
    }
    
    
    virtual std::string startNoise() = 0;
    
    
    protected:
    std::string name;
    
    
    double ID;
    
    
    double intelegience;
    
    
    double speed;
    
    
    double strength;
    
    
    
    
}
;



class Hero:public Character {
    
    
    public:
    Hero(std::string name_, double ID_,
    double intelegience_,
    double speed_,
    double strength_,
    int livesSaved_):
    Character(name_, ID_, intelegience_, speed_,
    strength_) {
        
        
        livesSaved = livesSaved_;
        
        
        
    }
    
    int getLivesSaved() {
        
        return livesSaved;
        
        
    }
    
    
    void setLivesSaved(int livesSaved_) {
        
        livesSaved = livesSaved_;
        
        
    }
    
    virtual std::string startNoise() {
        
        
        return "May the realm of my Victory enclose you!";
        
        
        
    }
    
    
    protected:
    int livesSaved;
    
    
    
}
;



class Enemy:public Character {
    
    
    public:
    Enemy(std::string name_, double ID_,
    double intelegience_,
    double speed_,
    double strength_, int heroesStopped_,
    
    std::string type_, bool mainiac_):
    Character(name_, ID_,
    intelegience_,
    speed_,
    strength_) {
        
        
        heroesStopped_ = heroesStopped_;
        
        type = type_;
        
        mainac = mainiac_;
        
        
        
    }
    
    void setHeroesStopped(int heroesStopped_) {
        
        heroesStopped = heroesStopped_;
        
        
    }
    
    void setType(std::string type_) {
        
        type = type_;
        
        
    }
    
    void setMainac(bool mainac_) {
        
        mainac = mainac_;
        
        
    }
    
    int  getHeroesStopped() {
        
        return heroesStopped;
        
        
    }
    
    
    std::string getType() {
        
        return type;
        
        
    }
    
    
    bool getMainac() {
        
        return mainac;
        
        
    }
    
    
    virtual std::string startNoise() {
        
        
        return "I Will ALWAYS CONQUER! Lie Beneath ME!";
        
        
        
    }
    
    
    protected:
    int heroesStopped;
    
    
    std::string type;
    
    
    bool mainac;
    
    
    
}
;




int
main()
{
    
    
    Hero Amanuel("Amanuel Bogale", 132, 97.32, 59.2, 77.33, 21);
    
    
    Enemy Sens("Sens Cueva", 21, 77.43, 95.32, 83.23, 11, "MAINIAC",
    true);
    
    
    
    Amanuel.setID(111);
    
    
    // Sens Upgrades his intellegience
    Sens.setIntelegience(88.2);
    
    
    // Amanuel Needs to work on speed...
    Amanuel.setSpeed(70.21);
    
    
    // Print Objects..
    Character * humans[2] = {
        
        
        &Amanuel,
        &Sens
        
    }
    ;
    
    
    for (int i = 0;
    i < 2;
    i++) {
        
        
        std::cout << "*** " << humans[i]->
        getName() << " ***" << std::
        endl
        <<"INTELLIEGENCE : " << humans[i]->
        getIntellegence() << std::endl
        <<"SPEED : " << humans[i]->
        getSpeed() << std::endl
        <<"ID : " << humans[i]->
        getID() << std::endl
        <<"STRENGTH : " << humans[i]->
        getStrength() << std::endl
        <<"START NOISE : " << humans[i]->
        startNoise() << std::endl;
        
        
        
    }
    
    return 0;
    
    
    
}

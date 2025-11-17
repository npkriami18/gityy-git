#include <bits/stdc++.h>
using namespace std;



// strategy interface for walk
class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot(){}
};

// concrete strategies for walk
class NormalWalk : public WalkableRobot{
public:
    void walk(){
        cout << " Walking normally" << endl;
    }
};

class NoWalk : public WalkableRobot{
public:
    void walk(){
        cout << " Not Walking " << endl;
    }
};


// strategy interface for talk
class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot(){}
};

// concrete strategies for talk
class NormalTalk : public TalkableRobot{
public:
    void talk(){
        cout << " Talking normally" << endl;
    }
};

class NoTalk : public TalkableRobot{
public:
    void talk(){
        cout << " Not Talking " << endl;
    }
};

// strategy interface for Fly
class FlyableRobot{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot(){}
};

// concrete strategies for Fly
class NormalFly : public FlyableRobot{
public:
    void fly(){
        cout << " Flying normally" << endl;
    }
};

class NoFly : public FlyableRobot{
public:
    void Fly(){
        cout << " Not Flying " << endl;
    }
};

class Robot{
protected:
    TalkableRobot* talkingBehaviour;
    WalkableRobot* walkingBehaviour;
    FlyableRobot* flyingBehaviour;
public:
    Robot(TalkableRobot* t, WalkableRobot* w, FlyableRobot* f){
        this->talkingBehaviour = t;
        this->walkingBehaviour = w;
        this->flyingBehaviour = f;
    }
    void walk() {
        walkingBehaviour->walk();
    }
    void talk(){
        talkingBehaviour->talk();
    }
    void fly(){
        flyingBehaviour->fly();
    }
    virtual void projection() = 0;
};

class CompanionRobot : public Robot{
public:
    CompanionRobot(TalkableRobot* t, WalkableRobot* w, FlyableRobot* f) : Robot(t, w, f){}

    void projection() override {
        cout << " Projection code of companion robot" << endl;
    }

};

class WorkingRobot : public Robot{
public:
    WorkingRobot(TalkableRobot* t, WalkableRobot* w, FlyableRobot* f) : Robot(t, w, f){}

    void projection() override {
        cout << " Projection code of working robot" << endl;
    }

};

int main(){
   
    // Client related code
    Robot* compRobot = new CompanionRobot(new NormalTalk(), new NormalWalk(), new NormalFly());
    Robot* workRobot = new WorkingRobot(new NoTalk(), new NormalWalk(), new NormalFly());

    cout << "following is activity of companion robot" << endl;
    compRobot->talk();
    compRobot->walk();
    compRobot->fly();
    compRobot->projection();
    cout << "following is activity of workRobot" << endl;
    workRobot->talk();
    workRobot->walk();
    workRobot->fly();
    workRobot->projection();

}
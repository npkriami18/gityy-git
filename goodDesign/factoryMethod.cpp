#include <bits/stdc++.h>
using namespace std;

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger(){}
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing basic burger " << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing standard burger " << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing Premium burger " << endl;
    }
};
class NBasicBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing Nbasic burger " << endl;
    }
};

class NStandardBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing Nstandard burger " << endl;
    }
};

class NPremiumBurger : public Burger {
public:
    void prepare() override {
        cout << " preparing NPremium burger " << endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class BurgerFactory1 : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if(type == "basic")
            return new BasicBurger(); 
        else if (type == "standard")
            return new StandardBurger();
        else if (type == "premium")
            return new PremiumBurger();
        else
            cout << " this burger is not available" << endl;
            return NULL;
    }
};

class BurgerFactory2 : public BurgerFactory{
public:
    Burger* createBurger(string& type) override {
        if(type == "nbasic")
            return new NBasicBurger(); 
        else if (type == "nstandard")
            return new NStandardBurger();
        else if (type == "npremium")
            return new NPremiumBurger();
        else
            cout << " this burger is not available" << endl;
            return NULL;
    }
};



int main(){
    
    BurgerFactory* factory1 = new BurgerFactory1();
    BurgerFactory* factory2 = new BurgerFactory2();
    string type = "basic";
    Burger* basicBurger = factory1->createBurger(type);
    type = "nbasic";
    Burger* nbasicBurger = factory2->createBurger(type);
    basicBurger->prepare();
    nbasicBurger->prepare();
    return 0;
}
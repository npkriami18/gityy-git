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

class BurgerFactory {
public:
    Burger* createBurger(string& type){
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



int main(){
    
    BurgerFactory* factory = new BurgerFactory();
    string type = "basic";
    Burger* basicBurger = factory->createBurger(type);
    basicBurger->prepare();
    return 0;
}
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

class Bread{
public:
    virtual void prepare() = 0;
    virtual ~Bread(){}
};

class BasicBread : public Bread {
public:
    void prepare() override {
        cout << " preparing basic bread " << endl;
    }
};

class StandardBread : public Bread {
public:
    void prepare() override {
        cout << " preparing standard bread " << endl;
    }
};

class PremiumBread : public Bread {
public:
    void prepare() override {
        cout << " preparing Premium bread " << endl;
    }
};
class NBasicBread : public Bread {
public:
    void prepare() override {
        cout << " preparing Nbasic bread " << endl;
    }
};

class NStandardBread : public Bread {
public:
    void prepare() override {
        cout << " preparing Nstandard bread " << endl;
    }
};

class NPremiumBread : public Bread {
public:
    void prepare() override {
        cout << " preparing NPremium bread " << endl;
    }
};

class Factory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual Bread* createBread(string& type) = 0;
};

class Factory1 : public Factory {
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
    Bread* createBread(string& type) override {
        if(type == "basic")
            return new BasicBread(); 
        else if (type == "standard")
            return new StandardBread();
        else if (type == "premium")
            return new PremiumBread();
        else
            cout << " this bread is not available" << endl;
            return NULL;
    }
};

class Factory2 : public Factory{
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
    Bread* createBread(string& type) override {
        if(type == "nbasic")
            return new NBasicBread(); 
        else if (type == "nstandard")
            return new NStandardBread();
        else if (type == "npremium")
            return new NPremiumBread();
        else
            cout << " this bread is not available" << endl;
            return NULL;
    }
};



int main(){
    
    Factory* factory1 = new Factory1();
    Factory* factory2 = new Factory2();
    string type = "basic";
    Burger* basicBurger = factory1->createBurger(type);
    Bread* basicBread = factory1->createBread(type);
    type = "nbasic";
    Burger* nbasicBurger = factory2->createBurger(type);
    Bread* nbasicBread = factory2->createBread(type);
    basicBurger->prepare();
    basicBread->prepare();
    nbasicBurger->prepare();
    nbasicBread->prepare();
    return 0;
}
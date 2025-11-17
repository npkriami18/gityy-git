#include <bits/stdc++.h>
using namespace std;

// class Singleton{
// public:
//     Singleton(){
//         cout << "Singleton constructor is called and new instance is created" << endl;
//     }
// };
class Singleton{

private:
    static Singleton* instance;
    static mutex mtx;
    Singleton(){
        cout << "Singleton constructor is called and new instance is created" << endl;
    }
public:
    static Singleton* getInstance(){
        if(instance == NULL){
            lock_guard<mutex> lock(mtx);
            if(instance == NULL)
            instance = new Singleton();
        }
        // lock_guard<mutex> lock(mtx);
        // if(instance == NULL){
        //     instance = new Singleton();
        // }
        return instance ;
    }
};

Singleton* Singleton::instance;
mutex Singleton::mtx;

int main(){

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1==s2) << endl;
    return 0;
}
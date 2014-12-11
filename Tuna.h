#ifndef TUNA_H
#define TUNA_H
#include "Cave.h"
#include "GameObject.h"
#include "Fish.h"
#include "Model.h"
#include <iostream>
#include "math.h"
using namespace std;

class Model;
class Tuna: public Fish {
public:
    Tuna(Model*);
    Tuna(Model*, int, Cave*);
    ~Tuna();
    
    double get_speed();
    void start_mating(Tuna*);
    bool update();
    void show_status();
    
    void do_mating(Tuna*);
    
private:
    int tuna_time;
    bool initiator;
};


#endif

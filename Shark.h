#ifndef SHARK_H
#define SHARK_H
#include <iostream>
#include "GameObject.h"
#include "Fish.h"
#include "Model.h"
#include "math.h"
using namespace std;

class Shark: public Fish {
public:
    Shark(Model*);
    Shark(Model*, int, CartPoint);
    ~Shark();
    
    double get_speed();
    void start_attack(Fish*);
    bool update();
    void show_status();
    
private:
    int attack_strength;
    double range;
    Fish* target;
    
};

#endif

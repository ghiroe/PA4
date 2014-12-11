#include "Shark.h"

Shark::Shark(Model* world): Fish('S', 20) {
    this->world = world;
    attack_strength = 2;
    range = 1;
    target = NULL;
}

Shark::Shark(Model* world, int in_id, CartPoint rand_loc): Fish('S', in_id, rand_loc, 20) {
    this->world = world;
    attack_strength = 2;
    range = 1;
    target = NULL;
}

Shark::~Shark() {}

double Shark::get_speed() {
    return (1/size) * energy * 8;
}


void Shark::start_attack(Fish* target) {
 //If the fish is in range of its destination, it sets its location to the destination
	if (fabs((target->get_location()).x - (this->get_location()).x) <= range &&
        fabs((target->get_location()).y - (this->get_location()).y) <= range) {
        this->target = target;
        cout << display_code << get_id() << ": Chomp!" << endl;
        target->get_bitten(attack_strength);
        state = 'a';
    }
    else {
        cout << display_code << get_id() << ": Fish are friends, not food" << endl;
    }
}


bool Shark::update() {
    bool output = false;
    //output will be changed to true if the state changes
    switch (state) {
        case 'x':
            break;
        case 's':
            break;
        case 'e':
            //Checks to see if reef is empty
            if (this->reef->is_empty() && prefeast_size * 2 > size) {
                state = 'f';
                cout << display_code << reef->get_id() << ": This reef has no more food for me." << endl;
                output = true;
            }
            //Eats from reef if it is not empty
            else {
                //Heads home if it's twice its original size
                if (prefeast_size * 2 <= size) {
                    setup_destination(home->get_location());
                    cout << display_code << get_id() << ": I'm full. I'm heading home." << endl;
                    state = 'z';
                    output = true;
                }
                //Keeps eating if it is not full yet
                else {
                    size += this->reef->provide_food()/2;
                    cout << display_code << get_id() << ": Grew to size " << size << endl;
                }
            }
            break;
        case 'a':
            if (fabs((target->get_location()).x - (this->get_location()).x) <= range &&
                fabs((target->get_location()).y - (this->get_location()).y) <= range) {
                if (target->get_energy() <= 0) {
                    cout << display_code << get_id() << ": I triumph!" << endl;
                    state = 's';
                    output = true;
                }
                else {
                    cout << display_code << get_id() << ": Chomp!" << endl;
                    target->get_bitten(attack_strength);
                }
            }
            else {
                this->target = NULL;
                cout << display_code << get_id() << ": Darn! It escaped." << endl;
                output = true;
            }
            break;
    }
    return output;
}

void Shark::show_status() {
    cout << "Shark status: ";
    Fish::show_status();
    //Something about if it is attacking
}

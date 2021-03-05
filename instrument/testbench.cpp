
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Instrument.h"

class Room {
protected:
    std::vector<Door*> doorList;
    std::vector<Light*> lightList;
    std::vector<Heater*> heaterList;
    std::vector<Coffe_Machine*> coffeList;
public:
    std::string r_name;
    void add_instrument(int id, int i_val);
    void add_door(int id);
    void quick_door(std::string name, int id, Position openClosed);
    void quick_light(std::string name, int id, int val, Position onOff, bool digital);
    void add_light(int id);
    void print_room();
    void quick_start();
};

void Room::print_room() {
    Door* d_temp = nullptr;
    Light* l_temp = nullptr;
    bool digital_pos;
    int analog_pos;
    std::string temp_n = "NA";
    std::cout << "---------------------------------------------\n";
    std::cout << "                  Door list\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < doorList.size(); i++) {
        digital_pos = doorList[i]->get_pos();
        temp_n = doorList[i]->get_name();
        std::cout << "Door name: " << temp_n;
        if (temp_n.size() > 4) {
            if (temp_n.size() < 9) {   std::cout << "\t";  }
        }
        else { std::cout << "\t\t"; }
        std::cout << "Position: " << (digital_pos == true ? "Open" : "Closed") << "\n";
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "                  Light list\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < lightList.size(); i++) {
        analog_pos = lightList[i]->l_get_status();
        digital_pos = lightList[i]->get_pos();
        temp_n = lightList[i]->get_name();
        std::cout << "Light name: " << temp_n;
        if (temp_n.size() > 3) {
            if (temp_n.size() < 8) { std::cout << "\t"; }
        }
        else { std::cout << "\t\t"; }
        std::cout << "Currently: " << (digital_pos == true ? "On" : "Off");
        std::cout << ", " << lightList[i]->l_get_status() << " \%\n";
    }
}

void Room::add_instrument(int id, int i_val) {
    if (i_val == 1) 
    {   add_door(id); }
    else if (i_val == 2)
    {   add_light(id); }
 /*   else if (i_val == 2)
    {
        add_light(id);
    }
    else if (i_val == 2)
    {
        add_light(id);
    }
    else if (i_val == 2)
    {
        add_light(id);
    }*/
}

void Room::add_door(int id) {
    std::string name;
    char door;
    Position d_st;
    std::cout << "Add a name to the DOOR: ";
    std::cin >> name;
    std::cout << "Is the door open? (Y/N) ";
    std::cin >> door;
    if (door == 'Y' || door == 'y')
    {   d_st = Position::On; }
    else
    {   d_st = Position::Off; }
    Door* new_d = new Door(name, id, d_st);
    doorList.push_back(new_d);
    new_d->print_out();
}

void Room::add_light(int id) {
    std::string name;
    int val = 0;
    char c2;
    bool digital;
    std::cout << "Add a name to the light: ";
    std::cin >> name;
    std::cout << "Is the light dimmable? (Y/N) ";
    std::cin >> c2;
    if (c2 == 'Y' || c2 == 'y') {
        digital = false;
        std::cout << "At what \% is the light currently? ";
        std::cin >> c2;
        val = (int)c2;
    }
    else if (c2 == 'N' || c2 == 'n') {
        digital = true;
        std::cout << "Is the light on or off (Y = on, N = off) ";
        std::cin >> c2;
        if (c2 == 'Y' || c2 == 'y') 
        {   val = 100; }
        else
        {   val = 0; }
    }
    Light* new_l = new Light(name, id, val, ((c2 == 'Y' || c2 == 'y') ? Position::On : Position::Off), digital);
    lightList.push_back(new_l);
    new_l->print_out();
}

void room_menu(int &c2) {
    std::cout << "---------------------------------------------\n";
    std::cout << "Press '1' to add a DOOR to the room\n";
    std::cout << "Press '2' to add a LIGHT to the room\n";
    std::cout << "Press '3' to add an kitchen or bathroom appliance\n";
    std::cout << "Press '4' to add a coffemachine to the room\n";
    std::cout << "Press '5' to add a heater to the room\n";
    std::cout << "Press '9' to print all instruments in the room\n";
    std::cout << "Press '0' to close the program\n";
    std::cout << "---------------------------------------------\n";
    std::cin >> c2;
}

void Room::quick_door(std::string name, int id, Position openClosed) {
    Door * new_d = new Door(name, id, openClosed);
    doorList.push_back(new_d);
}
void Room::quick_light(std::string name, int id, int val, Position onOff, bool dig) {
    Light * new_l = new Light(name, id, val, onOff, dig);
    lightList.push_back(new_l);
}

void Room::quick_start() {
    std::cout << "Creating 4 doors and 4 lights...\n";
    quick_door("Hoved", 1, Position::On);
    quick_door("Side", 2, Position::Off);
    quick_door("Bak", 3, Position::Off);
    quick_door("Skap", 4, Position::On);
    quick_light("Tak", 5, 13, Position::On, true);
    quick_light("Vegg", 6, 17, Position::Off, false);
    quick_light("Bord", 7, 25, Position::Off, true);
    quick_light("Gulv", 8, 90, Position::On, false);
}

int main()
{
    bool run = true;
    Room new_room;
    std::cout << "Added a room...\n";
    new_room.quick_start();
    int id = 10;
    int val;
    while (run){
        std::thread t_menu(room_menu, std::ref(val));
        t_menu.join();
        if (val == 1) {
            new_room.add_instrument(id, val);
            id++;
        }
        else if (val == 2) {
            new_room.add_instrument(id, val);
            id++;
        }
        else if (val == 9) {
            new_room.print_room();
        }
        else if (val == 0) {
            run = false;
        }
    }
}
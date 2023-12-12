// 2 вариант 
//

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Animal {

private:
    string name;
    string vid;
public:
    
    Animal(string name_t, string vid_t) : name{ name_t }, vid{ vid_t }
    { }

    virtual void display() const {
        cout << "Имя - " << name << ", Вид - " << vid << endl;
    }

    void rename(string newname) {
        name = newname;
    }

    void revid(string newvid) {
        vid = newvid;
    }

    string get_name() {
        return name;
    }
};

class Bird : public Animal {
private:
    int wing;

public:
    Bird(string name_t, string vid_t, int wing_t) : Animal{ name_t, vid_t }, wing{ wing_t }
    { }

    virtual void display() const {
        Animal::display();
        cout << "Размах крыла - " << wing <<  endl;
    }

};

class Mammal : public Animal {
private:
    string wool;

public:
    Mammal(string name_t, string vid_t, string wool) : Animal{ name_t, vid_t }, wool{ wool }
    { }

    virtual void display() const {
        Animal::display();
        cout << "Тип шерсти - " << wool << endl;
    }

};

void modifyAnimal(Animal* animal,string newname) {
    animal->rename(newname);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <Animal*> animal;
    
    animal.resize(3);
    animal[0] = new Animal("Ася", "кошка");
    animal[1] = new Bird("Кеша", "птица",15);
    animal[2] = new Mammal("Гена", "млекопитающие","короткая");
    
    modifyAnimal(animal[0], "НЕАСЯ");
    modifyAnimal(animal[1],"Некеша");
    for (auto* a : animal) {
        a->display();
    }
    animal.clear();
}

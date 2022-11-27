#include <iostream>
#include <string>

using namespace std;

class Transport
{
protected:
    string type;
public:
    Transport(string type = "") : type{type} {}
    virtual string Move()
    {
        return "transport " + type + " move";
    }
};

class Car : public Transport
{
protected:
    int speed;
public:
    Car(string type ="", int speed = 0) : Transport(type), speed{speed} {}
    string Move() override
    {
        return Transport::Move() + " with speed " + to_string(speed);
    }
};

class Plane : public Transport
{
protected:
    int height;
public:
    Plane(string type = "", int height = 0) : Transport(type), height{ height } {}
    string Move() override
    {
        return Transport::Move() + " on height " + to_string(height);
    }
};

int main()
{
    Car* car = new Car("lada", 200);
    Transport* transport = new Transport("transport");
    Plane* plane = new Plane("Supejet", 10000);

    Transport* trs[3];
    trs[0] = transport;
    trs[1] = car;
    trs[2] = plane;

    for (int i = 0; i < 3; i++)
        cout << trs[i]->Move() << "\n";
}

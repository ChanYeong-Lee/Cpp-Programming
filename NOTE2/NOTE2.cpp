#include <iostream>
using namespace std;

class Car abstract
{
public:
	virtual void Drive() = 0;
};

class RacingCar : public Car
{
public:
	void Drive() override
	{
		cout << "Functions" << endl;
	}
};

class Bus : public Car
{
public:
	void Drive() override
	{
		cout << "Functions" << endl;
	}
}; 

class PassengerCar : public Car
{
public:
	void Drive() override
	{
		cout << "Functions" << endl;
	}
};

void CarSelect()
{
	int select;
	cin >> select;
	switch (select)
	{
	case 0:
		Car* newCar = new RacingCar;
		break;
	case 1:
		Car* newCar = new PassengerCar;
		break;
	case 2:
		Car* newCar = new Bus;
		break;
	}
}
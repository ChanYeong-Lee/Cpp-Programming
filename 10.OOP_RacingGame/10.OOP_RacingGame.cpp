#include <iostream>
#include <conio.h>
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

class Car
{
protected:
	string name;
	float maxSpeed;
	float acceleration;
	float deceleration;
	float handling;
	float durability;

	float maxSpeedRate;
	float accelerationRate;
	float decelerationRate;
	float handlingRate;
	float durabilityRate;


public:
	float currentHp;
	float currentSpeed;
	float lossRate;
	void Accelerate()
	{
		if (lossRate < 1)
		{
			if (currentSpeed <= maxSpeed - acceleration * lossRate)
				currentSpeed += acceleration * lossRate;
			else
				currentSpeed = maxSpeed;
		}
		else
		{
			if (currentSpeed <= maxSpeed - acceleration)
				currentSpeed += acceleration;
			else
				currentSpeed = maxSpeed;
		}
		if (currentHp <= 0)
			currentHp = 0;
		else
			currentHp -= 10;
		lossRate = currentHp / durability + 0.4f;
	}
	void Decelerate()
	{
		if (lossRate < 1)
		{
			if (currentSpeed > deceleration * lossRate)
				currentSpeed -= deceleration * lossRate;
			else
				currentSpeed = 0;
		}
		else
		{
			if (currentSpeed > deceleration)
				currentSpeed -= deceleration;
			else
				currentSpeed = 0;
		}
		if (currentHp <= 0)
			currentHp = 0;
		else
			currentHp -= 10;
		lossRate = currentHp / durability + 0.4f;
	}
	void TurnLeft()
	{
		cout << "Turn Left!";
		if (currentHp <= 0)
			currentHp = 0;
		else
			currentHp -= 10;
		lossRate = currentHp / durability + 0.4f;
	}
	void TurnRight()
	{
		cout << "Turn Right!";
		if (currentHp <= 0)
			currentHp = 0;
		else
			currentHp -= 10;
		lossRate = currentHp / durability + 0.4f;
	}
	void Repair()
	{
		currentHp = durability;
	}
	string GetName() { return name; }
	float GetMaxSpeed() { return maxSpeed; }
	float GetAcceleration() { return acceleration; }
	float GetDeceleration() { return deceleration; }
	float GetHandling() { return handling; }
	float GetDurability() { return durability; }
	void Display()
	{
		cout << endl;
		cout << " 현재 속도 : " << currentSpeed << " km/h " << endl;
		cout << " 현재 체력 : " << currentHp << " / " << durability << endl << endl;
	}
	void Ready()
	{
		currentHp = durability;
		currentSpeed = 0;
		lossRate = currentHp / durability + 0.4f;
	}
};

class Driver
{
	string name;
	int level;
	int totalScore;

public:
	Driver(string _name) : name(_name)
	{
		level = 1;
		totalScore = 0;
	}
	string GetName() { return name; }
	int GetLevel() { return level; }
	int GetTotalScore() { return totalScore; }
	void Accelerate(Car& car) { car.Accelerate(); }
	void Decelerate(Car& car) { car.Decelerate(); }
	void TurnLeft(Car& car) { car.TurnLeft(); }
	void TurnRight(Car& car) { car.TurnRight(); }
	void Repair(Car& car) { car.Repair(); }
	void LevelUp() { level += 1; }
};

class SUV : public Car
{

public:
	SUV(string _name, float _maxS, float _accel, float _decel, float _dura, float _hand)
	{
		maxSpeedRate = 0.9f;
		accelerationRate = 0.9f;
		decelerationRate = 1.1f;
		handlingRate = 0.9f;
		durabilityRate = 1.4f;

		name = _name;
		maxSpeed = _maxS * maxSpeedRate;
		acceleration = _accel * accelerationRate;
		deceleration = _decel * decelerationRate;
		handling = _hand * handlingRate;
		durability = _dura * durabilityRate;
	}
};

class RacingCar : public Car
{

public:
	RacingCar(string _name, float _maxS, float _accel, float _decel, float _dura, float _hand)
	{
		maxSpeedRate = 1.3f;
		accelerationRate = 1.3f;
		decelerationRate = 1.1f;
		handlingRate = 1.1f;
		durabilityRate = 0.7f;

		name = _name;
		maxSpeed = _maxS * maxSpeedRate;
		acceleration = _accel * accelerationRate;
		deceleration = _decel * decelerationRate;
		handling = _hand * handlingRate;
		durability = _dura * durabilityRate;
	}
};

class MotorCycle : public Car
{

public:
	MotorCycle(string _name, float _maxS, float _accel, float _decel, float _dura, float _hand)
	{
		maxSpeedRate = 1.2f;
		accelerationRate = 1.2f;
		decelerationRate = 0.8f;
		handlingRate = 1.2f;
		durabilityRate = 0.5f;

		name = _name;
		maxSpeed = _maxS * maxSpeedRate;
		acceleration = _accel * accelerationRate;
		deceleration = _decel * decelerationRate;
		handling = _hand * handlingRate;
		durability = _dura * durabilityRate;
	}
};

class PassengerCar : public Car
{

public:
	PassengerCar(string _name, float _maxS, float _accel, float _decel, float _dura, float _hand)
	{
		maxSpeedRate = 1.0f;
		accelerationRate = 1.0f;
		decelerationRate = 1.0f;
		handlingRate = 1.0f;
		durabilityRate = 1.0f;

		name = _name;
		maxSpeed = _maxS * maxSpeedRate;
		acceleration = _accel * accelerationRate;
		deceleration = _decel * decelerationRate;
		handling = _hand * handlingRate;
		durability = _dura * durabilityRate;
	}
};

int GetKeyDown()					// 방향키 입력 받기
{
	int input = _getch();
	if (input == 224)
	{
		input = _getch();
		return input;
	}
	return input;
}

void Control(Driver& driver, Car& car)
{
	int input = GetKeyDown();
	switch (input)
	{
	case UP:
		driver.Accelerate(car);
		system("cls");
		car.Display();
		break;
	case DOWN:
		driver.Decelerate(car);
		system("cls");
		car.Display();
		break;
	case LEFT:
		system("cls");
		driver.TurnLeft(car);
		car.Display();
		break;
	case RIGHT:
		system("cls");
		driver.TurnRight(car);
		car.Display();
		break;
	case 'd':
		system("cls");
		cout << "< 드라이버 정보 >" << endl;
		cout << " 이름 : " << driver.GetName() << endl;
		cout << " 레벨 : " << driver.GetLevel() << endl;
		cout << " 총점 : " << driver.GetTotalScore() << endl << endl;
		break;
	case 'c':
		system("cls");
		cout << "< 차량 정보 >" << endl;
		cout << " 이름 : " << car.GetName() << endl;
		cout << " 최대 속력 : " << car.GetMaxSpeed() << endl;
		cout << " 가속력 : " << car.GetAcceleration() << endl;
		cout << " 감속력 : " << car.GetDeceleration() << endl;
		cout << " 조향성 : " << car.GetHandling() << endl;
		cout << " 내구성 : " << car.GetDurability() << endl;
		break;
	case 'r':
		system("cls");
		driver.Repair(car);
		cout << "Repair Complete.";
		car.Display();
	}
}

//bool CheckGame()
//{
//	static int count = 0;
//	count++;
//	if (count == 40)
//		return FALSE;
//	return TRUE;
//}

int main()
{
	Driver lee = Driver("Lee");
	PassengerCar sonata = PassengerCar("sonata", 200, 8.5, 11, 250, 100);
	sonata.Ready();
	while (true)
	{
		//bool checker = CheckGame();
		//if (checker == FALSE)
		//	break;
		Control(lee, sonata);
	}
}
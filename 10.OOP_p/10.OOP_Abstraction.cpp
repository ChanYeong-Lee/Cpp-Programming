#include <iostream>
const int TRUE = 1;
const int FALSE = 0;
using namespace std;


/****************************************************************
* 추상화 (Abstraction)
* 
* 클래스를 정의할 당시 구체화시킬 수 없는 기능을 추상적 표현으로 정의
*****************************************************************/

// <추상클래스 (Abstract Class)
// 하나 이상의 순수가상함수를 포함하는 클래스
// 클래스가 추상적인 표현을 정의하는 경우 자식에서 구체화시켜 구현할 것을 염두하고 추상화시킴
// 추상클래스에서 내용을 구체화할 수 없는 순수가상함수는 내용을 정의하지 않음
// 추상클래스를 상속하는 자식클래스가 순수가상함수를 재정의하여 구체화한 경우 사용 가능
class Item abstract
{
protected:
	string name;
	bool existed = TRUE;
public:
	virtual void Function() = 0;			// 순수가상함수 : 클래스에서 구현을 진행하지 않고 추상화시킴
	virtual void Existed()
	{
		existed = FALSE;
	}
	virtual void Use()
	{
		Function();
		cout << name << "이/가 소모되었습니다." << endl;
		Existed();
	}
	void SetName(string _name) { name = _name; }
};

class Potion : public Item
{
public:
	void Function() override				// 오버라이딩 : 가상함수를 재정의하여 구체화
	{
		cout << name << "을 사용하여 체력을 회복합니다." << endl;
	}
};

class Bomb : public Item
{
public:
	void Function() override				// 오버라이딩 : 가상함수를 재정의하여 구체화
	{
		cout << name << "을 사용하여 폭발을 일으킵니다." << endl;
	}
};

void Abstraction_Main1()
{
	// Item* item = new Item();       // error : 추상클래스는 인스턴스 생성불가

	// 추상클래스를 구체화한 자식클래스는 인스턴스 생성이 가능하며 관련 기능을 사용가능
	Item* potion = new Potion();
	potion->SetName("포션");
	potion->Use();

	Item* bomb = new Bomb();
	bomb->SetName("폭탄");
	bomb->Use();

	delete potion;
	delete bomb;
}

// <추상화 사용의미 1>
// 객체들의 공통적인 특징을 도출하는데 의미
// 구현을 구체화하기 어려운 상위클래스를 설계하기 위한 수단으로 사용

class Animal abstract
{
public:
	virtual void Cry() = 0;       // 동물의 울음소리를 부모클래스에서 정의하기 어려움
};

class Cat : public Animal
{
	void Cry() override { cout << "야옹" << endl; }       // 자식클래스에서 구체화
};

class Dog : public Animal
{
	void Cry() override { cout << "멍멍" << endl; }
};

// <추상화 사용의미 2>
// 클래스의 인터페이스를 구현하기 위한 수단으로 사용
// 추상적인 기능을 구체화시키지 않은 경우 인스턴스 생성이 불가
// 이를 통해 자식클래스에게 순수가상함수의 구현을 강제하여 실수를 줄임

class Lion : public Animal
{
	// 자식클래스를 구현할 경우 부모클래스의 순수가상함수를 구현하는 것이 강제됨
};

void AbstractionMain2()
{
	// Animal* lion = new Lion();   // error : 인스턴스 생성불가
}

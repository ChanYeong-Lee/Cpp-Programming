#include <iostream>

using namespace std;

/**************************************************************************
* 다형성 (Polymorphism)
* 
* 객체의 속성이나 기능이 상황에 따라 여러가지 형태를 가질 수 있는 성질
***************************************************************************/


// <다형성>
// 부모 클래스의 함수를 자식 클래스에서 재정의하여 자식 클래스의 서로 다른 반응을 구현함

class Skill
{
	int coolTime;

public:
	void Execute()
	{
		cout << "스킬 재사용 대기시간을 진행시킴" << endl;
	}
};

class FireArrow : public Skill
{
public:
	void Execute()
	{
		cout << "불화살을 날린다" << endl;
		Skill::Execute();
	}
};

class Smash : public Skill
{
public:
	void Execute()	// 오버라이딩
	{
		cout << "강타 스킬을 사용함" << endl;
		Skill::Execute();
	}
};

void Polymorphism_Main1()
{
	FireArrow fireArrow;
	Smash smash;
	fireArrow.Execute();
	smash.Execute();
}

// 오버로딩
int Add(int left, int right) { return left + right; }
float Add(float left, float right) { return left + right; }

class Character
{
protected:
	Skill* skill;

public:
	virtual ~Character()
	{

	}
	void UseSkill()
	{
		(*skill).Execute();
	}
};

class Archor : public Character
{
public:
	Archor()
	{
		skill = new FireArrow();
	}

	virtual ~Archor() override		// 소멸자 : 일반적으로 가상함수로 만듬
	{
		delete skill;
	}
	static void AAA() {}			// 정적 함수 : 인스턴스 없이 사용할 수 있음.
};

class Warrior : public Character
{
public:
	Warrior()
	{
		skill = new Smash();
	}

	~Warrior()
	{
		delete skill;
	}
};

void Polymorphism_Main2()	// UseSkill -> Skill.Execute()를 실행하기 때문에 FireArrow.Execute()는 안 된다.
{
	Archor* archor = new Archor;
	Warrior* warrior = new Warrior;
	(*archor).UseSkill();
	(*warrior).UseSkill();
	delete archor;
	delete warrior;
	Archor::AAA();
}	

// <가상함수와 오버라이딩>
// 가상함수		: 부모 클래스 함수 중 자식 클래스에 의해 재정의할 수 있는 함수 지정
// 오버라이딩	: 부모 클래스 함수를 같은 함수 이름과 같은 매개변수로 재정의
class Vehicle
{
protected:
	string name;
public:
	virtual void Move()
	{
		cout << "도로 위로 이동합니다." << endl;
	}
};

class AirPlane : public Vehicle
{
public:
	void Move() override
	{
		cout << "공중으로 이동합니다." << endl;
	}
};

class Bus : public Vehicle
{
public:
	void Move() override
	{
		Vehicle::Move();
		cout << "정류장에 도착하면 승하차 후 출발합니다." << endl;
	}
};

void Polymorphism_Main3()
{
	// <정적바인딩>										쓰지마!!!!
	// 컴파일 당시에 호출될 함수가 결정
	// 변수의 자료형을 기반으로 호출할 함수를 결정
	Vehicle vValue = Vehicle();
	Vehicle aValue = AirPlane();
	Vehicle bValue = Bus();
	vValue.Move();      //Vehicle::Move()를 호출함
	aValue.Move();
	bValue.Move();
	cout << endl;

	AirPlane aValue2;	// 정상 동작함
	Bus bValue2;
	aValue2.Move();
	bValue2.Move();
	cout << endl;

	// <동적바인딩>										무조건 이거 쓰셈
	// 런타임 당시에 호출될 함수가 결정
	// virtual 함수를 포함하는 객체는 가상함수테이블을 포함함
	// 가상함수를 재정의하는 경우 가상함수테이블의 주소값을 재정의한 함수의 주소로 변경
	// 호출시 가상함수테이블에 있는 함수 주소를 읽어 함수를 진행
	Vehicle* vPtr = new Vehicle();
	Vehicle* aPtr = new AirPlane();
	Vehicle* bPtr = new Bus();
	vPtr->Move();		// 가상함수테이블에 연결된 함수를 호출함
	aPtr->Move();
	bPtr->Move();
	cout << endl;

	(*vPtr).Move();
	(*aPtr).Move();
	(*bPtr).Move();
	cout << endl;

	delete vPtr;
	delete aPtr;
	delete bPtr;

	Vehicle* selectVehicle = nullptr;
	string select;
	cout << "탑승물을 선택하세요 : ";
	cin >> select;

	if (select == "버스")
	{
		selectVehicle = new Bus();
	}
	else if (select == "비행기")
	{
		selectVehicle = new AirPlane();
	}
	selectVehicle->Move();

}
// <다형성 사용의미>
// 부모 클래스를 설계할 당시 기본적인 기능을 구현하며
// 자식 클래스를 설계할 당시 자식 클래스만의 기능을 고려하여 구현 가능

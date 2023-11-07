#include <iostream>

using namespace std;

/**************************************************************************
* ������ (Polymorphism)
* 
* ��ü�� �Ӽ��̳� ����� ��Ȳ�� ���� �������� ���¸� ���� �� �ִ� ����
***************************************************************************/


// <������>
// �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� �������Ͽ� �ڽ� Ŭ������ ���� �ٸ� ������ ������

class Skill
{
	int coolTime;

public:
	void Execute()
	{
		cout << "��ų ���� ���ð��� �����Ŵ" << endl;
	}
};

class FireArrow : public Skill
{
public:
	void Execute()
	{
		cout << "��ȭ���� ������" << endl;
		Skill::Execute();
	}
};

class Smash : public Skill
{
public:
	void Execute()	// �������̵�
	{
		cout << "��Ÿ ��ų�� �����" << endl;
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

// �����ε�
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

	virtual ~Archor() override		// �Ҹ��� : �Ϲ������� �����Լ��� ����
	{
		delete skill;
	}
	static void AAA() {}			// ���� �Լ� : �ν��Ͻ� ���� ����� �� ����.
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

void Polymorphism_Main2()	// UseSkill -> Skill.Execute()�� �����ϱ� ������ FireArrow.Execute()�� �� �ȴ�.
{
	Archor* archor = new Archor;
	Warrior* warrior = new Warrior;
	(*archor).UseSkill();
	(*warrior).UseSkill();
	delete archor;
	delete warrior;
	Archor::AAA();
}	

// <�����Լ��� �������̵�>
// �����Լ�		: �θ� Ŭ���� �Լ� �� �ڽ� Ŭ������ ���� �������� �� �ִ� �Լ� ����
// �������̵�	: �θ� Ŭ���� �Լ��� ���� �Լ� �̸��� ���� �Ű������� ������
class Vehicle
{
protected:
	string name;
public:
	virtual void Move()
	{
		cout << "���� ���� �̵��մϴ�." << endl;
	}
};

class AirPlane : public Vehicle
{
public:
	void Move() override
	{
		cout << "�������� �̵��մϴ�." << endl;
	}
};

class Bus : public Vehicle
{
public:
	void Move() override
	{
		Vehicle::Move();
		cout << "�����忡 �����ϸ� ������ �� ����մϴ�." << endl;
	}
};

void Polymorphism_Main3()
{
	// <�������ε�>										������!!!!
	// ������ ��ÿ� ȣ��� �Լ��� ����
	// ������ �ڷ����� ������� ȣ���� �Լ��� ����
	Vehicle vValue = Vehicle();
	Vehicle aValue = AirPlane();
	Vehicle bValue = Bus();
	vValue.Move();      //Vehicle::Move()�� ȣ����
	aValue.Move();
	bValue.Move();
	cout << endl;

	AirPlane aValue2;	// ���� ������
	Bus bValue2;
	aValue2.Move();
	bValue2.Move();
	cout << endl;

	// <�������ε�>										������ �̰� ����
	// ��Ÿ�� ��ÿ� ȣ��� �Լ��� ����
	// virtual �Լ��� �����ϴ� ��ü�� �����Լ����̺��� ������
	// �����Լ��� �������ϴ� ��� �����Լ����̺��� �ּҰ��� �������� �Լ��� �ּҷ� ����
	// ȣ��� �����Լ����̺� �ִ� �Լ� �ּҸ� �о� �Լ��� ����
	Vehicle* vPtr = new Vehicle();
	Vehicle* aPtr = new AirPlane();
	Vehicle* bPtr = new Bus();
	vPtr->Move();		// �����Լ����̺� ����� �Լ��� ȣ����
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
	cout << "ž�¹��� �����ϼ��� : ";
	cin >> select;

	if (select == "����")
	{
		selectVehicle = new Bus();
	}
	else if (select == "�����")
	{
		selectVehicle = new AirPlane();
	}
	selectVehicle->Move();

}
// <������ ����ǹ�>
// �θ� Ŭ������ ������ ��� �⺻���� ����� �����ϸ�
// �ڽ� Ŭ������ ������ ��� �ڽ� Ŭ�������� ����� ����Ͽ� ���� ����

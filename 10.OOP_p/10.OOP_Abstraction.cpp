#include <iostream>
const int TRUE = 1;
const int FALSE = 0;
using namespace std;


/****************************************************************
* �߻�ȭ (Abstraction)
* 
* Ŭ������ ������ ��� ��üȭ��ų �� ���� ����� �߻��� ǥ������ ����
*****************************************************************/

// <�߻�Ŭ���� (Abstract Class)
// �ϳ� �̻��� ���������Լ��� �����ϴ� Ŭ����
// Ŭ������ �߻����� ǥ���� �����ϴ� ��� �ڽĿ��� ��üȭ���� ������ ���� �����ϰ� �߻�ȭ��Ŵ
// �߻�Ŭ�������� ������ ��üȭ�� �� ���� ���������Լ��� ������ �������� ����
// �߻�Ŭ������ ����ϴ� �ڽ�Ŭ������ ���������Լ��� �������Ͽ� ��üȭ�� ��� ��� ����
class Item abstract
{
protected:
	string name;
	bool existed = TRUE;
public:
	virtual void Function() = 0;			// ���������Լ� : Ŭ�������� ������ �������� �ʰ� �߻�ȭ��Ŵ
	virtual void Existed()
	{
		existed = FALSE;
	}
	virtual void Use()
	{
		Function();
		cout << name << "��/�� �Ҹ�Ǿ����ϴ�." << endl;
		Existed();
	}
	void SetName(string _name) { name = _name; }
};

class Potion : public Item
{
public:
	void Function() override				// �������̵� : �����Լ��� �������Ͽ� ��üȭ
	{
		cout << name << "�� ����Ͽ� ü���� ȸ���մϴ�." << endl;
	}
};

class Bomb : public Item
{
public:
	void Function() override				// �������̵� : �����Լ��� �������Ͽ� ��üȭ
	{
		cout << name << "�� ����Ͽ� ������ ����ŵ�ϴ�." << endl;
	}
};

void Abstraction_Main1()
{
	// Item* item = new Item();       // error : �߻�Ŭ������ �ν��Ͻ� �����Ұ�

	// �߻�Ŭ������ ��üȭ�� �ڽ�Ŭ������ �ν��Ͻ� ������ �����ϸ� ���� ����� ��밡��
	Item* potion = new Potion();
	potion->SetName("����");
	potion->Use();

	Item* bomb = new Bomb();
	bomb->SetName("��ź");
	bomb->Use();

	delete potion;
	delete bomb;
}

// <�߻�ȭ ����ǹ� 1>
// ��ü���� �������� Ư¡�� �����ϴµ� �ǹ�
// ������ ��üȭ�ϱ� ����� ����Ŭ������ �����ϱ� ���� �������� ���

class Animal abstract
{
public:
	virtual void Cry() = 0;       // ������ �����Ҹ��� �θ�Ŭ�������� �����ϱ� �����
};

class Cat : public Animal
{
	void Cry() override { cout << "�߿�" << endl; }       // �ڽ�Ŭ�������� ��üȭ
};

class Dog : public Animal
{
	void Cry() override { cout << "�۸�" << endl; }
};

// <�߻�ȭ ����ǹ� 2>
// Ŭ������ �������̽��� �����ϱ� ���� �������� ���
// �߻����� ����� ��üȭ��Ű�� ���� ��� �ν��Ͻ� ������ �Ұ�
// �̸� ���� �ڽ�Ŭ�������� ���������Լ��� ������ �����Ͽ� �Ǽ��� ����

class Lion : public Animal
{
	// �ڽ�Ŭ������ ������ ��� �θ�Ŭ������ ���������Լ��� �����ϴ� ���� ������
};

void AbstractionMain2()
{
	// Animal* lion = new Lion();   // error : �ν��Ͻ� �����Ұ�
}

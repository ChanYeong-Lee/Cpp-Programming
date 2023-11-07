#include <iostream>

using namespace std;

/*****************************************************************************
* ��� (Inheritance)
* 
* �θ� Ŭ������ ��� ����� ������ �ڽ� Ŭ������ �����ϴ� ���
* is-a ���� : �θ� Ŭ������ �ڽ� Ŭ������ �����ϴ� ���������� ��� ��Ӱ��谡 ������
* (child�� parent��, �巡���� ���ʹ�.)
******************************************************************************/

// <���>
// �θ� Ŭ������ ����ϴ� �ڽ� Ŭ�������� �θ� Ŭ������ ��� ����� �ο�
// class �ڽ�Ŭ���� : public �θ�Ŭ����

class Monster
{
protected:
	string name;
	int hp;
	int exp;

public:
	string GetName()
	{
		return name;
	}

	void TakeHit(int damage)
	{
		hp -= damage;
		cout << name << "��/�� " << damage << "�� �޾� ü���� " << hp << " ��/�� �Ǿ����ϴ�." << endl;
	}
	
	void Die()
	{
		cout << name << "��/�� �׾ " << exp << "��ŭ ����ġ�� ����߸��ϴ�." << endl;
	}
};

class Slime : public Monster
{
public:
	Slime()
	{
		name = "������";
		hp = 100;
	}
};

class Dragon : public Monster
{
public:
	Dragon()
	{
		name = "�巡��";
		hp = 300;
	}

	void Breath()
	{
		cout << name << "��/�� �극���� �ս��ϴ�." << endl;
	}
};

class Hero
{
	int damage;
public:
	Hero()
	{
		damage = 3;
	}
	void SetDamage(int _damage) { damage = _damage; }
	void Attack(Monster monster)
	{
		monster.TakeHit(damage);
		cout << "������ " << monster.GetName() << "��/�� �����մϴ�." << endl;
	}
};

void Inheritance_Main1()
{
	Slime slime;
	Dragon dragon;

	// �θ� Ŭ���� Monster�� ����� �ڽ� Ŭ������ ��� �θ� Ŭ������ ����� ������ ����
	slime.TakeHit(10);
	dragon.TakeHit(10);

	// �ڽ� Ŭ������ �θ� Ŭ������ ��ɿ� �ڽĸ��� ����� �߰��� ���� ����
	dragon.Breath();

	// ��ĳ���� : �ڽ� Ŭ������ �θ� Ŭ���� �ڷ������� ����ȯ ����
	Hero hero;
	hero.SetDamage(20);
	hero.Attack(dragon);
	Monster monster = Dragon();
	hero.Attack(monster);

	hero.Attack(slime);
}

// <��� ��� �ǹ�>
// 1. �ڵ��� ����
// 2. �������� ġȯ : �θ� �ڸ��� �ڽ�	�ν��Ͻ��� ��ü�Ͽ��� ��� ��� ������ �����ϴ�.
// 
// (������ ��ӵ� �ȴ�. �׷��� �ΰ��� ���ÿ� ����ϴ� ��� '������ ���̾Ƹ��'�� �����ؾ� �Ѵ�.)

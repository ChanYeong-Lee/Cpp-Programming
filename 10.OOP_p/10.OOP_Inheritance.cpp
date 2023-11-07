#include <iostream>

using namespace std;

/*****************************************************************************
* 상속 (Inheritance)
* 
* 부모 클래스의 모든 기능을 가지는 자식 클래스를 설계하는 방법
* is-a 관계 : 부모 클래스가 자식 클래스를 포함하는 상위개념일 경우 상속관계가 적합함
* (child는 parent다, 드래곤은 몬스터다.)
******************************************************************************/

// <상속>
// 부모 클래스를 상속하는 자식 클래스에게 부모 클래스의 모든 기능을 부여
// class 자식클래스 : public 부모클래스

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
		cout << name << "이/가 " << damage << "를 받아 체력이 " << hp << " 이/가 되었습니다." << endl;
	}
	
	void Die()
	{
		cout << name << "이/가 죽어서 " << exp << "만큼 경험치를 떨어뜨립니다." << endl;
	}
};

class Slime : public Monster
{
public:
	Slime()
	{
		name = "슬라임";
		hp = 100;
	}
};

class Dragon : public Monster
{
public:
	Dragon()
	{
		name = "드래곤";
		hp = 300;
	}

	void Breath()
	{
		cout << name << "이/가 브레스를 뿜습니다." << endl;
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
		cout << "영웅이 " << monster.GetName() << "을/를 공격합니다." << endl;
	}
};

void Inheritance_Main1()
{
	Slime slime;
	Dragon dragon;

	// 부모 클래스 Monster를 상속한 자식 클래스는 모두 부모 클래스의 기능을 가지고 있음
	slime.TakeHit(10);
	dragon.TakeHit(10);

	// 자식 클래스는 부모 클래스의 기능에 자식만의 기능을 추가해 구현 가능
	dragon.Breath();

	// 업캐스팅 : 자식 클래스는 부모 클래스 자료형으로 형변환 가능
	Hero hero;
	hero.SetDamage(20);
	hero.Attack(dragon);
	Monster monster = Dragon();
	hero.Attack(monster);

	hero.Attack(slime);
}

// <상속 사용 의미>
// 1. 코드의 재사용
// 2. 리스코프 치환 : 부모 자리를 자식	인스턴스로 대체하여도 모든 기능 수행이 가능하다.
// 
// (여러번 상속도 된다. 그러나 두개를 동시에 상속하는 경우 '죽음의 다이아몬드'를 조심해야 한다.)

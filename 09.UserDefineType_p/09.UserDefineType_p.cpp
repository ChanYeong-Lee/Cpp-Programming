#include <iostream>

using namespace std;

/***********************************************
* 구조체 (Struct)
* 
* 하나 이상의 변수를 그룹지어 새로운 자료형을 정의
************************************************/

// <구조체 선언>
// struct 구조체이름 { 구조체내용 };
// 구조체 내용으로 변수와 함수가 포함 가능
// 구조체에 포함한 변수를 멤버변수(필드), 구조체에 포함한 함수를 멤버함수(메소드)라고 함
struct Monster
{
	string name;		// 멤버변수
	int hp;
	int mp;
	int attack;
	int defense;

	void Attack()		// 멤버함수
	{
		cout << name << "이/가 " << attack << "만큼 공격합니다." << endl;
	}

	// <구조체 생성자>
	// 변수 생성과 동시에 멤버변수를 초기화해주는 멤버함수
	// 반환형 없이 구조체 이름의 함수를 사용
	Monster()
	{
		name = "Monster";
		hp = 100;
		mp = 30;
		attack = 10;
		defense = 1;
	}

	Monster(string _name, int _hp, int _mp, int _attack, int _defense)
	{
		name = _name;
		hp = _hp;
		mp = _mp;
		attack = _attack;
		defense = _defense;
	}

	Monster(string _name)
	{
		if (_name == "Elf")
		{
			name = "Elf";
			hp = 80;
			mp = 60;
			attack = 7;
			defense = 1;
		}
		else if (_name == "Ogre")
		{
			name = "Ogre";
			hp = 200;
			mp = 20;
			attack = 20;
			defense = 3;
		}
		else
		{
			name = "Monster";
			hp = 100;
			mp = 30;
			attack = 10;
			defense = 1;
		}
	}
};	// 세미클론 잊지말자

void Main1()
{
	Monster goblin;				// 구조체 선언
	goblin.name = "Goblin";		// 멤버변수에 접근하기 위해 구조체 변수에 .사용
	goblin.hp = 100;
	goblin.mp = 10;
	goblin.attack = 10;
	goblin.defense = 1;
	goblin.Attack();

	Monster ghost;
	ghost.name = "Ghost";
	ghost.hp = 40;
	ghost.mp = 40;
	ghost.attack = 5;
	ghost.defense = 0;
	ghost.Attack();

	Monster monster = Monster();
	monster.Attack();

	Monster dragon = Monster("Dragon", 1000, 600, 100, 20);

	Monster elf = Monster("Elf");
	Monster Ogre = Monster("Ogre");
}

// 매개변수가 없는 생성자
// 생성자를 정의하지 않는 경우 기본생성자는 자동으로 생성됨
// 만약 다른 생성자를 정의하는 경우 기본생성자는 자동으로 생성되지 않음
struct Vector3
{
	float x;
	float y;
	float z;

	/*
	Vector3() {}     // 기본생성자 : 생성자를 생략한 경우 자동 생성
	*/
};

struct Point
{
	int x;
	int y;

	// 생성자를 정의하는 경우 기본생성자는 자동으로 생성되지 않음
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

void Main2()
{
	Vector3 vector = Vector3();     // 기본생성자를 생략한 경우에도 기본생성자가 정의됨

	// Point point = Point();       // error : 기본생성자가 정의되지 않음
	Point point = Point(3, 3);      // 정의한 생성자로만 생성이 가능
}

// 구조체 패딩
// char + int + int 를 저장하더라도 4바이트씩 저장하는 것이 유리해서 낭비를 하더라도 12바이트에 저장한다.


/****************************************************
* 열거형 (Enum)
* 
* 일정 개수의 멤버들을 이름으로 명명하여 정의하는 자료형
*****************************************************/

// <열거형 선언>
// enum 열거형이름 { 멤버목록 }
// 열거형에 대한 멤버 접근은 열거형이름::멤버이름 을 통해 접근
enum MoveKey { Up, Down, Left, Right };		// 열거형 정의 : 열거형 이름과 멤버 이름 작성
void Main3()
{
	MoveKey key = MoveKey::Left;			// 열거형 변수 : 열거형의 값을 가지는 변수
	switch (key)
	{
	case MoveKey::Up:                       // 다른 자료형을 쓰는 것보다 가독성이 좋음
		cout << "위쪽으로 이동" << endl;
		break;
	case MoveKey::Down:
		cout << "아래쪽으로 이동" << endl;
		break;
	case MoveKey::Left:
		cout << "왼쪽으로 이동" << endl;
		break;
	case MoveKey::Right:
		cout << "오른쪽으로 이동" << endl;
		break;
	}
}

// <열거형 변환>
// 열거형은 이름으로 명명되지만 구현 원리는 정수로 구현되어 있음
enum Season
{
	Spring,			// 0
	Summer,			// 1
	Autumn = 10,	// 10
	Winter			// 11
};

void Main4()
{
	Season season = (Season)1;
	cout << season << endl;
	int Value = Autumn;
	season = (Season)5;
}

// <열거형 클래스>
// C++ 11부터 지원하는 열거형 클래스
// 기존 열거형보다 강한 형식과 범위를 가짐
enum class Equip { Weapon, Shield, Armor };
void Main5()
{
	int value = Season::Spring;		// 묵시적 형변환 가능
	// int value = Equip::Weapon;	// 묵시적 형변환 불가능

	Season season = Summer;			// 열거형 범위 지정 없이 사용 가능
	// Equip equip = Shiled;		// 열거형 범위 지정 없이 사용 불가능
}


/*************************************************
* 자료형 재정의
* 
* 자료형의 별칭을 생성하고 실제 자료형 이름 대신 사용
**************************************************/
typedef int myInt_t;				// 자료형 재정의는 _t로 끝내는 것을 권장
typedef unsigned long long ull_t;	// 복잡한 자료형의 간소화 버전 생성
void Main6()
{
	myInt_t value1 = 2;
	ull_t value2 = 4;
}

// <메모리크기 기반 자료형>
// 프로그래밍 언어와 환경에 따라 기본 자료형의 크기가 다를 수 있음
// 기본 자료형 대신 메모리 크기를 기반하여 프로그램을 작성하는 경우 언어와 환경에 영향을 받지 않음
// (굳이 쓸 상황은 없을듯?)
void Main7()
{
	int8_t		int8Value;
	int32_t		int32Value;
	uint16_t	uint16Value;

	size_t		sizeValue;
	time_t		timeValue;
}

int main()
{
	Main4();
}
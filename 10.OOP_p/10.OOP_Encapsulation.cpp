#include <iostream>

using namespace std;


/*********************************************************
* 캡슐화 (Encapsulation)
* 
* 객체를 상태와 기능으로 묶는 것을 의미
**********************************************************/

// <캡슐화>
// 객체를 상태와 기능으로 묶는 것, 객체의 상태와 기능을 멤버라고 표현함
// 현실세계의 객체를 표현하기 위해 객체가 가지는 정보와 행동을 묶어 구현하며 이를 통해 객체간 상호작용

class Capsule
{
	int variable;		// 멤버 변수 : 객체의 상태를 표현
	void Function() {}	// 멤버 함수 : 객체의 기능을 표현
};

// <접근 제한자>
// 외부에서 접근 가능한 멤버 변수와 멤버 함수를 지정하는 기능
//
// public:		외부에서도 접근 가능
// private:		내부에서만 접근 가능
// protected:	외부접근은 private, 상속한 클래스는 public

class AccessSpecifier
{
public:					// public 접근 제한자	: 외부에서도 접근 가능
	int publicValue;
private:				// private 접근 제한자	: 내부에서만 접근 가능
	int privateValue;
protected:				// protected 접근 제한자	: 외부 접근은 private, 상속한 클래스는 public
	int protectedValue;

	void Function()
	{
		publicValue;
		privateValue;
	}
};

void Encapsulation_Main1()
{
	AccessSpecifier instance;
	instance.publicValue;		// 접근 가능
	// instance.privateValue;	// 접근 불가
}

// <정보 은닉>
// 객체 구성에 있어 외부에서 사용하기를 원하는 기능과 사용하기를 원하지 않는 기능을 구분하기 위해 사용
// 사용자가 객체를 사용하는데 있어 필요한 기능만을 확인하기 위한 용도
// 외부에 영향받지 않길 원하는 기능을 감추기 위한 용도이기도 함

class Bank
{
	int balance;

public:
	void SetBalance(int _balance) { balance = _balance; } // Set, Get 함수를 만드는게 국룰		
	int GetBalance() { return balance; }

	void Save(int money)
	{
		balance += money;
	}
	void Load(int money)
	{
		balance -= money;
	}
};

void Encapsulation_Main2()
{
	Bank bank;
	// 외부에서 Bank의 balance를 직접적으로 접근 불가
	// bank.balance = 1000000;
	//
	// 외부에서는 Bank에서 의도한 Save와 Load를 통해 Bank를 다루게 유도
	bank.Save(20000);
	bank.Load(10000);
}

// <캡슐화 사용의미 1 - 복잡성 감소>
// 캡슐화된 클래스는 외부에서 사용하기 위한 인터페이스만 제공
// 즉, 캡슐화된 클래스는 내부적으로 어떻게 구현되었는지 몰라도 사용가능

class VeryComplicatedObject
{
	// 캡슐화된 클래스의 private는 외부에서 접근불가하므로 사용할 수 없음
	int veryComplicatedValue1;
	int veryComplicatedValue2;
	int veryComplicatedValue3;

	void VeryComplicatedFunction1() {}
	void VeryComplicatedFunction2() {}
	void VeryComplicatedFunction3() {}

public:
	// 캡슐화된 클래스의 public은 외부에서 접근가능하므로 사용을 권장하는 기능
	void UseThisFunction() {}
};

// <캡슐화 사용의미 2 - 오용 방지>
// 캡슐화된 클래스는 외부에서 원하지 않는 사용법으로부터 보호할 수 있음

class IntArray
{
	int array[10];

public:
	void SetValue(int index, int value)
	{
		if (index < 0 || index >= 10)
			return;

		array[index] = value;
	}
};

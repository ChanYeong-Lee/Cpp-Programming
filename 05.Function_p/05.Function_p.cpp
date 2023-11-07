#include <iostream>

using namespace std;

/*************************************************************
* 함수 (Function / Procedure)
* 
* 미리 정해진 동작을 수행하는 코드 묶음
* 어떤 처리를 미리 함수로 만들어 두면 다시 반복적으로 사용 가능
**************************************************************/

// <함수 구성>
// 반환형 함수이름(매개변수목록) { 함수내용 }
int Add1(int left, int right) { return left + right; }

void Func1()	 // 매개변수가 없는 경우 빈괄호
{
	cout << "아무 효능 없는 함수입니다." << endl;
}		

int Bigger(int left, int right)
{
	return left > right ? left : right;  
}

// <함수 사용>
// 작성한 함수의 이름에 괄호를 붙이며, 괄호 안에 매개변수들을 넣어 사용
void Main1()
{
	Add1(1, 2);
	Add1(3, 4);

	Func1();
}

// <반환형 (Return Type)>
// 함수의 결과(출력) 데이터의 자료형
// 함수 결과 데이터가 없는 경우 반환형은 void
// <return>
// 함수가 끝나기 전까지 반드시 return으로 반환형에 맞는 데이터를 return 해야함
// 함수 진행 중 return을 만날 경우 데이터를 반환하고 함수를 탈출함
// void 반환형 함수는 return 생략 가능
int IntReturnFunc2()
{
	cout << "return 전" << endl;
	return 10;						// return으로 10을 반환하며 함수 완료
	cout << "return 후" << endl;		// 실행되지 않음
}

void VoidReturnFunc2()
{
	cout << "return 전" << endl;		// void 반환형은 return 생략 가능하나 함수를 종료하고 싶을 때 사용 가능
	return;							// void 반환형은 return 데이터가 없음
	cout << "retrun 후" << endl;
}

void Main2()
{
	int value = IntReturnFunc2();		// IntReturnFunc2 함수가 10의 값을 반환하므로 value는 10이 됨
	VoidReturnFunc2();					// 반환값이 없는 void 함수는 일반적으로 함수내의 행동이 의미가 있음
	// int value = VoidReturnFunc2();	// error : VoidReturnFunc2 함수가 void 반환형이므로 반환데이터 없음
}

// <매개 변수 (Parameter)>
// 함수에 입력할 데이터의 자료형과 변수명
// 같은 함수에서도 입력이 다르면 다른 처리가 가능
int Add3(int left, int right)
{
	// 함수 입력을 넣은 left, right에 따라 동작
	return left + right;
}

void Main3()
{
	int value1 = Add3(10, 20);		// 매개변수 10, 20이 들어간 Add3 함수의 반환은 30
	int value2 = Add3(10, 10);		// 매개변수 10, 10이 들어간 Add3 함수의 반환은 20
}

// <전방 선언 (Forward Declation)>
// 프로그램은 위에서부터 차례대로 진행되어 main 함수 아래 구현된 함수를 사용할 수 없다.
// 그래서 main 함수 위에 전방 선언을 해주면 main 함수 뒤에 함수를 작성해도 사용 가능하다.
// 선언 : 반환형 함수이름(매개변수목록);
// 구현 : 반환형 함수이름(매개변수목록) {함수내용} 
// 함수의 경우도 순서가 중요하지만 이를 전방 선언으로 해결할 수 있다. (객체지향 프로그래밍을 위해)
// 이것을 한번에 해결하는 것이 헤더 파일이다.
int Func5(int num);

// <함수 오버로딩> vs <오버라이딩>		// 기술면접 출제율 90% 
// 이름이 같은 함수의 매개변수를 달리하여 다른 함수로 재정의하는 기술
int Sub(int left, int right) { return left - right; }
float Sub(float left, float right) { return left - right; }
double Sub(double left, double right) { return left - right; }

void Main5()
{
	cout << Sub(5, 3) << endl;			// Sub(int, int)가 호출
	cout << Sub(5.1f, 3.2f) << endl;	// Sub(float, float)가 호출
	cout << Sub(3.1, 3.2) << endl;		// Sub(double, double)가 호출
}

// <함수 호출스택>
// 함수는 호출되었을때 해당 함수 블록으로 제어가 전송되며 완료되었을때 원위치로 전송됨
// 이를 관리하기 위해 호출스택을 활용
// 함수에서 선언한 데이터를 호출 스택에 저장하기 때문에 메모리 관리에 용이함
// 이 때, 함수 내에서 선언한 변수를 '지역 변수/로컬 변수'라고 한다.
// 함수가 순환구조로 무한히 호출되어 더이상 스택에 빈공간이 없는 경우 StackOverFlow가 발생
void Func4_2()
{							// 1
	cout << "End" << endl;	// 2
}							// 3
							
void Func4_1()				
{							// 4
	Func4_2();				// 5
}							// 6

void Main4()				
{							// 7
	Func4_1;				// 8
}							// 9
// 함수 호출 순서 : 7 -> 8 -> 4 -> 5 -> 1 -> 2 -> 3 -> 6 -> 9

string name = "Lee";			// 전역 변수 : 프로그램 전역에서 사용 가능

int Attack(int attackPoint)
{
	int damage = attackPoint * 2;	// 지역 변수
	float critical = 1.2f;			// 호출 스택에 같이 저장되기 때문에
	double debuf = 0.5;				// 함수 실행이 끝나면 삭제된다.

	cout << name << "가 공격합니다." << endl;

	return damage;
}

int Combo()
{
	int totalDamage = 0;

	totalDamage += Attack(1);
	totalDamage += Attack(3);
	totalDamage += Attack(2);

	cout << name << "가 연속기를 사용하여 " << totalDamage << "만큼의 데미지를 줍니다." << endl;

	return totalDamage;
}

/************************************
* <메모리 구조>
* 
* 코드 영역		: 실행할 프로그램 코드
* 데이터 영역	: 전역 변수, 정적 변수
* 힙 영역		: 사용자의 동적 할당
* 스택 영역		: 지역 변수, 매개변수
* ***********************************/

// <인라인 함수>
// 함수 호출 -> 스택 -> 돌아갈 곳 기입 -> 스택 삭제 등의 오버헤드
// 함수의 호출과정에서 발생하는 오버헤드를 줄이기 위해 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수
// 이는 반복적인 호출에서 걸리는 시간을 절약할 수 있으나, 함수 호출 과정으로 생기는 이점을 포기하게 됨
// 따라서 코드가 매우 간단하며 잦은 호출이 있는 함수만을 인라인 함수로 선언하는 것이 좋음
// 참고 : 인라인 함수를 알고 있어야 하지만 최신 컴파일러는 함수를 적절하게 인라인화 하므로 대부분 inline 키워드를 사용할 필요는 없다.
inline int Bigger(int left, int right) { return left > right ? left : right; }

// <StackOverFlow>
// 함수가 스스로를 호출하거나 두 함수가 서로를 호출하면 순환 구조가 되어 영원히 끝나지 않는다.
// 이럴 경우 StackOverFlow가 생기면서 오류가 발생한다.
//void Test1()
//{
//	Test(2);
//}
//
//void Test2()
//{
//	Test1();
//}

int main()    // Windows가 int를 요구함. 정상적으로 닫히면 1, 안 닫히면 -1
{
	cout << Bigger(3, 4);
	
	int num1 = 10;
	int num2 = 20;
	cout << Bigger(num1, num2);
}

int Func5(int num) // 전방 선언이 됬기에 실행 가능
{
	return num;
}
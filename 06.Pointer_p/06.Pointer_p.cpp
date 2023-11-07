#include <iostream>

using namespace std;

/*******************************************************************
* 포인터 (Pointer)
* 
* 프로그램은 메모리를 사용하며 메모리는 변수를 저장한 주소를 가지고 있음
* 프로그램의 메모리 주소값을 통한 접근방법으로 다양한 작업이 가능
********************************************************************/

// <주소 연산자>
// 변수명 앞 &를 붙여 변수가 메모리에 할당된 주소를 확인할 수 있음
void Main1()
{
	int num = 5;
	cout << "num에 저장된 데이터 " << num << endl;
	cout << "num이 저장된 메모리 주소 " << &num << endl;
}

// <포인터 변수>
// 포인터 변수는 메모리 주소를 저장하는 변수
// 자료형 뒤 *을 붙여 포인터 변수를 선언함
// 왜 특정 자료형을 사용할까?
// '거기 가보면 그 자료형의 값이 있을꺼야' 라고 설명해주기 위함 
void Main2()
{
	int num = 100;
	int* ptr = &num;  // 포인터 변수에 주소값을 대입
	

	cout << "num이 저장된 메모리 주소 " << &num << endl;
	cout << "ptr이 가지는 데이터 주소값 " << ptr << endl;
}

// <포인터 역참조>
// 포인터 변수가 가지는 주소값을 역으로 따라갈 수 있음
// 포인터 변수 앞 *을 붙여 포인터 변수가 가지고 있는 주소값에 저장된 데이터를 확인
// 주소값에 저장된 데이터를 변경하는 경우 주소값을 제공한 변수의 "원본" 데이터를 변경함
// (어려우면 그림 그리셈)
void Main3()
{
	int num = 10;
	int* ptr = &num;

	cout << "num에 저장된 데이터 " << num << endl;
	cout << "ptr이 가지는 주소값을 역참조하여 확인한 데이터 " << *ptr << endl;

	*ptr = 20;
	cout << "num에 저장된 데이터 " << num << endl;
	cout << "ptr이 가지는 주소값을 역참조하여 확인한 데이터 " << *ptr << endl;
}

// <포인터 변수 사용시 주의사항>
// 포인터 변수를 초기화 없이 사용하면 쓰레기값을 주소값으로 판단하여 프로그램을 손상시킬 수 있음
// 반드시 포인터 변수가 주소값을 가지고 있지 않은 경우에는 nullptr로 초기화 해주도록 함
void Main4()
{
	int* ptr1;
	// *ptr1 = 20;				// 주의! 프로그램을 손상시킬 수 있음

	int* ptr2 = nullptr;		// 주소값을 가지고 있지 않은 포인터 변수는 nullptr로 초기화하여 안전하게 사용
	*ptr2 = 20;					// 예외처리가 발생
}

// <포인터의 크기>
// 포인터 크기는 주소값의 크기로 메모리가 주소값을 표현하는 단위가 됨
// 32비트 프로그램은 포인터 크기를 32비트, 64비트 프로그램은 포인터 크기를 64비트를 사용한다.
// x86(32Bit) -> 과거 86구조를 나타냄
void Main5()
{
	int* iPtr;
	float* fPtr;
	double* dPtr;

	cout << sizeof(iPtr) << endl;
	cout << sizeof(fPtr) << endl;
	cout << sizeof(dPtr) << endl;
}

// <값에 의한 호출, 주소에 의한 호출> 중요!!!!!       // 출제율 90%
// 함수의 매개변수로 전달되는 데이터는 변수 자체가 아닌 데이터를 복사하여 전달됨
// 만약 변수를 매개변수로 전달하는 경우 데이터를 복사하여 전달하므로 원본이 변경되지 않음
// 만약 변수의 주소를 매개변수로 전달하는 경우 주소를 복사하여 전달하므로 원본의 주소를 역참조하여 원본이 변경됨

void Swap(int left, int right)		// Call By Value : 값 자체가 중요할 때 사용
{
	int temp = left;
	left = right;
	right = temp;
}

void Swap(int* left, int* right)	// Call By Address : 원본이 중요할 때 사용
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void Main6()
{
	int a = 10;
	int b = 20;

	Swap(a, b);							// 데이터를 복사하여 전달하므로 원본이 변경되지 않음.
	cout << a << ", " << b << endl;
	
	Swap(&a, &b);						// 주소를 복사하여 전달하므로 원본 주소를 역참조하여 원본이 변경됨.
	cout << a << ", " << b << endl;
}

void CallByValue(int value) { value = 10; }
void CallByAddress(int* ptr) { *ptr = 10; }

void Main7()
{
	int value = 0;
	cout << "value의 값은 " << value << endl;		// 0
	CallByValue(value);
	cout << "value의 값은 " << value << endl;		// 0
	CallByAddress(&value);
	cout << "value의 값은 " << value << endl;		// 10
}

// <참조자>
// C++에 추가된 새로운 기능
// 참조자의 내부 구현은 포인터를 통해 구현되어 있지만 사용시에 원본을 변수에 가지도록 하는 기법
void Main8()
{
	int num = 10;
	int& ref = num;

	ref = 20;
	cout << "num에 저장된 데이터 " << num << endl;
	cout << "ref가 참조하고 있는 데이터 " << ref << endl;
}

void Swap2(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

void Main9()			// Call By Reference : 함수에 원본 전달
{
	int a = 10;
	int b = 20;
	Swap2(a, b);
	cout << a << ", " << b << endl;
}

void CallByReference(int& ptr) { ptr = 10; }

void Main10()
{
	int value = 0;
	cout << "value의 값은 " << value << endl;		// 0
	CallByReference(value);
	cout << "value의 값은 " << value << endl;		// 10
}

int main()
{
	Main5();
}
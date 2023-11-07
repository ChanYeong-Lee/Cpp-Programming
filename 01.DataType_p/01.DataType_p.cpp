#include <iostream>
#include <string>

using namespace std;

int main()
{
	/************************************************************
	* 자료형 (Data Type)
	* 
	* 자료(Data)의 형태를 지정
	* 데이터가 메모리에 저장되는 형태와 처리되는 방식을 명시하는 역할
	* 0과 1만으로 구성된 컴퓨터가 여러 형태의 자료를 저장하기 위함
	*************************************************************/

	// <자료형 종류>
	// 자료형 이름		자료형 형태		메모리 크기	표현 범위
	// - 논리형 -
	// bool				논리 자료형		1byte		true, false
	// 
	// - 정수형 -
	// short			부호 있는 정수	2byte		-2^15 ~ +2^15 - 1
	// int				부호 있는 정수	4byte		-2^31 ~ +2^31 - 1
	// long				부호 있는 정수	4byte		-2^31 ~ +2^31 - 1
	// long long		부호 있는 정수	8byte		-2^63 ~ +2^63 - 1
	// 
	// unsigned short	부호 없는 정수	2byte		0 ~ +2^32 - 1 
	// unsigned int		부호 없는 정수	4byte		0 ~ +2^64 - 1
	// unsigned long	부호 없는 정수	8byte		0 ~ +2^128 - 1
	// 
	// - 실수형 -
	// float			부동소수점 실수	4byte		3.4e-38  ~ 3.4e+38
	// double			부동소수점 실수	8byte		1.7e-308 ~ 1.7E+308
	// 
	// - 문자형 - 
	// char				문자				1byte		'a', 'b', ...
	// string			문자열			X			"abcd", ...

	int value = 10;
	char c = 'e';
	string str = "asdasd";
	bool b = false;
	float f = 2.3453;
	double d = 1.2424;
	
	/**********************************************************
	* 변수 (Variable)
	* 
	* 데이터를 저장하기 위해 프로그램에 이름을 할당받은 메모리 공간
	* 저장된 값은 변경 가능 
	***********************************************************/

	// <변수 선언 및 초기화>
	// 자료형을 선언하고 빈칸 뒤에 변수 이름 작성
	// 변수 선언과 동시에 초기화 과정 진행할 수 있음

	// <변수에 데이터 저장>
	// =(대입연산자) 좌측에 변수를 배치
	
	// <변수의 데이터 불러오기>
	// 데이터가 필요한 곳에 변수명을 배치

	string name = "홍길동";
	int strength = 10;
	float damage = strength * 0.8;
	float defence = 10.3;
	int level = 3;
	cout << "<현재 상태>"
		<< "\nName	: " << name
		<< "\nLevel   : " << level
		<< "\nStr	:" << strength
		<< "\n\nDamage  : " << damage
		<< "\nDefence : " << defence
		<< endl << endl;

	// <카멜 표기법>
	// 변수를 선언할 때는 소문자로 시작
	// 단어가 바뀔때마다 대문자로 표시
	// 함수를 선언할 때는 대문자로 시작

	/**************************************************************
	* 상수(Constant)
	* 
	* 프로그램이 실행되는 동안 변경할 수 없는 데이터
	* 프로그램에서 값이 변경되지 않기를 원하는 데이터가 있을 경우 사용
	* 저장된 값은 변경 불가능
	***************************************************************/
	
	// <상수 선언 및 초기화>>
	// 변수 선언 앞에 const를 입력
	// const int maxPlayer;	// error : 상수는 초기화 없이 사용 불가
	// maxPlayer = 200;		// error : 상수 데이터는 변경 불가능

	const int maxPlayer = 100;
	int IP;
	cout << "Input your IP	: ";
	cin >> IP;
	const int userIP = IP;
	cout << "Your IP is " << userIP
		<<endl <<endl;

	/****************************************************************************
	* 형변환 (Casting)
	* 
	* 데이터를 선언한 자료형에 맞는 형태로 변환하는 작업
	* C++의 자료형은 다른 자료형의 데이터를 저장하기 위해서 형변환 과정을 거쳐야 하며
	* 이 과정에서 보관할 수 없는 데이터는 버려짐
	*****************************************************************************/

	// <명시적 형변환>
	// 변환할 데이터 앞의 괄호 안에 변환할 자료형을 넣어 형변환
	float floatValue = (float)3;
	int intValue = (int)1.2;
	cout << "float 변수에 3을 형변환한 데이터는 " << floatValue << "입니다." << endl << endl;

	// <묵시적 형변환>
	// 변수에 데이터를 넣는 과정에서 자료형이 다른 경우 자동으로 형변환
	// 이 때, 데이터 손실을 최소화하는 방향을 형변환 진행
	// 하지만 자료형이 표현할 수 없는 범위의 데이터인 경우, 원하지 않는 데이터가 표현될 수 있음
	int num1 = 3.14;			// 의도하지 않는 경우 소수점 데이터 손실, 의도적일 경우 명시적 형변환을 하는 것이 직관적
	double num3 = 5;			// 데이터 손실 없이 double의 형태로 저장됨

	cout << "정수형 자료형으로 나눗셈을 진행하는 경우 : " << 1 / 4 << endl;           // 소수점이 버려진 0
	cout << "실수형 자료형으로 나눗셈을 진행하는 경우 : " << 1.0 / 4.0 << endl;       // 소수점이 있는 0.25
	cout << "정수형 자료형을 형변환 한 후 진행하는 경우 : " << (double)1 / 4 << endl << endl; // 소수점이 있는 0.25 (하나라도 double로 변환해주면 된다.)

	// <문자 형변환과 'ASCII CODE'>
	// 컴퓨터는 문자를 숫자로 변환하여 저장한다.
	// 이 때 사용하는 것이 'ASCII CODE'
	// (최신 트렌드는 UNI CODE)
	cout << "ASCII CODE를 문자로 변환 : ";
	int ascii;
	cin >> ascii;
	cout << ascii << "번째 ASCII CODE 문자는 " << (char)ascii << "입니다."
		<< endl << endl;
	cout << "문자를 ASCII CODE로 변환 : ";
	char asciiStr;
	cin >> asciiStr;
	cout << "\'" << asciiStr << "\'의 ASCII CODE는 " << (int)asciiStr << "입니다."
		<< endl << endl;

	// <문자열 형변환>
	// 문자열의 경우 string 헤더의 함수를 사용
	// 형변환이 불가능한 경우 예외처리가 발생
	cout << stoi("123") << endl		// stoi : string을 int로 변환	
		<< stof("3.1") << endl		// stof : string을 float로 변환
		<< stod("5.44") << endl;	// stod : string을 double로 변환
	// cout << stoi("abc") << endl; // error : 형변환이 불가능한 문자열의 경우 예외처리 발생

	string text = to_string(123); // 숫자를 문자열로 변환

	int valueTrue = true;	// true = 1
	int valueFalse = false; // false = 0

	bool valueBool = 3;		// 0을 제외한 숫자는 true로 반환
}

// <#define 과 const의 차이점>
// #define은 자료형에 무관하게 글자 그대로를 대체해서 사용
// const는 자료형이 고정

// <소수점 출력에 대해>
// 기본적으로 유효숫자 6개까지 출력
// cout << fixed	 : 앞으로 소수점만을 제어한다.
// cout.precision(n) : 유효숫자 n까지만 표현한다.

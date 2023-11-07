﻿#include <iostream>

using namespace std;

/*********************************************************
* 메모리 (Memory)
* 
* 프로그램을 처리하기 위해 필요한 정보를 저장하는 기억장치
* 프로그램은 메모리에 저장한 정보를 토대로 명령들을 수행함
*********************************************************/


/***********************************************************************
* 메모리 구조
* 
* 프로그램은 효율적인 메모리 관리를 위해 메모리 영역을 구분
* 데이터는 각 역할마다 저장되는 영역을 달리하여 접근범위, 생존범위 등을 관리
************************************************************************/

/* <메모리 구조>
   (0x0000...)  +------------+
   낮은 주소		| 코드 영역	 | => 실행할 프로그램의 코드
				+------------+
				| 데이터 영역 | => 전역변수, 정적변수
				+------------+
				| 힙 영역	 | => 사용자의 동적할당
				+~~~~~~~~~~~~+
				|			 | => (늘어나기도 하고 줄어들기도함)
				+~~~~~~~~~~~~+
   높은 주소		| 스택 영역	 | => 지역변수, 매개변수
   (0xFFFF...)  +------------+				
*/

// <코드 영역>
// 프로그램이 실행할 코드가 저장되는 영역
// 데이터가 변경되지 않는 읽기 전용 데이터

// <데이터 영역>
// 전역변수와 정적변수가 저장되는 영역
// 프로그램 시작시 할당되며 종료시 삭제됨

// <스택 영역>
// 지역변수와 매개변수가 저장되는 영역
// 함수 호출시 할당되며 종료시 삭제됨

// <힙 영역>
// (빈 영역)
// 사용자의 동적할당 메모리가 저장되는 영역
// 사용자가 프로그램 런타임 당시 요청으로 할당되며 반납으로 삭제됨

// <변수의 접근범위와 생존범위>
/*
			| 메모리 영역	접근 범위	생존 범위
	--------+----------------------------------------------------
	전역변수	| 데이터 영역	모든 범위	프로그램 시작에서 끝까지 
	--------+----------------------------------------------------
	정적변수	| 데이터 영역	블록 내부	프로그램 시작에서 끝까지		: 전역변수에서 접근 범위를 제한
	--------+----------------------------------------------------
	지역변수	| 스택 영역		블록 내부	블록 시작에서 끝까지
	매개변수	|	
	--------+----------------------------------------------------
	사용자의	| 힙 영역		포인터 변수	사용자의 할당부터 반납까지
	동적할당	|
*/

// <지역변수와 매개변수>
// 블록 시작에서 끝까지 데이터가 유지됨
// 블록 내부에서만 접근 가능
void Func1(int param)
{
	int value;

	value;		// 지역변수 접근 가능
	param;		// 매개변수 접근 가능
}

void Main1()
{
	// value;	// 지역변수 접근 불가
	// param;	// 매개변수 접근 불가
}

// <전역변수와 정적 변수>
// 공통점 : 프로그램 시작에서 끝까지 데이터가 유지됨
// 차이점 : 전역변수(모든 구역에서 접근 가능), 정적변수(블록 내부에서 접근 가능)
int g_value = 0;				// 함수 바깥에서 선언

void Func2()
{
	static int s_value = 0;		// 정적변수 초기화는 블록내에서 한번만 진행

	cout << "전역 변수 : " << g_value++
		<< ", 정적 변수 : " << s_value++ << endl;
}

void Main2()
{
	g_value;	// 전역변수 접근 가능
	// s_value;	// 정적변수 접근 불가
	Func2();	// 전역변수 : 0, 정적변수 : 0
	Func2();	// 전역변수 : 1, 정적변수 : 1
	Func2();	// 전역변수 : 2, 정적변수 : 2
}


/*********************************************************************
* 함수호출스택
* 
* 함수 호출과 종료에 연관되는 데이터를 저장하는 방법
* 프로그램은 스택구조를 통해 함수에서 사용한 데이터들을 효율적으로 관리함
**********************************************************************/

// <함수호출스택>
void Stack2() {}
void Stack1() 
{
    Stack2();
}

void Main3()
{
	Stack1();
}

/*
                  +-----------+                +-----------+               +-----------+
                  |           |                |           |               |           |
                  |           |                |           |               +-----------+
                  |           |                |           |               | Stack2()  |
                  |           |                |           |               | local     |
                  |           |                |           |               | parameter |
                  |           |                |           |               | return    |
                  |           |                +-----------+               +-----------+
                  |           |                | Stack1()  |               | Stack1()  |
                  |           |                | local     |               | local     |
                  |           |                | parameter |               | parameter |
                  |           |                | return    |               | return    |
                  +-----------+                +-----------+               +-----------+
                  | Main2()   |                | Main2()   |               | Main2()   |
                  | local     |                | local     |               | local     |
                  | parameter |                | parameter |               | parameter |
                  | return    |                | return    |               | return    |
    Main2 호출 -> +-----------+ Stack1 호출 ->  +-----------+ Stack2 호출 -> +-----------+

                  +-----------+               +-----------+               +-----------+
                  |           |               |           |               |           |
                  |           |               |           |               |           |
                  |           |               |           |               |           |
                  |           |               |           |               |           |
                  |           |               |           |               |           |
                  |           |               |           |               |           |
                  +-----------+               |           |               |           |
                  | Stack1()  |               |           |               |           |
                  | local     |               |           |               |           |
                  | parameter |               |           |               |           |
                  | return    |               |           |               |           |
                  +-----------+               +-----------+               |           |
                  | Main2()   |               | Main2()   |               |           |
                  | local     |               | local     |               |           |
                  | parameter |               | parameter |               |           |
                  | return    |               | return    |               |           |
   Stack2 종료 -> +-----------+ Stack1 종료 -> +-----------+ Main2 종료 -> +-----------+
*/

// <스택 오버플로우>
// 함수가 무한히 반복되거나 너무 많은 메모리를 사용하는 경우 스택영역에 빈공간이 부족
// 스택 영역을 벗어나 함수호출스택이 늘어나는 경우 스택 오버플로우 발생

void Func4()
{
    Func4();
}

void Main4()
{
    Func4();        // 함수호출스택이 늘어나다 스택영역이 넘치는 경우 스택 오버플로우 발생
}


/***************************************************************
* 동적할당 (Dynamic Allocate)
* 
* (스택영역에는 그 함수가 할당받는 메모리는 확정되어 있다)
* 런타임 당시 사용자가 사용할 메모리 공간을 할당받는 방법
* 사용이 끝나면 사용자가 사용한 메모리 공간을 반납해야 함
****************************************************************/

// <C 스타일 동적할당>
// malloc 함수를 통해 원하는 크기의 메모리를 할당받으며, 메모리 주소를 반환받음
// free 함수를 통해 반납해야하는 메모리 주소를 지정함
void Main5()
{
    // <동적할당>
    int* intPtr = (int*)malloc(sizeof(int));
    char* charPtr = (char*)malloc(sizeof(char));
    void* ptr = malloc(100);

    // <메모리 반납>
    free(intPtr);
    free(charPtr);
    free(ptr);
}

// <C++ 동적할당>
// new 키워드 후 자료형을 작성하여 자료형 크기의 메모리를 할당받으며, 메모리 주소를 반환받음
// delete 키워드 후 반납해야 하는 메모리 주소를 지정함
void Main6()
{
    // <동적할당>
    int* intPtr = new int;
    char* charPtr = new char;

    // <메모리 반납>
    delete intPtr;
    delete charPtr;

    // <안전한 메모리 반납>
    int* ptr1 = new int;
    delete ptr1;
    // delete ptr1;     // error : 이미 반납한 메모리는 반납할 수 없음
    
    int* ptr2 = new int;

    delete ptr2;
    ptr2 = nullptr;     // 메모리 반납 후 포인터 변수를 nullptr로 설정하여 메모리를 가리키지 않도록 설정

    delete ptr2;        // nullptr을 반납하려 하는 경우는 아무 일도 일어나지 않음
}

// <메모리 누수>
// 사용자가 동적할당한 메모리는 사용자가 반납하기 전까지 유지됨
// 사용자가 더이상 사용하지 않은 메모리를 반납하지 않는 경우 메모리 손실로 이어지고, 이를 메모리 누수라고 함
void Main7()
{
    int* intPtr = new int;

    // 동적할당 받은 메모리를 사용할 수 있는 구간

    // delete intPtr;       // 주의! 메모리를 반납하지 않으면 프로그램 종료까지 유지되며 메모리 누수가 됨
    // CRT : 메모리 누수를 확인하는 라이브러리
}

void Main8()
{
    // <얕은 복사>  -> 동일한 대상을 가리켜야 할때
    int playerX = 2;
    int* monsterDestX = &playerX;

    // <깊은 복사>  -> 동일한 값을 가져야 할때
    int* monsterPotion = new int;
    *monsterPotion = 10;
    int* monster2Potion = new int;
    *monster2Potion = *monsterPotion;
    *monsterPotion = 9;
    cout << *monsterPotion << endl;
    cout << *monster2Potion;
}

int main()
{
	Main8();
}
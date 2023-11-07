#include <iostream>

using namespace std;

int main()
{
	/***************************************************
	* 조건문 (Conditional)
	* 
	* 조건에 따라 실행이 달라지게 할 때 사용하는 문장
	****************************************************/


	/***************************************************
	* <if 조건문>
	*
	* 조건식의 true, false에 따라 실행할 블록을 결정
	****************************************************/

	// <if 조건문 기본>
	bool bValue; // 처음에 선언할 때는 true or false 입력 가능
	cout << "Input true(1) or false(0)" << endl; // bool에 cin을 받을거면 1이나 0으로 입력
	cin >> bValue;
	if (bValue) // 조건이 true인 경우 바로 아래 블록 실행
	{
		cout << "You choose 'true'" << endl;
	}
	else		// 조건이 false인 경우 else 블록 실행
	{
		cout << "You choose 'false'" << endl;
	}
	cout << endl;

	// else 블록은 선택사항
	int studentCount;
	cout << "How many student are there?" << endl;
	cin >> studentCount;
	if (studentCount > 20)
	{
		cout << "책상을 추가합니다." << endl;
	}
	cout << endl;
	// else
	// {
	//		아무것도 하지 않음;
	// }
 
	// else 블록에 if 문을 추가함으로 여러 조건을 확인할 수 있음
	string input;
	cout << "Choose rock/scissors/paper" << endl;
	cin >> input;

	if (input == "scissors")
	{
		cout << "You choose scissors" << endl;
	}
	else
	{
		if (input == "rock")
		{
			cout << "You choose rock" << endl;
		}
		else 
		{
			if (input == "paper")
			{
				cout << "You choose paper" << endl;
			}
			else
			{
				cout << "Error!" << endl;
			}
		}
	}
	cout << endl;

	// else 블록에 if 문이 있다면 블록을 생략해도 동일한 효과
	// else if 키워드가 따로 있는 것이 아닌 else + if
	cout << "Retry. Choose rock/scissors/paper" << endl;
	cin >> input;

	if (input == "scissors")
	{
		cout << "You choose scissors" << endl;
	}
	else if (input == "rock")
	{
		cout << "You choose rock" << endl;
	}
	else if (input == "paper")
	{
		cout << "You choose paper" << endl;
	}
	else
	{
		cout << "Error!" << endl;
	}
	cout << endl;


	/**********************************************************
	* switch 조건문
	* 
	* 조건값에 따라 실행할 시작지점을 결정하는 조건문
	***********************************************************/

	// <switch 조건문 기본>
	cout << "Choose Option" << endl
		<< "1. Start Game" << endl
		<< "2. Settings" << endl
		<< "3. End Game" << endl;
	int option;
	cin >> option;
	switch (option)							// 조건값 지정
	{
	case 1:									// 조건값이 일치하지 않으면 넘어감
		cout << "Start Game Now..." << endl;
		break;
	case 2:									// 일치하는 case부터 시작
		cout << "Settings" << endl;
		break;
	case 3:
		cout << "End Game" << endl;
		break;					   			// break가 있는 지점에서 switch 블록을 빠져나감
	default:								// 조건값이 일치하는 case가 없는 경우 default 가 실행지점이 됨
		cout << "Error!" << endl;
		break;								// 생략해도 문제는 없음 취향 차이
	}
	cout << endl;
	// 주의!
	// break를 적지 않으면 실행된 case부터 밑의 조건까지 같이 실행

	// 조건값에 따라 동일한 실행이 필요한 경우 묶어서 사용 가능
	cout << "Move your Character" << endl;
	char key;
	cin >> key;
	switch (key)
	{
	case 'w':
	case 'W':
		cout << "Move Upward" << endl;
		break;
	case 'a':
	case 'A':
		cout << "Move leftward" << endl;
		break;
	case 's':
	case 'S':
		cout << "Move downward" << endl;
		break;
	case 'd':
	case 'D':
		cout << "Move rightward" << endl;
		break;
	}
	cout << endl;


	/**********************************************
	* 삼항 연산자
	* 
	* 간단한 조건문을 빠르게 작성
	***********************************************/
	
	// <삼항 연산자 기본>
	// 조건식 ? true인 경우 값 : false인 경우 값
	cout << "Which is bigger? Input two numbers" << endl
		<< "A : ";
	int leftValue;
	cin >> leftValue;
	cout << "B : ";
	int rightValue;
	cin >> rightValue;
	int bigger = leftValue > rightValue ? leftValue : rightValue;
	cout << bigger << " is bigger" << endl;
}
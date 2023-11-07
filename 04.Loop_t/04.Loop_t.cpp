#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "1번 문제" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "2번 문제" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "3번 문제" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > i; j--)
		{
			cout << "*";

		}
		cout << endl;
	}
	cout << endl;

	cout << "4번 문제" << endl;
	int number;
	cout << "숫자를 입력하세요." << endl;
	cin >> number;
	for (int i = 0; i < 2*number-1; i++)
	{
		if (i < number)
		{
			for (int j = 0; j < number-1 - i; j++)
			{
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j < i - number+1; j++)
			{
				cout << " ";
			}
			for (int j = 0; j < (4*number-3)-(2 * i) ; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	cout << endl;

	cout << "4번 문제(다른 풀이)" << endl;
	cout << "숫자를 입력해주세요." << endl;
	cin >> number;
	for (int i = -(number-1); i <= number-1; i++)
	{
		for (int j = 0; j < abs(i); j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*(number - abs(i))-1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	cout << "4번 문제(교수님 풀이)" << endl;
	cout << "숫자를 입력해주세요." << endl;
	cin >> number;
	for (int y = -number+1; y <= number-1; y++)
	{
		for (int x = -number + 1; x <= number - 1; x++)
		{
			int absX = x > 0 ? x : -x;
			int absY = y > 0 ? y : -y;
			if (absX + absY >= number)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

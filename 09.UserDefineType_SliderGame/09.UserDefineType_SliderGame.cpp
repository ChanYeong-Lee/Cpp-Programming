#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

void Swap(int* left, int* right)	// Swap 함수
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

int GetKeyDown()					// 방향키 입력 받기
{
	int input = _getch();
	if (input == 224)
	{
		input = _getch();
		return input;
	}
	if (input == 'a')
		return input;
	else
		return 0;
}

void MoveUp(int* array, int size, int key)
{
	if (key - size < 0)
		return;
	else
		Swap(array + key, array + key - size);
}

void MoveDown(int* array, int size, int key)
{
	if (key + size >= size * size)
		return;
	else
		Swap(array + key, array + key + size);
}

void MoveLeft(int* array, int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (key >= i * size && key < (i + 1) * size)
			if (key - 1 == i * size - 1)
				break;
			else
				Swap(array + key, array + key - 1);
	}
}

void MoveRight(int* array, int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (key >= i * size && key < (i + 1) * size)
			if (key + 1 == (i + 1) * size)
				break;
			else
				Swap(array + key, array + key + 1);
	}
}

int InputSize()									// Size 입력
{
	int size = 0;
	while (true)
	{
		cout << "Input Puzzle Size (3 ~ 6) : ";
		cin >> size;
		if (3 <= size && size <= 6)
			return size;
		system("cls");
	}
	return 0;
}

void Shuffle(int* array, int size)				// 퍼즐 섞기
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 50; i++)
	{
		int left = rand() % (size * size);
		int right = rand() % (size * size);

		if (left != right)
		{
			Swap(&array[left], &array[right]);
		}
	}
}

void CreatePuzzle(int* array, int size)			// 퍼즐 만들기
{
	for (int i = 0; i < size * size; i++)
	{
		array[i] = i;
	}
	Shuffle(array, size);
}

void DisplayPuzzle(int* array, int size)		// 퍼즐 출력
{
	system("cls");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i * size + j] < 10)
			{
				cout << " ";
			}
			cout << array[i * size + j] << " ";
		}
		cout << endl;
	}
}

int* StartUp(int size)							// 퍼즐 섞고, 최초로 출력
{
	int* array = new int[size * size];
	CreatePuzzle(array, size);
	DisplayPuzzle(array, size);
	return array;
}

int FindKey(int* array, int size)				// 섞인 퍼즐에서 Key(0) 찾기
{
	int key = 0;
	for (int i = 0; i < size * size; i++)
	{
		if (array[i] == 0)
		{
			key = i;
			break;
		}
	}
	return key;
}

void Move(int* array, int size, int key)		// 방향키를 입력받아 이동
{
	int input = GetKeyDown();
	switch (input)
	{
	case UP:
		MoveUp(array, size, key);
		break;
	case DOWN:
		MoveDown(array, size, key);
		break;
	case LEFT:
		MoveLeft(array, size, key);
		break;
	case RIGHT:
		MoveRight(array, size, key);
		break;
	case 'a':
		for (int i = 0; i < size * size - 2; i++)
		{
			*(array + i) = i + 1;
		}
		*(array + size * size - 2) = 0;
		*(array + size * size - 1) = size * size - 1;
	}
}

void GameStart(int* array, int size)	// key(0)을 찾고 이동
{
	int key = FindKey(array, size);
	Move(array, size, key);
}

bool CheckGame(int* array, int size)	// 게임 종료 여부 판단
{
	for (int i = 0; i <= size * size - 2; i++)
	{
		if (array[i] == i + 1)
		{
			if (i == size * size - 2 && array[i] == i + 1)
				return TRUE;
			continue;
		}
		break;
	}
	return FALSE;
}

void Finish()	// 게임 종료
{
	cout << endl << "You solve the puzzle! Congratulations!" << endl;
}

int main()
{
	int size = InputSize();						// 1. Size input
	int* array = StartUp(size);					// 2. Make Puzzle
	while (true)								// <Game Loop(3~5)>
	{
		bool checker = CheckGame(array, size);	// 3. Checker
		if (checker != true)
		{
			GameStart(array, size);				// 4. Start Game
			DisplayPuzzle(array, size);			// 5. Display Puzzle
		}
		else
		{
			Finish();							// 6.Finish Game
			break;
		}
	}
	return 0;
}
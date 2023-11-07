#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime> 
#include <Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
void Swap(int* left, int* right);
void Move(int key, int* array);
void Table(int* array);
using namespace std;


void Move(int key,int* array) 
{
    int input;
    while (true) 
    {
        input = _getch(); // 키 입력 받기

        if (input == 224) { // 화살표 키의 첫 번째 바이트를 나타내는 값
            input = _getch(); // 화살표 키의 두 번째 바이트를 읽음

            switch (input) {
            case UP: // 위쪽 화살표
                if (key - 5 < 0)
                    break;
                Swap(array + key, array+ key - 5);
                break;
            case DOWN: // 아래쪽 화살표
                if (key + 5 > 25)
                    break;
                Swap(array + key, array + key + 5);
                break;
            case LEFT: // 왼쪽 화살표
                for (int i = 0; i < 5; i++)
                {
                    if (key >= i * 5 && key < (i + 1) * 5)
                        if (key - 1 == i * 5 - 1)
                            break;
                        else
                            Swap(array + key, array + key - 1);
                }
                break;
            case RIGHT: // 오른쪽 화살표
                for (int i = 0; i < 5; i++)
                {
                    if (key >= i * 5 && key < (i + 1) * 5)
                        if (key + 1 == (i + 1) * 5 )
                            break;
                        else
                            Swap(array + key, array + key + 1);
                }
                break;
            default:
                break;
            }
        }
        return;
    }
}

void Swap(int* left, int* right)
{
        int temp = *left;
        *left = *right;
        *right = temp;
}

void Table(int* array)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (*(array + 5 * i + j) < 10)
                cout << " ";
            cout << *(array +5*i+ j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    int data[25];
    int x;
    int y;
    int key;
    for (int i = 0; i < 25; i++)
    {
        data[i] = i;
    }
    for (int i = 0; i < 50; i++)
    {
        x = rand() % 25;
        y = rand() % 25;

        if (x != y)
        {
            Swap(&data[x], &data[y]);
        }
    }

    bool gameover = false;
    Table(data);

    while (gameover == 0)
    {
        for (int i = 0; i < 25; i++)
        {
            if (data[i] == 0)
            {
                key = i;
                break;
            }
        }
        Move(key,data);
        system("cls");
        Table(data);

        if (data[0] == 1)
        {
            for (int i = 0; i < 25; i++)
            {
                if (data[i] == i + 1)
                    continue;
                if (i == 24)
                {
                    if (data[i] == 0)
                        gameover = 1;
                    break;
                }
                break;
            }
        }
    }
    cout << "You cleared game! Congratulation!" << endl;
}
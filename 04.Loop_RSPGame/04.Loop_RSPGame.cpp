#include<iostream>
#include<cstdlib>
#include<ctime> 

using namespace std;

int main()
{
	int playerVp;
	int computerVp;
	int foul;
	srand((unsigned int)time(NULL));
	string playerHand;
	int computerHand;
	char restart;

	cout << "<가위바위보 게임>" << endl << endl;

	cout << "[규칙 설명]" << endl << endl;

	cout << "1. 플레이어는 \"가위\", \"바위\", \"보\" 중 한 개를 선택합니다." << endl;
	cout << "2. 컴퓨터는 셋 중 하나를 랜덤하게 선택합니다." << endl;
	cout << "3. 가위바위보를 이긴 사람이 승점 1점을 가져갑니다." << endl;
	cout << "4. 승점 3점을 먼저 획득한 사람이 최종 승리를 합니다." << endl;
	cout << "5. 오타를 치면 Foul이 올라가고 Foul이 3이 되면 상대편에게 승점 1점을 줍니다." << endl << endl;

	cout << "1. 게임 시작" << endl;
	cout << "2. 게임 종료" << endl << endl;

	int option;
	cin >> option;
	cout << endl;
	switch (option)
	{
	case 1:
		do
		{
			cout << "게임을 시작합니다." << endl << endl;

			playerVp = 0;
			computerVp = 0;
			foul = 0;
			while ((computerVp != 3) && (playerVp != 3))
			{
				cout << "\"가위\", \"바위\", \"보\" 중 한 개를 선택해주세요." << endl << endl;
				cin >> playerHand;
				cout << endl;
				computerHand = rand() % 3;
				if (playerHand == "가위")
				{
					switch (computerHand)
					{
					case 0:
						cout << "컴퓨터는 \"가위\"를 선택했습니다." << endl;
						cout << "비겼습니다!" << endl;
						break;
					case 1:
						cout << "컴퓨터는 \"바위\"를 선택했습니다." << endl;
						cout << "컴퓨터가 이겼습니다!" << endl;
						computerVp += 1;
						break;
					case 2:
						cout << "컴퓨터는 \"보\"를 선택했습니다." << endl;
						cout << "당신이 이겼습니다!" << endl;
						playerVp += 1;
						break;
					}
				}
				else if (playerHand == "바위")
				{
					switch (computerHand)
					{
					case 0:
						cout << "컴퓨터는 \"가위\"를 선택했습니다." << endl;
						cout << "당신이 이겼습니다!" << endl;
						playerVp += 1;
						break;
					case 1:
						cout << "컴퓨터는 \"바위\"를 선택했습니다." << endl;
						cout << "비겼습니다!" << endl;
						break;
					case 2:
						cout << "컴퓨터는 \"보\"를 선택했습니다." << endl;
						cout << "컴퓨터가 이겼습니다!" << endl;
						computerVp += 1;
						break;
					}
				}
				else if (playerHand == "보")
				{
					switch (computerHand)
					{
					case 0:
						cout << "컴퓨터는 \"가위\"를 선택했습니다." << endl;
						cout << "컴퓨터가 이겼습니다!" << endl;
						computerVp += 1;
						break;
					case 1:
						cout << "컴퓨터는 \"바위\"를 선택했습니다." << endl;
						cout << "당신이 이겼습니다!" << endl;
						playerVp += 1;
						break;
					case 2:
						cout << "컴퓨터는 \"보\"를 선택했습니다." << endl;
						cout << "비겼습니다!" << endl;
						break;
					}
				}
				else
				{
					cout << "잘못 입력하였습니다." << endl;
					cout << "Foul이 1개 올라갑니다." << endl;
					foul += 1;
				}
				if (foul == 3)
				{
					computerVp += 1;
					cout << endl;
					cout << "foul이 3개가 되었습니다. 컴퓨터는 승점 1점 획득합니다." << endl;
					foul = 0;
				}
				cout << endl;
				cout << "[현재 승점]" << endl;
				cout << "You:Com:Foul" << endl;
				cout << " " << playerVp << "   " << computerVp << "   " << foul << endl << endl;
			}
			if (playerVp == 3)
				cout << "당신이 이겼습니다! 축하합니다!" << endl;
			else
				cout << "컴퓨터가 이겼습니다! 아쉽네요!" << endl;
			cout << endl;
			cout << "재시작 하시겠습니까? (Y/N)" << endl << endl;
			cin >> restart;
			cout << endl;
		} while (restart == 'Y' || restart == 'y');
	case 2:
		cout << "게임을 종료합니다." << endl;
	}
}


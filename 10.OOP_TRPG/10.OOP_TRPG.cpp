#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <Windows.h>
#include <string>

using namespace std;

struct Stats
{
	int	maxHp;
	int	attackDamage;
	int defense;
	int criticalPercent;
	int criticalRate;
};

class Equipment abstract
{
protected:
	bool equiped;
};

class HatSlot : public Equipment		// 모자는 체력, 방어력
{};

class ArmorSlot : public Equipment		// 방어구는 체력, 방어력
{};

class WeaponSlot : public Equipment		// 무기는 공격력, 치명타피해
{};

class ShoeSlot : public Equipment		// 신발은 체력, 치명타확률
{};

class Item abstract
{
protected:
	string name;
	int stack;
public:
	void Use()
	{
		Function();
		stack -= 1;
	}
	virtual void Function() = 0;
};

class Character abstract
{
private:
	int level;
	Stats stats;
	int currentHp;
	string name;
	bool alive;
public:
	Character(string _name, int _level)
	{	
		name = _name;
		alive = TRUE;
		level = _level;
		currentHp = stats.maxHp;
	}
	void TakeHit(int damage)
	{
		if (currentHp > damage)
			currentHp -= damage;
		else
		{
			currentHp = 0;
			Die();
		}
	}
	void Die()
	{
		alive = FALSE;
	}
	void LevelUp()
	{
		level += 1;
	}
	void ShowName()
	{
		cout << name;
	}
};

class Defender : public Character
{
	
};

class Dealer : public Character
{};

class Healer : public Character
{};

class Skill abstract
{};

class Player
{
public:
	string name;
	Character* characters[3] = { nullptr, nullptr,nullptr };
	Player(string _name) : name("_name") {}
	void SetName(string _name)
	{
		name = _name;
	}
};

class Game
{
public:
	Game()
	{
		gameChecker = TRUE;
	}
	bool gameChecker;
	void GameOver() 
	{
		gameChecker=FALSE;
	}
	bool GameCheck()
	{
		if (gameChecker == TRUE)
			return TRUE;
		else
			return FALSE;
	}
	void GameStart() {}
	void NameSetting()
	{
		system("cls");
		string playerName;
		string defenderName;
		string dealerName;
		string healerName;
		cout << "환영합니다! \n당신은 누구십니까? ";
		cin >> playerName;
		Player* player = new Player(playerName);
		cout << "\n반갑습니다! " << player->name << "님." << endl << endl;
		cout << "당신에겐 방어자, 공격자, 보호자 캐릭터가 주어집니다." << endl;
		cout << "각자의 이름을 정해주세요." << endl;
		cout << "방어자 : ";
		cin >> defenderName;
		player->characters[0] = new Defender(defenderName, 1);
		cout << "공격자 : ";
		cin >> dealerName;
		player->characters[1] = new Dealer("dd",0);
		cout << "보호자 : ";
		cin >> healerName;
		player->characters[2] = new Healer(healerName, 1);
		cout << "\n좋아요. "; player->characters[0]->ShowName(); cout << ", " << (*player).characters[1]->name << ", " << (*player).characters[2]->name << "와/과 함께 시작합니다." << endl << endl;
		Sleep(2000);
	}
	void CharacterSetting()
	{}
	void GameOption()
	{
		system("cls");
		cout << "1. 게임 시작" << endl;
		cout << "2. 이름 설정" << endl;
		cout << "3. 게임 종료" << endl << endl;;
		cout << "옵션을 선택해주세요 : ";
		int input;
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 1:
			cout << "게임을 시작합니다." << endl << endl;
			Sleep(1000);
			cout << "3.. ";
			Sleep(1000);
			cout << "2.. ";
			Sleep(1000);
			cout << "1.. ";
			Sleep(1000);
			GameStart();
			break;
		case 2:
			NameSetting();
			break;
		case 3:
			GameOver();
			break;
		default:
			return;
		}
	}
};

int main()
{
	Game game;
	game.NameSetting();
	game.CharacterSetting();
	game.GameOption();
	while (game.GameCheck() == TRUE)
	{
		
	} 

}
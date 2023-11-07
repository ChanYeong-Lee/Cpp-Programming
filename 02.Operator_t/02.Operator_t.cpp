#include <iostream>
using namespace std;

int main()
{
	string name;	//캐릭터 이름
	int bDmg;		//기본 데미지
	float qbDmgPer;	//Q 스킬의 기본 데미지 계수
	float qiDmgPer;	//Q 스킬의 아이템 데미지 계수
	int iDmg;		//아이템 데미지
	int dmgRate;	//레벨업마다 데미지 증가량
	int level;		//캐릭터 레벨
	int qDmg;		//Q 스킬 최종 데미지
	
	name = "Lee";
	bDmg = 80;
	qbDmgPer = 0.8;
	qiDmgPer = 0.6;
	dmgRate = 20;
	level = 1;
	bDmg += (level - 1) * dmgRate;

	cout << "캐릭터 이름 : " << name << endl
		<< "현재 레벨 : " << level << endl
		<< "기본 데미지 : " << bDmg << endl
		<< "레벨업 당 데미지 증가량 : " << dmgRate << endl << endl
		<< "Q 스킬 기본 데미지 계수 : " << qbDmgPer << endl
		<< "Q 스킬 아이템 데미지 계수 : " << qiDmgPer << endl << endl
		<< "아이템 데미지 : ";
	cin >> iDmg;	
	

	qDmg = bDmg + iDmg + bDmg * qbDmgPer + iDmg * qiDmgPer; 
	// 최종 데미지 = 
	// 기본 데미지 + 아이템 데미지 
	// + 기본데미지계수*기본데미지
	// + 아이템데미지계수*아이템데미지
	
	cout << endl << "Q 스킬 데미지는 " << qDmg << "입니다." << endl << endl;
	cout << "당신의 레벨은? ";
	cin >> level;
	bDmg += (level - 1) * dmgRate;
	qDmg = bDmg + iDmg + bDmg * qbDmgPer + iDmg * qiDmgPer ;
	cout << endl << "Q 스킬 데미지는 " << qDmg << "입니다." << endl;
}


/****************************************************
<실습>
카사딘
기본 공격력 10
Q스킬 계수 0.6
장비를 통한 공격력 증가 : {입력}

Q스킬 최종 데미지 : 기본 공격력 + 스킬 계수 * 총 공격력
카사딘의 Q스킬 데미지는 " " 입니다.

+a) 레벨업했을 때 공격력 상승
카사딘이 레벨 2 오르면 Q스킬 데미지는 " " 입니다.
*****************************************************/

/*************************************************
* <과제>
* int value = 5;
* bool result = 1 <= level <= 250;
* -> 컴퓨터 논리적으로 틀린 얘기
* 1. 위의 내용이 컴퓨터이기 때문에 틀린 이유
* 2. 위 내용을 제대로 구현하기 위한 방법
* 3. 비트 마스크
**************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int level;
    float height;

    cout << "<캐릭터 설정>\n"
        << "캐릭터의 이름을 입력해주세요.\n";
    cin >> name;
    cout << "캐릭터의 레벨을 입력해주세요.\n";
    cin >> level;
    cout << "캐릭터의 키를 입력해주세요.\n";
    cin >> height;

    cout << "\n<캐릭터 상태>"
        << "\n이름 : " << name
        << "\n레벨 : " << level
        << "\n키   : " << height;
}

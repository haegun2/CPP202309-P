#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void addMenuItem();

int main() {

    while (true) {
        cout << "\n----- 오늘 점심 뭐 먹지?? -----\n";
        cout << "1. 메뉴 추가\n2. 메뉴 추천\n3. 현재 저장된 메뉴 보기\n4. 저장 후 종료\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addMenuItem();
            break;

        case 2:
            //recommendMenu();
            cout << "마지막 주차에 메뉴 추천 부분 오픈 예정" << endl;
            break;

        case 3:
            cout << "CSV 파일에서 불러온 값을 출력하여 보여줄 예정" << endl;
            break;

        case 4:
            cout << "프로그램을 종료합니다." << endl;
            return 0;

        default:
            cout << "유효하지 않은 선택입니다. 다시 선택하세요." << endl;
        }
    }
    return 0;
}

void addMenuItem() {
    string name;
    int rating;
    cout << "메뉴 이름을 입력하세요: ";
    cin >> name;
    cout << "별점을 1에서 5 사이의 숫자로 입력하세요: ";
    cin >> rating;
    if (rating < 1 or rating > 5) {
        cout << "유효하지 않은 별점입니다. 1에서 5 사이의 숫자를 입력하세요." << endl;
        return;
    }
    cout << "이후 내용은 csv 파일에 저장하는 내용 추가 될 예정" << endl;
    return;
}
#include "lunch.h"

int main() {
    ManageUsers();

    while (true) {
        cout << "\n----- 오늘 점심 뭐 먹지?? -----\n";
        cout << "1. 메뉴 추가\n2. 메뉴 추천\n3. 현재 저장된 메뉴 보기\n4. 저장 후 종료\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            AddMenuItem();
            break;

        case 2:
            RecommendMenu();
            break;

        case 3:
            for (const MenuItem& item : menuItems) {
                cout << "메뉴: " << item.name << " (별점 : " << item.rating << " )" << endl;
            }
            break;

        case 4:
            SaveMenu(user_who); // 프로그램 종료 시 메뉴 저장
            return 0;

        default:
            //1,2,3,4 를 제외한 나머지 입력시 출력 할 예외처리 부분
            cout << "유효하지 않은 선택입니다. 다시 선택하세요." << endl;
        }
    }
    return 0;
}
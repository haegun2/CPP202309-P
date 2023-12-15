#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void AddMenuItem();

int main() {

    //cin으로 유저 이름을 입력받고, 유저의 파일을 켜서 수정 할 예정

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
            //random 함수 이용 메뉴와 별점이 반영이 될 수 있게 별점에 비례하게 생성된 전체 데이터셋에서
            //랜덤으로 추출한 값을 리스트 길이로 나누고, 그 값을 추천할 예정

            cout << "마지막 주차에 메뉴 추천 부분 오픈 예정" << endl;
            break;

        case 3:
            //csv파일의 값을 불러와 줄당 메뉴 1개 값 출력 예정
            cout << "CSV 파일에서 불러온 값을 출력하여 보여줄 예정" << endl;
            break;

        case 4:
            //파일 닫기 부분
            cout << "프로그램을 종료합니다." << endl;
            return 0;

        default:
            //1,2,3,4 를 제외한 나머지 입력시 출력 할 예외처리 부분
            cout << "유효하지 않은 선택입니다. 다시 선택하세요." << endl;
        }
    }
    return 0;
}

void AddMenuItem() {
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
    //클래스와 벡터 사용하여 입출력 고려 예정
}
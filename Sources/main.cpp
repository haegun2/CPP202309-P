#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

struct MenuItem {
    string name;
    int rating;
};

vector<MenuItem> menuItems;
string user_who; // 사용자를 식별하는 변수

void AddMenuItem();
void SaveMenu(const string& user);
void RecommendMenu();

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
    MenuItem item;
    item.name = name;
    item.rating = rating;
    menuItems.push_back(item);
    cout << "메뉴가 추가되었습니다." << endl;

    // 메뉴 추가 후, 메뉴 저장
    SaveMenu(user_who);
}

void SaveMenu(const string& user) {
    ofstream menu_file(user + "_menu.csv");
    if (menu_file.is_open()) {
        for (const MenuItem& item : menuItems) {
            menu_file << item.name << "," << item.rating << "\n";
        }
        menu_file.close();
    }
    else {
        cerr << "메뉴 파일을 생성할 수 없습니다." << endl;
    }
}

void RecommendMenu() {
// 메뉴가 비었는지 확인하고 비었으면 저장된 메뉴 없다고 출력하는 부분
    if (menuItems.empty()) {
        cout << "저장된 메뉴가 없습니다." << endl;
        return;
    }

    vector<double> probabilities;
    double total_probability = 0.0;

    // 각 메뉴별 점수가 확률화 된게 probabilities에 저장
    // 별점을 전부 더하여 총 합 확률을 구해서 total_probability에 저장
    for (const MenuItem& item : menuItems) {
        probabilities.push_back(static_cast<double>(item.rating));
        total_probability += item.rating;
    }

    // 확률을 모두 더해 1로 정규화
    for (double& probability : probabilities) {
        probability /= total_probability;
    }
    // 난수를 생성하는 부분
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<int> distribution(probabilities.begin(), probabilities.end());

    //랜덤하게 메뉴 선택 후 정보 출력
    int random_selected = distribution(gen);
    double pick_per_all = probabilities[random_selected] * 100.0;

    cout << "추천 메뉴: " << menuItems[random_selected].name << " (유저평점 " << menuItems[random_selected].rating << "점, " << pick_per_all << "% 확률로 추천됨)" << endl;
}
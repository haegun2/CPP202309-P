#include "lunch.h"

vector<MenuItem> menuItems;
string user_who;

void ManageUsers() {
    ifstream UserListFile("user_list.csv");
    if (!UserListFile.is_open()) {
        cout << "사용자 목록 파일이 없습니다. 새 사용자를 추가하세요." << endl;
        AddUser();
    }
    else {
        string line;
        cout << "사용자 목록:" << endl;
        while (getline(UserListFile, line)) {
            cout << line << endl;
        }
        user_who = ""; // 기본값 설정
        UserListFile.close();

        cout << "사용자를 입력하세요: ";
        cin >> user_who;

        if (!UserExists(user_who)) {
            AddUser();
        }
        else {
            LoadMenu(user_who);
        }
    }
}

bool UserExists(const string& user_name) {
    ifstream UserListFile("user_list.csv");
    if (UserListFile.is_open()) {
        string line;
        while (getline(UserListFile, line)) {
            if (line == user_name) {
                return true;
            }
        }
        user_who = "";
        UserListFile.close();
    }
    return false;
}

void AddUser() {
    ofstream UserListFile("user_list.csv", ios::app); // 기존 목록에 덧붙이기 모드로 열기
    if (!UserListFile.is_open()) {
        cerr << "사용자 목록 파일을 열 수 없습니다." << endl;
        return;
    }

    cout << "새 사용자 이름을 입력하세요: ";
    cin >> user_who;

    UserListFile << user_who << endl;
    UserListFile.close();

    // 새 사용자가 추가되면, 해당 사용자의 메뉴 파일 생성 (빈 파일)
    ofstream userMenuFile(user_who + "_menu.csv");
    if (!userMenuFile.is_open()) {
        cerr << "메뉴 파일을 생성할 수 없습니다." << endl;
        return;
    }
}

void LoadMenu(const string& user) {
    menuItems.clear(); // 기존 데이터를 모두 지웁니다.

    ifstream file(user + "_menu.csv");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t commaPos = line.find(",");
            if (commaPos != string::npos) {
                MenuItem item;
                item.name = line.substr(0, commaPos);
                item.rating = stoi(line.substr(commaPos + 1));
                menuItems.push_back(item);
            }
        }
        file.close();
    }
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
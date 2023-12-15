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
string user_who; // ����ڸ� �ĺ��ϴ� ����

void AddMenuItem();
void SaveMenu(const string& user);
void RecommendMenu();

int main() {

    //cin���� ���� �̸��� �Է¹ް�, ������ ������ �Ѽ� ���� �� ����

    while (true) {
        cout << "\n----- ���� ���� �� ����?? -----\n";
        cout << "1. �޴� �߰�\n2. �޴� ��õ\n3. ���� ����� �޴� ����\n4. ���� �� ����\n";
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
                cout << "�޴�: " << item.name << " (���� : " << item.rating << " )" << endl;
            }
            break;

        case 4:
            SaveMenu(user_who); // ���α׷� ���� �� �޴� ����
            return 0;

        default:
            //1,2,3,4 �� ������ ������ �Է½� ��� �� ����ó�� �κ�
            cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    }
    return 0;
}



void AddMenuItem() {
    string name;
    int rating;
    cout << "�޴� �̸��� �Է��ϼ���: ";
    cin >> name;
    cout << "������ 1���� 5 ������ ���ڷ� �Է��ϼ���: ";
    cin >> rating;
    if (rating < 1 or rating > 5) {
        cout << "��ȿ���� ���� �����Դϴ�. 1���� 5 ������ ���ڸ� �Է��ϼ���." << endl;
        return;
    }
    MenuItem item;
    item.name = name;
    item.rating = rating;
    menuItems.push_back(item);
    cout << "�޴��� �߰��Ǿ����ϴ�." << endl;

    // �޴� �߰� ��, �޴� ����
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
        cerr << "�޴� ������ ������ �� �����ϴ�." << endl;
    }
}

void RecommendMenu() {
// �޴��� ������� Ȯ���ϰ� ������� ����� �޴� ���ٰ� ����ϴ� �κ�
    if (menuItems.empty()) {
        cout << "����� �޴��� �����ϴ�." << endl;
        return;
    }

    vector<double> probabilities;
    double total_probability = 0.0;

    // �� �޴��� ������ Ȯ��ȭ �Ȱ� probabilities�� ����
    // ������ ���� ���Ͽ� �� �� Ȯ���� ���ؼ� total_probability�� ����
    for (const MenuItem& item : menuItems) {
        probabilities.push_back(static_cast<double>(item.rating));
        total_probability += item.rating;
    }

    // Ȯ���� ��� ���� 1�� ����ȭ
    for (double& probability : probabilities) {
        probability /= total_probability;
    }
    // ������ �����ϴ� �κ�
    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<int> distribution(probabilities.begin(), probabilities.end());

    //�����ϰ� �޴� ���� �� ���� ���
    int random_selected = distribution(gen);
    double pick_per_all = probabilities[random_selected] * 100.0;

    cout << "��õ �޴�: " << menuItems[random_selected].name << " (�������� " << menuItems[random_selected].rating << "��, " << pick_per_all << "% Ȯ���� ��õ��)" << endl;
}
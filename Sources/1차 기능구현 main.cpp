#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void addMenuItem();

int main() {

    while (true) {
        cout << "\n----- ���� ���� �� ����?? -----\n";
        cout << "1. �޴� �߰�\n2. �޴� ��õ\n3. ���� ����� �޴� ����\n4. ���� �� ����\n";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            addMenuItem();
            break;

        case 2:
            //recommendMenu();
            cout << "������ ������ �޴� ��õ �κ� ���� ����" << endl;
            break;

        case 3:
            cout << "CSV ���Ͽ��� �ҷ��� ���� ����Ͽ� ������ ����" << endl;
            break;

        case 4:
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;

        default:
            cout << "��ȿ���� ���� �����Դϴ�. �ٽ� �����ϼ���." << endl;
        }
    }
    return 0;
}

void addMenuItem() {
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
    cout << "���� ������ csv ���Ͽ� �����ϴ� ���� �߰� �� ����" << endl;
    return;
}
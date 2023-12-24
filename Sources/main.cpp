#include "lunch.h"

int main() {
    ManageUsers();

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
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void AddMenuItem();

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
            //random �Լ� �̿� �޴��� ������ �ݿ��� �� �� �ְ� ������ ����ϰ� ������ ��ü �����ͼ¿���
            //�������� ������ ���� ����Ʈ ���̷� ������, �� ���� ��õ�� ����

            cout << "������ ������ �޴� ��õ �κ� ���� ����" << endl;
            break;

        case 3:
            //csv������ ���� �ҷ��� �ٴ� �޴� 1�� �� ��� ����
            cout << "CSV ���Ͽ��� �ҷ��� ���� ����Ͽ� ������ ����" << endl;
            break;

        case 4:
            //���� �ݱ� �κ�
            cout << "���α׷��� �����մϴ�." << endl;
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
    cout << "���� ������ csv ���Ͽ� �����ϴ� ���� �߰� �� ����" << endl;
    return;
    //Ŭ������ ���� ����Ͽ� ����� ��� ����
}
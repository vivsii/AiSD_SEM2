#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Rus");
    int n, count = 1;
    cout << "������� �������� ������" << endl;
    cin >> n;
    int upper = n, lower = 1;
    int result = n / 2;
    cout << result << endl;
    while (true)
    {
        int choose;
        cout << "�������� �������" << endl;
        cout << "1 - �����" << endl;
        cout << "2 - ����" << endl;
        cout << "3 - ������" << endl;
        cin >> choose;
        cout << endl;
        switch (choose)
        {
        case 1:
            upper = result;
            result = (upper + lower) / 2;
            cout << result << endl;
            break;
        case 2:
            lower = result;
            result = (upper + result) / 2;
            cout << result << endl;
            break;
        case 3:
            cout << "����� �����: " << count << endl;
            exit(0);
            break;
        default:
            exit(0);
            break;
        }
        count++;
    }
}
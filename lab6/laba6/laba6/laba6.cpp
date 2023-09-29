#include <string>
#include <iostream>
#include <chrono>
#include <Windows.h>

using namespace std;
#define INT_MAX 32767 
#define NUM 13

struct arr
{
    string str = "\0";
    int num = 0;
    arr* next = NULL;
};

int hash_f(string str, int* rand8)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++) sum += str[i];
    return sum % NUM;
}
void output(arr* tab, int size)
{
    for (int i = 0; i < size; i++)// ���� �� ������� ���� ������
    {
        arr* ptr = &tab[i];
        cout << "������� #" << i << ":\n";
        do
        {
            if (ptr->str[0] == '\0')
            {
                cout << "�����\n";
                break;
            }
            else
            {
                cout << "������: " << ptr->str << " �����: " << ptr->num << endl;
            }
        } while (ptr = ptr->next);
    }
}
void dlt(arr* tab, int size, int num, int* rand8)
{
    int k = hash_f(to_string(num), rand8);//��������� ���� ��������
    while (k > size - 1) k -= size;//��������� ����
    arr* ptr = &tab[k];
    if (ptr->num == num)//���� ������� ������
    {
        if (ptr->next)
        {
            ptr->next = ptr->next->next;//������� ��������� �� ��������� ������� �� ���������
            ptr->num = ptr->num;// ���������� ����
            ptr->str = ptr->str;//���
        }
        else
        {
            ptr->num = 0;
            ptr->str = '\0';
        }
        return;
    }
    if (ptr->num)//���� ������ �� ����
    {
        arr* ptr_prev = new arr;
        while (ptr->next && ptr->next->num != num)
        {
            ptr_prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->num == num)
        {
            ptr_prev->next = ptr->next;
            delete ptr;
            return;
        }
        //exit(1);
    }
    cout << "�������� ���\n";
    return;
}
void input(arr* tab, int size, string str, int num, int* rand8)
{
    int k = hash_f(to_string(num), rand8);//���� ���� ��� �������� � ���-�������
    while (k > size - 1) k -= size;// ��������� ����,����� ���� � �����������
    arr* ptr = &tab[k];
    if (!ptr->num)//���� ������� ����
    {
        ptr->next = NULL;//��������� ������� NULL
        ptr->str = str;//���������� ���
        ptr->num = num;// ���������� ����
    }
    else
    {
        while (ptr->next) ptr = ptr->next;//������������� ������� � ����� ������������ ������
        arr* p = new arr;
        p->next = NULL;//��� ���������� �������� p ���������� Null
        p->str = str;//���
        p->num = num;//����
        ptr->next = p;// ��� ptr ���������� ��������� ��������� p
    }
}
void search(arr* tab, int size, int num, int* rand8)
{
    int k = hash_f(to_string(num), rand8);
    while (k > size - 1) k -= size;//���������� ����� ��� ������� �������
    arr* ptr = &tab[k];
    if (ptr->num)
    {
        while (ptr->next && ptr->num != num)
        {
            ptr = ptr->next;
        }
        if (ptr->num == num)
        {
            cout << "����: " << ptr->num << " ���: " << ptr->str << endl;
            return;
        }
        cout << "������\n";
        exit(1);
    }
    cout << "�������� ���\n";
    return;
}
void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 7;
    cout << "������� ������ ���-�������" << endl;
    cin >> size;
    int clearMas[256] = { 0 };
    arr* mas = new arr[size];
    int choise;
    do
    {
        system("cls");
        cout << "1 - ����� ���-�������\n2 - ���������� ��������\n3 - ����� ��������\n4 - ��������\n0 - �����\n";
        cin >> choise;
        switch (choise)
        {
        case 1:
        {
            output(mas, size);
            break;
        }
        case 2:
        {
            string str;
            int num;
            cout << "������� ���: ";
            cin.ignore();
            getline(cin, str);
            cout << "������� ����� ��������: ";
            cin >> num;
            if (0 < num < INT_MAX)
            {
                input(mas, size, str, num, clearMas);
            }
            else cout << "������������ �����\n";
            break;
        }
        case 3:
        {
            cout << "������� ����: ";
            int num;
            cin >> num;
            cin.ignore();
            auto start = chrono::high_resolution_clock::now();
            search(mas, size, num, clearMas);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float>duration = end - start;
            cout << "��������� �����: " << duration.count() << " ������" << endl;
            break;
        }
        case 4:
        {
            cout << "������� ����: ";
            int num;
            cin >> num; 
            dlt(mas, size, num, clearMas);
        }
        default:
            break;
        }
        system("pause");
    } while (choise);
}
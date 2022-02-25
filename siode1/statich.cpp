#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
using namespace std;
void Arrayinput(int n, int a[]) //����
{
    cout << "Enter " << n << " numbers\n";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[i] = k;
    }
}
void Arrout(int n, int a[], int task, int newn) //�����
{
    if (task == 1)
        for (int i = 0; i < n; i++)
            cout << a[i] << endl;
    else if (task == 2)
        for (int i = 0; i <= n; i++)
            cout << a[i] << endl;
    else if (task == 3)
        for (int i = 0; i < newn; i++)
            cout << a[i] << endl;
}
int maxim(int n, int a[]) //������������ ��������
{
    int maxc = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxc)
            maxc = a[i];
    }
    return maxc;
}
void mirror(int n, int a[], int maxc) //���������� ����� � ����������� ������� � ���������� ��������
{
    int first, last;
    bool flag = false;
    first = -1;
    last = -2;
    for (int i = 0; i < n; i++)
    {
        int mirror = a[i];
        last = mirror % 10;
        mirror = mirror / 10;
        while (mirror > 0)
        {
            first = mirror % 10;
            mirror = mirror / 10;
        }
        if (!flag)
        {
            if (first == last)
            {
                for (int j = n - 1; j > i; j--)
                    swap(a[j + 1], a[j]); // �������� ���������
                a[i + 1] = maxc;
                flag = true;
            }
        }
    }
    if (!flag) cout << "There is no numbers with the same first and last numbers\n";
}
int fibonaci(int n, int a[]) //���������� � �������� �����, ������������ ��� ���������
{
    int newn = n;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        int smotrim = a[i];
        int sr1, sr2, delim;
        stringstream test;
        test << smotrim;
        string str = test.str();
        if (str[0] == '1' && str[1] == '1')
        {
            if (str != "11")
                for (int j = 2; j < str.length(); j++)
                {
                    if (int(str[j - 1]) - int('0') + int(str[j - 2]) - int('0') == (int(str[j]) - int('0')))
                        continue;
                    else flag = false;
                }
            if (flag)
            {
                a[i] = 0;
                for (int j = i; j < n; j++)
                    swap(a[j], a[j + 1]);
                newn -= 1;
            }
        }
    }
    return newn;
}
int main()
{
    int a[100];
    for (int i = 0; i < 100; i++)
        a[i] = 0;
    cout << "Enter natural size of massive\n";
    int n;
    bool nat = true;
    while (nat) //�������� ����� ������ ������� ��� ������������ �������
    {
        cin >> n;
        if (n > 0 && n<100)
            nat = false;
        else cout << "Invalid input, try again\n";
    }
    int task = 0;
    bool flag = false;
    cout << "1. Find max number\n2. Insert max number after number with the same first and last digit\n3. Delete fibonacci numbers\n";
    cout << "Enter number of task (1-3)\n";
    while (!flag)
    {
        cin >> task;
        if (task > 0 && task < 4)
            flag = true;
        else cout << "Invalid input\n";
    }
    Arrayinput(n, a);
    //Arrout(n, a, task, 0);
    if (task == 1)
        cout << "Max value is " << maxim(n, a) << endl;
    else if (task == 2)
    {
        mirror(n, a, maxim(n, a));
        Arrout(n, a, task, 0);
    }
    else if (task == 3)
    {
        Arrout(n, a, task, fibonaci(n, a));
    }
}


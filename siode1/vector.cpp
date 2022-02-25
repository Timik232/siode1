#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
void Arrayinput(int n, vector <int>& a) //ввод
{
    cout << "Enter " << n << " numbers\n";
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a.push_back(k);
    }
}
void Arrout(vector <int>& a) //вывод
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
}
int maxim(vector <int> a) //максимальное значение
{
    int maxc = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > maxc)
            maxc = a[i];
    }
    return maxc;
}
void mirror(vector <int>& a, int maxc) //нахождение числа с одинаковыми цифрами и добавление элемента
{
    int first, last;
    first = -1;
    last = -2;
    bool flag = false;
    int zapon = 0;
    for (int i = 0; i < a.size(); i++)
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
                zapon = i + 1; //запомнить номер элемента, после которого вставл€ем
                flag = true;
            }
        }
    }
    if (!flag)
        cout << "There is no numbers with the same first and last numbers\n";
    else
    {
        vector<int>::iterator it;
        it = a.begin() + zapon;
        a.insert(it, maxc);
    }
}
void fibonaci(vector <int>& a) //нахождение и удаление чисел, составл€ющих р€д фибоначчи
{
    for (int i = 0; i < a.size(); i++)
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
                a.erase(a.begin() + i);

            }
        }
    }
}
int main()
{
    vector <int> a;
    cout << "Enter natural size of massive\n";
    int n;
    bool nat = true;
    while (nat)
    {
        cin >> n;
        if (n > 0)
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
    //Arrout(a);
    if (task == 1)
        cout << "Max value is " << maxim(a) << endl;
    else if (task == 2)
    {
        mirror(a, maxim(a));
        Arrout(a);
    }
    else if (task == 3)
    {
        fibonaci(a);
        Arrout(a);
    }
}


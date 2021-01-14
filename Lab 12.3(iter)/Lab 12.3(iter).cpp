#include <iostream>
#include <Windows.h>
using namespace std;
typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};
void Print(Elem* L)
{
    Elem* tmp = L;
    do
    {
        cout << tmp->info << " ";
        tmp = tmp->next;
    } while (tmp != NULL);
    cout << endl;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}

Info d_equeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value;
}
void D(Elem* first, Elem* last)
{
 Info x;
    cout << "Введіть  елемент: ";
    cin >> x;
    while (first != NULL)
    {
        if (first->info == x)
        {
            Elem* next = first->next; // 1
            Elem* prev = first->prev; // 2
            delete first; // 3
            next->prev = prev; // 4
            prev->next = next;// 5
            first = next; // 6
        }
        else first = first->next;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    Elem* first = NULL,
        * last = NULL;
   
    
    cout << endl;
    Info info, N;
    do
    {
        cout << "Введіть кількість елементів списку: "; cin >> N;
    } while (N < 0);
    
    for (int i = 0; i < N; i++)
    {
        cout << "Введіть дані: "; cin >> info;
        enqueue(first, last, info);
    }

    cout << "Елементи списку: ";
    Print(first); cout << endl;
    D(first, last);
    while (first != NULL)
    {
       cout<<d_equeue(first, last)<<' ';
    }
    cout << endl;
}



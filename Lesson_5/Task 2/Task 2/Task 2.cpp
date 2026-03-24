#include <iostream>
#include <string>

using namespace std;

void print_element(int* arr, int index)
{
    int level = 0;
    int i = index;

    while (i > 0)
    {
        i = (i - 1) / 2;
        level++;
    }

    if (index == 0)
    {
        cout << level << " root " << arr[index] << endl;
    }
    else
    {
        int parent = (index - 1) / 2;

        if (index % 2 == 1)
        {
            cout << level << " left(" << arr[parent] << ") "
                << arr[index] << endl;
        }
        else
        {
            cout << level << " right(" << arr[parent] << ") "
                << arr[index] << endl;
        }
    }
}

void print_pyramid(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        print_element(arr, i);
    }
}

void print_array(int* arr, int size)
{
    cout << "Исходный массив: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


// ===== функции переходов =====

bool get_parent(int index, int& result)
{
    if (index == 0)
        return false;

    result = (index - 1) / 2;
    return true;
}

bool get_left(int index, int size, int& result)
{
    int left = 2 * index + 1;

    if (left >= size)
        return false;

    result = left;
    return true;
}

bool get_right(int index, int size, int& result)
{
    int right = 2 * index + 2;

    if (right >= size)
        return false;

    result = right;
    return true;
}


// ===== путешествие по пирамиде =====

void travel(int* arr, int size)
{
    int current = 0;
    string cmd;

    do
    {
        cout << "Вы находитесь здесь: ";
        print_element(arr, current);

        cout << "Введите команду: ";
        cin >> cmd;

        int next;

        if (cmd == "up")
        {
            if (get_parent(current, next))
            {
                current = next;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
        }
        else if (cmd == "left")
        {
            if (get_left(current, size, next))
            {
                current = next;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
        }
        else if (cmd == "right")
        {
            if (get_right(current, size, next))
            {
                current = next;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }
        else if (cmd == "exit")
        {
            break;
        }
        else
        {
            cout << "Неизвестная команда" << endl;
        }

    } while (cmd != "exit");
}


// ===== main =====

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 1, 3, 6, 5, 9, 8 };
    int size = 6;

    print_array(arr, size);

    cout << "Пирамида:" << endl;
    print_pyramid(arr, size);

    travel(arr, size);

}
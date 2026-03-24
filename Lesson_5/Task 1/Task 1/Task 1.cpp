#include <iostream>
using namespace std;

void print_element(int* arr, int index)
{
    // считаем уровень
    int level = 0;
    int i = index;

    while (i > 0)
    {
        i = (i - 1) / 2;
        level++;
    }

    // вывод
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

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = 6;

    print_array(arr1, size1);
    cout << "Пирамида:" << endl;
    print_pyramid(arr1, size1);

    cout << endl;

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = 8;

    print_array(arr2, size2);
    cout << "Пирамида:" << endl;
    print_pyramid(arr2, size2);

    cout << endl;

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = 10;

    print_array(arr3, size3);
    cout << "Пирамида:" << endl;
    print_pyramid(arr3, size3);

}
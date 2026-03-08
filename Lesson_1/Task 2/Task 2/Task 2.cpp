#include <iostream>
using namespace std;

int countGreater(int* arr, int size, int point)
{
    int left = 0;
    int right = size - 1;
    int pos = size; 

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] > point)
        {
            pos = mid;
            right = mid - 1; 
        }
        else
        {
            left = mid + 1; 
        }
    }

    return size - pos;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int point;

    cout << "Введите точку отсчёта: ";
    cin >> point;

    cout << "Количество элементов больше чем "
        << point << ": "
        << countGreater(arr, size, point) << endl;

    cout << endl;

    cout << "Точка 32 -> "
        << countGreater(arr, size, 32) << endl;

    cout << "Точка 15 -> "
        << countGreater(arr, size, 15) << endl;

}
#include <iostream>
using namespace std;

// функция разбиения
int partition(int* arr, int left, int right)
{
    int pivot = arr[right]; // опорный элемент
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// рекурсивная часть quick sort
void quickSortRec(int* arr, int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);

        quickSortRec(arr, left, p - 1);
        quickSortRec(arr, p + 1, right);
    }
}

// функция из задания
void quick_sort(int* arr, int size)
{
    quickSortRec(arr, 0, size - 1);
}

// вывод массива
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = 10;

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = 15;

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = 18;

    cout << "Исходный массив: ";
    printArray(arr1, size1);
    quick_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    printArray(arr1, size1);

    cout << endl;

    cout << "Исходный массив: ";
    printArray(arr2, size2);
    quick_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    printArray(arr2, size2);

    cout << endl;

    cout << "Исходный массив: ";
    printArray(arr3, size3);
    quick_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    printArray(arr3, size3);

}
#include <iostream>
using namespace std;

// функция слияния двух частей массива
void merge(int* arr, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* L = new int[size1];
    int* R = new int[size2];

    for (int i = 0; i < size1; i++)
        L[i] = arr[left + i];

    for (int i = 0; i < size2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// рекурсивная часть merge sort
void mergeSortRec(int* arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSortRec(arr, left, mid);
    mergeSortRec(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

// функция из задания
void merge_sort(int* arr, int size)
{
    mergeSortRec(arr, 0, size - 1);
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
    merge_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    printArray(arr1, size1);

    cout << endl;

    cout << "Исходный массив: ";
    printArray(arr2, size2);
    merge_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    printArray(arr2, size2);

    cout << endl;

    cout << "Исходный массив: ";
    printArray(arr3, size3);
    merge_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    printArray(arr3, size3);

}
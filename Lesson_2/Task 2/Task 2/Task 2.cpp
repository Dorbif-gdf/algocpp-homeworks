#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    int* f = new int[n + 1];

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    int result = f[n];

    delete[] f;

    return result;
}

int main()
{
    int n;
    cin >> n;

    int result = fib(n);

    cout << "Fibonacci number: " << result << endl;
    cout << "Time complexity: O(n)" << endl;
    cout << "Memory complexity: O(n)" << endl;

}
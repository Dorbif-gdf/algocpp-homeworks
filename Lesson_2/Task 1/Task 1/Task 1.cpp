#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;

    int result = fib(n);

    cout << "Fibonacci number: " << result << endl;

    cout << "Time complexity: O(2^n)" << endl;
    cout << "Memory complexity: O(n)" << endl;

}
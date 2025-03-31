#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// [1] Truyền tham trị
void HoanVi1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout << "HoanVi1:\n";
    cout << "a: Addr=" << &a << ", Val=" << a << "\n";
    cout << "b: Addr=" << &b << ", Val=" << b << "\n";
}

// [2] Truyền tham biến (sử dụng tham chiếu)
void HoanVi2(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout << "HoanVi2:\n";
    cout << "a: Addr=" << &a << ", Val=" << a << "\n";
    cout << "b: Addr=" << &b << ", Val=" << b << "\n";
}

// [3] Truyền tham chiếu (dùng con trỏ)
void HoanVi3(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout << "HoanVi3:\n";
    cout << "a: Addr=" << &a << ", Val=" << a << ", ValRef=" << *a << "\n";
    cout << "b: Addr=" << &b << ", Val=" << b << ", ValRef=" << *b << "\n";
}

int main()
{
    int x = 5, y = 10;

    // Truyền tham trị
    cout << "-- Truyen tham tri --\n";
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n";
    HoanVi1(x, y);
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n\n";

    // Truyền tham biến
    x = 5, y = 10;
    cout << "-- Truyen tham bien --\n";
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n";
    HoanVi2(x, y);
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n\n";

    // Truyền tham chiếu bằng con trỏ
    x = 5, y = 10;
    cout << "-- Truyen tham chieu --\n";
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n";
    HoanVi3(&x, &y);
    cout << "Main:\n";
    cout << "x: Addr=" << &x << ", Val=" << x << "\n";
    cout << "y: Addr=" << &y << ", Val=" << y << "\n";

    return 0;
}

// Output:
// -- Truyen tham tri --
// Main:
// x: Addr=0x5ffe9c, Val=5
// y: Addr=0x5ffe98, Val=10
// HoanVi1:
// a: Addr=0x5ffe70, Val=10
// b: Addr=0x5ffe78, Val=5
// Main:
// x: Addr=0x5ffe9c, Val=5
// y: Addr=0x5ffe98, Val=10

// -- Truyen tham bien --
// Main:
// x: Addr=0x5ffe9c, Val=5
// y: Addr=0x5ffe98, Val=10
// HoanVi2:
// a: Addr=0x5ffe9c, Val=10
// b: Addr=0x5ffe98, Val=5
// Main:
// x: Addr=0x5ffe9c, Val=10
// y: Addr=0x5ffe98, Val=5

// -- Truyen tham chieu --
// Main:
// x: Addr=0x5ffe9c, Val=5
// y: Addr=0x5ffe98, Val=10
// HoanVi3:
// a: Addr=0x5ffe70, Val=0x5ffe9c, ValRef=10
// b: Addr=0x5ffe78, Val=0x5ffe98, ValRef=5
// Main:
// x: Addr=0x5ffe9c, Val=10
// y: Addr=0x5ffe98, Val=5
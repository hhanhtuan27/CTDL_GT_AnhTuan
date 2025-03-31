#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    string s;

    // Nhập chuỗi
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;

    // Sắp xếp các ký tự trong chuỗi theo thứ tự tăng dần
    sort(s.begin(), s.end());

    // Xuất kết quả
    cout << "Chuoi sau khi sap xep: " << s << endl;

    return 0;
}

// Input:
// Moi ban nhap chuoi s: abcba

// Output:
// Chuoi sau khi sap xep: aabbc
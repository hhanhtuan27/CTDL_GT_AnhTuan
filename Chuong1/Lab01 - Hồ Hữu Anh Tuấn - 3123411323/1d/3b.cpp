#include <iostream>

using namespace std;

int main()
{
    string s;
    int k;
    char c;

    // Nhập chuỗi
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;

    // Nhập vị trí cần chèn
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;

    // Nhập ký tự cần chèn
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;

    // Kiểm tra vị trí hợp lệ
    if (k < 0 || k > s.length())
    {
        cout << "Vi tri chen khong hop le!" << endl;
    }
    else
    {
        // Chèn ký tự tại vị trí k
        s.insert(k, 1, c);

        // Xuất chuỗi sau khi chèn
        cout << "Chuoi sau khi them ky tu '" << c << "' vao vi tri " << k << ": " << s << endl;
    }

    return 0;
}

// Input:
// Moi ban nhap chuoi s: abcba
// Moi ban nhap vi tri can chen: 1
// Moi ban nhap ky tu chen: d

// Output:
// Chuoi sau khi them ky tu 'd' vao vi tri 1: adbcba
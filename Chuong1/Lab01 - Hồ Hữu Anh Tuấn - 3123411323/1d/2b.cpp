#include <iostream>

using namespace std;

int main()
{
    string s;
    int k;

    // Nhập chuỗi
    cout << "Moi ban nhap chuoi s: ";
    cin >> s;

    // Nhập vị trí cần xóa
    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Kiểm tra vị trí hợp lệ
    if (k < 0 || k >= s.length())
    {
        cout << "Vi tri xoa khong hop le!" << endl;
    }
    else
    {
        // Xóa ký tự tại vị trí k
        s.erase(k, 1);

        // Xuất chuỗi sau khi xóa
        cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    }

    return 0;
}

// Input
// Moi ban nhap chuoi s: abcba
// Moi ban nhap vi tri can xoa: 1

// Output
// Chuoi sau khi xoa ky tu tai vi tri 1: acba
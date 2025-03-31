#include <iostream>

using namespace std;

// Hàm kiểm tra xem ký tự có phải nguyên âm không
bool LaNguyenAm(char c)
{
    c = tolower(c); // Chuyển ký tự về chữ thường để kiểm tra
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Hàm tách nguyên âm từ dãy a vào dãy b
void TachNguyenAm(char *a, int n, char **b, int *m)
{
    *m = 0; // Số lượng phần tử của mảng b ban đầu bằng 0

    // Đếm số nguyên âm trong dãy a
    for (int i = 0; i < n; i++)
    {
        if (LaNguyenAm(a[i]))
            (*m)++;
    }

    // Cấp phát bộ nhớ động cho dãy b
    *b = new char[*m];

    // Chèn các nguyên âm vào dãy b
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (LaNguyenAm(a[i]))
        {
            (*b)[index] = a[i];
            index++;
        }
    }
}

// Hàm xuất mảng ký tự
void XuatMang(char *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    // Nhập số lượng phần tử
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    // Kiểm tra đầu vào
    if (n <= 0 || n > 100)
    {
        cout << "So luong phan tu khong hop le!\n";
        return 1;
    }

    // Khai báo mảng động
    char *a = new char[n];

    // Nhập phần tử
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }

    // Tạo dãy b chứa nguyên âm
    char *b = NULL;
    int m;
    TachNguyenAm(a, n, &b, &m);

    // Xuất dãy chứa nguyên âm
    cout << "+ Day chua cac nguyen am: ";
    if (m > 0)
        XuatMang(b, m);
    else
        cout << "Khong co nguyen am nao.\n";

    // Giải phóng bộ nhớ
    delete[] a;
    delete[] b;

    return 0;
}

// Input:
//  Moi ban nhap so luong phan tu: 5
//  Phan tu 0: a
//  Phan tu 1: b
//  Phan tu 2: c
//  Phan tu 3: d
//  Phan tu 4: e

// Output:
//  + Day chua cac nguyen am: a e
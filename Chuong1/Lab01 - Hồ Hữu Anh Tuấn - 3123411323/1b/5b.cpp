#include <iostream>

using namespace std;

// Hàm nhập mảng số nguyên
void NhapMang(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }
}

// Hàm xuất mảng số nguyên
void XuatMang(int *a, int n)
{
    cout << "Day so co " << n << " phan tu: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm tách số chẵn vào b, số lẻ vào c
void TachChanLe(int *a, int n, int *b, int &m, int *c, int &p)
{
    m = 0; // Số phần tử của mảng b (số chẵn)
    p = 0; // Số phần tử của mảng c (số lẻ)

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[m++] = a[i]; // Lưu số chẵn vào b
        }
        else
        {
            c[p++] = a[i]; // Lưu số lẻ vào c
        }
    }
}

int main()
{
    int n, m, p;

    // Nhập mảng a
    cout << "+ Day so a\n";
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    if (n <= 0 || n > 100)
    {
        cout << "So luong phan tu khong hop le!\n";
        return 1;
    }

    int *a = new int[n]; // Cấp phát bộ nhớ động cho mảng a
    int *b = new int[n]; // Mảng b chứa số chẵn (tối đa n phần tử)
    int *c = new int[n]; // Mảng c chứa số lẻ (tối đa n phần tử)

    NhapMang(a, n);

    // Tách số chẵn vào b và số lẻ vào c
    TachChanLe(a, n, b, m, c, p);

    // Xuất kết quả
    cout << "\n+ Day so b chua so chan\n";
    XuatMang(b, m);

    cout << "\n+ Day so c chua so le\n";
    XuatMang(c, p);

    // Giải phóng bộ nhớ
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

// Input:
//  + Day so a
//  Moi ban nhap so luong phan tu: 3
//  Phan tu 0: 2
//  Phan tu 1: 5
//  Phan tu 2: 8

// Output:
//  + Day so b chua so chan
//  Day so co 2 phan tu: 2 8

// + Day so c chua so le
// Day so co 1 phan tu: 5
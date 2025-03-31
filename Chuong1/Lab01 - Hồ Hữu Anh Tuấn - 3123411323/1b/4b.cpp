#include <iostream>

using namespace std;

// Hàm nhập mảng số thực
void NhapMang(double *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }
}

// Hàm xuất mảng số thực
void XuatMang(double *a, int n)
{
    cout << "Day so co " << n << " phan tu: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm trộn hai dãy số đã sắp xếp thành dãy mới cũng sắp xếp
void TronMang(double *a, int n, double *b, int m, double *c, int &p)
{
    int i = 0, j = 0, k = 0;
    p = n + m; // Số phần tử của dãy c

    // Trộn hai mảng a và b vào c
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }

    // Sao chép các phần tử còn lại của a vào c
    while (i < n)
    {
        c[k++] = a[i++];
    }

    // Sao chép các phần tử còn lại của b vào c
    while (j < m)
    {
        c[k++] = b[j++];
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
    double *a = new double[n]; // Cấp phát bộ nhớ động
    NhapMang(a, n);

    // Nhập mảng b
    cout << "+ Day so b\n";
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> m;
    if (m <= 0 || m > 100)
    {
        cout << "So luong phan tu khong hop le!\n";
        delete[] a;
        return 1;
    }
    double *b = new double[m]; // Cấp phát bộ nhớ động
    NhapMang(b, m);

    // Cấp phát bộ nhớ cho mảng c
    double *c = new double[n + m];

    // Gộp hai mảng
    TronMang(a, n, b, m, c, p);

    // Xuất mảng kết quả
    cout << "\n+ Day so c\n";
    XuatMang(c, p);

    // Giải phóng bộ nhớ
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

// Input:
// + Day so a
// Moi ban nhap so luong phan tu: 3
// Phan tu 0: 1.1
// Phan tu 1: 3.2
// Phan tu 2: 5.3
// + Day so b
// Moi ban nhap so luong phan tu: 4
// Phan tu 0: 2.1
// Phan tu 1: 3.2
// Phan tu 2: 5.4
// Phan tu 3: 8.4

// Output:
// + Day so c
// Day so co 7 phan tu: 1.1 2.1 3.2 3.2 5.3 5.4 8.4

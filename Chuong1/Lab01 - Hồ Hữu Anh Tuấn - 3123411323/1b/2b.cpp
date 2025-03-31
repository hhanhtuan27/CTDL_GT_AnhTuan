#include <iostream>

using namespace std;

// Hàm kiểm tra tính chẵn lẻ xen kẽ trong dãy
bool KiemTraChanLe(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if ((a[i] % 2) == (a[i - 1] % 2)) // Hai số liên tiếp cùng chẵn hoặc cùng lẻ
            return false;
    }
    return true;
}

// Hàm kiểm tra tính toàn chẵn
bool KiemTraToanChan(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0) // Nếu có ít nhất 1 số lẻ, không phải toàn chẵn
            return false;
    }
    return true;
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
    int *a = new int[n];

    // Nhập phần tử
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }

    // Kiểm tra tính chất của dãy
    if (KiemTraChanLe(a, n))
        cout << "+ Day co tinh chat chan le\n";
    else
        cout << "+ Day khong co tinh chat chan le\n";

    if (KiemTraToanChan(a, n))
        cout << "+ Day co tinh chat toan chan\n";
    else
        cout << "+ Day khong co tinh chat toan chan\n";

    // Giải phóng bộ nhớ
    delete[] a;

    return 0;
}

// Input:
// Moi ban nhap so luong phan tu: 5
// Phan tu 0: 2
// Phan tu 1: 5
// Phan tu 2: 6
// Phan tu 3: 5
// Phan tu 4: 2

Output + Day co tinh chat chan le + Day khong co tinh chat toan chan
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void DocCacSoNguyen(const string &tenFile)
{
    ifstream file(tenFile); // Mở file để đọc
    if (!file)
    {
        cout << "Khong the mo file " << tenFile << "!" << endl;
        return;
    }

    int n;
    file >> n; // Đọc số lượng phần tử
    vector<int> arr(n);

    // Đọc n số nguyên vào vector
    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
    }

    file.close(); // Đóng file

    // Xuất dữ liệu đọc được ra màn hình
    cout << "So luong phan tu: " << n << endl;
    cout << "Cac so trong file: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    DocCacSoNguyen("DaySoNguyen.inp"); // Đọc file
    return 0;
}

// Input:
// 5
// 4 3 5 3 2

// Output:
// So luong phan tu: 5
// Cac so trong file: 4 3 5 3 2

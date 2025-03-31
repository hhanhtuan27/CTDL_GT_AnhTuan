#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void DocMang2C(const string &tenFile)
{
    ifstream file(tenFile); // Mở file để đọc
    if (!file)
    {
        cout << "Khong the mo file " << tenFile << "!" << endl;
        return;
    }

    int n, m;
    file >> n >> m; // Đọc số dòng và số cột
    vector<vector<int>> matrix(n, vector<int>(m));

    // Đọc dữ liệu vào ma trận
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            file >> matrix[i][j];
        }
    }

    file.close(); // Đóng file

    // Xuất dữ liệu đọc được ra màn hình
    cout << "So dong: " << n << ", So cot: " << m << endl;
    cout << "Ma tran doc duoc:\n";
    for (const auto &row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    DocMang2C("MangSo.inp"); // Đọc file
    return 0;
}

// Input:
// 3 5
// 5 3 5 7 2
// 4 5 5 7 1
// 5 4 5 3 9

// Output:
// So dong: 3, So cot: 5
// Ma tran doc duoc:
// 5 3 5 7 2
// 4 5 5 7 1
// 5 4 5 3 9
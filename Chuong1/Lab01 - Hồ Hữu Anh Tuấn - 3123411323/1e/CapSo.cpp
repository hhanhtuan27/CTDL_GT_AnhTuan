#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    // Đọc dữ liệu từ file CapSo.INP
    ifstream infile("CapSo.INP");
    int n, k;
    infile >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        infile >> a[i];
    }

    // Đóng file input
    infile.close();

    // Sử dụng một unordered_set để theo dõi các số đã gặp
    unordered_set<int> seen;
    vector<pair<int, int>> pairs;

    // Duyệt qua dãy số và tìm cặp (ai, aj) sao cho ai + aj = k
    for (int i = 0; i < n; ++i)
    {
        int complement = k - a[i]; // Tính số cần thiết để có tổng bằng k

        // Nếu số bổ sung đã gặp, thì ta tìm được một cặp
        if (seen.count(complement))
        {
            pairs.push_back({complement, a[i]});
        }

        // Thêm số hiện tại vào bảng đã gặp
        seen.insert(a[i]);
    }

    // Ghi kết quả vào file CapSo.OUT
    ofstream outfile("CapSo.OUT");

    if (pairs.empty())
    {
        outfile << 0 << endl; // Nếu không có cặp nào
    }
    else
    {
        for (const auto &p : pairs)
        {
            outfile << p.first << " " << p.second << endl;
        }
    }

    // Đóng file output
    outfile.close();

    return 0;
}

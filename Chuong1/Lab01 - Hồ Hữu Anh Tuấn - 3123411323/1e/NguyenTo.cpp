#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n <= 1)
        return false; // Số nguyên tố phải lớn hơn 1
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    // Đọc dữ liệu từ file NT.INP
    ifstream infile("NT.INP");
    int n;
    infile >> n;

    vector<int> primes; // Mảng lưu các số nguyên tố

    // Đọc các số và kiểm tra số nguyên tố
    for (int i = 0; i < n; ++i)
    {
        int num;
        infile >> num;
        if (isPrime(num))
        {
            primes.push_back(num);
        }
    }

    // Đóng file input
    infile.close();

    // Sắp xếp các số nguyên tố theo thứ tự tăng dần
    sort(primes.begin(), primes.end());

    // Ghi kết quả vào file NT.OUT
    ofstream outfile("NT.OUT");
    outfile << primes.size() << endl; // Ghi số lượng số nguyên tố

    // Nếu có số nguyên tố thì ghi chúng ra
    if (!primes.empty())
    {
        for (int i = 0; i < primes.size(); ++i)
        {
            outfile << primes[i];
            if (i < primes.size() - 1)
                outfile << " ";
        }
        outfile << endl;
    }

    // Đóng file output
    outfile.close();

    return 0;
}

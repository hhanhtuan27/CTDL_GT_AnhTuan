#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

// Hàm Fibonacci đệ quy
long long fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Hàm Fibonacci khử đệ quy (dùng stack)
long long fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    stack<pair<int, long long>> s;
    s.push({n, 0}); // {n, result}
    long long result = 0;

    while (!s.empty()) {
        pair<int, long long> current = s.top();
        s.pop();
        int k = current.first;
        long long res = current.second;

        if (k <= 1) {
            result += k;
        } else {
            s.push({k - 1, 0});
            s.push({k - 2, 0});
        }
    }
    return result;
}

// Hàm đảo ngược số đệ quy
int reverse_recursive(int n, int reversed = 0) {
    if (n == 0) {
        return reversed;
    }
    reversed = reversed * 10 + n % 10;
    return reverse_recursive(n / 10, reversed);
}

// Hàm đảo ngược số khử đệ quy (dùng stack)
int reverse_iterative(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int reversed = 0;
    int power = 1;
    while (!s.empty()) {
        reversed = reversed * 10 + s.top();
        s.pop();
    }
    return reversed;
}

// Hàm Hanoi Tower đệ quy
void hanoi_recursive(int n, int source, int destination, int auxiliary, ofstream& outfile) {
    if (n == 1) {
        outfile << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    hanoi_recursive(n - 1, source, auxiliary, destination, outfile);
    outfile << "Move disk " << n << " from " << source << " to " << destination << endl;
    hanoi_recursive(n - 1, auxiliary, destination, source, outfile);
}

// Struct để lưu trạng thái của bài toán Hanoi cho khử đệ quy
struct HanoiState {
    int n;
    int source;
    int destination;
    int auxiliary;
    string action; // "move", "hanoi"
};

// Hàm Hanoi Tower khử đệ quy (dùng stack)
void hanoi_iterative(int n, int source, int destination, int auxiliary, ofstream& outfile) {
    stack<HanoiState> s;
    s.push({n, source, destination, auxiliary, "hanoi"});

    while (!s.empty()) {
        HanoiState current = s.top();
        s.pop();

        if (current.action == "move") {
            outfile << "Move disk " << current.n << " from " << current.source << " to " << current.destination << endl;
        } else if (current.n == 1) {
            s.push({1, current.source, current.destination, current.auxiliary, "move"});
        } else {
            s.push({current.n - 1, current.auxiliary, current.destination, current.source, "hanoi"});
            s.push({current.n, current.source, current.destination, current.auxiliary, "move"});
            s.push({current.n - 1, current.source, current.auxiliary, current.destination, "hanoi"});
        }
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening input.txt or output.txt" << endl;
        return 1;
    }

    string task;
    int value;

    while (infile >> task >> value) {
        if (task == "fibonacci") {
            outfile << "Fibonacci(" << value << ") Recursive: " << fibonacci_recursive(value) << endl;
            outfile << "Fibonacci(" << value << ") Iterative (Stack): " << fibonacci_iterative(value) << endl;
        } else if (task == "reverse") {
            outfile << "Reverse(" << value << ") Recursive: " << reverse_recursive(value) << endl;
            outfile << "Reverse(" << value << ") Iterative (Stack): " << reverse_iterative(value) << endl;
        } else if (task == "hanoi") {
            outfile << "Hanoi Tower (" << value << " disks) Recursive:" << endl;
            hanoi_recursive(value, 1, 3, 2, outfile);
            outfile << "Hanoi Tower (" << value << " disks) Iterative (Stack):" << endl;
            hanoi_iterative(value, 1, 3, 2, outfile);
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
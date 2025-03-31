#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

// --- StackInt (Array-based) ---
const int MAX_SIZE = 100;

class StackInt {
private:
    int data[MAX_SIZE];
    int top;

public:
    StackInt() : top(-1) {}

    void initStack() { top = -1; }
    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX_SIZE - 1; }

    void pushStack(int value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    int popStack() {
        if (!isEmpty()) {
            return data[top--];
        }
        return -1; // Or throw an exception
    }

    int peekStack() const {
        if (!isEmpty()) {
            return data[top];
        }
        return -1; // Or throw an exception
    }

    void clear() { top = -1; }
};

// --- LinkedStackInt (Linked List-based) ---
struct NodeInt {
    int data;
    NodeInt* next;
};

class LinkedStackInt {
private:
    NodeInt* head;

public:
    LinkedStackInt() : head(nullptr) {}

    void initStack() {
        while (head != nullptr) {
            NodeInt* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const { return head == nullptr; }
    bool isFull() const { return false; } // Linked list doesn't have a fixed size

    void pushStack(int value) {
        NodeInt* newNode = new NodeInt{value, head};
        head = newNode;
    }

    int popStack() {
        if (!isEmpty()) {
            int value = head->data;
            NodeInt* temp = head;
            head = head->next;
            delete temp;
            return value;
        }
        return -1; // Or throw an exception
    }

    int peekStack() const {
        if (!isEmpty()) {
            return head->data;
        }
        return -1; // Or throw an exception
    }

    void clear() { initStack(); }
};

// --- StackString (Array-based for Strings) ---
const int MAX_STRING_SIZE = 100;

class StackString {
private:
    string data[MAX_STRING_SIZE];
    int top;

public:
    StackString() : top(-1) {}

    void initStack() { top = -1; }
    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX_STRING_SIZE - 1; }

    void pushStack(const string& value) {
        if (!isFull()) {
            data[++top] = value;
        }
    }

    string popStack() {
        if (!isEmpty()) {
            return data[top--];
        }
        return ""; // Or throw an exception
    }

    string peekStack() const {
        if (!isEmpty()) {
            return data[top];
        }
        return ""; // Or throw an exception
    }

    void clear() { top = -1; }
};

// Hàm đảo ngược số dùng StackInt
int reverseNumber(int n, StackInt& s) {
    while (n > 0) {
        s.pushStack(n % 10);
        n /= 10;
    }
    int reversed = 0;
    int power = 1;
    while (!s.isEmpty()) {
        reversed = reversed * 10 + s.popStack();
    }
    return reversed;
}

// Hàm đảo ngược số dùng LinkedStackInt
int reverseNumberLinked(int n, LinkedStackInt& s) {
    while (n > 0) {
        s.pushStack(n % 10);
        n /= 10;
    }
    int reversed = 0;
    int power = 1;
    while (!s.isEmpty()) {
        reversed = reversed * 10 + s.popStack();
    }
    return reversed;
}

// Hàm kiểm tra xâu đối xứng dùng StackString (không dùng cctype)
bool isPalindrome(const string& str, StackString& s) {
    string cleanedStr = "";
    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            cleanedStr += tolower(c);
        }
    }
    for (char c : cleanedStr) {
        s.pushStack(string(1, c));
    }
    string reversedStr = "";
    while (!s.isEmpty()) {
        reversedStr += s.popStack();
    }
    return cleanedStr == reversedStr;
}

// Hàm chuyển đổi số thập phân sang nhị phân dùng StackInt
string decimalToBinary(int n, StackInt& s) {
    if (n == 0) return "0";
    while (n > 0) {
        s.pushStack(n % 2);
        n /= 2;
    }
    string binary = "";
    while (!s.isEmpty()) {
        binary += to_string(s.popStack());
    }
    return binary;
}

// --- Expression Evaluation (không dùng sstream) ---
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> operators;
    string current_token = "";

    for (char c : infix) {
        if (c == ' ') {
            if (!current_token.empty()) {
                postfix += current_token + " ";
                current_token = "";
            }
        } else if (isdigit(c)) {
            current_token += c;
        } else if (c == '(') {
            operators.push('(');
        } else if (c == ')') {
            if (!current_token.empty()) {
                postfix += current_token + " ";
                current_token = "";
            }
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop();
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!current_token.empty()) {
                postfix += current_token + " ";
                current_token = "";
            }
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.push(c);
        }
    }
    if (!current_token.empty()) {
        postfix += current_token + " ";
    }

    while (!operators.empty()) {
        postfix += operators.top();
        postfix += " ";
        operators.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    stack<int> operands;
    string current_token = "";

    for (char c : postfix) {
        if (c == ' ') {
            if (!current_token.empty()) {
                operands.push(stoi(current_token));
                current_token = "";
            }
        } else if (isdigit(c)) {
            current_token += c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operands.top(); operands.pop();
            int operand1 = operands.top(); operands.pop();
            if (c == '+') operands.push(operand1 + operand2);
            else if (c == '-') operands.push(operand1 - operand2);
            else if (c == '*') operands.push(operand1 * operand2);
            else if (c == '/') operands.push(operand1 / operand2);
        }
    }
    return operands.top();
}

// Hàm chuyển đổi char sang lower (thay thế cctype)
char tolower_custom(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Hàm kiểm tra có phải là chữ số (thay thế cctype)
bool isdigit_custom(char c) {
    return (c >= '0' && c <= '9');
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening input files!" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        string task;
        size_t first_space = line.find(' ');
        if (first_space != string::npos) {
            task = line.substr(0, first_space);
        } else {
            task = line;
        }

        if (task == "reverse") {
            int num = stoi(line.substr(first_space + 1));
            StackInt stackInt;
            outfile << "--- StackInt (Array-based Stack) ---" << endl;
            outfile << "Reversed number (StackInt): " << reverseNumber(num, stackInt) << endl << endl;

            LinkedStackInt linkedStackInt;
            outfile << "--- LinkedStackInt (Linked List-based Stack) ---" << endl;
            outfile << "Reversed number (LinkedStackInt): " << reverseNumberLinked(num, linkedStackInt) << endl << endl;
        } else if (task == "palindrome") {
            string str = line.substr(first_space + 1);
            StackString stackStr;
            outfile << "--- StackString (Array-based Stack for Strings) ---" << endl;
            outfile << "\"" << str << "\" is a palindrome: " << isPalindrome(str, stackStr) << endl << endl;
        } else if (task == "decimal_to_binary") {
            int num = stoi(line.substr(first_space + 1));
            StackInt stackInt;
            outfile << "--- Decimal to Binary (StackInt) ---" << endl;
            outfile << "Binary of " << num << ": " << decimalToBinary(num, stackInt) << endl << endl;
        } else if (task == "expression") {
            string expression = line.substr(first_space + 1);
            outfile << "--- Expression Evaluation (StackInt & StackChar) ---" << endl;
            outfile << "Infix: " << expression << endl;
            string postfix = infixToPostfix(expression);
            outfile << "Postfix: " << postfix << endl;
            outfile << "Value: " << evaluatePostfix(postfix) << endl << endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}

// Hàm kiểm tra có phải là chữ cái hoặc chữ số (thay thế cctype::isalnum)
bool isalnum_custom(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

// Hàm tolower tự viết (thay thế std::tolower)
char tolower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Hàm kiểm tra có phải là chữ số (thay thế std::isdigit)
bool isdigit(char c) {
    return (c >= '0' && c <= '9');
}

// Hàm chuyển đổi string sang integer (thay thế std::stoi)
int stoi(const string& str) {
    int result = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; i < str.length(); ++i) {
        result = result * 10 + (str[i] - '0');
    }
    return result * sign;
}

// Hàm chuyển đổi integer sang string (thay thế std::to_string)
string to_string(int n) {
    if (n == 0) return "0";
    string s = "";
    bool negative = false;
    if (n < 0) {
        negative = true;
        n = -n;
    }
    while (n > 0) {
        s = char('0' + n % 10) + s;
        n /= 10;
    }
    if (negative) s = "-" + s;
    return s;
}
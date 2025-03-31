#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>

using namespace std;

// --- QueueInt (Array-based) ---
const int MAX_QUEUE_SIZE = 100;

class QueueInt {
private:
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int count;

public:
    QueueInt() : front(0), rear(MAX_QUEUE_SIZE - 1), count(0) {}

    void initQueue() { front = 0; rear = MAX_QUEUE_SIZE - 1; count = 0; }
    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == MAX_QUEUE_SIZE; }

    void enqueue(int value) {
        if (!isFull()) {
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = value;
            count++;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int value = data[front];
            front = (front + 1) % MAX_QUEUE_SIZE;
            count--;
            return value;
        }
        return -1; // Or throw an exception
    }

    int peek() const {
        if (!isEmpty()) {
            return data[front];
        }
        return -1; // Or throw an exception
    }

    void clear() { front = 0; rear = MAX_QUEUE_SIZE - 1; count = 0; }
    int size() const { return count; }
};

// --- LinkedQueueInt (Linked List-based) ---
struct NodeInt {
    int data;
    NodeInt* next;
};

class LinkedQueueInt {
private:
    NodeInt* front;
    NodeInt* rear;

public:
    LinkedQueueInt() : front(nullptr), rear(nullptr) {}

    void initQueue() {
        while (front != nullptr) {
            NodeInt* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() const { return front == nullptr; }
    bool isFull() const { return false; } // Linked list doesn't have a fixed size

    void enqueue(int value) {
        NodeInt* newNode = new NodeInt{value, nullptr};
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int value = front->data;
            NodeInt* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
            return value;
        }
        return -1; // Or throw an exception
    }

    int peek() const {
        if (!isEmpty()) {
            return front->data;
        }
        return -1; // Or throw an exception
    }

    void clear() { initQueue(); }
    int size() const {
        int count = 0;
        NodeInt* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// --- Dance Scheduling ---
void scheduleDance(QueueInt& maleQueue, QueueInt& femaleQueue, ofstream& outfile) {
    outfile << "Pairs (Array-based Queue):" << endl;
    while (!maleQueue.isEmpty() && !femaleQueue.isEmpty()) {
        outfile << "(" << maleQueue.dequeue() << ", " << femaleQueue.dequeue() << ")" << endl;
    }
    while (!maleQueue.isEmpty()) outfile << "(" << maleQueue.dequeue() << ", None)" << endl;
    while (!femaleQueue.isEmpty()) outfile << "(None, " << femaleQueue.dequeue() << ")" << endl;
}

void scheduleDanceLinked(LinkedQueueInt& maleQueue, LinkedQueueInt& femaleQueue, ofstream& outfile) {
    outfile << "Pairs (Linked List-based Queue):" << endl;
    while (!maleQueue.isEmpty() && !femaleQueue.isEmpty()) {
        outfile << "(" << maleQueue.dequeue() << ", " << femaleQueue.dequeue() << ")" << endl;
    }
    while (!maleQueue.isEmpty()) outfile << "(" << maleQueue.dequeue() << ", None)" << endl;
    while (!femaleQueue.isEmpty()) outfile << "(None, " << femaleQueue.dequeue() << ")" << endl;
}

// --- Radix Sort ---
void radixSortQueue(int arr[], int n, QueueInt queues[], int maxDigits, ofstream& outfile) {
    for (int digit = 1; digit <= maxDigits; ++digit) {
        for (int i = 0; i < n; ++i) {
            int digitValue = (arr[i] / (int)pow(10, digit - 1)) % 10;
            queues[digitValue].enqueue(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; ++i) {
            while (!queues[i].isEmpty()) {
                arr[index++] = queues[i].dequeue();
            }
        }
    }
    outfile << "Sorted array (Array-based Queue):";
    for (int i = 0; i < n; ++i) {
        outfile << " " << arr[i];
    }
    outfile << endl;
}

void radixSortLinkedQueue(int arr[], int n, LinkedQueueInt queues[], int maxDigits, ofstream& outfile) {
    for (int digit = 1; digit <= maxDigits; ++digit) {
        for (int i = 0; i < n; ++i) {
            int digitValue = (arr[i] / (int)pow(10, digit - 1)) % 10;
            queues[digitValue].enqueue(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; ++i) {
            while (!queues[i].isEmpty()) {
                arr[index++] = queues[i].dequeue();
            }
        }
    }
    outfile << "Sorted array (Linked List-based Queue):";
    for (int i = 0; i < n; ++i) {
        outfile << " " << arr[i];
    }
    outfile << endl;
}

int getMaxDigits(int arr[], int n) {
    int maxVal = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    int digits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        digits++;
    }
    return digits;
}

// Helper function to split a string by space (without stringstream)
int splitString(const string& str, string words[], int maxWords) {
    int wordCount = 0;
    string currentWord = "";
    for (char c : str) {
        if (c == ' ') {
            if (!currentWord.empty() && wordCount < maxWords) {
                words[wordCount++] = currentWord;
                currentWord = "";
            }
        } else {
            currentWord += c;
        }
    }
    if (!currentWord.empty() && wordCount < maxWords) {
        words[wordCount++] = currentWord;
    }
    return wordCount;
}

// Helper function to convert string to int (without stoi)
int stringToInt(const string& str) {
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

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening input files!" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        string words[20]; // Assuming max 20 words per line
        int wordCount = splitString(line, words, 20);

        if (wordCount > 0) {
            string task = words[0];

            if (task == "schedule") {
                if (wordCount >= 3) {
                    string gender = words[1];
                    if (gender == "male") {
                        QueueInt maleQueueArr;
                        LinkedQueueInt maleQueueLinked;
                        for (int i = 2; i < wordCount; ++i) {
                            maleQueueArr.enqueue(stringToInt(words[i]));
                            maleQueueLinked.enqueue(stringToInt(words[i]));
                        }
                        getline(infile, line);
                        string femaleWords[20];
                        int femaleWordCount = splitString(line, femaleWords, 20);
                        if (femaleWordCount >= 3 && femaleWords[0] == "schedule" && femaleWords[1] == "female") {
                            QueueInt femaleQueueArr;
                            LinkedQueueInt femaleQueueLinked;
                            for (int i = 2; i < femaleWordCount; ++i) {
                                femaleQueueArr.enqueue(stringToInt(femaleWords[i]));
                                femaleQueueLinked.enqueue(stringToInt(femaleWords[i]));
                            }
                            outfile << "--- QueueInt (Array-based Queue) ---" << endl;
                            outfile << "--- LinkedQueueInt (Linked List-based Queue) ---" << endl;
                            outfile << endl << "--- Dance Scheduling ---" << endl;
                            scheduleDance(maleQueueArr, femaleQueueArr, outfile);
                            outfile << endl;
                            scheduleDanceLinked(maleQueueLinked, femaleQueueLinked, outfile);
                            outfile << endl;
                        }
                    }
                }
            } else if (task == "radixsort") {
                outfile << endl << "--- Radix Sort ---" << endl;
                int arr[20]; // Assuming max 20 numbers
                int n = 0;
                for (int i = 1; i < wordCount; ++i) {
                    arr[n++] = stringToInt(words[i]);
                }
                outfile << "Original array:";
                for (int i = 0; i < n; ++i) outfile << " " << arr[i];
                outfile << endl;

                int arr_copy_arr[20];
                for (int i = 0; i < n; ++i) arr_copy_arr[i] = arr[i];
                QueueInt queues_arr[10];
                int maxDigits = getMaxDigits(arr_copy_arr, n);
                radixSortQueue(arr_copy_arr, n, queues_arr, maxDigits, outfile);

                int arr_copy_linked[20];
                for (int i = 0; i < n; ++i) arr_copy_linked[i] = arr[i];
                LinkedQueueInt queues_linked[10];
                radixSortLinkedQueue(arr_copy_linked, n, queues_linked, maxDigits, outfile);
            }
        }
    }

    infile.close();
    outfile.close();

    return 0;
}

// Helper function to convert string to lower (without algorithm)
string toLower(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
    }
    return s;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(NULL) {}

    ~LinkedList() {
        clear();
    }

    void add(int value) {
        Node* newNode = new Node{value, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void remove(int value) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp) {
            if (prev) {
                prev->next = temp->next;
            } else {
                head = temp->next;
            }
            delete temp;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << std::endl;
    }

    void clear() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addList(const LinkedList& other) {
        Node* temp = other.head;
        while (temp) {
            add(temp->data);
            temp = temp->next;
        }
    }

private:
    Node* head;
};

int main() {
    LinkedList list1, list2;

    cout << "Nhap 10 so nguyen:";
    for (int i = 0; i < 10; ++i) {
        int value;
        cin >> value;
        list1.add(value);
    }

    cout << "Danh sach ban dau: ";
    list1.display();

    int k;
    cout << "Nhap so can xoa: ";
    cin >> k;
    list1.remove(k);

    cout << "Danh sach sau khi xoa: ";
    list1.display();

    cout << "Nhap 5 so nguyen cho danh sach thu hai:";
    for (int i = 0; i < 5; ++i) {
        int value;
        cin >> value;
        list2.add(value);
    }

    list1.addList(list2);

    cout << "Danh sach sau khi them danh sach thu hai: ";
    list1.display();

    return 0;
}

// Output
Nhap 10 so nguyen: 1 3 5 7 9 2 4 6 8 10
Nhap so can xoa: 5
Nhap 5 so nguyen cho danh sach thu hai: 11 13 15 17 19

Danh sach ban dau: 1 3 5 7 9 2 4 6 8 10
Danh sach sau khi xoa: 1 3 7 9 2 4 6 8 10
Danh sach sau khi them danh sach thu hai: 1 3 7 9 2 4 6 8 10 11 13 15 17 19
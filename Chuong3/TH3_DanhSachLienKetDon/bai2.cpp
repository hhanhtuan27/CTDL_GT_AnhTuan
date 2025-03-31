#include <iostream>
#include <cstring>
using namespace std;

// Struct SinhVien to represent student informations
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
};

// Node structure to represent each student in the linked list
struct Node {
    SinhVien sv;
    Node* next;
};

// Comparison functions for students
bool compareHoTen(const SinhVien& a, const SinhVien& b) {
    return strcmp(a.hoTen, b.hoTen) < 0;
}

bool compareDiaChi(const SinhVien& a, const SinhVien& b) {
    return strcmp(a.diaChi, b.diaChi) < 0;
}

bool compareLop(const SinhVien& a, const SinhVien& b) {
    return strcmp(a.lop, b.lop) < 0;
}

bool compareKhoa(const SinhVien& a, const SinhVien& b) {
    return a.khoa < b.khoa;
}

// LinkedList class to manage a list of SinhVien
class ListSV {
public:
    ListSV() : head(NULL) {}

    ~ListSV() {
        clear();
    }

    // Function to add a new student to the end of the list
    void add(const SinhVien& sv) {
        Node* newNode = new Node{ sv, NULL };
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

    // Function to remove a student by their name
    void removeByName(const char* name) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp && strcmp(temp->sv.hoTen, name) != 0) {
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

    // Function to remove a student by their address
    void removeByAddress(const char* address) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp && strcmp(temp->sv.diaChi, address) != 0) {
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

    // Function to output the list of students to the screen
    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->sv.hoTen << ", " << temp->sv.diaChi << ", " << temp->sv.lop << ", " << temp->sv.khoa << endl;
            temp = temp->next;
        }
    }

    // Function to clear the list and deallocate memory
    void clear() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to add another list to the end of the current list
    void addList(const ListSV& other) {
        Node* temp = other.head;
        while (temp) {
            add(temp->sv);
            temp = temp->next;
        }
    }

    // Function to sort the list using selection sort and a comparison function
    void selectionSort(bool (*compare)(const SinhVien&, const SinhVien&)) {
        for (Node* i = head; i != NULL; i = i->next) {
            Node* minNode = i;
            for (Node* j = i->next; j != NULL; j = j->next) {
                if (compare(j->sv, minNode->sv)) {
                    minNode = j;
                }
            }
            if (minNode != i) {
                swap(i->sv, minNode->sv);
            }
        }
    }
    
private:
    Node* head; // Pointer to the first element in the list
};

// Function to input a student's information
void inputSinhVien(SinhVien& sv) {
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(sv.hoTen, sizeof(sv.hoTen));
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, sizeof(sv.diaChi));
    cout << "Nhap lop: ";
    cin.getline(sv.lop, sizeof(sv.lop));
    cout << "Nhap khoa: ";
    cin >> sv.khoa;
}

// Main function to execute the program
int main() {
    ListSV listSV;

    cout << "Nhap 10 sinh vien:" << endl;
    for (int i = 0; i < 10; ++i) {
        SinhVien sv;
        inputSinhVien(sv);
        listSV.add(sv);
    }

    cout << "Danh sach sinh vien ban dau:" << endl;
    listSV.display();

    listSV.removeByName("Nguyen Van Teo");
    listSV.removeByAddress("Nguyen Van Cu");

    SinhVien newSV;
    strcpy(newSV.hoTen, "Tran Thi Mo");
    strcpy(newSV.diaChi, "25 Hong Bang");
    strcpy(newSV.lop, "TT0901");
    newSV.khoa = 2009;
    listSV.add(newSV);

    cout << "Danh sach sinh vien sau khi xoa va them:" << endl;
    listSV.display();

    return 0;
}


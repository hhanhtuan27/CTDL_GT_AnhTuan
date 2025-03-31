#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Phone
{
    string id;    // Mã điện thoại
    string brand; // Nhãn hiệu
    int price;    // Giá điện thoại
};

class PhoneManager
{
private:
    vector<Phone> phones; // Danh sách điện thoại

public:
    // Hàm thêm điện thoại
    void addPhone()
    {
        if (phones.size() >= 100)
        {
            cout << "Danh sach day. Khong them duoc." << endl;
            return;
        }

        Phone newPhone;
        cout << "Nhap ma dien thoai: ";
        cin >> newPhone.id;

        // Kiểm tra xem điện thoại đã tồn tại chưa
        for (const auto &phone : phones)
        {
            if (phone.id == newPhone.id)
            {
                cout << "Dien thoai da ton tai." << endl;
                return;
            }
        }

        cout << "Nhap nhan hieu: ";
        cin.ignore(); // Để tránh lỗi nhập ký tự sau cin
        getline(cin, newPhone.brand);

        cout << "Nhap gia: ";
        cin >> newPhone.price;

        phones.push_back(newPhone);
        cout << "Dien thoai da duoc them." << endl;
    }

    // Hàm tìm điện thoại theo mã và in thông tin
    void viewPhoneById()
    {
        string id;
        cout << "Nhap ma dien thoai can tim: ";
        cin >> id;

        for (const auto &phone : phones)
        {
            if (phone.id == id)
            {
                cout << "Nhan hieu: " << phone.brand << endl;
                cout << "Gia: " << phone.price << endl;
                return;
            }
        }

        cout << "Dien thoai khong ton tai." << endl;
    }

    // Hàm cập nhật giá điện thoại theo mã
    void updatePhonePrice()
    {
        string id;
        cout << "Nhap ma dien thoai can cap nhat gia: ";
        cin >> id;

        for (auto &phone : phones)
        {
            if (phone.id == id)
            {
                cout << "Nhap gia moi: ";
                cin >> phone.price;
                cout << "Gia dien thoai da duoc cap nhat." << endl;
                return;
            }
        }

        cout << "Dien thoai khong ton tai." << endl;
    }

    // Hàm xóa điện thoại theo mã
    void deletePhone()
    {
        string id;
        cout << "Nhap ma dien thoai can xoa: ";
        cin >> id;

        for (auto it = phones.begin(); it != phones.end(); ++it)
        {
            if (it->id == id)
            {
                phones.erase(it);
                cout << "Dien thoai da duoc xoa." << endl;
                return;
            }
        }

        cout << "Dien thoai khong ton tai." << endl;
    }

    // Hàm xuất tất cả điện thoại
    void showAllPhones()
    {
        if (phones.empty())
        {
            cout << "Danh sach dien thoai rong." << endl;
            return;
        }

        cout << "Danh sach dien thoai:" << endl;
        for (const auto &phone : phones)
        {
            cout << "Ma: " << phone.id << ", Nhãn hiệu: " << phone.brand << ", Giá: " << phone.price << endl;
        }
    }

    // Hàm hiển thị menu và xử lý yêu cầu của người dùng
    void displayMenu()
    {
        int choice;
        do
        {
            cout << "\n----- MENU -----\n";
            cout << "1. Them dien thoai\n";
            cout << "2. Xem thong tin dien thoai theo ma\n";
            cout << "3. Cap nhat gia dien thoai\n";
            cout << "4. Xoa dien thoai\n";
            cout << "5. Xuat danh sach dien thoai\n";
            cout << "6. Thoat\n";
            cout << "Chon chuc nang: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addPhone();
                break;
            case 2:
                viewPhoneById();
                break;
            case 3:
                updatePhonePrice();
                break;
            case 4:
                deletePhone();
                break;
            case 5:
                showAllPhones();
                break;
            case 6:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
            }
        } while (choice != 6);
    }
};

int main()
{
    PhoneManager manager;
    manager.displayMenu(); // Hiển thị menu và bắt đầu chương trình quản lý điện thoại
    return 0;
}

// ----- MENU -----
// 1. Them dien thoai
// 2. Xem thong tin dien thoai theo ma
// 3. Cap nhat gia dien thoai
// 4. Xoa dien thoai
// 5. Xuat danh sach dien thoai
// 6. Thoat
// Chon chuc nang: 1
// Nhap ma dien thoai: A002
// Nhap nhan hieu: Samsung
// Nhap gia: 500000
// Dien thoai da duoc them.

// ----- MENU -----
// 1. Them dien thoai
// 2. Xem thong tin dien thoai theo ma
// 3. Cap nhat gia dien thoai
// 4. Xoa dien thoai
// 5. Xuat danh sach dien thoai
// 6. Thoat
// Chon chuc nang: 5
// Danh sach dien thoai:
// Ma: A002, Nhãn hiệu: Samsung, Giá: 500000
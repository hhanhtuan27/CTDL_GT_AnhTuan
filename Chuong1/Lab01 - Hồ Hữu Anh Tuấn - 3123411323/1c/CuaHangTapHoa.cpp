#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item
{
    string MSMH;  // Mã số mặt hàng
    string TenMH; // Tên mặt hàng
    int SoLuong;  // Số lượng mặt hàng
    int DonGia;   // Đơn giá
};

class StoreManager
{
private:
    vector<Item> items; // Danh sách mặt hàng

public:
    // Hàm nhập n mặt hàng
    void inputItems()
    {
        int n;
        cout << "Nhap so luong mat hang: ";
        cin >> n;
        cin.ignore(); // Để tránh lỗi khi sử dụng getline

        for (int i = 0; i < n; ++i)
        {
            Item newItem;
            cout << "Nhap thong tin mat hang thu " << i + 1 << endl;

            cout << "Nhap ma so mat hang: ";
            getline(cin, newItem.MSMH);

            cout << "Nhap ten mat hang: ";
            getline(cin, newItem.TenMH);

            cout << "Nhap so luong: ";
            cin >> newItem.SoLuong;

            cout << "Nhap don gia: ";
            cin >> newItem.DonGia;
            cin.ignore(); // Để tránh lỗi khi sử dụng getline cho lần nhập tiếp theo

            items.push_back(newItem);
        }
    }

    // Hàm tìm kiếm mặt hàng theo tên và in thông tin
    void searchItemByName()
    {
        string name;
        cout << "Nhap ten mat hang can tim: ";
        getline(cin, name);

        bool found = false;
        for (const auto &item : items)
        {
            if (item.TenMH == name)
            {
                cout << "Thong tin mat hang: " << endl;
                cout << "Ma so mat hang: " << item.MSMH << endl;
                cout << "Ten mat hang: " << item.TenMH << endl;
                cout << "So luong: " << item.SoLuong << endl;
                cout << "Don gia: " << item.DonGia << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong co mat hang dang tim" << endl;
        }
    }

    // Hàm tính tổng số lượng các mặt hàng
    void calculateTotalQuantity()
    {
        int totalQuantity = 0;
        for (const auto &item : items)
        {
            totalQuantity += item.SoLuong;
        }
        cout << "Tong so luong mat hang: " << totalQuantity << endl;
    }

    // Hàm hiển thị menu và xử lý các yêu cầu
    void displayMenu()
    {
        int choice;
        do
        {
            cout << "\n----- MENU -----\n";
            cout << "1. Nhap danh sach mat hang\n";
            cout << "2. Tim mat hang theo ten\n";
            cout << "3. Tinh tong so luong mat hang\n";
            cout << "4. Thoat\n";
            cout << "Chon chuc nang: ";
            cin >> choice;
            cin.ignore(); // Để tránh lỗi khi sử dụng getline cho lần nhập tiếp theo

            switch (choice)
            {
            case 1:
                inputItems();
                break;
            case 2:
                searchItemByName();
                break;
            case 3:
                calculateTotalQuantity();
                break;
            case 4:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
            }
        } while (choice != 4);
    }
};

int main()
{
    StoreManager manager;
    manager.displayMenu(); // Hiển thị menu và bắt đầu chương trình quản lý cửa hàng
    return 0;
}

// ----- MENU -----
// 1. Nhap danh sach mat hang
// 2. Tim mat hang theo ten
// 3. Tinh tong so luong mat hang
// 4. Thoat
// Chon chuc nang: 1
// Nhap so luong mat hang: 1
// Nhap thong tin mat hang thu 1
// Nhap ma so mat hang: A001
// Nhap ten mat hang: Cafe
// Nhap so luong: 2
// Nhap don gia: 20000

// ----- MENU -----
// 1. Nhap danh sach mat hang
// 2. Tim mat hang theo ten
// 3. Tinh tong so luong mat hang
// 4. Thoat
// Chon chuc nang: 3
// Tong so luong mat hang: 2
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_HOA 20 // Giới hạn số loại hoa tối đa

// Cấu trúc loại hoa
struct LoaiHoa
{
    char Ten[50];  // Tên loại hoa
    int SoLuong;   // Số lượng hiện có
    char DVT[10];  // Đơn vị tính
    double DonGia; // Đơn giá
};

// Cấu trúc danh sách các loại hoa
struct DanhSachLoaiHoa
{
    LoaiHoa ds[MAX_HOA]; // Mảng chứa các loại hoa
    int SoLuong;         // Số lượng loại hoa hiện có
};

// Hàm nhập danh sách các loại hoa
void NhapDanhSach(DanhSachLoaiHoa &ds)
{
    cout << "Moi ban nhap so luong loai hoa: ";
    cin >> ds.SoLuong;

    while (ds.SoLuong <= 0 || ds.SoLuong > MAX_HOA)
    {
        cout << "So luong khong hop le! Nhap lai: ";
        cin >> ds.SoLuong;
    }

    for (int i = 0; i < ds.SoLuong; i++)
    {
        cout << "\nNhap thong tin loai hoa thu " << i + 1 << ":\n";

        cout << "Ten loai hoa: ";
        cin.ignore();
        cin.getline(ds.ds[i].Ten, 50);

        cout << "So luong: ";
        cin >> ds.ds[i].SoLuong;
        while (ds.ds[i].SoLuong < 0)
        {
            cout << "Nhap sai! Nhap lai so luong: ";
            cin >> ds.ds[i].SoLuong;
        }

        cout << "Don vi tinh: ";
        cin.ignore();
        cin.getline(ds.ds[i].DVT, 10);

        cout << "Don gia: ";
        cin >> ds.ds[i].DonGia;
        while (ds.ds[i].DonGia < 0)
        {
            cout << "Nhap sai! Nhap lai don gia: ";
            cin >> ds.ds[i].DonGia;
        }
    }
}

// Hàm xuất danh sách các loại hoa
void XuatDanhSach(DanhSachLoaiHoa ds)
{
    cout << "\nDANH SACH CAC LOAI HOA:\n";
    for (int i = 0; i < ds.SoLuong; i++)
    {
        cout << "Ten: " << ds.ds[i].Ten
             << ", So luong: " << ds.ds[i].SoLuong
             << ", DVT: " << ds.ds[i].DVT
             << ", Don gia: " << ds.ds[i].DonGia << endl;
    }
}

// Hàm tìm vị trí loại hoa theo tên
int TimLoaiHoa(DanhSachLoaiHoa ds, char *tenloai)
{
    for (int i = 0; i < ds.SoLuong; i++)
    {
        if (strcmp(ds.ds[i].Ten, tenloai) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Hàm xử lý bán hoa
void XuLyBanHoa(DanhSachLoaiHoa &ds, char *tenloai, int soluong)
{
    int index = TimLoaiHoa(ds, tenloai);
    if (index == -1)
    {
        cout << "\nLoai hoa '" << tenloai << "' khong ton tai trong cua hang.\n";
    }
    else
    {
        if (ds.ds[index].SoLuong >= soluong)
        {
            double tongTien = soluong * ds.ds[index].DonGia;
            ds.ds[index].SoLuong -= soluong;
            cout << "\nMua thanh cong!\n";
            cout << "Loai hoa: " << tenloai << "\nSo luong: " << soluong;
            cout << "\nTong tien: " << tongTien << endl;
        }
        else
        {
            cout << "\nKhong du so luong hoa '" << tenloai << "' de ban.\n";
        }
    }
}

// Hàm main
int main()
{
    DanhSachLoaiHoa ds;
    char tenloai[50];
    int soluong;

    // Nhập danh sách hoa
    NhapDanhSach(ds);

    // Xuất danh sách hoa
    XuatDanhSach(ds);

    // Xử lý bán hoa
    cout << "\nNhap ten loai hoa can mua: ";
    cin.ignore();
    cin.getline(tenloai, 50);

    cout << "Nhap so luong can mua: ";
    cin >> soluong;

    XuLyBanHoa(ds, tenloai, soluong);

    // Xuất danh sách sau khi bán
    cout << "\nDanh sach hoa sau khi ban:\n";
    XuatDanhSach(ds);

    return 0;
}

// Input:
// Moi ban nhap so luong loai hoa: 3

// Nhap thong tin loai hoa thu 1:
// Ten loai hoa: Hoa Hong
// So luong: 50
// Don vi tinh: Bong
// Don gia: 10.5

// Nhap thong tin loai hoa thu 2:
// Ten loai hoa: Hoa Cuc
// So luong: 30
// Don vi tinh: Bong
// Don gia: 7.2

// Nhap thong tin loai hoa thu 3:
// Ten loai hoa: Hoa Lan
// So luong: 20
// Don vi tinh: Canh
// Don gia: 15.0

// Nhap ten loai hoa can mua: Hoa Lan
// Nhap so luong can mua: 20

// Ouput:
// DANH SACH CAC LOAI HOA:
// Ten: Hoa Hong, So luong: 50, DVT: Bong, Don gia: 10.5
// Ten: Hoa Cuc, So luong: 30, DVT: Bong, Don gia: 7.2
// Ten: Hoa Lan, So luong: 20, DVT: Canh, Don gia: 15

// Mua thanh cong!
// Loai hoa: Hoa Lan
// So luong: 20
// Tong tien: 300

// Danh sach hoa sau khi ban:
// Ten: Hoa Hong, So luong: 50, DVT: Bong, Don gia: 10.5
// Ten: Hoa Cuc, So luong: 30, DVT: Bong, Don gia: 7.2
// Ten: Hoa Lan, So luong: 0, DVT: Canh, Don gia: 15
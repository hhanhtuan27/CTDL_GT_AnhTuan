#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100 // Giới hạn số nhân viên tối đa

// Cấu trúc nhân viên
struct NhanVien
{
    char MaSo[11]; // Mã số (tối đa 10 ký tự)
    char Ho[11];   // Họ lót (tối đa 10 ký tự)
    char Ten[51];  // Tên (tối đa 50 ký tự)
    int Phai;      // 0: Nữ, 1: Nam
    int ThamNien;  // Số năm làm việc (>=0)
};

// Cấu trúc phòng ban
struct PhongBan
{
    NhanVien aNhanVien[MAX]; // Mảng chứa nhân viên
    int SoLuong;             // Số lượng nhân viên hiện có
};

// Hàm nhập danh sách nhân viên cho phòng ban
void NhapPhongBan(PhongBan &pb)
{
    cout << "Moi ban nhap so luong nhan vien: ";
    cin >> pb.SoLuong;

    while (pb.SoLuong <= 0 || pb.SoLuong > MAX)
    {
        cout << "So luong khong hop le! Nhap lai: ";
        cin >> pb.SoLuong;
    }

    for (int i = 0; i < pb.SoLuong; i++)
    {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":\n";

        cout << "Ma so: ";
        cin >> pb.aNhanVien[i].MaSo;

        cout << "Ho lot: ";
        cin.ignore();
        cin.getline(pb.aNhanVien[i].Ho, 11);

        cout << "Ten: ";
        cin.getline(pb.aNhanVien[i].Ten, 51);

        cout << "Phai (0: Nu, 1: Nam): ";
        cin >> pb.aNhanVien[i].Phai;
        while (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai != 1)
        {
            cout << "Nhap sai! Nhap lai (0: Nu, 1: Nam): ";
            cin >> pb.aNhanVien[i].Phai;
        }

        cout << "Tham nien (>=0 nam): ";
        cin >> pb.aNhanVien[i].ThamNien;
        while (pb.aNhanVien[i].ThamNien < 0)
        {
            cout << "Nhap sai! Nhap lai so nam lam viec: ";
            cin >> pb.aNhanVien[i].ThamNien;
        }
    }
}

// Hàm xuất thông tin nhân viên trong phòng ban
void XuatPhongBan(PhongBan pb)
{
    cout << "\nDANH SACH NHAN VIEN:\n";
    for (int i = 0; i < pb.SoLuong; i++)
    {
        cout << "Ma so: " << pb.aNhanVien[i].MaSo
             << ", Ho: " << pb.aNhanVien[i].Ho
             << ", Ten: " << pb.aNhanVien[i].Ten
             << ", Phai: " << (pb.aNhanVien[i].Phai == 1 ? "Nam" : "Nu")
             << ", Tham nien: " << pb.aNhanVien[i].ThamNien << " nam" << endl;
    }
}

// Hàm đếm số lượng nam, nữ
void DemSiSo(PhongBan pb, int &sonam, int &sonu)
{
    sonam = 0;
    sonu = 0;
    for (int i = 0; i < pb.SoLuong; i++)
    {
        if (pb.aNhanVien[i].Phai == 1)
            sonam++;
        else
            sonu++;
    }
}

// Hàm sắp xếp danh sách nhân viên theo thâm niên tăng dần (Bubble Sort)
void SapXepTangTheoThamNien(PhongBan &pb)
{
    for (int i = 0; i < pb.SoLuong - 1; i++)
    {
        for (int j = 0; j < pb.SoLuong - i - 1; j++)
        {
            if (pb.aNhanVien[j].ThamNien > pb.aNhanVien[j + 1].ThamNien)
            {
                swap(pb.aNhanVien[j], pb.aNhanVien[j + 1]);
            }
        }
    }
}

// Hàm main
int main()
{
    PhongBan pb;
    int soNam, soNu;

    // Nhập danh sách nhân viên
    NhapPhongBan(pb);

    // Xuất danh sách nhân viên ban đầu
    XuatPhongBan(pb);

    // Đếm sĩ số nam, nữ
    DemSiSo(pb, soNam, soNu);
    cout << "\nSi so nhan vien:\n";
    cout << "+ So nam: " << soNam << "\n";
    cout << "+ So nu: " << soNu << "\n";

    // Sắp xếp danh sách nhân viên theo thâm niên tăng dần
    SapXepTangTheoThamNien(pb);

    // Xuất danh sách nhân viên sau khi sắp xếp
    cout << "\nDanh sach nhan vien sau khi sap xep theo tham nien tang dan:\n";
    XuatPhongBan(pb);

    return 0;
}

// Input
//  Moi ban nhap so luong nhan vien: 3

// Nhap thong tin nhan vien thu 1:
// Ma so: NV001
// Ho lot: Tran
// Ten: Nam
// Phai (0: Nu, 1: Nam): 1
// Tham nien (>=0 nam): 5

// Nhap thong tin nhan vien thu 2:
// Ma so: NV002
// Ho lot: Le
// Ten: Hoa
// Phai (0: Nu, 1: Nam): 0
// Tham nien (>=0 nam): 3

// Nhap thong tin nhan vien thu 3:
// Ma so: NV003
// Ho lot: Nguyen
// Ten: An
// Phai (0: Nu, 1: Nam): 1
// Tham nien (>=0 nam): 7

// Output
//  DANH SACH NHAN VIEN:
//  Ma so: NV001, Ho: Tran, Ten: Nam, Phai: Nam, Tham nien: 5 nam
//  Ma so: NV002, Ho: Le, Ten: Hoa, Phai: Nu, Tham nien: 3 nam
//  Ma so: NV003, Ho: Nguyen, Ten: An, Phai: Nam, Tham nien: 7 nam

// Si so nhan vien:
// + So nam: 2
// + So nu: 1

// Danh sach nhan vien sau khi sap xep theo tham nien tang dan:

// DANH SACH NHAN VIEN:
// Ma so: NV002, Ho: Le, Ten: Hoa, Phai: Nu, Tham nien: 3 nam
// Ma so: NV001, Ho: Tran, Ten: Nam, Phai: Nam, Tham nien: 5 nam
// Ma so: NV003, Ho: Nguyen, Ten: An, Phai: Nam, Tham nien: 7 nam
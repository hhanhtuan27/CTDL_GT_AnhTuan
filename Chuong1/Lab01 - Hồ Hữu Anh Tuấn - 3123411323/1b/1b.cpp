#include <iostream>
#include <cmath>

using namespace std;

// Hàm giải phương trình bậc hai
void GiaiPhuongTrinhBacHai(double *a, double *b, double *c)
{
    // Nếu a = 0, kiểm tra xem đây có phải là phương trình bậc nhất
    if (*a == 0)
    {
        if (*b == 0)
        {
            if (*c == 0)
                cout << "Phuong trinh co vo so nghiem.\n";
            else
                cout << "Phuong trinh vo nghiem.\n";
        }
        else
        {
            double x = -(*c) / (*b);
            cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
        }
        return;
    }

    // Tính delta
    double delta = (*b) * (*b) - 4 * (*a) * (*c);

    // Xét các trường hợp của delta
    if (delta > 0)
    {
        double x1 = (-(*b) + sqrt(delta)) / (2 * (*a));
        double x2 = (-(*b) - sqrt(delta)) / (2 * (*a));
        cout << "Phuong trinh co 2 nghiem phan biet:\n";
        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (delta == 0)
    {
        double x = -(*b) / (2 * (*a));
        cout << "Phuong trinh co 1 nghiem kep x = " << x << endl;
    }
    else
    {
        cout << "Phuong trinh vo nghiem.\n";
    }
}

int main()
{
    double a, b, c;

    // Nhập hệ số từ bàn phím
    cout << "Moi ban nhap he so a, b, c: ";
    cin >> a >> b >> c;

    // Gọi hàm giải phương trình
    GiaiPhuongTrinhBacHai(&a, &b, &c);

    return 0;
}

// Input: Moi ban nhap he so a, b, c: 1 2 1
// Output: Phuong trinh co 1 nghiem kep x = -1

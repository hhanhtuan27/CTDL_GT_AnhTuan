#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void giaiptbac2(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Vo so nghiem\n";
            }
            else
            {
                cout << "Vo nghiem\n";
            }
        }
        else
        {
            cout << "Nghiem duy nhat: " << fixed << setprecision(2) << -1.0 * c / b << "\n";
        }
    }
    else
    {
        float d = b * b - 4 * a * c;
        if (d < 0)
        {
            cout << "Vo nghiem\n";
        }
        else if (d == 0)
        {
            cout << "Nghiem kep: " << fixed << setprecision(2) << -1.0 * b / (2 * a) << "\n";
        }
        else
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);

            if (x1 > x2)
            {
                swap(x1, x2);
            }
            cout << "2 nghiem phan biet : " << fixed << setprecision(2) << x1 << " and " << x2 << "\n";
        }
    }
}

int main()
{
    int a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    giaiptbac2(a, b, c);

    return 0;
}

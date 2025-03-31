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

void interchangeSort(double arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void GiaiPTTrungPhuong(int a, int b, int c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                cout << "Phuong trinh co vo so nghiem\n";
            }
            else
            {
                cout << "Phuong trinh vo nghiem\n";
            }
        }
        else
        {
            double y = -1.0 * c / b;
            if (y < 0)
            {
                cout << "Phuong trinh vo nghiem\n";
            }
            else if (y == 0)
            {
                cout << "Phuong trinh co 1 nghiem\n";
                cout << "0.00\n";
            }
            else
            {
                cout << "Phuong trinh co 2 nghiem\n";
                double roots[2] = {-sqrt(y), sqrt(y)};
                interchangeSort(roots, 2);
                cout << fixed << setprecision(2) << roots[0] << " " << roots[1] << "\n";
            }
        }
    }
    else
    {
        double d = b * b - 4 * a * c;

        if (d < 0)
        {
            cout << "Phuong trinh vo nghiem\n";
        }
        else
        {
            double y1 = (-b + sqrt(d)) / (2 * a);
            double y2 = (-b - sqrt(d)) / (2 * a);

            double roots[4];
            int count = 0;

            if (y1 >= 0)
            {
                roots[count++] = -sqrt(y1);
                roots[count++] = sqrt(y1);
            }
            if (y2 >= 0)
            {
                roots[count++] = -sqrt(y2);
                roots[count++] = sqrt(y2);
            }

            if (count == 0)
            {
                cout << "Phuong trinh vo nghiem\n";
            }
            else
            {
                cout << "Phuong trinh co " << count << " nghiem\n";
                interchangeSort(roots, count);
                for (int i = 0; i < count; i++)
                {
                    cout << fixed << setprecision(2) << roots[i];
                    if (i != count - 1)
                        cout << " ";
                }
                cout << "\n";
            }
        }
    }
}

int main()
{
    int a, b, c;
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    GiaiPTTrungPhuong(a, b, c);

    return 0;
}

#include <iostream>
using namespace std;

int rep(int a, int b)
{
    return a < b ? a : b;
}
int *solve(int arr1[], int n1, int arr2[], int n2, int &rsCount)
{
    int *rs = new int[rep(n1, n2)];
    int count = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                bool found = false;
                for (int k = 0; k < count; k++)
                {
                    if (rs[k] == arr1[i])
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    rs[count++] = arr1[i];
                }
            }
        }
    }
    rsCount = count;
    return rs;
}

int main()
{
    int x, y, z;

    cin >> x;
    int *setX = new int[x];
    for (int i = 0; i < x; i++)
    {
        cin >> setX[i];
    }

    cin >> y;
    int *setY = new int[y];
    for (int i = 0; i < y; i++)
    {
        cin >> setY[i];
    }

    cin >> z;
    int *setZ = new int[z];
    for (int i = 0; i < z; i++)
    {
        cin >> setZ[i];
    }

    int sizeXY = 0;
    int *setXY = solve(setX, x, setY, y, sizeXY);

    int sizeXYZ = 0;
    int *setXYZ = solve(setXY, sizeXY, setZ, z, sizeXYZ);

    cout << sizeXYZ << "\n";
    for (int i = 0; i < sizeXYZ; i++)
    {
        cout << setXYZ[i] << " ";
    }

    delete[] setX;
    delete[] setY;
    delete[] setZ;
    delete[] setXY;
    delete[] setXYZ;

    return 0;
}
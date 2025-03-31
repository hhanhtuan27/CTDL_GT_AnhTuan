#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Số lượng phần tử tối đa của mảng

/*
Nhập dãy số nguyên từ bàn phím
+ Vào: bàn phím
+ Ra: (*a), n
+ Ví dụ: (*a) = {1, 2, 3}, n = 3
*/
void NhapMang(int **a, int *n)
{
    do
    {
        printf("Moi ban nhap so luong phan tu (1-%d): ", MAX);
        scanf("%d", n);
        if (*n <= 0 || *n > MAX)
        {
            printf("So luong phan tu khong hop le! Nhap lai.\n");
        }
    } while (*n <= 0 || *n > MAX);

    *a = (int *)malloc((*n) * sizeof(int)); // Cấp phát bộ nhớ động
    if (*a == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++)
    {
        printf("Phan tu %d: ", i);
        scanf("%d", (*a) + i);
    }
}

/*
Xuất dãy số nguyên ra màn hình
+ Vào: (*a), n
+ Ra: màn hình
Ví dụ: *a = {2, 5, 3}, n = 3
=> màn hình = 2 5 3
*/
void XuatMang(int *a, int n)
{
    printf("Day so co %d phan tu: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

/*
Đếm số lượng số chẵn trong dãy
+ Vào: *a, n
+ Ra: Số lượng số chẵn
*/
int DemChan(int *a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
            dem++;
    }
    return dem;
}

/*
Tách các số chẵn từ mảng ban đầu
+ Vào: *a, n
+ Ra: *b, m (chứa các số chẵn)
*/
void TachChan(int *a, int n, int **b, int *m)
{
    *m = DemChan(a, n); // Đếm số lượng phần tử chẵn
    if (*m == 0)
    {
        *b = NULL;
        return;
    }

    *b = (int *)malloc((*m) * sizeof(int)); // Cấp phát mảng chứa số chẵn
    if (*b == NULL)
    {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }

    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            *((*b) + cs) = *(a + i);
            cs++;
        }
    }
}

int main()
{
    int *b = NULL, k = 0;
    int *aChan = NULL, nChan = 0;

    // Nhập dữ liệu
    NhapMang(&b, &k);

    // Xuất mảng ban đầu
    printf("\n+ Mang vua nhap:\n");
    XuatMang(b, k);

    // Tách số chẵn
    TachChan(b, k, &aChan, &nChan);

    // Xuất mảng số chẵn nếu có
    if (nChan > 0)
    {
        printf("\n+ Mang chua cac so chan:\n");
        XuatMang(aChan, nChan);
    }
    else
    {
        printf("\n+ Khong co so chan trong mang!\n");
    }

    // Giải phóng bộ nhớ động
    free(b);
    free(aChan);

    return 0;
}

// Input:
// Moi ban nhap so luong phan tu (1-100): 3
// Phan tu 0: 2
// Phan tu 1: 3
// Phan tu 2: 6

// Output:
// + Mang vua nhap:
// Day so co 3 phan tu: 2 3 6

// + Mang chua cac so chan:
// Day so co 2 phan tu: 2 6
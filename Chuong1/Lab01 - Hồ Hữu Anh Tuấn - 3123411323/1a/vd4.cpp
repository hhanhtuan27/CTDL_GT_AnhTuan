#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // so luong phan tu toi da cua day

/*
Nhap day so nguyen tu ban phim
+ Vao: ban phim
+ Ra : (*a), n
+ Vi du: (*a) = {1,2,3}, n = 3
*/
void NhapMang(int **a, int *n) // truyen tham chieu
{
    printf("Moi ban nhap so luong phan tu: "); // nhap (*n)
    scanf("%d", n);
    *a = (int *)malloc((*n) * sizeof(int)); // cap phat dong
    for (int i = 0; i < *n; i++)            // duyet tu vi tri 0 den (*n)-1
    {
        printf("Phan tu %d: ", i);
        scanf("%d", (*a) + i);
    }
}

/*
Xuat day so nguyen ra man hinh
+ Vao: (*a), n
+ Ra : man hinh + Vi du:
*a = {2,5,3}, n = 3
=> man hinh = 2 5 3
*/
void XuatMang(int *a, int n) // truyen tham tri
{
    printf("Day so co %d phan tu: ", n);
    for (int i = 0; i < n; i++) // duyet tu vi tri 0 den n-1
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

// Doi cac gia tri chan thanh 0
void DoiChan(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) % 2 == 0)
        {
            *(a + i) = 0;
        }
    }
}

int main()
{
    int *b = NULL, k = 0;

    // Nhap du lieu
    NhapMang(&b, &k);

    // Xuat du lieu ban dau
    printf("\n* Mang vua nhap:\n");
    XuatMang(b, k);

    // Thay doi cac gia tri chan thanh 0
    DoiChan(b, k);

    // Xuat mang sau khi bien doi
    printf("\n* Mang sau khi doi cac gia tri chan thanh 0:\n");
    XuatMang(b, k);

    // Giai phong bo nho cap phat dong
    if (b != NULL)
        free(b);

    return 0;
}

// Input:
// Moi ban nhap so luong phan tu: 5
// Phan tu 0: 3
// Phan tu 1: 6
// Phan tu 2: 7
// Phan tu 3: 2
// Phan tu 4: 9

// Output
//  * Mang vua nhap:
//  Day so co 5 phan tu: 3 6 7 2 9

// * Mang sau khi doi cac gia tri chan thanh 0:
// Day so co 5 phan tu: 3 0 7 0 9

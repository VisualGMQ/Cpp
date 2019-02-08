//
//  main.c
//  test
//
//  Created by 桂明谦 on 2018/11/24.
//  Copyright © 2018 桂明谦. All rights reserved.
//

#include <stdio.h>
void DataSort(int a[], int n);
void PrintfArray(int a[], int n);
#define N 5

int main(void)
{
    int a[N] = {12,11,23,14,22};
    DataSort(a,N);
    PrintfArray(a,N);
    return 0;
}

//函数功能：将一个数组内的元素从小到大排序
void DataSort(int a[], int n)
{
    int i, j, temp, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                k = j;
        }
        if (k != i)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    return;
}

//函数功能：输出一个数组的所有元素
void PrintfArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%-4d", a[i]);
    }
    printf("\n");
    return;
}

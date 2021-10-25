// 6-3 Matrix I (15 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 10
int a[N][N], b[N][N];//矩阵a，b
int ans[N][N];
int a_row, a_col, b_row, b_col;//分别为a，b矩阵的行数，列数,保证a_col=b_row

void multiply();//计算ans=a*b

int main()
{
    scanf("%d%d%d%d", &a_row, &a_col, &b_row, &b_col);
    for (int i = 1; i <= a_row; ++i) //注意从1开始读入
        for (int j = 1; j <= a_col; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= b_row; ++i)
        for (int j = 1; j <= b_col; ++j)
            scanf("%d", &b[i][j]);
    multiply();
    for (int i = 1; i <= a_row; ++i, puts(""))
        for (int j = 1; j <= b_col; ++j)
            printf("%d ", ans[i][j]);
}

void multiply()
{
    for (int i = 1; i <= a_row; i++)
    {
        for (int j = 1; j <= b_col; j++)
        {
            int tmp = 0;
            for (int k = 1; k <= a_col; k++)
            {
                tmp += (a[i][k] * b[k][j]);
            }

            ans[i][j] = tmp;
        }
    }
}
/* 请在这里填写答案 */

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

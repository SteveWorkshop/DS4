// 6-4 Matrix II (15 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <cmath>
#include <algorithm>   // For next_permutation()
using namespace  std;
int n;//a矩阵的大小是n*n的

double count_Determinant(double** det, int n);
//返回a矩阵行列式的值,其中det为行列式，n为行列式的阶数

int main()
{
    scanf("%d", &n);
    auto** a = new double* [n + 1];//动态内存分配
    for (int i = 0; i <= n; i++)
        a[i] = new double[n + 1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%lf", &a[i][j]);
    printf("%.5lf", count_Determinant(a, n));
}
/* 请在这里填写答案 */
double count_Determinant(double** det, int n)
{
    for (int circle = 1; circle <= n - 1; circle++)//整个过程需要处理n-1轮
    {
        for (int i = circle + 1; i <= n; i++)//从C往下的每一行
        {
            double factor;
            factor = det[i][circle] / det[circle][circle];
            for (int j = circle; j <= n; j++)//第i行的每一列（列号恰好从C开始）
            {
                det[i][j] = det[i][j] - factor * det[circle][j];
            }
        }
    }
    double ans2 = 1;
    for (int i = 1; i <= n; i++)
    {
        ans2 *= det[i][i];
    }
    return ans2;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

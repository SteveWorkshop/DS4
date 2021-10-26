// 7-2 Simple KMP (25 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using std::string;

const int N = 1e7 + 100;

int next[N];

void setNext(string s, int* next)
{
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < s.length(); i++)
    {
        while (j != -1 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if (s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
}

int MyKmp(string s1, string s2, int* next)
{
    setNext(s2, next);
    int i = 0, j = -1;
    for (int i = 0; i < s1.length(); i++)
    {
        while (j != -1 && s1[i] != s2[j + 1])
        {
            j = next[j];
        }
        if (s1[i] == s2[j + 1])
        {
            j++;
            if (j == s2.length() - 1)
            {
                return i - s2.length() + 1;
            }
        }
        
    }
    return -1;
}

int main()
{
    int n;
    string s1, s2;
    std::cin >> n;
    while (n--)
    {
        std::cin >> s1;
        std::cin >> s2;
        //std::fill(next, next + N, 0);
        std::cout << MyKmp(s1, s2, next) << "\n";
    }
    
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

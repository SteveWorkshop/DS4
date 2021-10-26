// 物是人非.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void getline(char s[]);
int function(char* s1, char* s2);
int main() {
    int n, res;
    scanf("%d", &n);
    char s1[1000000];
    char s2[10000];
    while (n > 0) {
        scanf("%s", s1);
        scanf("%s", s2);
        //getline(s1);
        //getline(s2);
        res = function(s1, s2);
        printf("%d\n", res);
        n--;
    }
    return 0;
}
void getline(char s[])
{
    int i = 0;
    char ch = getchar();
    while (ch != '\n') {
        s[i] = ch;
        i++;
        ch = getchar();
    }
    s[i] = '\0';
}

int function(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j, index;
    i = 0;
    for (; i < len1; ++i) {
        index = i;
        for (j = 0; j < len2 && s1[index] == s2[j]; ++index, ++j) {

        }
        if (j == len2) { return i; }
    }
    return -1;
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

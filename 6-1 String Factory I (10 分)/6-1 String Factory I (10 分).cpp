// 6-1 String Factory I (10 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200
#define MAXLEN 2010

typedef struct
{
    char* ch;
    int length;
}string;
typedef int status;

status Assign(string* str, char* chars);
status Clear(string* str);
int Length(string* str);
status Concat(string* res, string* s1, string* s2);
status Substr(string* res, string* str, int pos, int len);

string str[N];

int main()
{
    freopen("1.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        char temp[MAXLEN];
        scanf("%s", temp);
        Assign(str + i, temp);
    }

    for (int i = 0; i < m; i++)
    {
        int op;
        scanf("%d", &op);
        string* product = NULL;
        switch (op)
        {
            case 1:
            {
                int a, b;
                scanf("%d %d", &a, &b);
                product = (string*)malloc(sizeof(string));
                product->ch = NULL;
                Concat(product, str + a, str + b);
                break;
            }
            case 2:
            {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                product = (string*)malloc(sizeof(string));
                product->ch = NULL;
                Substr(product, str + a, b, c);
                break;
            }
        }
        if (product)
        {
            printf("%s\n", product->ch);
            Clear(product);
        }
    }
    return 0;
}

/* 请在这里填写答案 */
status Assign(string* str, char* chars)
{
    
    /*if (!chars) { str->length = 0; return 1; }
    else { str->length = strlen(chars); }*/
    if (!chars || !strlen(chars))
    {
        str->ch = NULL;
        str->length = 0;
        return 1;
    }
    
    str->ch = (char*)calloc(strlen(chars)+1, sizeof(char));
    if (!str->ch) { return 0; }
    int i;
    for (i = 0; i<strlen(chars); i++)
    {
        str->ch[i] = chars[i];
    }
    str->ch[i] = 0;
    str->length = strlen(chars);
    return 1;
}

status Clear(string* str)
{
    if (!str || !str->ch) { return 0; }
    free(str->ch);
    str->ch = NULL;
    str->length = 0;
    return 1;
}

int Length(string* str)
{
    return str->length;
}

status Concat(string* res, string* s1, string* s2)
{
    int nwlen = s1->length + s2->length;
    if (res->ch) { free(res->ch); }
    res->ch = (char*)calloc(nwlen + 1, sizeof(char));
    if (!res->ch) { return 0; }
    int index = 0;
    for (int i = 0; i < s1->length; i++)
    {
        res->ch[index] = s1->ch[i];
        index++;
    }
    for (int i = 0; i < s2->length; i++)
    {
        res->ch[index] = s2->ch[i];
        index++;
    }
    res->ch[index] = 0;
    res->length = nwlen;
    return 1;
}


status Substr(string* res, string* str, int pos, int len)
{
    if (!str->ch) { return 0; }
    if (pos < 0 || len<0 || pos + len>str->length) { return 0; }
    res->ch = (char*)calloc(len + 1, sizeof(char));
    if (!res->ch) { return 0; }
    res->length = len;
    int index = 0;
    for (int i = pos; i < pos + len; i++)
    {
        res->ch[index] = str->ch[i];
        index++;
    }
    res->ch[index] = 0;
    return 1;
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

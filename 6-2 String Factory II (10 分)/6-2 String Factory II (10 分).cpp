// 6-2 String Factory II (10 分).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

typedef struct chunk
{
    char* ch;
    struct chunk* next;
}chunk;
typedef struct
{
    chunk* head, * tail;
    int curlen;
}string;
typedef int status;

string* Readstring();
void Insert(string* s1, int pos, char* s2);
void Clear(string* s);
void Print(string* s);

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        string* s1 = Readstring();
        int n;
        char temp[81];
        scanf("%d %s", &n, temp);
        Insert(s1, n, temp);
        Print(s1);
        Clear(s1);
    }
    return 0;
}
/* 请在这里填写答案 */

string* Readstring()
{
    string* s = (string*)malloc(sizeof(string));
    s->head = (chunk*)malloc(sizeof(chunk));
    s->head->next = NULL;
    s->tail = s->head;
    char a[(int)1e5 + 10];
    scanf("%s", a);
    int len = strlen(a);
    int num = len / N;
    if (len % N) { num++; }
    int index = 0;
    for (int i = 0; i < num; i++)
    {
        chunk* p = (chunk*)malloc(sizeof(chunk));
        p->next = NULL;
        s->tail->next = p;
        s->tail = p;
        if (i != num - 1) 
        { 
            p->ch = (char*)calloc(N, sizeof(char)); 
            
        }
        else 
        { 
            p->ch = (char*)calloc(len % N, sizeof(char)); 
        }

        


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

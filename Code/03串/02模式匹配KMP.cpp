#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */

/* 生成一个其值等于chars的串T */
Status StrAssign(String T, char* chars) {
    int i;
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    else {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
            T[i] = *(chars + i - 1);
        return OK;
    }
}

Status ClearString(String S) {
    S[0] = 0; /*  令串长为零 */
    return OK;
}

/*  输出字符串T。 */
void StrPrint(String T) {
    int i;
    for (i = 1; i <= T[0]; i++)
        printf("%c", T[i]);
    printf("\n");
}

/*  输出Next数组值。 */
void NextPrint(int next[], int length) {
    int i;
    for (i = 1; i <= length; i++)
        printf("%d", next[i]);
    printf("\n");
}

/* 返回串的元素个数 */
int StrLength(String S) {
    return S[0];
}

/* 朴素的模式匹配法 */
int Index(String S, String T, int pos) {
    int i =
        pos; /* i用于主串S中当前位置下标值，若pos不为1，则从pos位置开始匹配 */
    int j = 1; /* j用于子串T中当前位置下标值 */
    while (i <= S[0] &&
           j <= T[0]) /* 若i小于S的长度并且j小于T的长度时，循环继续 */
    {
        if (S[i] == T[j]) /* 两字母相等则继续 */
        {
            ++i;
            ++j;
        } else /* 指针后退重新开始匹配 */
        {
            i = i - j + 2; /* i退回到上次匹配首位的下一位 */
            j = 1;         /* j退回到子串T的首位 */
        }
    }
    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

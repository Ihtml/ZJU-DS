#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */
typedef char String[MAXSIZE + 1]; /*  0号单元存放串的长度 */

/* 生成一个其值等于chars的串T */
/* 串是由零个或多个任意字符组成的字符序列 */

Status StrAssign(String T, char *chars) {
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

/* 由串S复制得串T */
Status StrCopy(String T, String S) {
    int i;
    for (i = 0; i <= S[0]; i++)
        T[i] = S[i];
    return OK;
}

/* 若S为空串,则返回TRUE,否则返回FALSE */
Status StrEmpty(String S) {
    if (S[0] == 0)
        return TRUE;
    else
        return FALSE;
}

/*  初始条件: 串S和T存在 */
/*  操作结果: 若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0 */
int StrCompare(String S, String T) {
    int i;
    for (i = 1; i <= S[0] && i <= T[0]; ++i)
        if (S[i] != T[i])
            return S[i] - T[i];
    return S[0] - T[0];
}

/* 返回串的元素个数 */
int StrLength(String S) {
    return S[0];
}

/* 初始条件:串S存在。操作结果:将S清为空串 */
Status ClearString(String S) {
    S[0] = 0; /*  令串长为零 */
    return OK;
}

/* 用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE */
Status Concat(String T, String S1, String S2) {
    int i;
    if (S1[0] + S2[0] <= MAXSIZE) { /*  未截断 */
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
    } else { /*  截断S2 */
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
            T[S1[0] + i] = S2[i];
        T[0] = MAXSIZE;
        return FALSE;
    }
}

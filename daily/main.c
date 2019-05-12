#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef  int DataType;
typedef struct stStack
{
    DataType data;
    struct stStack* pTop;
}STACK;

/* 初始化栈*/
STACK* initStack()
{
    STACK* pNewNode = (STACK*)malloc(sizeof(STACK));
    if (NULL != pNewNode)
    {
        pNewNode->data = 0;
        pNewNode->pTop = NULL;
    }

    return pNewNode;
}

/* 入栈操作 */
STACK* pushStack(STACK* pHead, DataType paraData)
{
    STACK* pNewNode = (STACK*)malloc(sizeof(STACK));
    if (NULL == pNewNode)
    {
        return NULL;
    }
    pNewNode->data = paraData;
    pNewNode->pTop = pHead;

    pHead = pNewNode;
    return pHead;
}

/* 出栈操作 */
STACK* popStack(STACK* pHead, DataType* outData)
{
    /* 如果栈为空 */
    if (NULL == pHead->pTop)
    {
        return NULL;
    }

    /* 把数据传出去 */
    *outData = pHead->data;
    STACK* pTemp = pHead;

    pHead = pHead->pTop;

    /* 把头删除 */
    delete pTemp;

    return pHead;
}

/* 返回栈顶元素值 */
int getTopStack(STACK* pHead, DataType* outData)
{
    /* 如果栈为空 */
    if (NULL == pHead->pTop)
    {
        return -1;
    }

    *outData = pHead->data;
    return 0;
}
/* 遍历栈的操作 */
int visitStack(STACK* pHead)
{
    STACK* pTemp = pHead;

    /* 判断栈是否为空 */
    if (NULL == pHead->pTop)
    {
        printf("This stack is empty\n");
        return -1;
    }

    while (NULL != pTemp->pTop)
    {
        printf("%d ", pTemp->data);
        pTemp = pTemp->pTop;
    }
    printf("\n");
}
/* 清空栈 */
STACK* destoryStack(STACK* pHead)
{
    STACK* pTemp = NULL;
    while (NULL != pHead->pTop)
    {
        pTemp = pHead;
        pHead = pHead->pTop;
        delete pTemp;
    }
    return pHead;
}
int main()
{
    DataType num = 0;
    STACK* pHead = initStack();

    /* 入栈 */
    pHead = pushStack(pHead, 3);
    pHead = pushStack(pHead, 10);
    pHead = pushStack(pHead, 55);

    visitStack(pHead);

    /* 出栈 */
    pHead = popStack(pHead, &num);
    visitStack(pHead);

    /* 返回栈顶的元素 */
    getTopStack(pHead, &num);
    printf("%d\n", num);

    /* 销毁栈 */
    pHead = destoryStack(pHead);
    visitStack(pHead);


    return 0;
}

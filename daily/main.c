#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef  int DataType;
typedef struct stStack
{
    DataType data;
    struct stStack* pTop;
}STACK;

/* ��ʼ��ջ*/
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

/* ��ջ���� */
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

/* ��ջ���� */
STACK* popStack(STACK* pHead, DataType* outData)
{
    /* ���ջΪ�� */
    if (NULL == pHead->pTop)
    {
        return NULL;
    }

    /* �����ݴ���ȥ */
    *outData = pHead->data;
    STACK* pTemp = pHead;

    pHead = pHead->pTop;

    /* ��ͷɾ�� */
    delete pTemp;

    return pHead;
}

/* ����ջ��Ԫ��ֵ */
int getTopStack(STACK* pHead, DataType* outData)
{
    /* ���ջΪ�� */
    if (NULL == pHead->pTop)
    {
        return -1;
    }

    *outData = pHead->data;
    return 0;
}
/* ����ջ�Ĳ��� */
int visitStack(STACK* pHead)
{
    STACK* pTemp = pHead;

    /* �ж�ջ�Ƿ�Ϊ�� */
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
/* ���ջ */
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

    /* ��ջ */
    pHead = pushStack(pHead, 3);
    pHead = pushStack(pHead, 10);
    pHead = pushStack(pHead, 55);

    visitStack(pHead);

    /* ��ջ */
    pHead = popStack(pHead, &num);
    visitStack(pHead);

    /* ����ջ����Ԫ�� */
    getTopStack(pHead, &num);
    printf("%d\n", num);

    /* ����ջ */
    pHead = destoryStack(pHead);
    visitStack(pHead);


    return 0;
}

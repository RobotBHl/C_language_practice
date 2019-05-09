
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2  //溢出
typedef int Status;
#define LIST_INIT_SIZE 5 //线性表存储空间的初始分配量
#define LISTINCREMENT  10    //线性表存储空间的分配增量


/*
*定义线性表的结构
**/
typedef struct{
  int * elem;
  int length;
  int listsize;
}SqList;
//以下是构造一个空的线性表

/*
*func:InitList()
*desc:构造一个空的线性表L
*@param:&L SqList
*@return OK int
*/
Status InitList(SqList &L){
  L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int)); //动态开辟一维数组
  if(!L.elem) exit(OVERFLOW);  //存储分配失败
  L.length=0;     //空表长度初始化为0
  L.listsize=LIST_INIT_SIZE;  //存储的初始容量
  return OK;
}
//在顺序线性表L中第i个位置插入新的元素e

/*
*fun:ListInsert_Sq()
*desc:在顺序线性表L中第i个位置之前插入新的元素e
*@param:&L SqList
*@param: i int
*@param: e int
*@ret OK int
*/
Status ListInsert_Sq(SqList &L,int i,int e){
    //i需要满足1<=i<=ListLength_Sq(L)+1
    if(i<1||i>L.length+1) return ERROR;
    if(L.length>=L.listsize){      //当前存储空间已满,增加分配
       int *newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
       if(!newbase) exit(OVERFLOW); //存储分配失败
       L.elem=newbase;              //新地址
       L.listsize+=LISTINCREMENT;   //增加存储容量
    }
    int *q=&(L.elem[i-1]);  //q为插入的位置(注意数组的下标是从0开始计数)
    for(int *p=&(L.elem[L.length-1]);p>=q;p--) *(p+1)=*p; //插入位置及之后的元素后移
    *q=e;                  //插入e
    L.length+=1;           //表长增1
    return OK;
}


/*
*fun:ListDelete_Sq()
*desc:在顺序线性表L中删除第i个元素,并用e值返回
*@param:&L SqList
*@param: i int
*@param: e int
*@ret OK int
*/
Status ListDelete_Sq(SqList &L,int i,int &e){
//i的合法性为1<=i<=ListLength_Sq(L)
 if(i<1||i>L.length) return ERROR;
 e=L.elem[i-1];        //把被删除的元素赋给e
 int *p=&L.elem[i-1];  //指针p为被删除元素的位置
 for(int *q=p+1;q<=p+(L.length-i);q++) *(q-1)=*q; //被删除位置之后的元素都往前移
 L.length-=1;              //表长减一
 return OK;
}

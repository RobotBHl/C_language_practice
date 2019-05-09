
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2  //���
typedef int Status;
#define LIST_INIT_SIZE 5 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10    //���Ա�洢�ռ�ķ�������


/*
*�������Ա�Ľṹ
**/
typedef struct{
  int * elem;
  int length;
  int listsize;
}SqList;
//�����ǹ���һ���յ����Ա�

/*
*func:InitList()
*desc:����һ���յ����Ա�L
*@param:&L SqList
*@return OK int
*/
Status InitList(SqList &L){
  L.elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int)); //��̬����һά����
  if(!L.elem) exit(OVERFLOW);  //�洢����ʧ��
  L.length=0;     //�ձ��ȳ�ʼ��Ϊ0
  L.listsize=LIST_INIT_SIZE;  //�洢�ĳ�ʼ����
  return OK;
}
//��˳�����Ա�L�е�i��λ�ò����µ�Ԫ��e

/*
*fun:ListInsert_Sq()
*desc:��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e
*@param:&L SqList
*@param: i int
*@param: e int
*@ret OK int
*/
Status ListInsert_Sq(SqList &L,int i,int e){
    //i��Ҫ����1<=i<=ListLength_Sq(L)+1
    if(i<1||i>L.length+1) return ERROR;
    if(L.length>=L.listsize){      //��ǰ�洢�ռ�����,���ӷ���
       int *newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(int));
       if(!newbase) exit(OVERFLOW); //�洢����ʧ��
       L.elem=newbase;              //�µ�ַ
       L.listsize+=LISTINCREMENT;   //���Ӵ洢����
    }
    int *q=&(L.elem[i-1]);  //qΪ�����λ��(ע��������±��Ǵ�0��ʼ����)
    for(int *p=&(L.elem[L.length-1]);p>=q;p--) *(p+1)=*p; //����λ�ü�֮���Ԫ�غ���
    *q=e;                  //����e
    L.length+=1;           //����1
    return OK;
}


/*
*fun:ListDelete_Sq()
*desc:��˳�����Ա�L��ɾ����i��Ԫ��,����eֵ����
*@param:&L SqList
*@param: i int
*@param: e int
*@ret OK int
*/
Status ListDelete_Sq(SqList &L,int i,int &e){
//i�ĺϷ���Ϊ1<=i<=ListLength_Sq(L)
 if(i<1||i>L.length) return ERROR;
 e=L.elem[i-1];        //�ѱ�ɾ����Ԫ�ظ���e
 int *p=&L.elem[i-1];  //ָ��pΪ��ɾ��Ԫ�ص�λ��
 for(int *q=p+1;q<=p+(L.length-i);q++) *(q-1)=*q; //��ɾ��λ��֮���Ԫ�ض���ǰ��
 L.length-=1;              //����һ
 return OK;
}

#include"stdio.h"
#include"stdlib.h"  
#define TRUE 1 
#define  ERROR 0
typedef struct 
{
  int * elem; //储存空间基地址     
  int length; // 记录当前链表长度  
  int listsize;	//链表规模
} SqList;
int InitList(SqList *L)
{
(*L).elem =(int*)malloc( 100*sizeof(int) ); //返回NULL 
if (!(*L).elem) 
     {
 printf("顺序表初始化失败");
  exit(-2); //内存分配失败 
}
(*L).length=1;
(*L).listsize =100;  
    return 1;
}


void Clear_Sq(SqList *L)
{
(*L).length =0;
} 
void Destroy(SqList*L)
{
free((*L).elem);
(*L).elem =NULL;

(*L).length =0;
}


int ListEmpty_Sq(SqList L)  //值拷贝  


{
return L.length ==0 ?1:0; 

}


int ListLength_Sq(SqList L)
{
    return L.length ;
    
 } 
 
 int  GetEle_Sq(SqList L,int i,int *e)
{
   if (i<1||i>L.length)
   return 0;
   	   *e =L.elem[i-1];
   	   return 1;
 }  
/*
往顺序表中插入值。数字下标从零开始。 


*/ 
int ListInsert_Sq(SqList *L ,int i, int e) 
{  
   int * newbase;
   int *p,*q;
   if (i<1||i>(*L).length)
    return 0;
   if((*L).length >=(*L).listsize)
    {
    newbase = ( int *)realloc ((*L).elem,((*L).listsize+10)*sizeof(int));
                                // 第一个参数是线性表节点地址 第二个参数是在开辟多大的内存 。
(*L) .elem = newbase;
(*L).listsize+=10;
}
q =&(*L).elem[i-1];  
for (p=&(*L).elem[(*L).length-1];p>=q;--p) //元素储存位置挨个减一 ,插入第一个数不进入这个循环。 
    {
    *(p+1)=*p; 
}
*q=e;
(*L).length++; 
   return 1;
} 
int LocateElem_Sq(SqList L,int e ) 
{
   int i=1;
   while(i<L.length && L.elem [i-1]!=e)
    {
i++;
}
  if (i<L.length )
   {  return i;
  }
return 0;
}
  
int ListDelete_Sq(SqList *L,int i,int *e)
{
int j;
int *p,*q ;  
 if (i<1||i>(*L).length )
  return 0;
p=&(*L).elem [i-1];
*e=*p; 
q=(*L).elem +(*L).length -1;//elem[length-1]
for  (++p;p<=q;++p)
{
*(p-1)= *p;
 
}
(*L).length--;
return 1;

} 
/* 线性表遍历 从0到legnth-1; 
*/
int ListTraverse_Sq(SqList L)
{
 int i;
 for (i=0;i<L.length-1 ;i++)
     printf(" 打表 %d ",L.elem [i]);

}
int main()
{
SqList L;
int  e;
int i; 
if(InitList(&L)==1)
 {
 	printf("顺序表初始化成功\n"); 
 } 
printf("当前线性表长度%d\n",L.length-1); 
  //   L.length=1; 
//ListTraverse_Sq(L);
for(i=1;i<10;i++)
ListInsert_Sq(&L,i, 2*i); //插入一个元素  
printf("当前线性表长度%d\n",L.length-1); 
printf("4的定 =% d\n",LocateElem_Sq(L,4));
ListTraverse_Sq(L);
ListDelete_Sq(&L,2,&e);
printf("删除的第二个元素是%d\n",e); 
ListTraverse_Sq(L);
return 0;
}

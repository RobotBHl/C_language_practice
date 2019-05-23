#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INFINITY 65535
#define TRUE 1
#define FALSE 0

typedef char VertexType;
typedef int EdgeType;

typedef int Boole;  //�������� �洢TRUE FALSE
Boole visited[MAX];    //���ʱ�־����

typedef int QElemType;    //�����е���������
typedef int Status;


/*�ڽӾ���ṹ*/
typedef struct
{
	VertexType vexs[MAX];   //�����
	EdgeType arc[MAX][MAX];   //�ڽӾ��� �ɿ����߱�
	int numVertexes,numEdges;   //�������ͱ���
}MGraph;

/*���нṹ*/
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr front,rear;  //��ͷ��βָ��
}LinkQueue;


//�����ڽӾ���
void create(MGraph *G)
{
	int i,j,k,w;
	printf("�����붥�����ͱ���:\n");
	scanf("%d%d",&G->numVertexes,&G->numEdges);
	fflush(stdin);
	for(i=0;i<G->numVertexes;i++)     //���������
	{
		printf("\n��%d������",i+1);
		scanf("%c",&G->vexs[i]);
		getchar();
	}

	for(i=0;i<G->numVertexes;i++)   //�����ʼ��
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;

	for(k=0;k<G->numEdges;k++)
	{
		printf("����ߣ�Vi,Vj�������±�i,j��Ȩw(�ո����)��");
		scanf("%d%d%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];
	}
}

  //����ڽӾ���
void Output(MGraph *G)
{
	int i,j,count=0;
	for(i=0;i<G->numVertexes;i++)
		printf("\t%c",G->vexs[i]);
	printf("\n");
	for(i=0;i<G->numVertexes;i++)
	{
		printf("%4c",G->vexs[i]);
		for(j=0;j<G->numVertexes;j++)
		{

				printf("\t%d",G->arc[i][j]);
				count++;
				if(count%G->numVertexes==0)
				printf("\n");
		}
    }
 }


//�����ն���
Status InitQueue(LinkQueue &Q)
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front)
		exit(0);
	Q.front->next=NULL;
	return 1;
}

//�����
//��s��Ϊ��Ԫ�ؼ����β
Status EnQueue(LinkQueue &Q,int i)
{
	QueuePtr s;
	s=(QueuePtr)malloc(sizeof(QNode));
	if(!s)
		exit(0);
	s->data=i;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	return 1;
}

//�����Ƿ�Ϊ��
Status QueueEmpty(LinkQueue Q)
{
	if(Q.front->next==NULL)
		return 0;
	else
		return 1;
 }

//������
Status DeQueue(LinkQueue *Q,int *i)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return 0;
	p=Q->front->next;     //��д��ֵ����ȶ
						//�൱��p�����һ�����
	*i=p->data;
	Q->front->next=p->next;

	if(p==Q->rear)   //����ͷ�Ƕ�β	,ɾ����rearָ��ͷ���
		Q->rear==Q->front;
	free(p);
	return 1;
 }



/*��ȱ���*/
void BFSTraverse(MGraph G)
{

	int i,j;
	LinkQueue Q;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	InitQueue(Q);          //&���÷�??     ��ʼ������
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i])    //δ���ʹ� �ö���
		{
			visited[i]=TRUE;
			printf("%c->",G.vexs[i]);
			EnQueue(Q,i);      //���������
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);    //������Ԫ�س����У���ֵ��i
				for(j=0;j<G.numVertexes;j++)
				{
					if(G.arc[i][j]==1&&!visited[j])      //����������ö�����ڱ�   ��δ���ʹ�
					{
						visited[j]=TRUE;
						printf("%c",G.vexs[j]);
						EnQueue(Q,j);                 //�����
					}

				}
			}
		}
	}
}


int main()
{
	MGraph G;
	create(&G);
	printf("�ڽӾ����������£�\n");
	Output(&G);
	printf("\n");
	BFSTraverse(G);
	printf("\nͼ�������");
	return 0;

}

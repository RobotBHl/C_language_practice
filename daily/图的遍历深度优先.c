
/*������ȱ���*/
//������ȵݹ��㷨
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //�����ʵı��
	printf("%c->",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])   //��(i,j)������j����δ�����ʣ��ݹ�
			DFS(G,j);
	}
}
//������ȱ���
void DFStraverse(MGraph G)
{

	int i;
	for(i=0;i<G.numVertexes;i++)
		visited[i]=FALSE;
	for(i=0;i<G.numVertexes;i++)
			if(!visited[i])
				DFS(G,i);

}
int main()
{
	MGraph G;
	int i,j;
	printf("��������ͼ������(����ͼ0/����ͼ1)��");
	scanf("%d",&G.GraphType);
	create(&G);
	printf("�ڽӾ����������£�\n");
	Output(&G);
	printf("\n");
	DFStraverse(G);
	printf("\nͼ�������");
	return 0;
}

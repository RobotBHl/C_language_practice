
/*深度优先遍历*/
//深度优先递归算法
void DFS(MGraph G,int i)
{
	int j;
	visited[i]=TRUE;   //被访问的标记
	printf("%c->",G.vexs[i]);
	for(j=0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j]==1&&!visited[j])   //边(i,j)存在且j顶点未被访问，递归
			DFS(G,j);
	}
}
//深度优先遍历
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
	printf("输入生成图的类型(无向图0/有向图1)：");
	scanf("%d",&G.GraphType);
	create(&G);
	printf("邻接矩阵数据如下：\n");
	Output(&G);
	printf("\n");
	DFStraverse(G);
	printf("\n图遍历完毕");
	return 0;
}

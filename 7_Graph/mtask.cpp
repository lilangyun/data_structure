/*
* 必做任务·源代码
*/
#include<iostream>
#include<stack>  //导入栈
#include<queue>  //导入队列
using namespace std;

const int MaxVexNum=10;  //最大顶点个数

typedef char VertexData;
typedef int EdgeData;

typedef struct node{
    int dest;  //目标顶点位置
    EdgeData cost;  //边的权重
    struct node* link;  //下一条边的连接指针
}EdgeNode;  //边结点

typedef struct {
    VertexData data;  //顶点数据结构
    EdgeNode *adj;  //边链表
}VertexNode;  //顶点结点

typedef struct{
    VertexNode VerList[MaxVexNum];  //邻接表
    int n,e;  //图中当前顶点的个数与边数
}AdjGraph;  //图

// func1:实现无向图的邻接表并输出
void CreateGraph(AdjGraph& G){
    cout<<"请输出图的结点数和边的个数："<<endl;
    cin>>G.n>>G.e;  //结点个数和边的个数
    cout<<"请输出顶点信息："<<endl;
    for(int i=0;i<G.n;i++){
        cin>>G.VerList[i].data;  //输入顶点信息
        G.VerList[i].adj=NULL;
    }

    cout<<"请按照编号输入每条边的源头，目的地，边权重："<<endl;
    for (int i = 0; i < G.e; i++)
    {
        /* code */
        int source,dest,cost;  //源头，目的地，边权重
        cin>>source>>dest>>cost;
        EdgeNode *p=new EdgeNode;
        p->dest=dest;
        p->cost=cost;
        p->link=G.VerList[source].adj;
        G.VerList[source].adj=p;

        p=new EdgeNode;
        p->dest=source;
        p->cost=cost;
        p->link=G.VerList[dest].adj;
        G.VerList[dest].adj=p;
    }

    // 输出
    cout<<"邻接表输出为："<<endl;
    cout<<"source  dest  cost"<<endl;
    for(int i=0;i<G.n;i++){
        cout<<G.VerList[i].data<<" : "<<endl;
        EdgeNode *p=G.VerList[i].adj;
        for( ;p;p=p->link){
            cout<<i<<" "<<p->dest<<" "<<p->cost<<endl;
        }
    }
}  //这里针对无向图，应该一条边链接2次

// 访问结点
void Visit(AdjGraph& G,int v){
    // 本题中，访问可以看作是输出即可
    cout<<G.VerList[v].data<<endl;
}

// 获取第一个邻接结点
int GetFirstNeighbor(AdjGraph& G,int v){
    if(!G.VerList[v].adj){
        return -1;  //如果无邻接边链表，返回-1
    }
    int ans=G.VerList[v].adj[0].dest;
    return ans;
}

// 找到w之后的邻接顶点
int GetNextNeighbor(AdjGraph& G,int v,int w){
    EdgeNode* p=G.VerList[v].adj;
    while(p!=NULL&&p->dest!=w){
        p=p->link;
    }
    if(!p||!p->link){
        return -1;
    }
    return p->link->dest;
}

// 深度搜索
void dfs(AdjGraph& G,int v,int visited[]){
    Visit(G,v);  //访问顶点v
    visited[v]=1;  ///标志数组
    
    for(int w = GetFirstNeighbor(G,v); w != -1; w = GetNextNeighbor(G, v, w)){
        if(!visited[w]){
            dfs(G, w, visited);
        }
    }
}

// 非递归实现
void dfs_s(AdjGraph& G,int v,int visited[]){  // 这里visited表示是否入过栈而不是是否访问
    stack<int>s;
    s.push(v);
    visited[v] = 1;  // 入栈
    while(!s.empty()){
        int w = s.top();
        s.pop();
        Visit(G, w);
        for(int k = GetFirstNeighbor(G, w); k != -1; k = GetNextNeighbor(G, w, k)){
            if(!visited[k]){
                s.push(k);
                visited[k] = 1;
            }
        }
    }
}

// DFS遍历
void Graph_Traverse_DFS(AdjGraph G){
    int *visited=new int[MaxVexNum];
    for(int i=0;i<G.n;i++){
        visited[i]=0;
    }
    for(int i=0;i<G.n;i++){  //解决连通分量问题
        if(!visited[i]){
            dfs_s(G,i,visited);
        }
    }
    delete[] visited;
}

// 广度搜索
void bfs(AdjGraph& G,int v,int visited[]){
    Visit(G,v);
    visited[v]=1;
    queue<int> q;  //创建队列
    q.push(v);  //v入队
    while(!q.empty()){
        v=q.front();
        q.pop();  //对头出队

        int w=GetFirstNeighbor(G,v);
        while(w!=-1){
            if(!visited[w]){
                Visit(G,w);
                visited[w]=1;
                q.push(w);
            }
            w=GetNextNeighbor(G,v,w);
        }
    }
}

// BFS遍历
void Graph_Traverse_BFS(AdjGraph G){
    int *visited=new int[MaxVexNum];
    for(int i=0;i<G.n;i++){
        visited[i]=0;
    }
    for(int i=0;i<G.n;i++){  //解决连通分量问题
        if(!visited[i]){
            bfs(G,i,visited);
        }
    }
    delete[] visited;
}

int main(){
    AdjGraph G;
    CreateGraph(G);
    printf("The Graph's output sequence is following (DFS): \n");
    Graph_Traverse_DFS(G);
    printf("The Graph's output sequence is following (BFS): \n");
    Graph_Traverse_BFS(G);
    return 0;
}
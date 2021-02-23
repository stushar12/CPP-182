#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edgelist;

void addEdge(int x,int y,int weight)
{
    edgelist.push_back({weight,x,y});
}

int find_set(int i,int parent[])
{
    if(parent[i]==-1)
        return i;
    parent[i] = find_set(parent[i],parent);
    return parent[i];
}
void union_set(int x,int y,int parent[],int rank[])
{
    int s1 = find_set(x,parent);
    int s2 = find_set(y,parent);

    if(s1!=s2)
    {
        if(rank[s1]<rank[s2])
        {
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
        else
        {
            parent[s1]=s2;
            rank[s2]+=rank[s1];
        }
    }
}

int mst(int vertices)
{
   int parent[vertices];
   int rank[vertices];
   int ans=0;
   for(int i=0;i<vertices;i++)
   {
       parent[i]=-1;
       rank[i]=1;
   }
   sort(edgelist.begin(),edgelist.end());
   for(auto edge: edgelist)
   {
       int weight = edge[0];
       int x = edge[1];
       int y = edge[2];
       if(find_set(x,parent)!=find_set(y,parent))
       {
           union_set(x,y,parent,rank);
           ans+=weight;

       }
   }
   return ans;
}


int spanningTree(int V, vector<vector<int>> adj[]) 
{
    int a,b,c,ans=0;
    for(int i=0;i<V;i++)
    {
    for(auto itr:adj[i])
    {
        a=i;
        b=itr[0];
        c=itr[1];
        addEdge(a,b,c);
    }
    
    }
    ans=mst(V);
    return ans;
}
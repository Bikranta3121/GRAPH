#include<bits/stdc++.h>
class Solution {
public:
    /*******************DFS**********************/
    // bool dfs(int i,int dest,vector<int> adj[],vector<int> &vis)
    // {
    //     if(i==dest) return true;
    //     vis[i]=1;
    //     for(int j=0;j<adj[i].size();j++)
    //     {
    //         if(vis[j]!=0) continue;
    //         if(dfs(j,dest,adj,vis)==true) 
    //                 return true;            
    //     }
    //     vis[i]=0;
    //     return false;
    // }
    /****************BFS*****************************/
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int> adj[n];
        if(src==dest) return true;
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis(n,0);
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(auto i:adj[u])
            {
                if(i==dest) return true;
                if(vis[i]==0)
                {
                    q.push(i);
                    vis[i]=1;
                }   
            }
           
         }
        return false;
    }
};

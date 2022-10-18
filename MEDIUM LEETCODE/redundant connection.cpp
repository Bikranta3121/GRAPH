class Solution {
public:
  /***********************USING DISJOINT UNION SET*****************************/
    int findpar(int node,vector<int> &par)
    {
        if(node==par[node])
            return node;
        return par[node]=findpar(par[node],par);
    }
    bool uni(int u,int v,vector<int> &parent,vector<int> &rank)
    {
       u=findpar(u,parent);
       v=findpar(v,parent);
       if(u==v) return true; 
       if(rank[u]>rank[v])
           parent[v]=u;
       else if(rank[u]<rank[v])
           parent[u]=v;
        else
        {
            parent[u]=v;
            rank[u]++;
        }
        return false;
           
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n];
        vector<int> parent(n,-1);
        vector<int> rank(n,0);
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0]-1;
            int y=edges[i][1]-1;
            if(uni(x,y,parent,rank)){ v.push_back(x+1); v.push_back(y+1);break;}
            
        }
        return v;
        
//         queue<int> q;
//         q.push(0);
//         vector<vector<int>> v;
//         vector<int> vis(n,0);
//         vis[0]=1;
//         while(!q.empty())
//         {
//             int node=q.front();
//             q.pop();
//             for(int i:adj[node])
//             {
//                 if(vis[i]==0)
//                 {
//                     q.push(i);
//                     vis[i]=1;
//                 }
//                 else if(adj[node].size()>1 and adj[i].size()>1)
//                 {
//                    v.push_back({node,i});
//                 }
//             }
            
//         }
//         vector<int> ans;
//         int len=v.size()-1;
//         int flag=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             int u=edges[i][0]-1;
//             int w=edges[i][1]-1;
//             for(int j=0;j<=len;j++)
//             {
//                 // cout<<v[j][0]<<" "<<v[j][1]<<endl;
//               if((u==v[j][0] and w==v[j][1])||(u==v[j][1] and w==v[j][0]))
//               {
//                   ans.push_back(u+1);
//                   ans.push_back(w+1);
//                   flag=1;
//                   break;
//               }
              
                
//             }
//             if(flag==1) break;
//         }
//         return ans;
        
       
    }
};

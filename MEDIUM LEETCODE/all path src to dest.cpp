class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &graph,vector<vector<int>> &res,vector<int> ans)
    {
        if(i==graph.size()-1)
        {
          res.push_back(ans);  
        }
        vis[i]=1;
        for(int j=0;j<graph[i].size();j++)
        {
            int u=graph[i][j];
            if(!vis[u])
            {
                ans.push_back(u);
                dfs(u,vis,graph,res,ans);
                ans.pop_back();
            }
        }
        vis[i]=0;
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<int> vis(n,0);
        ans.push_back(0);
        vector<vector<int>> res;
        dfs(0,vis,graph,res,ans);
        return res;
    }
};

class Solution {
public:
    /*******************BFS*****************************/
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0); 
        int count=0; 
        queue<int> q;
        for(int i=0;i<n;i++)
        {
          if(vis[i]==0)
          {
              count++;
              vis[i]=1;
              q.push(i);
              while(!q.empty())
              {
                  int node=q.front();
                  q.pop();
                  for(int j=0;j<isConnected[node].size();j++)
                  {
                      int u=isConnected[node][j];
                      if(vis[j]==0 and u==1)
                      {
                          q.push(j);
                          vis[j]=1;
                      }
                  }
              }
          }
        }
        return count;
    }
};

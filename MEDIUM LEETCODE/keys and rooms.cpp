class Solution {
public:
   /*****************BFS*****************/
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        vector<int> vis(rooms.size(),0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int i=0;i<rooms[node].size();i++)
            {
                int u=rooms[node][i];
                if(!vis[u])
                {
                    q.push(u);
                    vis[u]=1;
                }
            }
         }
        for(int i=0;i<rooms.size();i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
    
};

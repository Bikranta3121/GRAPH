class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       map<int,int> m;
        int res=0;
       for(int i=0;i<edges.size();i++)
       {
          int u=edges[i][0];
          int v=edges[i][1];
           if(m.find(u)==m.end())
               m[u]=1;
           else
           {
            res=u;
               break;
           }
           if(m.find(v)==m.end())
               m[v]=1;
           else
           {
               res=v;
               break;
           }
           
       }
        return res;
    }
        
};

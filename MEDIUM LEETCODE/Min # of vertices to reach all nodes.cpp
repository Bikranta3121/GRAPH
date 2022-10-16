class Solution {
public:
    /**************CONCEPT OF INDEGREE******************/
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      vector<int> vis(n,0);
      vector<int> adj[n];  
      vector<int> ans; 
        map<int,int> g;
        map<int,int> indeg;//indgree
       for(auto i:edges)
       {
         g[i[0]]=i[1];
         indeg[i[1]]+=1;           
       }
      for(auto itr=g.begin();itr!=g.end();itr++)
      {
          if(indeg.find(itr->first)==indeg.end())
            ans.push_back(itr->first);
      }
      return ans;  
    }
};


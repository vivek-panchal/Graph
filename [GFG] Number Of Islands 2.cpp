// User function Template for C++
class disjoint{
    public:
    vector<int>parent,size;
    disjoint(int v){
        parent.resize(v+1);
        size.resize(v+1,1);
        for(int i=0;i<=v;i++)   parent[i] = i;
    }
    int findParent(int u){
        if(parent[u] == u)  return u;
           return parent[u] = findParent(parent[u]);
    }
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv)    return;
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  private:
      bool isValid(int i, int j, int n, int m){
          return i>=0 && i<n && j>=0 && j<m;
      }

  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjoint ds(n*m);
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int islands = 0;
        vector<int> ans;
        for(auto i : operators)
        {
            int row = i[0], col = i[1];
            if(!vis[row][col])
            {
                vis[row][col] = 1;
                islands++;
                int x[] = {0,0,-1,1};
                int y[] = {1,-1,0,0};
                for(int j=0;j<4;j++)
                {
                    int newR = row + x[j];
                    int newC = col + y[j];
                    if(isValid(newR, newC, n, m) && vis[newR][newC])
                    {
                        int u = row*m + col;
                        int v = newR*m + newC;
                        if(ds.findParent(u) != ds.findParent(v))
                        {
                            ds.unionBySize(u,v);
                            islands--;
                        }
                    }
                }
            }
            ans.push_back(islands);
        }
        return ans;
    }

};

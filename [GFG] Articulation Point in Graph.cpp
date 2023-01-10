class Solution {
  int timer = 1;
    void dfs(int node, int parent, vector<int>adj[], vector<int>&vis, int tim[], int low[], int arti[]) {
        vis[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto i: adj[node]) {
            if(i == parent) continue;
            
            if(!vis[i]) {
                dfs(i,node,adj,vis,tim,low,arti);
                low[node] = min(low[node], low[i]);
                if(low[i] >= tim[node] and parent != -1)
                    arti[node] = 1;
                child++;
            }
            else low[node] = min(low[node], tim[i]);
        }
        if(child > 1 and parent == -1)
            arti[node] = 1;
    }
  public:
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        vector<int>vis(v);
        int tim[v], low[v], arti[v] = {0};
        for(int i=0;i<v;i++) {
            if(!vis[i]) dfs(i,-1,adj,vis,tim,low,arti);
        }
        vector<int>ans;
        for(int i=0;i<v;i++) {
            if(arti[i]) ans.push_back(i);
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};

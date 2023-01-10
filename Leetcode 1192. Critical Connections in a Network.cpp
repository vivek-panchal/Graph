class Solution {
    public:
    int timer = 1;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer; 
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;

            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,bridges);
                low[node] = min(low[node],low[it]);

                // Can this edge (node--it) be a bridge?
                if(low[it] > tin[node]) bridges.push_back({it,node});
            }
            else low[node] = min(low[node],low[it]);
        }
    }

	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];
        for(int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> vis(n, 0);
        vector<int> tin(n);
        vector<int> low(n);
        dfs(0,-1,adj,vis,tin,low,bridges);

        return bridges;
	}
};

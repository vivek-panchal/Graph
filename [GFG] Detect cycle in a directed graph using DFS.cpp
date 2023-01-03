#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool dfsCheck(int node, vector<int> adj[],int vis[],int pathVis[]){
        
        vis[node]=1;
        pathVis[node]=1;
        
        //Traverse for adjacent nodes
        for(auto it: adj[node]){
            // when the node is not visited
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,pathVis)==true){
                    return true;
                }
            }
            // if the node has been prev. visited and it has to be visisted on the same path
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
        
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis)==true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

class Solution {
public:
    bool check(int start,int n,vector<vector<int>> &graph,vector<int>&color){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it: graph[node]){
                //if adj node yet not colored
                // we will color it in opp. color
                if(color[it]==-1){
                    color[it]= !color[node];
                    q.push(it);
                }
                //is the adj guy having the same color someone did color it on some other path
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,n,graph,color)==false){
                    return false;
                }
            }
        }

        return true;
    }
};


// ****************************************DFS**************************************************

class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>> &graph,vector<int>&color){
       color[node]=col;

       for(auto it : graph[node]){
           if(color[it]==-1){
               if(dfs(it,!col,graph,color)==false){
                   return false;
                }
               
            }
           else if(color[it]==col){
                   return false;
                }
       }
       return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }

        return true;
    }
};

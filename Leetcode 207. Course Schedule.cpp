class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(V,0);
        vector<int>adj[V];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            } 
        }
        if(cnt==V)return true;
        return false;
    }    
};

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod =(int)(1e9+7);
        vector<pair<int,int>> adj[n];
        vector<long long int> dist(n,LONG_MAX), ways(n,0);
        priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>> pq;
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        dist[0]=0;
        ways[0]=1;
        
        pq.push({0,0});
        while(!pq.empty()){
            long long int dis=pq.top().first;
            int node= pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long int edw=it.second;
                if(dis+edw<dist[adjNode]){
                    dist[adjNode]=dis+edw;
                    pq.push({dis+edw,adjNode});
                    ways[adjNode]=ways[node]%mod;
                }
                else if(dis+edw ==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};

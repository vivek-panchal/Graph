class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod=100000;
        //({num,steps})
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start]=0;
        
        while(!q.empty()){
            int node =q.front().first;
            int steps =q.front().second;
            q.pop();
            
            for(auto it : arr){
                int num=(it * node)%mod;
                if(steps+1 <dist[num]){
                    dist[num]=steps+1;
                    if(num==end){
                        return steps+1;
                    }
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};

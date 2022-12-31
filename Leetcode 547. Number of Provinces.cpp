class Solution {
private:
    void dsf(int node , vector<int> adjLs[] , vector<int> &vis){
        vis[node] = 1;
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dsf(it , adjLs , vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dsf(i ,adjLs , vis);
            }
        }
        return count;
    }
};

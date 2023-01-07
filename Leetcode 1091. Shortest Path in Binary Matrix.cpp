class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[m].size();
        if(grid[0][0]!=0)return -1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        int dr[]={-1,0,1,0,-1,-1,1,1};
        int dc[]={0,1,0,-1,-1,1,1,-1};

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1)return dis;
            for(int i=0;i<8;i++){
                int newR=r+dr[i];
                int newC=c+dc[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==0 && dis+1<dist[newR][newC]){
                    dist[newR][newC]=1+dis;
                    q.push({1+dis,{newR,newC}});
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int newColor,vector<vector<int>>& ans,int delRow[],int delCol[],int inicolor){
        ans[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+ delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && image[nRow][nCol]==inicolor && ans[nRow][nCol]!=newColor){
                dfs(image,nRow,nCol,newColor,ans,delRow,delCol,inicolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        int delRow[]={-1,0,+1,0} ;
        int delCol[]={0,+1,0,-1} ;
        dfs(image,sr,sc,color,ans,delRow,delCol,iniColor);
        return ans;
    }
};

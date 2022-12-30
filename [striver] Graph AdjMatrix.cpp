#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int m;
	cin>>n >> m;
	vector<vector<int>> adjMatrix(n+1,vector<int>(m+1,0));
	for(int i=0;i<m;i++){
		int u;
		int v;
		cin>>u >> v;
		adjMatrix[u][v]=1;
		adjMatrix[v][u]=1;
	}
	return 0;
}

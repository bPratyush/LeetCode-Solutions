class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int n = mat.size(); 
	  int m = mat[0].size(); 
      vector<vector<int>> dis(n, vector<int> (m, 0));
   vector<vector<int>> v(n, vector<int> (m+1,0));
   queue<pair<pair<int, int>, int>> q;
   for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
           if(mat[i][j]==0){
              q.push({{i,j},0});
              v[i][j]=1;
           }
       }
   }
int dr[]= {-1, 1, 0,0};
int dc[]= {0,0,1,-1};
while(!q.empty()){
int x= q.front().first.first;
int y= q.front().first.second;
int steps= q.front().second;
q.pop();
dis[x][y]= steps;
for(int i=0; i<4; i++){
   int nx= x+ dr[i];
   int ny= y+ dc[i];
  if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && !v[nx][ny]){
    v[nx][ny]=1;
    q.push({{nx,ny},steps+1});
    } 
}
  }
return dis;
}
};
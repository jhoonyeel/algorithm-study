#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 
int board[1002][1002];
int dist[1002][1002]; // 초기화 하지 않으면 0이 채워짐.
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int,int>> Q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin >> board[i][j];
        if(board[i][j] ==1)
            Q.push({i,j});
        if(board[i][j] ==0)
        dist[i][j] = -1;
    }
}
while(!Q.empty()){
    auto cur = Q.front(); Q.pop();
    for(int dir =0;dir<4;dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >=n || ny<0 || ny>=m) continue;
        if(dist[nx][ny] >= 0) continue; // 이미 방문한 곳이면 무시. // BFS 탐색 조건 추가if (dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;
        
        dist[nx][ny] = dist[cur.X][cur.Y]+1; //거리 갱신 및 큐에 추가.
        Q.push({nx,ny});
    }
}
int ans =0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(dist[i][j] ==-1){
        cout << -1;
        return 0;
    }
    ans = max(ans,dist[i][j]);
}
cout << ans;
}
}

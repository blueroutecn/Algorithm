#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;



int n;
int d[1001][1001];

void bfs(){

 // (s,c)
  tuple<int,int> init = make_tuple(1,0);
  queue<tuple<int,int>> q;
  q.push(init);
  d[1][0] = 0;
  int s,c = -1;

  while(!q.empty()){
    // (s+c,c),(s-1,c),(s,s)
    tie(s,c) = q.front();
    q.pop();

    if(s+c<1001 && d[s+c][c] == -1){
      q.push(make_tuple(s+c,c));
      d[s+c][c] = d[s][c] + 1;
    }
    if(s-1>=0 && d[s-1][c] == -1){
      q.push(make_tuple(s-1,c));
      d[s-1][c] = d[s][c] + 1;
    }
    if(d[s][s] == -1){
      q.push(make_tuple(s,s));
      d[s][s] = d[s][c] + 1;
    }
  }

}


int main(){

  for(int i = 0;i<1001;i++)
    memset(d[i],-1,sizeof(int)*1001);

  cin>>n;

  bfs();

  // for(int i = 0;i<10;i++){
  //   for(int j = 0;j<10;j++){
  //     cout<<d[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }


  int ans = -1;

  for(int i = 0;i<1001;i++){
    if(d[n][i] !=-1){
      if(ans == -1 || ans > d[n][i]){
        ans = d[n][i];
      }
    }
  }

  cout<<ans<<endl;

}

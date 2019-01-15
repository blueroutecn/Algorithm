#include <iostream>
#include <deque>
#include <string.h>
#include <typeinfo>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int,int> cord;

int map[101][101];
int d[101][101];
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void bfs(){

  deque<cord> dq;
  dq.push_front(make_pair(1,1));
  d[1][1] = 0;
  while(!dq.empty()){
    cord xy = dq.front();
    int x = get<0>(xy);
    int y = get<1>(xy);
    dq.pop_front();

    for(int i = 0;i<4;i++){
      int tmpx = x + dx[i];
      int tmpy = y + dy[i];
      if(!(tmpx<1 || tmpx > 100 || tmpy < 1 || tmpy > 100)){
        if(map[tmpy][tmpx] == 0 && d[tmpy][tmpx] == -1){
          dq.push_front(make_pair(tmpx,tmpy));
          d[tmpy][tmpx] = d[y][x];
        }
        if(map[tmpy][tmpx] == 1 && d[tmpy][tmpx] == -1){
          dq.push_back(make_pair(tmpx,tmpy));
          d[tmpy][tmpx] = d[y][x] + 1;
        }
      }
    }
  }


}

int main(){



  cin>>M>>N;
  cin.ignore();

  for(int i = 0;i<101;i++)
    memset(map[i],-1,sizeof(int)*101);
  for(int i = 0;i<101;i++)
    memset(d[i],-1,sizeof(int)*101);


  string line;
  for(int i = 1;i<=N;i++){
    getline(cin,line);
    for(int j = 1;j<=M;j++){
      map[i][j] = line[j-1] - 48;
    }
  }

  // for(int i = 1;i<=N;i++){
  //   for(int j = 1;j<=M;j++){
  //     cout<<map[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  //
  // cout<<endl;

  bfs();
  //cout<<"end"<<endl;
  // for(int i = 1;i<=N;i++){
  //   for(int j = 1;j<=M;j++){
  //     cout<<d[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<d[N][M]<<endl;

}

#include <iostream>
#include <tuple>
#include <queue>
#include <typeinfo>
#include <string.h>

using namespace std;

int map[1001][1001];
int v[1001][1001];
int dx[4] = {1,-1,0, 0};
int dy[4] = {0,0,1, -1};
int N,M;
string line;
typedef tuple<int,int,int> state;
void bfs(){
  state p = make_tuple(1,1,0);
  queue <state> q;
  q.push(p);
  v[1][1] = 1;
  while(!q.empty()){
    state s = q.front();
    q.pop();
    //cout<<typeid(s).name()<<endl;
    int x = get<0>(s);
    int y = get<1>(s);
    int z = get<2>(s);
    if(z == 0){
      for(int i = 0;i<4;i++){
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if(tmpx>0 && tmpx<=M && tmpy>0 && tmpy<=N){
          if(v[tmpy][tmpx] == -1){
            q.push(make_tuple(tmpx,tmpy,map[tmpy][tmpx]));
            v[tmpy][tmpx] = v[y][x] + 1;
          }
        }
      }
    }
    else if(z == 1){
      for(int i = 0;i<4;i++){
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if(tmpx>0 && tmpx<=M && tmpy>0 && tmpy<=N){
          if(map[tmpy][tmpx] != 1 && v[tmpy][tmpx] == -1){
            q.push(make_tuple(tmpx,tmpy,z));
            v[tmpy][tmpx] = v[y][x] + 1;
          }
        }
      }
    }
  }

}


int main(){


  cin>>N>>M;
  cin.ignore();

  for(int i = 0;i<1001;i++)
    memset(map[i],-1,sizeof(int)*1001);

  for(int i = 0;i<1001;i++)
    memset(v[i],-1,sizeof(int)*1001);

  for(int i = 1;i<=N;i++){
    getline(cin,line);
    for(int j = 1;j<=M;j++){
      map[i][j] = line[j-1] - 48;
    }
  }

  bfs();

  // for(int i = 0;i<=N;i++){
  //   for(int j = 0;j<=M;j++){
  //     cout<<map[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  //
  // for(int i = 0;i<=N;i++){
  //   for(int j = 0;j<=M;j++){
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<v[N][M]<<endl;
}

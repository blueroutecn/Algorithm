#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int map[1000][1000];
int v[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int nsize = -1;
int cnt = 0;
int h,w = -1;

int bfs(int x,int y,int val){

  tuple<int,int,int> item = make_tuple(x,y,val);
  queue<tuple<int,int,int>> q;
  q.push(item);
  v[y][x] = val;

  while(!q.empty()){
    tuple<int,int,int> tmp = q.front();
    q.pop();

    x = get<0>(tmp);
    y = get<1>(tmp);
    val = get<2>(tmp);

    for(int i = 0;i<4;i++){
      int tmpx = x + dx[i];
      int tmpy = y + dy[i];
      if(!(tmpx<0 || tmpx>w || tmpy<0 || tmpy >h)){
        if(map[tmpy][tmpx] == 1 && v[tmpy][tmpx]==0){
          q.push(make_tuple(tmpx,tmpy,val+1));
          v[tmpy][tmpx] = val+1;
          // cout<<"val: " << val+1<<" ";
          // cout<<v[tmpy][tmpx]<<" ";
        }
      }
    }


  }


}

int main(){

  string tmps;

  //pair<int,int> a = make_pair(1,2);
  //cout<<a.first<<" "<<a.second<<endl;

  for(int i = 0;i<1000;i++)
    memset(map[i],0,sizeof(int)*1000);

  for(int i = 0;i<1000;i++)
    memset(v[i],0,sizeof(int)*1000);

  cin>>h>>w;
  cin.ignore();

  for(int i = 0;i<h;i++){
    getline(cin,tmps);
    for(int j = 0;j<w;j++){
      map[i][j] = tmps[j] - 48;
    }
  }


  bfs(0,0,1);

  cout<<v[h-1][w-1]<<endl;

}

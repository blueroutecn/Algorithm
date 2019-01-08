#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int map[26][26];
int v[26][26];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int nsize = -1;
int cnt = 0;

int bfs(int x,int y,int cnt){

  int nhome = 0;

  pair<int,int> p = make_pair(x,y);
  queue<pair<int,int>> q;
  q.push(p);
  v[x][y] = cnt;

  while(!q.empty()){
    pair<int,int> p = q.front();
    q.pop();
    nhome = nhome + 1;

    for(int i = 0;i<4;i++){
      int tmpx = p.first + dx[i];
      int tmpy = p.second + dy[i];
      if(!(tmpx<0 || tmpx>nsize || tmpy<0 || tmpy >nsize)){
        if(map[tmpx][tmpy] == 1 && v[tmpx][tmpy] == 0){
          q.push(make_pair(tmpx,tmpy));
          v[tmpx][tmpy] = cnt;
        }
      }
    }
  }
  return nhome;
}

vector<int> solve(){


  vector<int> hset;
  for(int i = 0;i<nsize;i++){
    for(int j = 0;j<nsize;j++){
      if(map[i][j] == 1 && v[i][j] == 0){
        int nhome = bfs(i,j,++cnt);
        hset.push_back(nhome);
      }
    }
  }

  return hset;

}



int main(){

  string tmps;

  //pair<int,int> a = make_pair(1,2);
  //cout<<a.first<<" "<<a.second<<endl;

  for(int i = 0;i<26;i++)
    memset(map[i],0,sizeof(int)*26);

  for(int i = 0;i<26;i++)
    memset(v[i],0,sizeof(int)*26);


  cin>>nsize;


  for(int i = 0;i<nsize;i++){
    cin>>tmps;
    //cout<<tmps<<" ";
    for(int j = 0;j<nsize;j++){
      map[i][j] = tmps[j] - 48;
    }
  }

  // for(int i = 0;i<nsize;i++){
  //   for(int j = 0;j<nsize;j++){
  //     cout<<map[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  //
  vector<int> tmph = solve();
  // cout<<endl;
  // for(int i = 0;i<nsize;i++){
  //   for(int j = 0;j<nsize;j++){
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  sort(tmph.begin(),tmph.end());

  cout<<cnt<<endl;
  for(int i = 0;i<cnt;i++){
    cout<<tmph[i]<<endl;
  }



}

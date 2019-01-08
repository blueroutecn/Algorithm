#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;


int map[52][52];
int v[52][52];
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};
int w,h = -1;
int cnt = 0;

int bfs(int x,int y,int cnt){

  int nhome = 0;

  pair<int,int> p = make_pair(x,y);
  queue<pair<int,int>> q;
  q.push(p);
  v[y][x] = cnt;

  while(!q.empty()){
    pair<int,int> p = q.front();
    q.pop();
    nhome = nhome + 1;

    for(int i = 0;i<8;i++){
      int tmpx = p.first + dx[i];
      int tmpy = p.second + dy[i];
      if(!(tmpx<0 || tmpx>w || tmpy<0 || tmpy >h)){
        if(map[tmpy][tmpx] == 1 && v[tmpy][tmpx] == 0){
          q.push(make_pair(tmpx,tmpy));
          v[tmpy][tmpx] = cnt;
        }
      }
    }
  }
  return nhome;
}

vector<int> solve(){


  vector<int> hset;
  for(int i = 0;i<h;i++){
    for(int j = 0;j<w;j++){
      if(map[i][j] == 1 && v[i][j] == 0){
        int nhome = bfs(j,i,++cnt);
        hset.push_back(nhome);
      }
    }
  }

  return hset;

}



int main(){

  int tmp = -1;
  string tmps;
  stringstream ss;
  //pair<int,int> a = make_pair(1,2);
  //cout<<a.first<<" "<<a.second<<endl;

  while(getline(cin,tmps)){




    ss.str(tmps);
    ss>>w>>h;
    if(w == 0 && h == 0)
      break;

    for(int i = 0;i<52;i++)
      memset(map[i],0,sizeof(int)*52);

    for(int i = 0;i<52;i++)
      memset(v[i],0,sizeof(int)*52);

    // cout<<"tmps: "<<tmps<<endl;
    // cout<<"w h: "<<w<<" "<<h<<endl;
    for(int i = 0;i<h;i++){
      for(int j = 0;j<w;j++){
        cin>>map[i][j];
      }
    }



    vector<int> tmph = solve();

    // cout<<"print map ans: " << endl;
    // for(int i = 0;i<h;i++){
    //   for(int j = 0;j<w;j++){
    //     cout<<map[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    // cout<<endl;
    
    //
    // cout<<"print mark: " << endl;
    //
    // for(int i = 0;i<h;i++){
    //   for(int j = 0;j<w;j++){
    //     cout<<v[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    //
    // sort(tmph.begin(),tmph.end());
    //
    // cout<<"print ans: " << endl;
    cout<<cnt<<endl;
    // for(int i = 0;i<cnt;i++){
    //   cout<<tmph[i]<<endl;
    // }

    cin.ignore();
    ss.clear();
    tmps = "";
    cnt = 0;
  }









}

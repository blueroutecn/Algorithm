#include <iostream>
#include <tuple>
#include <queue>
#include <typeinfo>
#include <string.h>

using namespace std;
typedef tuple<int,int> state;

int map[51][51];
int v1[51][51];
int v2[51][51];
int dx[4] = {1,-1,0, 0};
int dy[4] = {0,0,1, -1};
int R,C;
int ansx,ansy = -1;
int sx,sy = -1;
int wx,wy = -1;
string line;
queue <state> q1;
queue <state> q2;

void updateS(queue<state>& q1){

  int sz = q1.size();
  int x,y = -1;
  if(sz == 0)
    return;

  for(int i = 0;i<sz;i++){
    tie(x,y) = q1.front();
    q1.pop();
    for(int j = 0;j<4;j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        if(nx >=0 && nx <C && ny>=0 && ny<R){
          if((map[ny][nx] == 0 || map[ny][nx] == 3) && v1[ny][nx] == -1){
            q1.push(make_tuple(nx,ny));
            v1[ny][nx] = v1[y][x] + 1;
          }
        }
    }
  }

}

void updateW(queue<state>& q2){

  int sz = q2.size();
  int x,y = -1;
  if(sz == 0)
    return;

  for(int i = 0;i<sz;i++){
    tie(x,y) = q2.front();
    q2.pop();
    for(int j = 0;j<4;j++){
        int nx = x + dx[j];
        int ny = y + dy[j];
        if(nx >=0 && nx <C && ny>=0 && ny<R ){
          if(map[ny][nx] == 0 && v2[ny][nx] == -1){
            q2.push(make_tuple(nx,ny));
            v2[ny][nx] = v2[y][x] + 1;
            map[ny][nx] = 1;
          }
        }
    }
  }
}

void bfs(){


  state p1 = make_tuple(sx,sy);
  q1.push(p1);
  v1[sy][sx] = 0;




  while(!q1.empty()){

    updateW(q2);
    updateS(q1);
  }
}



int main(){



  for(int i = 0;i<51;i++)
    memset(map[i],-1,sizeof(int)*51);

  for(int i = 0;i<51;i++)
    memset(v1[i],-1,sizeof(int)*51);

  for(int i = 0;i<51;i++)
    memset(v2[i],-1,sizeof(int)*51);

  cin>>R>>C;
  cin.ignore();

  for(int i = 0;i<R;i++){
    getline(cin,line);
    for(int j = 0;j<C;j++){
      //cout<<line[j]<<" ";
      if(line[j] == 'D'){
        map[i][j] = 3;
        ansx = j;
        ansy = i;
      }
      else if(line[j] == 'X'){
        map[i][j] = 2;
      }
      else if(line[j] == '*'){
        map[i][j] = 1;
        state p2 = make_tuple(j,i);
        q2.push(p2);
        v2[j][i] = 0;
      }
      else if(line[j] == '.'){
        map[i][j] = 0;
      }
      else if(line[j] == 'S'){
        map[i][j] = 0;
        sx = j;
        sy = i;
      }
    }
    //cout<<endl;
  }

  // for(int i = 0;i<R;i++){
  //   for(int j = 0;j<C;j++){
  //     cout<<map[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;

  bfs();

  // for(int i = 0;i<R;i++){
  //   for(int j = 0;j<C;j++){
  //     cout<<v1[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;
  //
  //
  // for(int i = 0;i<R;i++){
  //   for(int j = 0;j<C;j++){
  //     cout<<v2[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<endl;

  if(v1[ansy][ansx]!=-1)
    cout<<v1[ansy][ansx]<<endl;
  else
    cout<<"KAKTUS"<<endl;
}

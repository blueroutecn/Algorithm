#include <iostream>
#include <string.h>

using namespace std;

int M;
int N;
int map[500][500];
int cache[500][500];

int solve(int x,int y){

  if(y<0 || y>=N)
    return 0;

  if(x>=M || x<0)
    return 0;


  int& ret = cache[x][y];
  if(ret!=-1){
    // cout<<"hre2"<<x<<" "<<y<<endl;
    return ret;
  }

  if(x == M-1 && y == N-1){
    ret = 1;
    // cout<<"hrer"<<endl;
    return ret;
  }

  ret = 0;
  if(map[x][y] > map[x+1][y])
    ret = ret + solve(x+1,y);

  if(map[x][y] > map[x][y+1])
    ret = ret + solve(x,y+1);

  if(y-1>=0){
    if(map[x][y] > map[x][y-1])
      ret = ret + solve(x,y-1);
  }

  if(x-1>=0){
    if(map[x][y] > map[x-1][y])
      ret = ret + solve(x-1,y);
  }

  return ret;

}

int main(){



  for(int i = 0;i<500;i++)
    memset(map[i],-1,sizeof(int)*500);

  for(int i = 0;i<500;i++)
    memset(cache[i],-1,sizeof(int)*500);


  cin>>M>>N;


  for(int i = 0;i<M;i++){
    for(int j = 0;j<N;j++){
      cin>>map[i][j];
    }
  }



  cout<<solve(0,0);

  // for(int i = 0;i<M;i++){
  //   for(int j = 0;j<N;j++){
  //     cout<<map[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }


}

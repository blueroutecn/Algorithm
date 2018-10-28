#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int ncase;
int trsize;
int trmap[100][100] = {-1};
int maxmap[100][100] = {-1};
int cntmap[100][100] = {-1};

int solve(int x,int y){

  int& ret = maxmap[x][y];

  if(ret != -1)
    return ret;

  if(x == (trsize - 1)){
    ret = trmap[x][y];
    return ret;
  }


  int m1 = trmap[x][y] + solve(x+1,y);
  int m2 = trmap[x][y] + solve(x+1,y+1);
  ret = max(m1,m2);
  return ret;

}

int cnt(int x, int y){


  int& ret = cntmap[x][y];
  if(ret!= - 1){
    return ret;
  }

  if(x == trsize-1){
    ret = 1;
    return ret;
  }

  if(maxmap[x+1][y] > maxmap[x+1][y+1]){
    ret = cnt(x+1,y);

  }
  else if(maxmap[x+1][y] < maxmap[x+1][y+1]){
    ret = cnt(x+1,y+1);
  }
  else{
    ret =  cnt(x+1,y) + cnt(x+1,y+1);
  }

  return ret;


}


int main(){

  cin>>ncase;
  for(int i = 0;i<ncase;i++){

    trsize = 0;


    cin>>trsize;

    for(int j = 0;j<trsize;j++)
      memset(trmap[j],-1,sizeof(int)*trsize);
    for(int j = 0;j<trsize;j++)
      memset(maxmap[j],-1,sizeof(int)*trsize);
    for(int j = 0;j<trsize;j++)
      memset(cntmap[j],-1,sizeof(int)*trsize);

    for(int j = 0;j<trsize;j ++){
      for(int k = 0;k<j+1;k++){
        cin>>trmap[j][k];
      }
    }



    solve(0,0);
    int ans = cnt(0,0);
    cout<<ans<<endl;

  }


return 0;
}

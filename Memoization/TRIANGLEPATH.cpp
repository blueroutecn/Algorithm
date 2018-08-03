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
int minvalue = -1;
int solve(int x,int y){

  /*
  0. 들어온 x, y가 범위를 벗어나면 함수 종료
  0. 들어온 x, y에 대해 답이 찾아져 있으면 return
  0. 들어온 x, y 가 삼각형의 끝변이면 값을 저장, 값을 return
  1. 아래로 하나, 오른쪽으로 하나 재귀를 돌린다.
  2. return 된 값 비교해서 최소값을 x,y 의 답으로 저장
  */
  //cout<<x<<" "<<y<<endl;
  if(y >= x+1)
    return minvalue;


  if(maxmap[x][y] != -1)
    return maxmap[x][y];


  if(x == (trsize - 1))
    return trmap[x][y];

  int m1 = trmap[x][y] + solve(x+1,y);
  int m2 = trmap[x][y] + solve(x+1,y+1);
  //cout<<"m1 m2 x y: "<<m1<<" "<<m2<<" "<<x<<" "<<y<<endl;
  return maxmap[x][y] = max(m1,m2);





}
int main(){

  cin>>ncase;
  //cout<<ncase<<endl;
  for(int i = 0;i<ncase;i++){

    trsize = 0;


    cin>>trsize;

    for(int j = 0;j<trsize;j++)
      memset(trmap[j],-1,sizeof(int)*trsize);
    for(int j = 0;j<trsize;j++)
      memset(maxmap[j],-1,sizeof(int)*trsize);

    for(int j = 0;j<trsize;j ++){
      for(int k = 0;k<j+1;k++){
        cin>>trmap[j][k];
      }
    }

    //cout<<trsize<<endl;
    /*
    cout<<trsize<<endl;
    for(int j = 0;j<trsize;j ++){
      for(int k = 0;k<j+1;k++){
        cout<<trmap[j][k]<<" ";
      }
      cout<<endl;
    }*/

    int ans = solve(0,0);
    cout<<ans<<endl;

  }


return 0;
}

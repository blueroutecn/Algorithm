#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;
int N;
int x[500000];
int y[500000];

struct SL{
  int sareaL;
  int sareaR;
  int Larea;
};

typedef struct SL SL;

SL solve(int p0,int p2){
  /*
  0. x 개수가 총 문제 개수
  1. 재귀로 2등분 문제로 쪼갠다
  1. 1개일때 재귀 빠져나온다.
  2. 각각 최대 넓이 구하면서 merge 한다
  3. merge 될때 각각 최대값, 그리고 두개 합쳐서 만들수 있는 L 사각형 넓이
  4. 사각형 크기 다른거 두개 합쳐서 L 만들기
  4. 만들어졌던 L에 사각형 붙여서 L 만들기 (왼쪽 오른쪽)
  */
  SL data;
  data.Sarea = 0;
  data.Larea = 0;
  if((p0+1) == p2 && p0%2 ==0){
    int xidx = p0*2 +1;
    int width = x[xidx+1] - x[xidx];
    int height = y[xidx];
    int area = width*height;
    cout<<"even: "<<area<<endl;
    data.sarea = area;
    return data;
  }

  if((p0+1) == p2 && p0%2 == 1){
    int xidx = (p0+1)*2-1;
    int width = x[xidx+1] - x[xidx];
    int height = y[xidx];
    int area = width*height;
    cout<<"odd: "<<area<<endl;
    data.Sarea = area;
    return data;
  }

  int p1 = (p0+p2)/2;
  SL tmp1 = solve(p0,p1);
  SL tmp2 = solve(p1,p2);

  if(p0%2 ==0){


  }else{


  }
  cout<<"out "<<p0<<" "<<p1<<" "<<p2<<endl;
  return data;
}

int main(){
  cin>>N;
  for(int i =0;i<N;i++){
    cin>>x[i];
    cin>>y[i];
  }

  solve(0,N/2-1);
}

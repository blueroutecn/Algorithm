#include <iostream>
#include <string.h>
using namespace std;

int cache[101];
int asycache[101];
int Modnum = 1000000007;

int tiling(int n){

  int& ret = cache[n];

  if(ret!=-1)
    return ret;

  if(n == 1 || n == 0){
    ret = 1;
    return ret;
  }

  ret = tiling(n-1)%Modnum + tiling(n-2)%Modnum;
  ret = ret%Modnum;

  // cout<<"returned ret: "<<ret<<endl;
  return ret;
}


int asytiling(int n){

  int& ret = asycache[n];

  if(ret!=-1)
    return ret;

  if(n == 1 || n == 0){
    ret = 1;
    return ret;
  }

  if(n % 2 ==0){
    int tmp1 = tiling(n)%Modnum;
    int tmp2 = tiling(n/2)%Modnum;
    int tmp3 = tiling((n/2) - 1)%Modnum;
    // cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
    ret = tmp1 - tmp2;
    // cout<<ret<<" ";
    ret = ret%Modnum;
    // cout<<ret<<" ";
    ret = ret - tmp3;
    // cout<<ret<<" ";
    ret = ret%Modnum;
    // cout<<ret<<" ";
    //ret = (tiling(n)%Modnum - tiling(n/2)%Modnum)%Modnum - tiling((n/2) - 1)%Modnum;
    // cout<<"here"<<endl;
  }
  else{
    ret = tiling(n)%Modnum - tiling((n-1)/2)%Modnum;


  }

  ret = ret%Modnum;
  if(ret<0)
    ret = ret + Modnum;
  // cout<<"asy returned ret: "<<ret<<endl;
  return ret;
}


int main(){

  int n;
  int cs;
  cin>>n;

  while(n>0){
    memset(cache,-1,sizeof(cache));
    memset(asycache,-1,sizeof(asycache));
    cin>>cs;
    //cout<<"tiling: "<<tiling(cs)<<endl;
    //cout<<"asytiling: "<<asytiling(cs)<<endl;
    cout<<asytiling(cs)<<endl;
    n--;
  }
}

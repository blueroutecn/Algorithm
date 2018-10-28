#include <iostream>
#include <string.h>
using namespace std;

int cache[101];

int tiling(int n){

  int& ret = cache[n];

  if(ret!=-1)
    return ret;

  if(n == 1 || n == 0){
    ret = 1;
    return ret;
  }

  ret = (tiling(n-1) + tiling(n-2))%1000000007;
  return ret;
}


int main(){

  int n;
  int cs;
  cin>>n;

  while(n>0){
    memset(cache,-1,sizeof(cache));
    cin>>cs;
    cout<<tiling(cs)<<endl;
    n--;
  }
}

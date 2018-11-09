#include<iostream>
#include<string.h>

using namespace std;



int nstep;

int cache[2][302];
int score[301];


int step(int start,int prevstep){

  int& ret = cache[prevstep-1][start];

  if(ret!=-1){
    return ret;
  }

  if(start>nstep){
    ret = -300*100000;
    return ret;
  }

  if(start == nstep){
    ret = score[start];
    return ret;
  }

  int ans = 0;
  if(start==0 ||start == 1){
    ret = score[start] + max(step(start+1,1),step(start+2,2));
  }
  else if(prevstep == 1){
    ret = score[start] + step(start+2,2);
  }
  else if(prevstep == 2){
    ret = score[start] + max(step(start+1,1),step(start+2,2));
  }

  return ret;

}

int main(){

  nstep = 0;
  memset(score,0,sizeof(int)*300);
  for(int i = 0;i<2;i++){
    memset(&cache[i],-1,sizeof(int)*302);
  }

  cin>>nstep;

  for(int i = 0;i<nstep;i++)
    cin>>score[i+1];

  cout<<step(0,1)<<endl;
}

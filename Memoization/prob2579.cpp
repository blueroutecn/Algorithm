#include<iostream>
#include<string.h>

using namespace std;



int nstep;

int cache[3][302];
int score[301];


int step(int start,int prevstep){

  if(start>nstep){
    return -300*100000;
  }

  if(start == nstep){
    return score[start];
  }

  int ans = 0;
  if(start==0 ){
    ans = max(step(start+1,1),step(start+2,2));
  }
  else if(start == 1){
    ans = score[start] + max(step(start+1,1),step(start+2,2));
  }
  else if(prevstep == 1){
    ans = score[start] + step(start+2,2);
  }
  else if(prevstep == 2){
    ans = score[start] + max(step(start+1,1),step(start+2,2));
  }

  return ans;

}

int main(){

  nstep = 0;
  memset(score,-1,sizeof(int)*300);
  for(int i = 0;i<4;i++){
    memset(&cache[i],-1,sizeof(int)*302);
  }

  cin>>nstep;

  for(int i = 0;i<nstep;i++)
    cin>>score[i+1];

  cout<<step(0,0)<<endl;
}

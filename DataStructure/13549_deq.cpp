#include <iostream>
#include <deque>
#include <string.h>
#include <typeinfo>
#include <algorithm>

using namespace std;

int d[100001];
int p[100001];
int N,K;

void bfs(){

  deque<int> dq;
  dq.push_front(N);
  d[N] = 0;
  p[N] = N;
  while(!dq.empty()){
    int cur = dq.front();
    dq.pop_front();
    if(cur*2<100001 && d[cur*2]==-1){
      dq.push_front(cur*2);
      d[cur*2] = d[cur];
      p[cur*2] = cur;
    }
    if(cur-1>=0 && d[cur-1] == -1){
      dq.push_back(cur-1);
      d[cur-1] = d[cur] + 1;
      p[cur-1] = cur;
    }
    if(cur+1>=0 && d[cur+1] == -1){
      dq.push_back(cur+1);
      d[cur+1] = d[cur] + 1;
      p[cur+1] = cur;
    }
  }

}

int main(){

  memset(d,-1,sizeof(int)*100001);
  N = -1;
  K = -1;


  cin>>N>>K;
  bfs();
  cout<<d[K]<<endl;

  // int s = K;
  // vector<int> v;
  // while(p[s]!=s){
  //   v.push_back(s);
  //   s = p[s];
  // }
  // v.push_back(s);
  //
  // reverse(v.begin(),v.end());
  //
  // for(int i = 0;i<v.size();i++){
  //   cout<<v[i]<<" ";
  // }
  // cout<<endl;
}

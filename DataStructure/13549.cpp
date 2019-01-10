#include <iostream>
#include <queue>
#include <string.h>
#include <typeinfo>
#include <algorithm>

using namespace std;

int d[100001];
int p[100001];
int N,K;

void bfs(){

  queue<int> q1;
  queue<int> q2;
  q1.push(N);
  d[N] = 0;
  p[N] = N;
  while(!q1.empty()){
    int cur = q1.front();
    q1.pop();
    if(cur*2<100001 && d[cur*2] == -1){
        q1.push(cur*2);
        d[cur*2] = d[cur];
        p[cur*2] = cur;
    }
    if(cur - 1 >= 0 && d[cur-1] == -1){
      q2.push(cur-1);
      d[cur-1] = d[cur] + 1;
      p[cur-1] = cur;
    }
    if(cur + 1 >= 0 && d[cur+1] == -1){
      q2.push(cur+1);
      d[cur+1] = d[cur] + 1;
      p[cur+1] = cur;
    }
    if(q1.empty()){
      q1 = q2;
      q2 = queue<int>();
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

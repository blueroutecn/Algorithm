#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a[1000];
queue<int> bfsqueue;

bool visit[1000];

void dfs(int node){

  visit[node] = true;
  cout<<node+1<<" ";
  for(int i = 0;i<a[node].size();i++){
    if(visit[a[node][i]]==false)
      dfs(a[node][i]);
  }
}

void dfs(int node){

// dfs 인접행렬로 구현하기
// dfs , bfs 시간복잡도, 공간복잡도
// 연결 노드 개수 찾기 ?? (강의 따라하기)

}


void bfs(int node){

  visit[node] = true;
  cout<<node+1<<" ";

  for(int i = 0;i<a[node].size();i++){
    if(!visit[a[node][i]]){
      visit[a[node][i]] = true;
      bfsqueue.push(a[node][i]);
    }
  }

  if(!bfsqueue.empty()){
    int next = bfsqueue.front();
    bfsqueue.pop();
    bfs(next);
  }
}

void bfs_nonrec(int node){


  visit[node] = true;
  cout<<node+1<<" ";


  do{

    for(int i = 0;i<a[node].size();i++){
      if(!visit[a[node][i]]){
        visit[a[node][i]] = true;
        bfsqueue.push(a[node][i]);
      }
    }

    node = bfsqueue.front();
    bfsqueue.pop();

  }while(!bfsqueue.empty());

}



int main(){
  int n, m, start;
  cin>>n>>m>>start;
  for(int i = 0;i<m;i++){
    int u,v;
    cin>>u>>v;
    a[u-1].push_back(v-1);
    a[v-1].push_back(u-1);
  }

  for(int i = 0;i<n;i++){
    sort(a[i].begin(),a[i].end());
  }

  memset(visit,false,sizeof(visit));

  //dfs(0);
  //bfs(0);
  bfs_nonrec(0);
    // for(int i = 0;i<n;i++){
  //   cout<<"node: "<<i+1<<endl;
  //   for(int j = 0;j<a[i].size();j++){
  //     cout<<a[i][j]+1<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<"done: "<<endl;


}

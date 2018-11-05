#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int map[50][50];
double deg[50];

double search(vector<int>& path,int n,int d,int q){

  if(path.size() == d+1){
    if(path.back() != q){
      return 0;
    }

    double ret = 1;
    for(int i = 0;i<path.size()-1;i++){
      ret *=1/deg[path[i]];
    }
    return ret;
  }


  double prob = 0;

  int now = path.back();
  for(int i = 0;i<n;i++){
    if(map[now][i] == 1){
      path.push_back(i);
      prob += search(path,n,d,q);
      path.pop_back();
    }
  }

  return prob;

}



int main(){


  int ncase;
  int n,d,p;
  int t;
  int target[50];

  cin>>ncase;

  while(ncase>0){

    n = 0;
    d = 0;
    p = 0;

    for(int i = 0;i<50;i++)
      memset(&map[i],0,sizeof(map[i]));
    memset(target,0,sizeof(target));
    memset(deg,0,sizeof(deg));

    cin>>n>>d>>p;
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cin>>map[i][j];
      }
    }



    cin>>t;
    for(int i = 0;i<t;i++){
      cin>>target[i];
    }



    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        //cout<<map[i][j]<<" ";
        deg[i] = deg[i] + map[i][j];
      }

    }


    for(int i = 0;i<t;i++){
      vector<int> path;
      path.push_back(p);
      cout<<search(path,n, d, target[i])<<" ";
    }
    cout<<endl;






    ncase--;
  }



}

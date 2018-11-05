#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


int map[50][50];
double cache[50][51];
double deg[50];

double search(vector<int>& path,int n,int d,int t){


  double& ret = cache[path.back()][path.size()-1];
  // cout<<"here1"<<endl;
  if(ret!=-1){
    // cout<<"here1 nan: "<<ret<<endl;
    return ret;
  }

  // cout<<"here2"<<endl;
  if(path.size() == d+1){
    if(path.back() == t){
      //cout<<"here1 nan: "<<nan<<endl;
      ret = 1;
      return ret;
    }
    else{
      ret = 0;
      return ret;
    }
  }

  // cout<<"here3"<<endl;
  ret = 0;
  int now = path.back();
  for(int i = 0;i<n;i++){
    if(map[now][i] == 1){
      double p = 1/deg[now];
      //cout<<p<<" "<<endl;
      path.push_back(i);
      ret += p*search(path,n,d,t);
      path.pop_back();
    }
  }

  return ret;
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
      memset(&map[i],0,sizeof(int)*50);
    fill(&cache[0][0],&cache[49][51],-1);

    memset(target,0,sizeof(target));
    memset(deg,0,sizeof(deg));



    cin>>n>>d>>p;

    // for(int i = 0;i<n;i++){
    //   for(int j = 0;j<n;j++){
    //     cout<<cache[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    //
    // for(int i = 0;i<n;i++){
    //   for(int j = 0;j<n;j++){
    //     cout<<map[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }

    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cin>>map[i][j];
      }
    }



    cin>>t;
    //cout<<"target: ";
    for(int i = 0;i<t;i++){
      cin>>target[i];
      //cout<<target[i]<<" ";
    }
    //cout<<endl;


    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        //cout<<map[i][j]<<" ";
        deg[i] = deg[i] + map[i][j];
      }

    }


    for(int i = 0;i<t;i++){
      vector<int> path;
      path.push_back(p);
      cout.setf(ios::fixed);
      cout.precision(8);
      cout<<search(path,n, d, target[i]);
      if(i!=t-1)
        cout<<" ";
      fill(&cache[0][0],&cache[49][51],-1);
    }
    cout<<endl;






    ncase--;
  }



}

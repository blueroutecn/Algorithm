#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


int ncase;
int n;
int w;
int carr[100];
int warr[100];
int bestcache[100][100];
string fname[100];


int search(int head,int start,int wadd){

  wadd += warr[start];
  if(wadd>w){

    return 0;
  }

  int best = carr[start];
  int nextbest = -1;
  for(int i = start + 1;i<n;i++){
    cout<<"now: "<<fname[start]<<" try add: "<<fname[i]<<endl;
    int tmp = carr[start] + search(head,i,wadd);
    if(tmp>best){
      best = tmp;
      nextbest = i;
    }
  }


  bestcache[head][start] = nextbest;
  if(nextbest!= -1)
    cout<<"head: "<<head<<"fname: "<<fname[start]<<" "<<fname[nextbest]<<endl;
  else
    cout<<"head: "<<head<<"fname: "<<fname[start]<<" "<<nextbest<<endl;
  return best;

}


void reconstruct(int head,int start,vector<int>& idxset){

  if(start !=-1){
    idxset.push_back(start);
    int next = bestcache[head][start];
    reconstruct(head,next,idxset);
  }

}


int main(){

  cin>>ncase;
  while(ncase>0){
    n = 0;
    w = 0;
    memset(carr,-1,sizeof(int)*100);
    memset(warr,-1,sizeof(int)*100);
    for(int i = 0;i<100;i++)
    {
      memset(&bestcache[i],-1,sizeof(int)*100);
    }

    cin>>n>>w;
    for(int i = 0;i<n;i++){
      cin>>fname[i];
      cin>>warr[i];
      cin>>carr[i];
    }


    // cout<<n<<" "<<w<<endl;
    // for(int i = 0;i<n;i++){
    //   cout<<fname[i]<<" ";
    //   cout<<narr[i]<<" ";
    //   cout<<warr[i]<<" ";
    //   cout<<endl;
    // }


    int ans = 0;
    int start = 0;
    for(int i = 0;i<n;i++){
      int tmp = search(i,i,0);
      if(ans<tmp){
        ans = tmp;
        start = i;
      }
    }

    vector<int> idxset;
    reconstruct(start,start,idxset);

    cout<<"answer: "<<ans<<" "<<idxset.size()<<endl;
    for(int i = 0;i<idxset.size();i++){
      cout<<"idx: "<<idxset[i]<<endl;
      cout<<fname[idxset[i]]<<" "<<carr[idxset[i]]<<" "<<warr[idxset[i]]<<endl;
    }

    ncase--;
  }

}

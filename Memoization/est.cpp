#include <iostream>
#include <vector>

using namespace std;


vector<int> T;
int ncases;
int nnode;
int tmp;
vector<int> ans;

int solve(int idx){

  if(T[idx]==idx)
    return 1;

  return 1 + solve(T[idx]);
}

vector<int> solution(vector<int> &T){

  ans.clear();

  int nsize = T.size();
  for(int i = 0;i<nsize;i++){
    ans.push_back(solve(T[i]));
  }

  return ans;


}


int main(){


  cin>>ncases;
  while(ncases>0){

    cin>>nnode;
    for(int i = 0;i<nnode;i++){
      cin>>tmp;
      T.push_back(tmp);
    }


    vector<int> tmp_vec = solution(T);
    for(int i = 0;i<nnode;i++){
      cout<<tmp_vec[i]<<" ";
    }
    cout<<endl;

    ncases--;
  }


}

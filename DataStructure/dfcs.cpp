#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjlist;


int main(){

  int nitem = 4;
  vector<int> element(3,-1);
  adjlist.push_back(element);
  vector<int> element2(4,-2);
  adjlist.push_back(element2);
  for(int j = 0;j<adjlist.size();j++){
    for(int i = 0;i<adjlist[j].size();i++){
      cout<<adjlist[j][i]<<" ";
    }
    cout<<endl;
  }


}

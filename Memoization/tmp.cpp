#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



int main(){

  vector<int> v;

  for(int i = 0;i<5;i++)
    v.push_back(i);

  for(int i = 0;i<5;i++)
    cout<<v.at(i)<<" ";
  cout<<endl;

  vector<int>::iterator iter = v.begin() + 3;
  cout<<*iter<<endl;
  *iter = 2;
  cout<<*iter<<endl;

  for(int i = 0;i<5;i++)
    cout<<v.at(i)<<" ";
  cout<<endl;


}

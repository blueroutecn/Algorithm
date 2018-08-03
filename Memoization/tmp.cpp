#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> strset(5);


int main(){

  for(int i = 0;i<strset.size();i++)
    cout<<strset.at(i).length()<<endl;
  string tmp = "";
  cout<<tmp<<endl;
  cout<<tmp.length()<<endl;
  cout<<"end"<<endl;

  int arr[5];
  arr[0] = 3;
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 5;
  arr[4] = 4;
  arr[5] = 0;

  sort(arr+3,arr+5);

  for(int i = 0;i<6;i++)
    cout<<arr[i]<<endl;

  vector<string> v;
  v.push_back("ac");
  v.push_back("ad");
  v.push_back("Ab");


  sort(v.begin(),v.end());

  for(int i = 0;i<5;i++)
    cout << v[i] <<endl;

}

#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector <int> v;
  for(int i =0;i<10;i++)
    v.push_back(i);

  for(int i =0;i<v.size();i++)
      cout << v.at(i) << ' ';
  cout<<endl;

  v.clear();

  //cout<<v.size() << ' '<<v.capcity()<<endl;

  return 0;
}

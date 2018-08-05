#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;



int main(){

  vector<string> s;
  s.push_back("a");
  s.push_back("b");
  s.push_back("c");
  s.push_back("d");

  vector<string>::iterator iter;
  iter = s.begin();
  vector<string>::iterator pos;
  for(pos = iter;pos!=s.end();pos++){
    cout<<*pos<<" ";

  }
  cout<<endl;
}

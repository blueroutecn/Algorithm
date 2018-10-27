#include <iostream>
#include <string>
using namespace std;


bool matching(string& pat, string& test, int idx1, int idx2){



  bool check = false;
  size_t tmp;

  if(idx1 == pat.length() && idx2 == test.length()){
    return true;
  }
  else if(idx1 == pat.length() || idx2 == test.length()){
    return false;
  }

  if(pat[idx1] == '*'){

    idx1 += 1;
    if(idx1 >= pat.length())
      return true;


    idx2 = test.find(pat.substr(idx1,1),idx2);
    while(idx2 != string::npos){
      idx2 = idx2 + 1;
      check = check||matching(pat,test,idx1+1,idx2);
      idx2 = test.find(pat.substr(idx1,1),idx2);
    }

    return check;
  }

  if(pat[idx1] == test[idx2]){
      idx1 += 1;
      idx2 += 1;
      check = matching(pat, test, idx1, idx2);
  }
  else{
      check = false;
  }


  return check;

}

int main(){

  int n = 0;
  string pat;
  string test;
  cin>>n;
  cin.ignore(256,'\n'); // cin으로 받을 때 입력버퍼의 '\n' 개행문자를 비워야함
  getline(cin,pat);

  while(n>0){

    getline(cin,test);
    if(matching(pat, test, 0, 0))
      cout<<"DA";
    else
      cout<<"NE";
    cout<<endl;

    n = n - 1;
  }
}

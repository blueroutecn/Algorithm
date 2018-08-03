#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int ncase;
string pattern;
int nfile;
string fname;
int lenpattern;
int lenfname;
vector<string> v;
int check[101][101] = {-1};

/*
 1. 위치 두개 준다 (패턴 위치, 체크 문자열 위치)
 2. 패턴 위치 문자가 별이나 물음표가 아니면
     - 패턴 위치 문자 == 체크 위치 문자
     - return false
 3. 패턴 위치 문자가 물음표
     - 다음 재귀로 넘어가기
 4. 패턴 위치 문자가 별
     - for 문 돌리기
     - 체크 + 0, 체크 + 1, 체크 + 2,... 체크 + 마지막
     - 패턴 + 1
     - return 값  or 연산으로 리턴
*/


int& solve(int x,int y){

  if(check[x][y] != - 1){
    //cout<<"check use: "<<pattern<<" "<<fname<<" "<<x<<" "<<y<<" "<<check[x][y]<<endl;
    return check[x][y];
  }
  //cout<<"run start: "<<pattern<<" "<<fname<<" "<<x<<" "<<y<<" "<<endl;
  int& ret = check[x][y];

  if(x==lenpattern && y==lenfname){
    //cout<<"here1"<<endl;
    ret = 1;
    return ret;
  }
  else if(x==lenpattern && y<lenfname){
    //cout<<"here2"<<endl;
    ret = 0;
    return ret;
  }


  if(pattern[x] != '*' && pattern[x] != '?'){
    if(pattern[x] == fname[y]){
      //cout<<"here4"<<endl;
      ret = solve(x+1,y+1);
      return ret;
    }
    else{
      //cout<<"here5"<<endl;
      ret = 0;
      return ret;
    }
  }
  else if(pattern[x] == '?'){
    //cout<<"here6"<<endl;
    ret = solve(x+1,y+1);
    return ret;
  }
  else if(pattern[x] == '*'){

    for(int i = 0; y+i<=lenfname;i++){
      int tmp = solve(x+1,y+i);
      //cout<<"run end: "<<pattern<<" "<<fname<<" "<<x+1<<" "<<(y+i)<<" "<<tmp<<endl;
        if(tmp == 1){
          ret = 1;
          return ret;
        }
      }
  }
  //cout<<"run final: "<<pattern<<" "<<fname<<x<<" "<<y<<endl;
  ret = 0;
  return ret;


}
int main(){


  cin>>ncase;
  //cout<<ncase<<endl;
  for(int i = 0;i<ncase;i++){
    cin>>pattern;
    cin>>nfile;
    lenpattern = pattern.length();
    //cout<<pattern<<endl;
    //cout<<nfile<<endl;
    for(int k = 0;k<101;k++){
      memset(check[k],-1,sizeof(int)*101);
    }
    for(int j = 0;j<nfile;j++){
      cin>>fname;

      lenfname = fname.length();

      int& ck = solve(0,0);

      //cout<<lenfname<<" "<<lenpattern<<endl;
      //cout<<"ck: "<<ck<<endl;
      //cout<<"true?: "<<true<<endl;
      if(ck == 1)
        v.push_back(fname);

      //cout<<fname<<endl;
      ck = 0;
      for(int k = 0;k<101;k++){
        memset(check[k],-1,sizeof(int)*101);
      }
    }
    sort(v.begin(),v.end());
    //cout<<"answer: "<<endl;
    for(int j = 0;j<v.size();j++)
      cout<<v.at(j)<<endl;
    v.clear();

    fname = "";
    pattern = "";
    nfile = 0;
    lenpattern = 0;
    lenfname = 0;


  }
  vector<string>().swap(v);
  return 0;
}

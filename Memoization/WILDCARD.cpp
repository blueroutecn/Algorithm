#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int ncase;
string pattern;
int nfile;
string fname;
int lenpattern;
int lenfname;
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
int solve(int x,int y){

  //cout<<"run start: "<<pattern<<" "<<fname<<" "<<x<<" "<<y<<" "<<endl;
  if(x==lenpattern && y==lenfname){
    //cout<<"here1"<<endl;
    return 1;
  }
  else if(x==lenpattern && y<lenfname){
    //cout<<"here2"<<endl;
    return 0;
  }


  if(pattern[x] != '*' && pattern[x] != '?'){
    if(pattern[x] == fname[y]){
      //cout<<"here4"<<endl;
      return solve(x+1,y+1);
    }
    else{
      //cout<<"here5"<<endl;
      return 0;
    }
  }
  else if(pattern[x] == '?'){
    //cout<<"here6"<<endl;
    return solve(x+1,y+1);
  }
  else if(pattern[x] == '*'){

    for(int i = 0; y+i<=lenfname;i++){
      int tmp = solve(x+1,y+i);
      //cout<<"run end: "<<pattern<<" "<<fname<<" "<<x+1<<" "<<(y+i)<<" "<<tmp<<endl;
        if(tmp == 1){
          return 1;
        }
      }
  }
  else if(x<lenpattern && y==lenfname){
    //cout<<"here3"<<endl;
    return 0;
  }


}
int main(){

  int ck = 0;
  cin>>ncase;
  cout<<ncase<<endl;
  for(int i = 0;i<ncase;i++){
    cin>>pattern;
    cin>>nfile;
    lenpattern = pattern.length();
    //cout<<pattern<<endl;
    //cout<<nfile<<endl;
    for(int j = 0;j<nfile;j++){
      cin>>fname;

      lenfname = fname.length();

      ck = solve(0,0);
      //cout<<lenfname<<" "<<lenpattern<<endl;
      //cout<<"ret: "<<ck<<endl;
      //cout<<"true?: "<<true<<endl;
      if(ck == 1)
        cout<<"Match"<<endl;
      else
        cout<<"No-Match"<<endl;
      //cout<<fname<<endl;
      ck = 0;
    }
    fname = "";
    pattern = "";
    nfile = 0;
    lenpattern = 0;
    lenfname = 0;
  }
  return 0;
}

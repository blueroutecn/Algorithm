#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;


int ncase;
int nelement;
int tmp;
vector<int> seq;
vector<int> optimal;

int findseq(int idx){

  /*
  0. idx가 seq 길이보다 크면 종료
  0. idx에 대한 max sequence length 찾아져 있으면 그 값 return 후 종료
  1. idx값 기준으로 seq[idx] 보다 큰 값 나오면 재귀 돌리기
  */
  if(idx>=seq.size())
    return 0;

  if(optimal.at(idx) != -1)
    return optimal.at(idx);

  int& ret = optimal
  for(int i = idx + 1;i<seq.size();++i){
    if(seq[i]>seq[idx]){
      ret = 1 + findseq(i)
    }
  }
}


int main(){


  cin>>ncase;
  cout<<ncase<<endl;
  for(int i = 0;i<ncase;++i){
    cin>>nelement;
    cout<<nelement<<endl;
    for(int j = 0;j<nelement;++j){
      cin>>tmp;
      seq.push_back(tmp);
    }

    for(int j = 0;j<nelement;++j){
      optimal.push_back(-1);
    }

    for(int j = 0;j<seq.size();++j){
      cout<<seq.at(j)<<" ";
    }
    cout<<endl;
    seq.clear();
    optimal.clear();


    //cout << typeid(vector<int>()).name()<<endl;

    cout<<"seq: "<<seq.size()<<" "<<seq.capacity()<<endl;
    //cout<<"empty: "<<vv.size()<<" "<<vv.capacity()<<endl;
  }

  vector<int>().swap(seq);
  vector<int>().swap(optimal);
}

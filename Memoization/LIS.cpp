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

/*
문제에는 없지만,
순열길이가 0 인경우, 순열이 존재하지 않는 경우도 고려해서 풀 수 있어야.
0인경우는 findseq 함수를 돌리기전에 체크해서 순열이 없다고 출력해야 할 듯.
*/
int findseq(int idx){

  /*
  0. idx가 seq 길이보다 크면 종료
  0. idx에 대한 max sequence length 찾아져 있으면 그 값 return 후 종료
  1. idx값 기준으로 seq[idx] 보다 큰 값 나오면 재귀 돌리기
  */
  //cout<<"function run: "<<idx<<" "<<endl;
  vector<int>::iterator ret = optimal.begin() + idx;
  if(idx==seq.size() - 1){
    //cout<<"here1"<<endl;
    *ret = 1;
    return *ret;
  }
  if(optimal.at(idx) != -1){
    //cout<<"here2"<<endl;
    return optimal.at(idx);
  }

  bool flag = false;
  for(int i = idx + 1;i<seq.size();++i){
    if(seq[i]>seq[idx]){
      //cout<<"here3"<<endl;
      tmp = 1 + findseq(i);
      if(*ret < tmp){
        //cout<<"here4"<<endl;
        *ret = tmp;
        flag = true;
      }
    }
    else{
      //cout<<"here5"<<endl;
      findseq(i);
    }
  }

  if(!flag){
    //cout<<"here6"<<endl;
    *ret = 1;
  }

  return *ret;

}


int main(){


  cin>>ncase;
  //cout<<ncase<<endl;
  for(int i = 0;i<ncase;++i){
    cin>>nelement;
    //cout<<nelement<<endl;
    for(int j = 0;j<nelement;++j){
      cin>>tmp;
      seq.push_back(tmp);
    }

    for(int j = 0;j<nelement;++j){
      optimal.push_back(-1);
    }

    findseq(0);

    int opt = *max_element(optimal.begin(),optimal.end());
    cout<<opt<<endl;

    seq.clear();
    optimal.clear();
    tmp = -1;
  }

  vector<int>().swap(seq);
  vector<int>().swap(optimal);
}

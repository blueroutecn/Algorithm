#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int nfence;
int input;
vector<int> h;

int solve(int left,int right){
  /*
  1. left, right, 각각 solve
  2. left와 right에 걸치는 답 체크
  3. 한개짜리 fence 면 return the fence
  4.
  */
  if(left == right)
    return h[left];

  int mid = ((left + right)/2);
  //cout<<"phalf: "<<phalf<<endl;
  int ret = max(solve(left,mid),solve(mid+1,right));
  int lo = mid, hi = mid+1;
  int height = min(h[lo],h[hi]);
  ret = max(ret,height*2);
  while(left<lo || hi<right){
    if(hi<right && (lo == left || h[lo-1]<h[hi+1])){
      ++hi;
      height = min(h[hi],height);
    }
    else{
      --lo;
      height = min(h[lo],height);
    }
    ret = max(ret,height*(hi-lo + 1));
  }

  return ret;


}
int main(){
  cin>>n;
  //cout<<n<<endl;
  for(int i = 0;i<n;i++){

    cin>>nfence;

    for(int j = 0;j<nfence;j++){
      cin >> input;
      h.push_back(input);
    }
    //cout<<"input data : "<<endl;
    //cout<<nfence<<endl;
    /*
    for(int j = 0;j<nfence;j++){
      cout << h[j] <<' ';
    }
    cout << endl;
    */
    int ret = solve(0,nfence-1);
    cout<<ret<<endl;
    //cout<< "answer: "<< ret<<endl;
    h.clear();
    //cout<< "h state: "<< h.size()<<endl;
  }



  return 0;
}

#include <iostream>
#include <string>
#include <math.h>       /* pow */
#include <limits>


using namespace std;


int arr[10000] = {-1};

int cache[10000] = {0};

int num_len = 0;


int cost(int idx,int len){

  int darr[len-1] = {0};

  for(int i = idx;i<idx+len-1;i++){
    darr[i] = arr[i+1] - arr[i];
  }

  bool flag = true;


  flag = true;
  for(int i = 0;i<len-1;i++){
    if(darr[i] != 0)
      flag = false;
  }
  if(flag)
    return 1;

  flag = true;
  for(int i = 0;i<len-1;i++){
    if(darr[i] != 1)
      flag = false;
  }
  if(flag)
    return 2;

  flag = true;
  for(int i = 0;i<len-1;i++){
    if(darr[i] != -1)
      flag = false;
  }
  if(flag)
    return 2;

  flag = false;
  if(len == 3){
    if(arr[idx] == arr[idx+2]){
      flag = true;
    }
  }
  else if(len == 4){
    if((arr[idx] == arr[idx+2]) && (arr[idx+1] == arr[idx+3])){
      flag = true;
    }
  }
  else if(len == 5){
    if(((arr[idx] == arr[idx+2]) && (arr[idx+2]  == arr[idx+4])) && (arr[idx+1] == arr[idx+3])){
      flag = true;
    }
  }
  if(flag)
    return 4;

  //cout<<"I am here"<<endl;
  flag = false;
  if(len == 3){
    if(darr[0] == darr[1]){
      flag = true;
    }
  }
  else if(len == 4){
    //cout<<"I am here2"<<endl;
    if((darr[0] == darr[1]) &&(darr[1]  == darr[2])){
      flag = true;
      //cout<<"I am here3"<<endl;
    }
  }
  else if(len == 5){
    if((darr[0] == darr[1]) && (darr[1] == darr[2]) && (darr[2] == darr[3])){
      flag = true;
    }
  }
  if(flag)
    return 5;

  //cout<<"I am here4"<<endl;
  return 10;


  // for(int i = idx;i<idx+len-1;i++){
  //   cout<<darr[i]<<" ";
  // }
  // cout<<endl;

}

int pi(int idx){

  //cout<<"cost: "<<cost(idx,4)<<endl;

  int& ret = cache[idx];
  if(ret!=0)
    return ret;

  if(idx+2>=num_len){
    ret = 0;
    return ret;
  }

  int c1 = std::numeric_limits<int>::max();
  int c2 = std::numeric_limits<int>::max();
  int c3 = std::numeric_limits<int>::max();

  if(idx+2<num_len)
    c1 = cost(idx,3) + pi(idx+3);
  if(idx+3<num_len)
    c2 = cost(idx,4) + pi(idx+4);
  if(idx+4<num_len)
    c3 = cost(idx,5) + pi(idx+5);
  ret = min(min(c1,c2),c3);

  return ret;


}



int main(){

  int n = -1;
  int num = -1;
  int idx2 = 0;
  int k = 1;

  cin>>n;
  while(n>0){
    cin>>num;

    k = 1;
    num_len = 0;
    idx2 = 0;

    while(num>k){
      k *=10;
      num_len++;
    }

    while(num!=0){
      arr[num_len-1-idx2] = num%10;
      num = num/10;
      idx2++;
    }

    for(int i = 0;i<num_len;i++)
      cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"ans: "<<pi(0)<<endl;


    n--;
  }
}

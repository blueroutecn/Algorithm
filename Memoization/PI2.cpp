#include <iostream>
#include <string>
#include <math.h>       /* pow */
#include <limits>
#include <string.h>

using namespace std;


int arr[10005] = {-1};

int cache[10005] = {-1};
int darr[10005] = {0};
int num_len = 0;


int cost(int idx,int len){



  for(int i = idx;i<idx+len-1;i++){
    darr[i - idx] = arr[i+1] - arr[i];
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

  flag = false;
  if(len == 3){
    if(darr[0] == darr[1]){
      flag = true;
    }
  }
  else if(len == 4){
    if((darr[0] == darr[1]) &&(darr[1]  == darr[2])){
      flag = true;
    }
  }
  else if(len == 5){
    if((darr[0] == darr[1]) && (darr[1] == darr[2]) && (darr[2] == darr[3])){
      flag = true;
    }
  }
  if(flag)
    return 5;

  return 10;


}

int pi(int idx){


  int& ret = cache[idx];

  if((idx==(num_len-2)) || (idx == (num_len - 1)) || (idx > num_len)){
    ret = 987654321;
    return ret;
  }
  else if(idx == num_len){
    ret = 0;
    return ret;
  }


  if(ret!=-1){
    return ret;
  }
  ret = 987654321;
  for(int L = 3;L<6;L++){
    if(idx+L-1<num_len){

      ret = min(ret,cost(idx,L) + pi(idx+L));
    }
  }

  return ret;

}



int main(){

  int n = -1;
  int num = -1;
  int idx2 = 0;
  int k = 1;

  cin>>n;
  while(n>0){

    memset(arr,-1,sizeof(arr));
    memset(cache,-1,sizeof(cache));
    memset(darr,0,sizeof(darr));
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



    cout<<pi(0)<<endl;



    n--;
  }
}

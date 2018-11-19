#include <iostream>
#include <string.h>

using namespace std;



int ncases;
int arr[200];
int n;
int m;
int k;
int currentk;
int nseq;
int cache[200];

void printarr(int* arr){

  for(int i = 0;i<nseq;i++){
    if(arr[i]  == 0)
      cout<<"-";
    else
      cout<<"o";
  }

  cout<<endl;
}

int factorial(int n){

  int& ret = cache[n];


  if(ret !=-1){
    return ret;
  }



  if(n == 0){
    ret = 1;
    return ret;
  }

  ret = n*factorial(n-1);
  return ret;

}

int fact(int n,int m){

  // if(n<0)
  //   n = 0;
  // if(m<0)
  //   m = 0;

  return factorial(n+m)/(factorial(n)*factorial(m));
}

void solve(int nleft, int mleft,int depth,int kmin){


  if(currentk>k)
    return;

   cout<<"nleft, mleft : "<<nleft<<" "<<mleft<<endl;
  // cout<<"nleft, mleft, kmin, factorial: "<<nleft<<" "<<mleft<<" "<<kmin<<" "<<fact(nleft-1,mleft)<<endl;

  if(nleft==0 && mleft==0){
    currentk++;
    if(currentk == k)
      printarr(arr);
  }
  else if(nleft!=0 && mleft!=0){
    if(k<=kmin + fact(nleft-1,mleft)){
      arr[depth] = 0;
      solve(nleft-1,mleft,depth+1,kmin);
    }
    else{

      int tmp = fact(nleft-1,mleft);
      kmin = kmin + tmp;
      currentk = currentk + tmp;

      arr[depth] = 1;
      solve(nleft,mleft-1,depth+1,kmin);
      kmin = kmin - tmp;
      currentk = currentk - tmp;
    }
  }
  else if(nleft != 0 && mleft == 0){
    currentk = currentk + 1;
    if(currentk == k){
      for(int i = depth;i<nseq;i++){
        arr[i] = 0;
      }
      printarr(arr);
    }

  }
  else if(nleft == 0 && mleft != 0){
    currentk = currentk + 1;

    if(currentk == k){
      for(int i = depth;i<nseq;i++){
        arr[i] = 1;
      }
      printarr(arr);
    }
  }

}

//
//
// void solve(int nleft, int mleft,int depth,int kmin){
//
//   if(currentk>k)
//     return;
//
//   if(nleft == 0 && mleft == 0){
//     currentk++;
//     if(currentk == k)
//       printarr(arr);
//   }
//   else if(nleft!=0){
//
//     int tmp = fact(nleft,mleft);
//     if(k<tmp){
//       nleft--;
//       arr[depth] = 0;
//       solve(nleft,mleft,depth+1);
//       nleft++;
//     }
//
//
//     if(mleft>0){
//       mleft--;
//       arr[depth] = 1;
//       solve(nleft,mleft,depth+1);
//       mleft++;
//     }
//   }
//   else{
//     mleft--;
//     arr[depth] = 1;
//     solve(nleft,mleft,depth+1);
//     mleft++;
//   }
//
// }


int main(){

  cin>>ncases;
  while(ncases>0){


    cin>>n;
    cin>>m;
    cin>>k;
    nseq = n + m;
    // cout<<n<<" "<<m<<" "<<k<<endl;
    memset(cache,-1,sizeof(cache));
    memset(arr,-1,sizeof(arr));
    currentk = 0;
    // cout<<"start case"<<endl;
    solve(n,m,0,0);
    // cout<<"end case"<<endl;
    ncases--;
  }



}

#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

int cache1[100];
int cache2[100];
int arr1[100];
int arr2[100];
int n;
int len1;
int len2;


int jlis(int idx1,int idx2){

    int &ret1 = cache1[idx1];
    int &ret2 = cache2[idx2];

    ret1 = 1;
    ret2 = 1;
    // arr1 시작, 수열 1에서 다음 후보를 찾고
    for(int i = idx1+1;i<len1;i++){
      if(arr1[idx1]<arr1[i]){
          ret1 = max(ret1,1+jlis(i,idx2));
      }
    }
   // arr1 시작, 수열 2에서 다음 후보를 찾고
   for(int i = idx2;i<len2;i++){
     if(arr1[idx1]<arr2[i]){
         ret1 = max(ret1,1+jlis(idx1+1,i));
     }
   }
   // arr2 시작, 수열 1에서 다음 후보를 찾고
   for(int i = idx1;i<len1;i++){
     if(arr2[idx2]<arr1[i]){
         ret2 = max(ret2,1+jlis(i,idx2+1));
     }
   }
   // arr2 시작, 수열 2에서 다음 후보를 찾고
   for(int i = idx2+1;i<len2;i++){
     if(arr2[idx2]<arr2[i]){
         ret2 = max(ret2,1+jlis(idx1,i));
     }
   }

   return max(ret1,ret2);

}


int main(){



  cin>>n;
  while(n>0){
    cin>>len1;
    cin>>len2;
    cout<<len1<<" "<<len2<<" "<<endl;
    for(int i = 0;i<len1;i++)
      cin>>arr1[i];
    for(int i = 0;i<len2;i++)
      cin>>arr2[i];

    cout<<jlis(0,0)<<endl;
    
    n--;
  }



}

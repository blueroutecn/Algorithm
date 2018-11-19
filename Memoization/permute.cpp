#include <iostream>
#include <algorithm>

using namespace std;



int ncases;
int nseq;
int arr[100];

void swap(int* arr,int i, int j){

  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;

}

void rotate_right(int* arr, int start, int end){

  int tmp = arr[end];
  for(int i = end-1;i>=start;i--){
    arr[i+1] = arr[i];
  }
  arr[start] = tmp;
}

void rotate_left(int* arr, int start, int end){

  int tmp = arr[start];
  for(int i = start+1;i<=end;i++){
    arr[i-1] = arr[i];
  }
  arr[end] = tmp;


}

void printarr(int* arr){

  for(int i = 0;i<nseq;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

}

void permute_dict(int* arr,int head,int r){

  if(r == 0){
    printarr(arr);
  }

  //sort(arr+head+1,arr+nseq);
  // cout<<"sorted subarray:"<<endl;
  // printarr(arr);
  // cout<<"end subarray:"<<endl;
  for(int i = head;i<nseq;i++){
    rotate_right(arr,head,i);
    permute_dict(arr,head+1,r-1);
    rotate_left(arr,head,i);
  }


}

void permute(int* arr,int head,int r){

  if(r == 0){
    printarr(arr);
  }

  for(int i = head;i<nseq;i++){
    swap(arr,head,i);
    permute(arr,head+1,r-1);
    swap(arr,i,head);
  }


}

int main(){


  cin>>ncases;
  while(ncases>0){
    cin>>nseq;
    for(int i = 0;i<nseq;i++){
      cin>>arr[i];
    }

    cout<<"input: "<<endl;
    cout<<nseq<<endl;
    for(int i = 0;i<nseq;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"solve: "<<endl;
    sort(arr,arr+nseq);
    permute_dict(arr,0,nseq-1);


    ncases--;
  }



}

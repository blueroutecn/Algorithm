#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <typeinfo>       // operator typeid

using namespace std;


const int INF = 987654321;
int n;
int nseq;
int ns;


int arr[1000];

int cache[1000][10];

int cost(int start,int last){

  double tmp = 0;

  for(int i = start;i<=last;i++){
    //cout<<arr[i]<<" ";
    tmp = tmp + arr[i];
  }

  tmp = round(tmp/(last - start + 1));
  int mu = int(tmp);

  // cout<<"mu: "<<mu<<endl;
  int ans = 0;
  for(int i = start;i<=last;i++){
    int tmp1 = arr[i] - mu;
    // cout<<tmp1*tmp1<<" ";
    ans = ans + tmp1*tmp1;
  }
  // cout<<"= "<<ans<<endl;
  return ans;

}

int qt(int start,int sleft){

  // cout<<"current start and sleft: "<<start<<" "<<sleft<<endl;
  // cout<<"condition check"<<endl;
  if(sleft == 0 && start != nseq){
    // cout<<"sequence left, s not left"<<endl;
    return INF;
  }
  else if(sleft == 0 && start == nseq){
    // cout<<"sequence end, s end"<<endl;
    return 0;
  }
  else if(sleft !=0 && start == nseq){
    // cout<<"sequence end, s not end"<<endl;
    return 0;
  }

  int& ret = cache[start][sleft-1];


  if(ret!=-1){
    // cout<<"already have answer: "<<ret<<endl;
    return ret;

  }

  // cout<<"recursive"<<endl;
  ret = INF;
  for(int last = start;last<nseq;last++){
    // cout<<"start last sleft: "<<start<<" "<<last<<" "<<sleft<<endl;
    int tmp1 = qt(last+1,sleft-1);
    int tmp2 = cost(start,last);
    ret = min(ret,tmp1 + tmp2);
    // cout<<"start last sleft cost qt ret "<<start<<" "<<last<<" "<<sleft<<" "<<tmp2<<" "<<tmp1<<" "<<ret<<" "<<endl;
  }
  // cout<<"here2"<<endl;

  return ret;

}


int main(){

  cin>>n;

  while(n>0){

    memset(arr,-1,sizeof(arr));
    for(int i = 0;i<1000;i++){
      memset(cache[i],-1,sizeof(int)*10);
    }

    cin>>nseq;
    cin>>ns;

    for(int i = 0;i<nseq;i++){
      cin>>arr[i];
    }

    // cout<<nseq<<endl;
    // cout<<ns<<endl;


    sort(arr,arr+nseq);

    // for(int i = 0;i<nseq;i++)
    //   cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"cost: "<<cost(0,2)<<endl;
    // cout<<"cost: "<<cost(3,5)<<endl;
    // cout<<"cost: "<<cost(6,8)<<endl;
    // cout<<"pow: "<<pow(15,2)<<endl;
    // for(int i = 0;i<nseq;i++)
    //   cout<<arr[i]<<" ";
    //
    // cout<<endl;
    // cout<<endl;
    // cout<<"----------------"<<endl;
    cout<<qt(0,ns)<<endl;
    // cout<<"----------------"<<endl;

    n--;
  }


}

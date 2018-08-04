#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include <cmath>


using namespace std;

int N;
int K;
double arr[500] = {0};


double check(){


  double stdev = 99999999;
  int i = K;
  for(int j = 0;j<N-i+1;j++){

    double avg = 0;
    double variance = 0;

    for(int s = j;s<j+i;s++){
      avg = avg + arr[s];
    }
    avg = avg/i;
    //cout<<"avg: "<<avg<<endl;

    for(int s = j;s<j+i;s++){
      variance = variance + pow(arr[s] - avg,2);
    }
    variance = variance/i;
    //cout<<"var: "<<variance<<endl;
    double tmp = sqrt(variance);
    //cout<<" "<<i<<" "<<j<<" "<<(j+i-1)<<endl;
    if(stdev>tmp){
      stdev = tmp;
      //cout<<"std update: "<<stdev<<endl;
    }
   }


  return stdev;
}
int main(){
    cin>>N;
    cin>>K;

    for(int i = 0;i<N;i++){
      cin>>arr[i];
    }

    double ans = check();
    //double err = ans - 0.94280904158;
    //double err = ans - 0.81649658092;
    cout<<ans<<endl;
    //cout<<"err: "<<err<<endl;
    //memset(arr,0,sizeof(double)*N);

}

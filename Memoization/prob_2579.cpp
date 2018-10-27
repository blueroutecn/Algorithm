#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int cache[300] = {-1};

int step(){



}
int main(){

  int n = 0;
  string pat;
  string test;
  cin>>n;
  cout<<n<<endl;
  int step[300];
  int tmp = 0;
  while(tmp<n){
    cin>>step[tmp];
    cout<<step[tmp]<<endl;
    tmp = tmp + 1;
  }

  memset(cache,-1,sizeof(cache));


}

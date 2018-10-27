#include <iostream>
#include <string>


using namespace std;

int arr[100] = {-1};

int main(){

  int n = - 1;
  cin>>n;
  cin.ignore(256,'\n');
  while(n>0){
    string seq;
    getline(cin,seq);
    cout<<"length "<<seq.length()<<endl;
    for(int i = 0;i<seq.length();i++){
      arr[i] = seq.at(i) - '0';
    }

    for(int i = 0;i<seq.length();i++)
      cout<<arr[i]<<" ";
    cout<<endl;

    n--;
  }


}

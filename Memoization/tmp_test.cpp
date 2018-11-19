#include <iostream>
#include <vector>

using namespace std;







int main(){

  int nvec;
  cin>>nvec;
  int arr[nvec] = {0};

  vector<int> T(nvec);
  for(int i = 0;i<T.size();i++)
    cout<<T[i]<<" ";
  cout<<endl;
  for(int i = 0;i<T.size();i++)
    cout<<arr[i]<<" ";
}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int n;
string pattern;
int ncase;
string fname;

int main(){

  ifstream readFile("WILDCARD.txt");
  if(readFile.is_open()){
    readFile>>n;
    cout<<n<<endl;
    for(int i = 0;i<n;i++){
      readFile>>pattern;
      cout<<pattern<<endl;
      readFile>>ncase;
      cout<<ncase<<endl;
      for(int j = 0;j<ncase;j++){
        readFile>>fname;
        cout<<fname<<endl;
      }
      fname = "";
      pattern = "";
      ncase = 0;

    }

  }




  return 0;
}

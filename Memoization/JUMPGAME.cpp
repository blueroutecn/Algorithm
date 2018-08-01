#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

#include <direct.h>


int cases;
int mapsize;
int mapinput[100][100];
int mapcheck[100][100] = {-1};

bool runmap(int x,int y){

  if(x>=mapsize || y>=mapsize){
    return 0;
  }

  if(x==mapsize-1 && y == mapsize - 1)
    return 1;

  int& ret = mapcheck[x][y];
  if(ret!=-1)
    return ret;

  int mov = mapinput[x][y];
  return ret = runmap(x+mov,y)||runmap(x,y + mov);

}


int main(){

  ifstream readFile("JUMPGAME.txt");
  cout<<(0||0)<<endl;
  if(readFile.is_open()){
    readFile>>cases;
    for(int i = 0;i<cases;i++){



      readFile >> mapsize;

      for(int j = 0;j<mapsize;j++){
        memset(mapcheck[j],-1,sizeof(int)*mapsize);
      }


      for(int j = 0;j<mapsize;j++){
        for(int k = 0;k<mapsize;k++){
          readFile>>mapinput[j][k];
        }
      }

      runmap(0,0);
      if(mapcheck[0][0] == 1)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;
    }
  }


  return 0;
}

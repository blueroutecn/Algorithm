#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;




int cases;
int mapsize;
int mapinput[100][100];
int cache[100][100] = {-1};// = {false};

bool runmap(int y,int x){

  if(y>=mapsize || x>=mapsize)
    return 0;


  if(y==mapsize-1 && x == mapsize - 1)
    return 1;

  int& ret = cache[y][x];

  if(ret!=-1)
    return ret;

  int mov = mapinput[y][x];
  return ret = runmap(y,x+mov) || runmap(y+mov,x);

}


int main(){



  cin>>cases;
  for(int i = 0;i<cases;i++){



    cin >> mapsize;

    for(int j = 0;j<mapsize;j++){
      memset(cache[j],-1,sizeof(int)*mapsize);
    }


    for(int j = 0;j<mapsize;j++){
      for(int k = 0;k<mapsize;k++){
        cin>>mapinput[j][k];
      }
    }

    runmap(0,0);
    if(cache[0][0])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    }



  return 0;
}

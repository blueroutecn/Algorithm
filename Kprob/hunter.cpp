#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;

int ncase;
int a;
int b;

int acut[6] = {1,3,6,10,15,21};
int bcut[6] = {1,3,7,15,31};

int amoney[7] = {500,300,200,50,30,10,0};
int bmoney[7] = {512,256,128,64,32,0};

int m1 = 0;
int m2 = 0;

int checka(){
  int apos = 6;
  for(int i =0;i<6;i++){
    if(a<=acut[i]){
      apos = i;
      break;
    }
  }
  return amoney[apos];
}

int checkb(){
  int bpos = 6;
  for(int i =0;i<6;i++){
    if(b<=bcut[i]){
      bpos = i;
      break;
    }
  }
  return bmoney[bpos];
}


int main(){
    cin>>ncase;
    for(int i = 0;i<ncase;i++){

      a = 0;
      b = 0;
      m1 = 0;
      m2 = 0;

      cin>>a;
      cin>>b;


      if(a!=0)
        m1 = checka();
      else
        m1 = 0;

      if(b!=0)
        m2 = checkb();
      else
        m2 = 0;
      //cout<<"m1 "<<m1<<endl;
      //cout<<"m2 "<<m2<<endl;
      int mtotal = m1 + m2;
      cout<<mtotal*10000<<endl;


    }

}

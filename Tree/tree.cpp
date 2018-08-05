#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TreeNode{
  int num;
  TreeNode* parent;
  vector<TreeNode*> children;
} TreeNode;

int ncase;
vector<int> carray;

void gettree(TreeNode* head,vector<int>::iterator iter){


  if(iter == carray.end())
    return;

  cout<<*iter<<" ";
  head->num = *iter;

  for(int i = 0;i<2;i++){
    TreeNode* ch = new TreeNode;
    head->children.push_back(ch);
    iter = iter + 1;
    gettree(ch,iter);
  }

}

int main(){
  TreeNode* t = new TreeNode();

  cin>> ncase;
  int tmp;
  for(int i = 0;i<ncase;i++){
    cin>>tmp;
    carray.push_back(tmp);
  }

  vector<int>::iterator iter = carray.begin();
  gettree(t,iter);


  return 0;
}

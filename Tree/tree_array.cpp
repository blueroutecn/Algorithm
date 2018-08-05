#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct TreeNode{
  int data;
  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;

} TreeNode;

void preorder(TreeNode* head){

  if(head == NULL)
    return;

  cout<<head->data<<" ";
  preorder(head->left);
  preorder(head->right);
}

void inorder(TreeNode* head){

  if(head == NULL)
    return;

  inorder(head->left);
  cout<<head->data<<" ";
  inorder(head->right);
}

void postorder(TreeNode* head){

  if(head == NULL)
    return;

  postorder(head->left);
  postorder(head->right);
  cout<<head->data<<" ";
}

int ncase;

int main(){
  TreeNode t[15];
  cin>>ncase;
  int tmp;

  for(int i = 0;i<ncase;i++){
    cin>>tmp;
    t[i].data = tmp;
    t[i].left = NULL;
    t[i].right = NULL;
  }



  for(int i = 1;i<ncase;i++){
    int pidx = (i-1)/2;
    if(i%2 == 1){
      t[pidx].left = &t[i];
    }
    else{
      t[pidx].right = &t[i];
    }
  }


  preorder(&t[0]);
  cout<<endl;
  inorder(&t[0]);
  cout<<endl;
  postorder(&t[0]);
  cout<<endl;


  return 0;
}

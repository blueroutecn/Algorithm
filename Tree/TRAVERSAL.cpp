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
TreeNode t[100];
int nelement;
int pre[100] = {-1};
int in[100] = {-1};
int post[100] = {-1};

int main(){

  cin>>ncase;
  cout<<ncase<<endl;
  int tmp;

  for(int i = 0;i<ncase;i++){


    cin>>nelement;
    cout<<nelement<<endl;

    for(int j = 0;j<nelement;j++){
      cin>>pre[j];
      cout<<pre[j]<<" ";
    }
    cout<<endl;

    for(int j = 0;j<nelement;j++){
      cin>>in[j];
      cout<<in[j]<<" ";
    }
    cout<<endl;

    nelement = 0;

    memset(pre,-1,sizeof(int)*nelement);
    memset(in,-1,sizeof(int)*nelement);
    memset(post,-1,sizeof(int)*nelement);

  }







  return 0;
}

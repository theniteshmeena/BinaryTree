#include<bits/stdc++.h>
using namespace std;

struct tn{
     int data;
     struct tn* left;
     struct tn* right;

     tn(int val)
     {
         data = val;
         left = NULL;
         right = NULL;
     }
 };
int search(int ino[],int start, int end,int curr){
  for(int i = start;i<=end;i++)
  {
    if(ino[i]==curr){
      return i;
    }
  }
  return -1;
}

void Printinorder(struct tn* root)
 {
   if(root==NULL)
   return;
   
   Printinorder(root->left);
   cout<<root->data<<" ";
   Printinorder(root->right);
 }
tn* buildTree(int preo[], int ino[], int start, int end){
  static int idx=0;
  if(start>end)
  return NULL;

int curr = preo[idx];
idx++;
tn* root = new tn(curr);
if(start == end){
  return root;
}
int pos = search(ino,start, end,curr);

root->left=buildTree(preo,ino,start,pos-1);
root->right= buildTree(preo, ino, pos+1, end);
return root;
}

int main()
{
  int preo[]={1,2,4,3,5};
  int ino[]={4,2,1,5,3};
  tn* root = buildTree(preo,ino,0,4);

  Printinorder(root);
  return 0;
}
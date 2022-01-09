#include <bits/stdc++.h>
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
 
 void printLevel(tn* root)
 {
   if(root==NULL)
   return ;

   queue<tn*> q;
   q.push(root);
   q.push(NULL);

   while(!q.empty())
   {
     tn* node= q.front();
     q.pop();
     if(node!=NULL){
      cout<<node->data<<" ";
     if(node->left!=NULL)
      q.push(node->left);
      if(node->right!=NULL)
      q.push(node->right);
    }
    else if(!q.empty()){
      q.push(NULL);
    }
   }
 }

int main()
{
    struct tn * root = new tn(1);
    root->left = new tn(2);
    root->right = new tn(3);
    root->left->left=new tn(4);
    root->left->right= new tn(5);
    root->right->left=new tn(6);
    root->right->right = new tn(7);
    
    printLevel(root);

    return 0;
}
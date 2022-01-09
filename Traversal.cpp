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
 void preorder(struct tn* root)
 {
   if(root==NULL)
   return;
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
 }
void inorder(struct tn* root)
 {
   if(root==NULL)
   return;
   
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
 }

 void postorder(struct tn* root)
 {
   if(root==NULL)
   return;
   
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
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
    
    cout<<"PreOrder Traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"InOrder Traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal : ";
    postorder(root);
    cout<<endl;

    return 0;
}
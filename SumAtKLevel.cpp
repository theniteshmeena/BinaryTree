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
 
  int sumofkLevel (tn *root, int k)
  {
    if(root==NULL)
    return -1;

    queue<tn*>q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum=0;
    while(!q.empty()){
    tn* node = q.front();
    q.pop();
    if(node!=NULL)
    {
      if(level==k){
        sum+=node->data;
      }
      if(node->left!=NULL)
      q.push(node->left);

      if(node->right!=NULL)
      q.push(node->right);

    }
    else if(!q.empty())
    {
      q.push(NULL);
      level++;
    }
    
  }
    return sum;
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
    int k= 2;
    cout<<sumofkLevel(root,k)<<endl;

    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
struct tree{
ll val;
struct tree *left;
struct tree *right;
};
struct tree *head=NULL;
void levelorder(struct tree *head){
queue<struct tree *>q;
q.push(head);
while(!q.empty()){
  struct tree * node=q.front();
  q.pop();
  cout<<node->val<<" ";
  if(node->left!=NULL)q.push(node->left);
  if(node->right!=NULL)q.push(node->right);
}

}
struct tree * inserttree(ll n,struct tree *root){
if(root==NULL){
  struct tree* temp=(struct tree *)malloc(sizeof(struct tree));
  temp->val=n;
  temp->left=NULL;temp->right=NULL;
  return temp;
}
if(root->val<n){
root->left=inserttree(n,root->left);
}
else if(root->val>n){
root->right=inserttree(n,root->right);
}
return root;
}
int main(){
ll n;
cin>>n;
ll a[n];
f(i,0,n){
  cin>>a[i];
}
f(i,0,n){
 head=inserttree(a[i],head);
}

//level order traversal;
levelorder(head);

}
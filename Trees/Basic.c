#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node *Create(struct node *root,int arr[],int i);

int main(){

    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    struct node* root;
    int i=0;
    //root=NULL;
    root=Create(root,arr,i);
    preorder(root);


    // create(root,arr);
}
struct node *Create(struct node *root,int arr[],int i){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    // int k=sizeof(arr)/sizeof(int);
            int x;
            x=arr[i];
        // scanf("%d",&x);
        if(x==-1){
            // ++i;
            return 0 ;
         }
        new->data=x;
        new->left=Create(root,arr,++i);
        new->right=Create(root,arr,++i);
        return new;


}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d-> ",root->data);
    preorder(root->left);
    preorder(root->right);
    
}
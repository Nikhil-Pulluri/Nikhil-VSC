#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* new(int val){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insert(struct node* root, int val){
    if(root == NULL){
        return new(val);
    }
    if(val < root -> data) root->left=insert(root->left,val);
    if(val > root -> data) root->right = insert(root->right, val);

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }

}

void preorder(struct node* root){
    if(root!= NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

friend int fun(obj){
    
}

void level_order(struct node* root){
    struct node* q[50];
    if(root == NULL){
        return ;
    }

    int front =0;
    int rear = 0;
    q[rear++]=root;

    while(front < rear){
        struct node* current = q[front++];
        printf("%d\t", current->data);
        if(current->left!=NULL) q[rear++]=current->left;
        if(current->right!=NULL) q[rear++]=current->right;
    }
}

int sum(struct node* root){
    if(root == NULL) return 0;

     return (root->data + sum(root->left) + sum(root->right));
}

int maximum(struct node* root){
    int max = root->data;
    if(root->right == NULL) return max;
    maximum(root->right);
}

int minimum(struct node* root){
    int min = root->data;
    if(root->left == NULL ) return min;
    minimum(root->left);
}

int lnumber(struct node* root){
    if(root == NULL) return 0;

    else if(root->right == NULL && root->left == NULL) return 0;

    return (1+lnumber(root->left)+lnumber(root->right));
}

int enumber(struct node* root){
    if(root == NULL) return 0;

    if(root->right == NULL && root->left == NULL) return 1;

    return (enumber(root->left)+enumber(root->right));
}

struct node* LCA(struct node* root, int x, int y){
    if(root == NULL){
        return NULL;
    }

    if(x < root->data && y < root->data){
        return LCA(root->left,x,y);
    }

    if(x > root->data && y > root->data){
        return LCA(root->right,x,y);
    }

    else return root;
}



int main(){
    int n;
    scanf("%d",&n);
    struct node* root = NULL;
    while(n--){
        int val;
        scanf("%d",&val);
        root = insert(root, val);
    }
printf("ASCENDING ORDER: ");
    inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);
    // printf("\n");
    // level_order(root);
    // printf("\n");

    // printf("%d",sum(root));

    // printf("\n%d",maximum(root));
    // printf("\n%d",minimum(root));

    //printf("\n%d",lnumber(root));
    //printf("\n%d",enumber(root));


    // struct node* common = LCA(root, 1,3);
    // printf("\n%d",common->data);


    return 0;
}


/*
My tesing in BST



#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* new(int val){
    struct node* newn = malloc(sizeof(struct node));
    newn->data = val;
    newn->right = NULL;
    newn->left = NULL;

    return newn;
}

struct node* insert(struct node* root, int val){
    if(root == NULL){
        return new(val);
    }

    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);


    return root;
}

void inorder(struct node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root ==  NULL){
        return;
    }

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

void level_order(struct node* root){
    struct node* q[50];
    int front =0;
    int rear = 0;

    if(root!= NULL){
        q[rear++] = root;
    };

    while(front < rear){
        struct node* current = q[front++];
        printf("%d\t", current->data);

        if(current->left!=NULL){
            q[rear++]=current->left;
        }

        if(current->right!=NULL){
            q[rear++]= current->right;
        }
    }
}

int sum(struct node* root){
    if(root == NULL) return 0;

    return (root->data+ sum(root->left)+sum(root->right));
}

int min(struct node* root){
    if(root->left == NULL) return root->data;

    return min(root->left);
}

int max(struct node* root){
    if(root->right == NULL) return root->data;

    return max(root->right);
}

struct node* rightmin(struct node* root){
    if(root->left == NULL) return root;

    return rightmin(root->left);
}

struct node* leftmax(struct node* root){
    if(root->right == NULL) return root;

    return leftmax(root->right);
}

int internal_nodes(struct node* root){
    if(root == NULL) return 0;

    if(root->left == NULL && root->left == NULL) return 0;

    return (1+internal_nodes(root->left)+internal_nodes(root->right));
}

int external_nodes(struct node* root){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    return (external_nodes(root->left)+external_nodes(root->right));
}

int height(struct node* root){
    if(root == NULL) return -1;

    int l = height(root->left);
    int m = height(root->right);

    if(l>m) return 1+l;

    else return m+1;
}

int depth(struct node* root){
    return height(root)-1;
}

int diameter(struct node* root){
    int l = height(root->left);
    int m = height(root->right);

    return 1+l+m;
}



struct node* delete(struct node* root, int val){
    // searching

    struct node* update = NULL;

    if(root->data == val) {

        if(root->right == NULL && root->left ==  NULL) {
            free(root);
        }

        // else if()
        update = leftmax(root->left);
        root->data = update->data;
        free(update);
    }

    if(val < root->data){
        root->left = delete(root->left, val);
    }

    if(val > root->data){
        root->right = delete(root->right, val);
    }

    return root;
}

struct node* BS(struct node* root, int val){
    if(root == NULL) return NULL;

    if(root->data == val) return root;

    if(val < root->data){
         return BS(root->left, val);
    }

    if(val > root->data) return BS(root->right, val);
}

// bool is_BST(struct node* root, int min, int max){
//     if(root->data <=min || root->data >=max) return false;

//     else return 
// }

// void rota(int arr[],int k, int n){
//     for(int i=k;i<n;i++) printf("%d\t",arr[i]);
//     for(int i=0;i<k;i++) printf("%d\t",arr[i]);
// }





// void display(struct node* root){
    
// }

int main(){
    int n;
    scanf("%d",&n);

    struct node* root = NULL;


    while(n--){
        int val;
        scanf("%d",&val);

        root = insert(root, val);
    }

    // inorder(root);
    // printf("\n");
    // preorder(root);
    // printf("\n");
    // postorder(root);

    // level_order(root);

    // printf("%d", sum(root));

    // printf("%d",max(root));
    // inorder(delete(root,7)); // failed

    // printf("%d\t%d",internal_nodes(root),external_nodes(root));

    // printf("\n%d", height(root));

    // printf("\n%d",diameter(root));
    // struct node* temp = BS(root, 7);
    // printf("\n%d", temp->data);

    // int n=3;
    // int arr[]={1,2,3,4,5};
    // rota(arr, n, 5);


    return 0;
}*/
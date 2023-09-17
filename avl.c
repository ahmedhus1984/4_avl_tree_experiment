#include<stdio.h>
#include<stdlib.h>

struct node{
  int *number;
  struct node *left, *right;
};

typedef struct node node;

node* create_node(int); //3
node* insert_node(node*, int); //4
void print_tree_preorder(node*); //5
void print_tree_inorder(node*); //5
void print_tree_postorder(node*); //5
void free_tree(node*); //6
node* read_node(node*, int); //7
node* minValueNode(node*); //8
node* maxValueNode(node*); //8
int node_height(node*); //9
int node_balance_factor(node*); //10
node* delete_node(node*, int); //11
node* update_node(node*, int, int); //12
void printLevelOrder(node*); //13
void printCurrentLevel(node*, int); //13
int node_depth(node*, int); //14
node* leftRotate(node*);//15
node* rightRotate(node*);//15
node* insert_node_avl(node*, int);//15
node* delete_node_avl(node*, int);//17

int main(void){
  printf("\n");
  //creating the main root for a bst tree
  node *root=NULL;
  
  //normal bst insertation test 1
  root=create_node(4);
  printf("\n");

  // //avl tree insertation test 2
  // root=create_node(10);
  // printf("\n");

  // //avl tree insertation test 3
  // root=create_node(40);
  // printf("\n");

  // //avl tree insertation test 4 (for avl delete test)
  // root=create_node(9);
  // printf("\n");

  //avl tree insertation test 1
  root=insert_node_avl(root, 1);
  root=insert_node_avl(root, 5);
  root=insert_node_avl(root, 7);
  root=insert_node_avl(root, 6);
  root=insert_node_avl(root, 9);
  root=insert_node_avl(root, 7);
  root=insert_node_avl(root, 2);
  root=insert_node_avl(root, 0);
  root=insert_node_avl(root, 8);
  root=insert_node_avl(root, 3);
  printf("\n");

    // // avl tree insertation test 2
    // root = insert_node_avl(root, 20);
    // root = insert_node_avl(root, 30);
    // root = insert_node_avl(root, 40);
    // root = insert_node_avl(root, 50);
    // root = insert_node_avl(root, 25);
    // printf("\n");

    // // avl tree insertation test 3
    // root=insert_node_avl(root, 30);
    // root=insert_node_avl(root, 50);
    // root=insert_node_avl(root, 20);
    // root=insert_node_avl(root, 35);
    // root=insert_node_avl(root, 45);
    // root=insert_node_avl(root, 60);
    // root=insert_node_avl(root, 41);
    // root=insert_node_avl(root, 46);
    // root=insert_node_avl(root, 70);
    // root=insert_node_avl(root, 42);
    // printf("\n");

    //avl tree insertation test 4 (for avl delete test)
    // root = insert_node_avl(root, 5);
    // root = insert_node_avl(root, 10);
    // root = insert_node_avl(root, 0);
    // root = insert_node_avl(root, 6);
    // root = insert_node_avl(root, 11);
    // root = insert_node_avl(root, -1);
    // root = insert_node_avl(root, 1);
    // root = insert_node_avl(root, 2);
    // printf("\n");

//   //search for nodes
//   printf("searching for nodes in tree:\n");
//   read_node(root, 4);
//   read_node(root, 1);
//   read_node(root, 5);
//   read_node(root, 7);
//   read_node(root, 6);
//   read_node(root, 9);
//   read_node(root, 2);
//   read_node(root, 0);
//   read_node(root, 8);
//   read_node(root, 3);
//   read_node(root, 11);
//   printf("\n");

    //print min_value of tree
    printf("min_value of tree: %d\n", *(minValueNode(root)->number));
    printf("\n");

    //print max_value of tree
    printf("max_value of tree: %d\n", *(maxValueNode(root)->number));
    printf("\n");

    //print height of tree
    if (node_height(root) == 0){
        printf("tree has only 1 node, which is the root\n");
    }
    else{
        printf("height of tree: %d\n", node_height(root));
    }
    printf("\n");

    //print balance factor of tree's root
    int balance_factor=node_balance_factor(root);
    printf("balance factor of node %d is %d\n", *(root->number), balance_factor);
    printf("\n");

    //print tree preorder for checking insert and read;
    printf("printing tree preorder for checking insert and read:\n");
    print_tree_preorder(root);
    printf("\n");

    //print tree inorder for checking insert and read;
    printf("printing tree inorder for checking insert and read:\n");
    print_tree_inorder(root);
    printf("\n");

    //print tree postorder for checking insert and read;
    printf("printing tree postorder for checking insert and read:\n");
    print_tree_postorder(root);
    printf("\n");

    printf("level order traversal of binary tree before delete is: \n");
    printLevelOrder(root);
    printf("\n");

    // print depth of nodes
    printf("depth of node with value 4 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 4));
    printf("depth of node with value 5 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 5));
    printf("depth of node with value 0 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 0));
    printf("depth of node with value 11 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 11));
    printf("depth of node with value 9 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 9));
    printf("depth of node with value 8 in the tree with root value %d is: %d\n", *(root->number), node_depth(root, 8));
    printf("\n");

  root=update_node(root, 4, 14);
  root=update_node(root, 1, 11);
  root=update_node(root, 5, 15);
  root=update_node(root, 7, 17);
  root=update_node(root, 6, 16);
  root=update_node(root, 9, 19);
  root=update_node(root, 2, 12);
  root=update_node(root, 0, 10);
  root=update_node(root, 8, 18);
  root=update_node(root, 3, 13);
  printf("\n");

  // print tree preorder for checking update;
  printf("printing tree preorder for checking update:\n");
  print_tree_preorder(root);
  printf("\n");

  // print tree inorder for checking update;
  printf("printing tree inorder for checking update:\n");
  print_tree_inorder(root);
  printf("\n");

  // print tree postorder for checking update;
  printf("printing tree postorder for checking update:\n");
  print_tree_postorder(root);
  printf("\n");

//   // //delete leaf nodes
//   root=delete_node_avl(root, 0);
//   root=delete_node_avl(root, 3);
//   root=delete_node_avl(root, 6);
//   root=delete_node_avl(root, 8);

//   // //delete 1-child nodes
//   root=delete_node_avl(root, 1);
//   root=delete_node_avl(root, 5);
//   root=delete_node_avl(root, 7);
//   root=delete_node_avl(root, 2);
//   root=delete_node_avl(root, 9);

//   //delete 2-child nodes
//   root=delete_node_avl(root, 4);

//   //delete non-existing nodes
//   root=delete_node_avl(root, 11);
//   root=delete_node_avl(root, 6);

  // //avl delete test
  // root=delete_node_avl(root, 10);
  // printf("\n");
  // printf("level order traversal of binary tree after delete is: \n");
  // printLevelOrder(root);
  // printf("\n");

//   //print tree preorder;
//   printf("printing tree preorder for checking delete:\n");
//   print_tree_preorder(root);
//   printf("\n");

//   //print tree inorder;
//   printf("printing tree inorder for checking delete:\n");
//   print_tree_inorder(root);
//   printf("\n");

//   //print tree postorder;
//   printf("printing tree postorder for checking delete:\n");
//   print_tree_postorder(root);
//   printf("\n");

  //free tree
  free_tree(root);

  return 0;
}

node* create_node(int value){
    node *temp=malloc(sizeof(node));
    if(temp!=NULL){
        temp->number=malloc(sizeof(int));
        if(temp->number!=NULL){
            *(temp->number)=value;
            temp->left=temp->right=NULL;
            printf("node %d created\n", *(temp->number));
            return temp;
        }
        free(temp);
        temp=NULL;
    }
    printf("unable to allocate temporary memory for create_node()\n");
    return temp;
}

node* insert_node_avl(node *root, int value){
  if(root==NULL){
    node *temp=create_node(value);
    if(temp==NULL){
      printf("unable to allocate temporary memory for storing new node data\n");
    }
    else{
      printf("%d inserted to tree\n", *(temp->number));
      return temp;
    }
  }
  else if(value<*(root->number)){
    root->left=insert_node_avl(root->left, value);
  }
  else if(value>*(root->number)){
    root->right=insert_node_avl(root->right, value);
  }
  else{
    printf("unable to insert node with value %d. value %d already exists in tree\n", value, value);
    return root;
  }

/*code for avl balance factor checks and subsequent rotations if necessary after node insertation begins*/
  int balance=node_balance_factor(root);
  //case of right-right imbalance requiring a left rotation on the root to correct imbalance
  if(balance==-2 && node_balance_factor(root->right)<=0){
      root = leftRotate(root);
  }
  //case of right-left imbalance requiring a right rotation on the root's right node then a left rotation on the root to correct imbalance
  if(balance==-2 && node_balance_factor(root->right)>0){
      root->right = rightRotate(root->right);
      root=leftRotate(root);
  }
  //case of left-left imbalance requiring a right rotation on the root to correct imbalance
  if(balance==2 && node_balance_factor(root->left)>=0){
      root = rightRotate(root);
  }
  //case of left-right imbalance requiring a left rotation on the root's left node then a right rotation on the root to correct imbalance
  if(balance==2 && node_balance_factor(root->left)<0){
      root->left = leftRotate(root->left);
      root=rightRotate(root);
  }
/*code for avl balance factor checks and subsequent rotations if necessary after
node insertation ends*/
  return root;
}

node* read_node(node *root, int value){
    //base 1 + work
    if (root == NULL){
        printf("node with value %d does not exist in tree\n", value);
        return NULL;
    }
    //base 2 + work
    else if(value==*(root->number)){
        printf("node with value %d exists in tree\n", *(root->number));
        return root;
    }
    //recursions
    node *temp=NULL;
    if(value<*(root->number)){
        temp=read_node(root->left, value);
    }
    else{
        temp=read_node(root->right, value);
    }
    return temp;
}

node* update_node(node *root, int old_value, int new_value){
    root=delete_node_avl(root, old_value);
    root=insert_node_avl(root, new_value);
    return root;
}

node* delete_node_avl(node *root, int value){
  if(root==NULL){
    printf("unable to delete node %d as it does not exist in tree\n", value);
    return root;
  }
  else if (value<*(root->number)){
    root->left=delete_node_avl(root->left, value);
  }
  else if (value>*(root->number)){
    root->right=delete_node_avl(root->right, value);
  }
  else{
    if(root->left==NULL){
      node *temp=root->right;
      free(root->number);
      free(root);
      printf("node %d has been deleted from the tree\n", value);
      return temp;
    }
    else if(root->right==NULL){
      node *temp=root->left;
      free(root->number);
      free(root);
      printf("node %d has been deleted from the tree\n", value);
      return temp;
    }
    else{
      node *temp=minValueNode(root->right);
      *(root->number)=*(temp->number);
      printf("node %d has replaced double-child node %d, the original node %d is ready to be deleted from the tree\n", *(temp->number), value, *(temp->number));
      root->right=delete_node_avl(root->right, *(temp->number));
    }
  }

/*code for avl balance factor checks and subsequent rotations if necessary after node deletion begins*/
  int balance = node_balance_factor(root);
  //case of right-right imbalance requiring a left rotation on the root to correct imbalance
  if(balance==-2 && node_balance_factor(root->right)<=0){
      root = leftRotate(root);
  }
  //case of right-left imbalance requiring a right rotation on the root's right node then a left rotation on the root to correct imbalance
  if(balance==-2 && node_balance_factor(root->right)>0){
      root->right = rightRotate(root->right);
      root=leftRotate(root);
  }
  //case of left-left imbalance requiring a right rotation on the root to correct imbalance
  if(balance==2 && node_balance_factor(root->left)>=0){
      root = rightRotate(root);
  }
  //case of left-right imbalance requiring a left rotation on the root's left node then a right rotation on the root to correct imbalance
  if(balance==2 && node_balance_factor(root->left)<0){
      root->left = leftRotate(root->left);
      root=rightRotate(root);
  }
/*code for avl balance factor checks and subsequent rotations if necessary after node deletion ends*/

  return root;
}

struct node* minValueNode(node* root){
    node *current = root;
    /* loop down to find the left-most leaf */
    while(current->left!=NULL){
        current=current->left;
  }
    return current;
}

struct node* maxValueNode(node* root){
    node *current = root;
    /* loop down to find the right-most leaf */
    while(current->right!=NULL){
        current=current->right;
  }
    return current;
}

int node_height(node* root){
    if (root == NULL){
        return -1;
    }
    else {
        // Find the height of left, right subtrees
        int left_height = node_height(root->left)+1;
        int right_height = node_height(root->right)+1;
        // Find max(sub tree's height) + 1 to get the height of the tree
        return (left_height>right_height) ? left_height:right_height;
    }
}

int node_depth(node* root, int value){
    int x=0;
    if (root == NULL){
        printf("node with value %d does not exist in tree\n", value);
        return -1;
    }
    if(value<*(root->number)){
        x=node_depth(root->left, value);
    }
    else if(value>*(root->number)){
        x=node_depth(root->right, value);
    }
    else{
        printf("node with value %d exists in tree\n", *(root->number));
        return x;
    }
    if(x==-1){
      return x;
    }
    return x+1;
}

int node_balance_factor(node* root){
    // Find the height of left, right subtrees
    int left=node_height(root->left);
    int right=node_height(root->right);
    int balance_factor=left-right;
    // printf("balance factor of node %d is %d\n", *(root->number), balance_factor);
    return balance_factor;
}

// A utility function to correct Right-Right cases by doing a left rotate on a given root of a tree/subtree
// See the diagram given above.
node* leftRotate(node* root){
    node *y=root->right;
    node *T2=y->left;

    // Perform rotation
    y->left=root;
    root->right=T2;

    return y;
}

// A utility function to correct Left-Left cases by doing a right rotate on a given root of a tree/subtree
node* rightRotate(node* root){
    node *y=root->left;
    node *T2=y->right;

    // Perform rotation
    y->right=root;
    root->left=T2;

    return y;
}

void print_tree_preorder(node* root){
  if (root==NULL){
      return;
  }
  printf("%d\n", *(root->number));
  print_tree_preorder(root->left);
  print_tree_preorder(root->right);
}

void print_tree_inorder(node* root){
  if (root==NULL){
      return;
  }
  print_tree_inorder(root->left);
  printf("%d\n", *(root->number));
  print_tree_inorder(root->right);
}

void print_tree_postorder(node* root){
  if (root==NULL){
      return;
  }
  print_tree_postorder(root->left);
  print_tree_postorder(root->right);
  printf("%d\n", *(root->number));
}

//levelorder traversal print
/* Function to print level order traversal a tree*/
void printLevelOrder(node *root){
  int a = node_height(root);
  for (int i = 0; i <= a; i++){
    printCurrentLevel(root, i);
    printf("\n");
  }
}

/* Print nodes at a current level */
void printCurrentLevel(node *root, int level){
  if (root == NULL){
    return;
  }
  if(level == 0){
    printf("%d ", *(root->number));
  }
  printCurrentLevel(root->left, level-1);
  printCurrentLevel(root->right, level-1);
}

void free_tree(node* root){
  if (root==NULL){
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root->number);
  free(root);
}

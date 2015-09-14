#include<stdio.h>
#include<stdlib.h>

typedef struct node {
   int data;
   struct node *left;
   struct node *right;
} node_t;

node_t* new_node(int data)
{
    node_t *node;
    node = calloc(1, sizeof(node_t));
    if (node == NULL) {
       return NULL;
    }
    node->data = data;
    return node;
}

/*
 * 1
 */
node_t* insert(node_t * root, int data)
{
     if (root == NULL) {
         root = new_node(data);
         return root;
     }
     if (root->data > data) {
         root->left = insert(root->left, data);
     } else if(root->data < data) {
         root->right = insert(root->right, data);
     } 
     return root;     
}

/*
 * 2
 */
int size(node_t * node)
{
    if (!node) {
        return 0;
    }
   return (size(node->left) + 1 + size(node->right));
}


/*
 *  3
 */
int maxdepth(node_t *node)
{
   int lmaxd, rmaxd;
   if (!node)
        return 0;
   lmaxd = maxdepth(node->left); 
   rmaxd = maxdepth(node->right); 
   
   return lmaxd > rmaxd ? lmaxd+1:rmaxd+1;
}

/*
 * 4 Min Value
 */

int minValue(struct node* node) {
 struct node* current = node;
 // loop down to find the leftmost leaf
 while (current->left != NULL) {
 current = current->left;
 }
 return(current->data);
}

/*
 * 5
 */
void inorder(node_t * root)
{
   if (!root)
        return;

   inorder(root->left); 
  
   printf("data is %d \n", root->data); 

   inorder(root->right); 
   
}

void preorder(node_t * root)
{
   if (!root) {
        return;
   }

   printf("data is %d \n", root->data); 
   preorder(root->left); 
   preorder(root->right); 
}

/*
 * 6 Post Order
 */
void postorder(node_t * root)
{
   if (!root) {
        return;
   }

   postorder(root->left); 
   postorder(root->right); 
   printf("data is %d \n", root->data); 
}

/*
 * 7. has path sum ?
 */ 
int hashpathsum(node_t *node, int sum)
{
    if (!node) {
        return (sum == 0) ? 1:0;
    }
    sum = sum - (node->data);
    return (hashpathsum(node->left, sum) ||
    hashpathsum(node->right, sum));
}

 
// Utility that prints out an array on a line.
void printArray(int ints[], int len) {
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");
}

/*
 Recursive helper function -- given a node, and an array containing
 the path from the root node up to but not including this node,
 print out all the root-leaf paths.
*/
void printPathsRecur(struct node* node, int path[], int pathLen) {

    if (node==NULL) { 
        return;
    }

    // append this node to the path array
    path[pathLen] = node->data;
    pathLen++;

    // it's a leaf, so print the path that led to here
    if (node->left==NULL && node->right==NULL) {
        printArray(path, pathLen);
    } else {
        // otherwise try both subtrees
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }
}

/*
 * 8. printPaths
 Given a binary tree, print out all of its root-to-leaf
 paths, one per line. Uses a recursive helper to do the work.
*/
void printPaths(struct node* node) {
    int path[1000];
    printPathsRecur(node, path, 0);
}




void swap(node_t *node)
{
   node_t *temp;
   temp = node->right;
   node->right = node->left;
   node->left = temp;
}

/*
 * 9. Mirror tree
 */

node_t* mirror(node_t *node)
{
    if (!node) {
       return NULL;
    }
    mirror(node->left);
    mirror(node->right);
    swap(node);
    return node;
} 


/*
 * 10. Double tree
 */
void doubleTree(struct node* node) {
    struct node* oldLeft;
    if (node==NULL) return;
    // do the subtrees
    doubleTree(node->left);
    doubleTree(node->right);
    // duplicate this node to its left
    oldLeft = node->left;
    node->left = new_node(node->data);
    node->left->left = oldLeft;
}
/*
 * Same tree
 */

int sameTree(node_t *node1, node_t *node2)
{
    if (!node1 && !node2) {
        return 1;
    } 

    if (!node1 && !node2) { 
        return (node1->data == node2->data)
              && sameTree(node1->left, node2->left) 
              && sameTree(node1->right, node2->right); 
    }
    return 0;
} 

int  main()
{
    node_t * root = NULL;
    node_t * mirror_n = NULL;
    root = insert(root, 4);     
    root = insert(root, 2);     
    root = insert(root, 6);     
    root = insert(root, 1);     
    root = insert(root, 3);     
    root = insert(root, 5);     
    root = insert(root, 7);     
    printf("In order\n");
    inorder(root);
    printf("Pre order\n");
    preorder(root);
    printf("Post order\n");
    postorder(root); 
    printf("Size of the tree is %d ", size(root));
    printf("Max Depth\n");
    printf("Max Depth is %d", maxdepth(root));
    printf("hashpathsum\n");
    printf("hashpathsum  as 15 ?  %d \n", hashpathsum(root, 15));
    printf("hashpathsum  as 16 ?  %d \n", hashpathsum(root, 16));
    printf("printPaths\n");
    printPaths(root);      
    printf("Mirror\n");
    mirror_n = mirror(root);
    printf("printPaths of Mirror\n");
    printPaths(mirror_n);      
    printf("Same Tree\n");
    printf("Same tree(root, root) ? %d \n",sameTree(root, root));      
    printf("Same tree(root, mirror_n) ? %d \n",sameTree(root, mirror_n));      
    return 1;
}

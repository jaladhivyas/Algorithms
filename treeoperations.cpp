#include<iostream>
#include<vector>
using namespace std;

template<typename T>
struct Node
{
   Node(T value =0)
   :data(value)
   {
   }

   T data;
   Node<T> *left;
   Node<T> *right;
};

template<typename T>
Node<T> *createBstTree(Node<T> *root, T data)
{
    if(root == NULL)
    {
        root = new Node<T>();
        root->left  = NULL;
        root->right = NULL;
        root->data  = data;
        return root;
    }
    if(root->data < data)
      root->right = createBstTree(root->right, data);
    else
      root->left  = createBstTree(root->left, data);
}

template<typename T>
void inorderTraversal(Node<T> *root,std::vector<T> &a)
{
    if(root != NULL)
    {
        inorderTraversal(root->left,a);
        a.push_back(root->data);
        cout<<"Data is "<<root->data<<" ";
        inorderTraversal(root->right,a);
    }
}

template<typename T>
void inorderTraversal(Node<T> *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        cout<<"value is "<<root->data<<endl;
        inorderTraversal(root->right);
    }
}

template<typename T>
void preOrderTraversal(Node<T> *root)
{
    if(root != NULL)
    {
        cout<<"Data is "<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

template<typename T>
void postOrderTraversal(Node<T> *root)
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<"Data is "<<root->data<<" ";
    }
}

template<typename T>
Node<T> *minValueNode(Node<T> *root)
{
   if(root == NULL)
       return root;
   else
       return minValueNode(root->left);
}

template<typename T>
Node<T> *deleteNode(Node<T> *root,T key)
{
    if(root == NULL)
        return root;
    else if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else if(root->data == key)
    {
           if(root->left == NULL)
           {
               Node<T> *temp = root->right;
               delete(root);
               return temp;
           }
           else if(root->right == NULL)
           {
               Node<T> *temp = root->left;
               delete(root);
               return temp;
           }
           else
           {
               Node<T> * temp = minValueNode(root->right);
               root->data = temp->data;
               root->right = deleteNode(root->right, temp->data);
           }
     }

    else
    {
        cout<<"Key is not available"<<endl;
        return root;
    }
}

template<typename T>
int findHeight(Node<T>*root)
{
  int leftcount=0;
  if(root == NULL)
      return 0;

  else
  {
    if(root->left !=NULL)
      leftcount = 1 + findHeight(root->left);
    if(root->right !=NULL)
      leftcount = std::max(leftcount, 1+ findHeight(root->right));
       //cout<<"Height is"<<totalcount<<endl;
  }
  return leftcount;
}

template<typename T>
int totalNoOfLeaves(Node<T> *root)
{
    int count =0;
    if(root !=NULL)
    {
        if(root->left ==NULL && root->right == NULL)
            return 1;
         else
        {
            count += totalNoOfLeaves(root->left);
            count += totalNoOfLeaves(root->right);
        }
    }
    else
    {
        return 0;
    }
    return count;
}

template<typename T>
void insertionSort(vector<T> &b)
{
  for(int j =1; j<b.size(); j++)
  {
      T key = b[j];
      int i = j-1;
      while(i>=0 && b[i]>=key)
      {
         b[i+1] = b[i];
         i--;
      }
      b[i+1] = key;
  }
}

template<typename T>
void RestoreBST(Node<T>*root, T &a, T &b)
{

  if(root !=NULL)
  {
      RestoreBST(root->left,a,b);
      if(root->data == b)
      {
          root->data = a;
      }
      else if(root->data == a)
      {
          root->data = b;
      }
      RestoreBST(root->right,a,b);
  }
}

template<typename T>
void reStoreBst(Node<T> *root)
{
   std::vector<T> a;
   inorderTraversal(root,a);
   vector<T> b = a;
   for(int i=0; i<a.size();i++)
   {
       b[i]= a[i];
   }
   insertionSort(a);
   for(int i=0;i<a.size();i++)
   {
     if(a[i] != b[i])
       RestoreBST(root,b[i],a[i]);
       break;
   }
   inorderTraversal(root);
}

template<typename T>
void mirror(Node<T>* root)
{
    if(root == NULL)
        return;
    else
    {
        Node<T> *temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

template<typename T>
int SizeOfTree(Node<T> *root)
{
    if(root == NULL)
        return 0;
    else
        return (SizeOfTree(root->left)+ SizeOfTree(root->right) +1);
}

template<typename T>
bool checkIdentical(Node<T> *root1, Node<T> *root2)
{
    if(root1 == NULL && root2 == NULL)
        return;
    else if(root1 !=NULL && root2 !=NULL)
    {
        return((root1->data == root2->data) &&
                (root1->left == root2->left) &&
                (root1->right == root2->right));

    }
    return 0;
}


void printArray(int ints[], int len)
{
    for(int i=0; i<len;i++)
        cout<<ints[i];
    cout<<endl;
}

template<typename T>
void printPath(Node<T> *node, int path[], int pathlen)
{
    if(node == NULL)
        return;
    path[pathlen] = node->data;
    pathlen++;

    if(node->left == NULL && node->right == NULL)
        printArray(path, pathlen);

    else
    {
        printPath(node->left, path, pathlen);
        printPath(node->right,path, pathlen);
    }
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            break;
    }
    return i;
}

template<typename T>
Node<T>* buildUtils(T in[], T post[], T inStart, T inEnd, T *pIdx)
{
  if(inStart > inEnd)
      return NULL;
  Node<T> *node = new Node<T>(post[*pIdx]);
  (*pIdx)--;
  if(inStart == inEnd)
      return node;
  int iIndex  = search(in, inStart, inEnd, node->data);
  node->right = buildUtils(in, post, iIndex + 1, inEnd, pIdx);
  node->left  = buildUtils(in, post, inStart, iIndex-1, pIdx);
  return node;
}

template<typename T>
Node<T>* buildTree(T in[], T post[], T n)
{
  int pIdx = n -1;
  return buildUtils(in, post, 0, n-1, &pIdx);
}

//int main()
//{
////    Node<int> *root;
////    root = createBstTree(root,10);
////    root = createBstTree(root,20);
////    root = createBstTree(root,30);
////    root = createBstTree(root,4);
////    root = createBstTree(root,3);
//    //int height = findHeight(root);
//   // cout<<"Height is "<<height<<endl;
//    //int leaves = totalNoOfLeaves(root);
//    //cout<<"leaves are"<<leaves<<endl;
//    //inorderTraversal(root);
//    Node<int> *root2 = new Node<int>(6);
//    root2->left = new Node<int>(10);
//    root2->right = new Node<int>(2);
//    root2->left->left = new Node<int>(1);
//    root2->left->right = new Node<int>(3);
//    root2->right->right = new Node<int>(12);
//    root2->right->left = new Node<int>(7);
//    int sizeoftree = SizeOfTree(root2);
//    int path[100];
//    printPath(root2,path,0);
//    cout<<"Tree Size is"<<sizeoftree<<endl;
//   // reStoreBst(root2);
//    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
//    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
//    int n = sizeof(in)/sizeof(in[0]);
//    Node<int> * root3= buildTree(in,post,n);
//    preOrderTraversal(root3);
//}

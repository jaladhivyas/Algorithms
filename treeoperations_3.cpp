#include<iostream>
#include<queue>
using namespace std;



template<typename T>
struct Node
{
    T data;
    Node<T> *left, *right;
};


template<typename T>
Node<T>* newNode(T data)
{
 Node<T> *temp = new Node<T>();
 temp->data = data;
 temp->left = NULL;
 temp->right = NULL;
}

template<typename T>
void createTopology(Node<T> **root)
{
  *root = newNode(10);
  (*root)->left = newNode(20);
  (*root)->right = newNode(30);
  (*root)->left->left = newNode(40);
  (*root)->left->right = newNode(50);
  (*root)->right->left = newNode(60);
  (*root)->right->right = newNode(70);

  (*root)->left->left->left = newNode(75);
  (*root)->left->left->right = newNode(80);
  (*root)->right->left->left = newNode(85);
  (*root)->right->right->right = newNode(90);
}


template<typename T>
int maxLevelSum(Node<T> *root)
{
  if(root == NULL)
      return 0;
  int result = root->data;

  queue<Node<T> *> q;
  q.push(root);

  while(!q.empty())
  {
      int count = q.size();
      int sum =0;

      while(count--)
      {
          Node<T> *temp = q.front();
          q.pop();
          sum = sum + temp->data;

          if(temp->left != NULL)
              q.push(temp->left);
          if(temp->right != NULL)
              q.push(temp->right);
      }

      result = max(sum, result);
  }

  return result;
}

template<typename T>
int maxNoOFPerlevel(Node<T> *root)
{
  if(root == NULL)
      return 0;
  int result = root->data;

  queue<Node<T> *> q;
  q.push(root);

  int maxVal  = INT8_MIN;
  int level   = 0;
  int levelNo = 0;

  while(1)
  {
      int nodeCount = q.size();
      if(nodeCount ==0)
          break;
      if(nodeCount > maxVal)
      {
          maxVal = nodeCount;
          levelNo = level;
      }

      while(nodeCount >0)
      {
          Node<T> *node = q.front();
          q.pop();
          if(node->left != NULL)
              q.push(node->left);
          if(node->right != NULL)
              q.push(node->right);
          nodeCount--;
      }
      level++;
  }

  return levelNo;
}

template<typename T>
Node<T>* extractLeafList(Node<T> *root, Node<T>** head)
{
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
    {
       if((*head) == NULL)
       {
         (*head) = root;
       }
       else
       {
         (*head)->right = root;
         root->left = *head;
         *head = root;
       }

        return NULL;
    }
    root->left  = extractLeafList(root->left, head);
    root->right = extractLeafList(root->right, head);
}

template<typename T>
Node<T>* concatenate(Node<T>* leftList, Node<T>* rightList)
{
  if(leftList == NULL)
      return rightList;
  if(rightList == NULL)
      return leftList;

  Node<T> *leftLast  = leftList->left;
  Node<T> *rightLast = rightList->left;

  leftLast->right = rightList;
  rightList->left = leftLast;

  leftList->left = rightLast;
  rightLast->right = leftList;

  return leftList;
}


template<typename T>
Node<T>* bTreeToCList(Node<T>* root)
{
   if(root == NULL)
       return NULL;

   Node<T> *left = bTreeToCList(root->left);
   Node<T> *right = bTreeToCList(root->right);

   root->left = root->right = root;

   return concatenate(concatenate(left,root), right);
}

template<typename T>
Node<T>* removeHalfNodes(Node<T>* root)
{
  if(root == NULL)
      return root;

  root->left  = removeHalfNodes(root->left);
  root->right = removeHalfNodes(root->right);

  if(root->left == NULL && root->right == NULL)
      return root;

  if(root->left == NULL)
  {
      Node<T> *newRight = root->right;
      delete root;
      return newRight;
  }

  if(root->right == NULL)
  {
     Node<T> *newLeft = root->left;
     delete root;
     return newLeft;
  }

  return root;

}


template<typename T>
void print(Node<T> *root)
{
    if(root != NULL)
    {

       print(root->left);
       cout<<root->data<<endl;
       print(root->right);
    }
}

template<typename T>
void printList(Node<T> *head)
{
    while(head != NULL)
    {
       cout<<head->data<<endl;
       head = head->left;
    }
}

int main()
{
  cout<<"Hello"<<endl;
  Node<int> *root=NULL;
  Node<int> *head = NULL;
  createTopology(&root);
  //print(root);
  //root = extractLeafList(root, &head);
  // head = bTreeToCList(root);

  //Node<int> *newRoot = removeHalfNodes(root);
  //printList(head);

  int maxlevel = maxLevelSum(root);
  cout<<"Sum is"<<maxlevel<<endl;
  print(root);

  return 0;
}






#include<iostream>
#include<queue>
using namespace std;


template<typename T>
struct Node
{
    T data;
    Node<T> *left, *right;
    int distance;
};

template<typename T>
struct List
{
    T data;
    List<T> *next;
};

template<typename T>
Node<T>* newNode(T data)
{
 Node<T> *temp = new Node<T>();
 temp->data = data;
 temp->left = NULL;
 temp->right = NULL;
 temp->distance =0;
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
void BreathFirstSearch(Node<T> *root)
{
  queue<Node<T> *> q;

  q.push(root);

  int max = INT8_MIN;
  int currLevel     =0;
  int levelMaxNodes =0;

  while(1)
  {
    int size = q.size();

    if(size == 0)
        break;
    if(size > max)
    {
        max = size;
        levelMaxNodes = currLevel;
    }
    while(size > 0)
    {
      Node<T> *t = q.front();
      q.pop();
      if(t->left != NULL)
      {
         q.push(t->left);

      }
       if(t->right != NULL)
       {
           q.push(t->right);
       }
       size--;
    }

   currLevel++;
  }

  cout<<"Max value is"<<levelMaxNodes<<endl;
}


int main()
{
  Node<int> *root = NULL;;
  createTopology(&root);
  BreathFirstSearch(root);
  return 0;
}

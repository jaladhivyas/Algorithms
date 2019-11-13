#include<iostream>
using namespace std;

template<typename T>
struct Node
{
  T data;
  Node<T> *next;
};

template<typename T>
void createList(Node<T> *list)
{
  int N;
  cout<<"Enter no of nodes"<<endl;
  cin>>N;

  for(int i=0; i<N; i++)
  {
    Node<T> *temp = new Node<T>();
    cout<<"Enter Data"<<endl;
    cin>>temp->data;
    temp->next = NULL;
    list->next = temp;
  }
}

template<typename T>
void reverseList(Node<T> *list)
{
  Node<T> *currTemp = list->next;
  Node<T> *currNext = list->next->next;
  Node<T> *prevTemp = list;
  Node<T> *prev = NULL;
  while(list != NULL)
  {

      prevTemp->next = prev;
      currTemp->next = prevTemp;

  }
}

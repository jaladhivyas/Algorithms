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
  Node<T> *curr = list;
  Node<T> *prev = NULL;
  Node<T> *s;
  while(list != NULL)
  {
      s= prev;
      prev = curr;
      curr = curr->next;
      prev->next = s;
  }
  *list = prev;
}

template<typename T>
int count(Node<T> *list)
{
  if(list->next == NULL)
      return 0;
  else
      return(1 + count(list->next));
}

template<typename T>
void print(Node<T> *list)
{
    if(list->next !=NULL)
    {
      cout<<"data"<<list->data;
      if(list->next->next == NULL)
          print(list->next->data);
      print(list->next);
    }
    return;
}

template<typename T>
void createListRecursive(Node<T> *list)
{
    cout<<"Input Number"<<endl;
    cin>>list->data;
    if(list->data == -999)
        list->next = NULL;
    else
    {
        list->next = (Node<T> *) malloc(sizeof(Node<T>));
        createListRecursive(list->next);
    }
    return;
}

//#include<iostream>
//#define SIZE 10
//using namespace std;

//namespace stackArray
//{

//template<typename T>
//struct stack
//{
//  T data[SIZE];
//  T top;
//};

//template<typename T>
//void init(stack<T> &s)
//{
// s.top = 0;
//}

//template<typename T>
//void push(stack<T> &s,T item)
//{
//  if(s.top == SIZE)
//      return;
//  s.data[s.top++] = item;
//}

//template<typename T>
//T pop(stack<T> &s)
//{
//  if(s.top == 0)
//  {
//    cout<<"Stack is empty";
//    return 0;
//  }
//  return s.data[s.top--];
//}

//}

//namespace stackList
//{

//template<typename T>
//struct Node
//{
//    T data;
//    Node<T> *next;
//};

//template<typename T>
//class stack
//{
//  Node<T> *top;
//};

//template<typename T>
//void init(stack<T> *s)
//{
//    s->top = NULL;
//}

//template<typename T>
//void push(stack<T> *s, T item)
//{
//  Node<T> *temp = new Node<T>();
//  temp->data = item;
//  temp->next = s->top;
//  s->top = temp;
//}

//template<typename T>
//Node<T> *pop(stack<T> *s)
//{
//  Node<T> *temp =s->top;
//  s->top = s->top->next;
//  temp->next =NULL;
//  delete temp;
//  return s->top;
//}

//}


//int main()
//{
//   stackArray::stack<int> s;
//   stackArray::init(s);
//   stackArray::push(s,10);
//   stackArray::push(s,20);
//   stackArray::pop(s);
//   stackArray::pop(s);
//   stackArray::pop(s);
//}

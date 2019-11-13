#include<iostream>
#define SIZE 10
using namespace std;

template<typename T>
struct stack
{
  T data[SIZE];
  T top;
};

template<typename T>
void init(stack<T> &s)
{
 s.top = 0;
}

template<typename T>
void push(stack<T> &s,T item)
{
  if(s.top == SIZE)
      return;
  s.data[s.top++] = item;
}

template<typename T>
T pop(stack<T> &s)
{
  if(s.top == 0)
  {
    cout<<"Stack is empty";
    return 0;
  }
  return s.data[s.top--];
}


int main()
{
   stack<int> s;
   init(s);
   push(s,10);
   push(s,20);
   pop(s);
   pop(s);
   pop(s);
}

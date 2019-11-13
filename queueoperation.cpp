//#include<iostream>
//using namespace std;

////Array Implimentation

//namespace arrayQueue
//{
//#define arraySize 5
//struct Queue
//{
//  int queue[arraySize];
//  int front=0;
//  int rear =0;
//};

//int empty(struct Queue &q)
//{
//   if(q.front == q.rear)
//     return 1;
//   else
//     return 0;
//}

//void insertElement(struct Queue &q, int item)
//{
//  if((q.rear +1)% arraySize == q.front)
//  {
//    cout<<"Queue is full";
//    return;
//  }
//  else
//  {
//     q.queue[q.rear++] = item;
//     if(q.rear == arraySize)
//         q.rear =0;
//  }
//}

//void deleteElement(struct Queue &q)
//{
//   if(empty(q))
//   {
//       cout<<"Queue is empty";
//       return;
//   }
//   else
//   {
//      int value = q.queue[q.front];
//      q.queue[q.front] =0;
//      q.front++;
//      if(q.front == arraySize)
//         q.front =0;
//   }
//}
//}

//namespace CQueue
//{

//template<typename T>
//struct Node
//{
//  T data;
//  Node<T> *next;
//};

//template<typename T>
//class Queue
//{
//  Node<T> *front;
//  Node<T> *rear;
//};

//template<typename T>
//void createQueue(Queue<T> *q)
//{
//  q->front = q->rear = NULL;
//}

//template<typename T>
//void enQueue(Queue<T> *q, T key)
//{
//  Node<T> *temp = new Node<T>();
//  temp->data = key;
//  temp->next =NULL;
//  if(q->front == NULL)
//      q->front = q->rear = temp;
//  q->rear->next = temp;
//  q->rear = temp;
//}

//template<typename T>
//Node<T>* deQueue(Queue<T> *q)
//{
//  if(q->front == NULL)
//      return NULL;
//  Node<T> *temp = q->front;
//  delete(temp);

//  q->front = q->front->next;
//  if(q->front == NULL)
//      q->rear = NULL;
//  return temp;
//}

//}

//int main()
//{
//   arrayQueue::Queue q;
//   arrayQueue::insertElement(q,10);
//   arrayQueue::deleteElement(q);
//   arrayQueue::deleteElement(q);
//   return 0;
//}


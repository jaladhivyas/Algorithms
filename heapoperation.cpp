//#include<iostream>
//using namespace std;
//#define n 4

//template<typename T>
//struct MinHeapNode
//{
//    T element; // Element to be stored
//    int i;     // Index of array from which element is taken
//    int j;     // Index of next element to be piked form array
//};

//template<typename T>
//void swap(MinHeapNode<T> *x, MinHeapNode<T> *y)
//{
//    MinHeapNode<T> temp = *x;
//    *x = *y;
//    *y = temp;
//}

//template<typename T>
//class MinHeap
//{
//   public:
//    MinHeap(MinHeapNode<T> a[], int size)
//        :harr(a)
//        ,heapSize(size)
//    {
//      int i= (heapSize -1)/2;
//      while(i >= 0)
//      {
//          minHeapify(i);
//          i--;
//      }
//    }
//    void minHeapify(T);
//    int left(int i){return (2*i +1);}
//    int right(int i){return (2*i +2);}
//    MinHeapNode<T> getMin(){return harr[0];}
//    void replaceMin(MinHeapNode<T> x){harr[0]= x; minHeapify(0);}
//   private:
//    MinHeapNode<T> *harr;
//    int heapSize;
//};

//template<typename T>
//void MinHeap<T>::minHeapify(T i)
//{
//  T l = left(i);
//  T r = right(i);
//  T smallest = i;
//  if(l < heapSize && harr[l].element <harr[i].element)
//  {
//      smallest =l;
//  }
//  if(r < heapSize && harr[r].element <harr[smallest].element)
//  {
//      smallest =r;
//  }
//  if(smallest != i)
//  {
//      swap(&harr[i],&harr[smallest]);
//      minHeapify(smallest);
//  }

//}

//template<typename T>
//T *mergeKArrays(T arr[][n], int k)
//{
//   T *output = new T[n*k];
//   MinHeapNode<T> *harr = new MinHeapNode<T>[k];
//   for(int i=0;i<k;i++)
//   {
//       harr[i].element = arr[i][0];
//       harr[i].i = i;
//       harr[i].j = 1;
//   }
//   MinHeap<T> hp(harr,k); // Create the heap
//   for(int count = 0; count < n*k; count++)
//   {
//       MinHeapNode<T> root= hp.getMin();
//       output[count] = root.element;

//       if(root.j < n)
//       {
//         root.element = arr[root.i][root.j];
//         root.j +=1;
//       }

//       else
//       {
//           root.element = INT16_MAX;
//       }
//       hp.replaceMin(root);
//   }
//   return output;
//}

//int main()
//{
//   int arr[][n]={{2, 6, 12, 34},
//                 {1, 9, 20, 1000},
//                 {23, 34, 90, 2000}};
//   int k = sizeof(arr)/sizeof(arr[0]);
//   int *output = mergeKArrays(arr, k);
//   return 0;
//}

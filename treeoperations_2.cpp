//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;

//template<typename T>
//struct Node
//{
//   Node(T value =0)
//   :data(value)
//   {
//     left  = NULL;
//     right = NULL;
//   }

//   T data;
//   Node<T> *left;
//   Node<T> *right;
//};

//template<typename T>
//void printTree(Node<T> * root)
//{
//    if(root == NULL)
//        return;
//    cout<<" "<<root->data<<endl;
//    printTree(root->left);
//    printTree(root->right);
//}

//template<typename T>
//Node<T>* convertExpression(string str, T &i)
//{

//  Node<T> *root = new Node<T>(str[i]);

//  if(i == str.length()-1) return root;

//  i++;

//  if(str[i]=='?')
//  {
//      i++;
//      root->left = convertExpression(str,i);
//      i++;
//      root->right = convertExpression(str,i);
//  }

//  else
//      return root;
//}

//int main()
//{

//  string expression = "a?b?c:d:e";
//  int i=0;

//  Node<int> *root = convertExpression(expression, i);
//  printTree(root);
//  return 0;
//}

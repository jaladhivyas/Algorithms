//#include<iostream>
//#include<string.h>
//#include<stack>
//using namespace std;

//struct Et
//{
// char value;
// Et *left, *right;
//};

//bool isOperator(char c)
//{
//  if(c=='+' || c =='-' || c=='*'
//     || c =='/' || c=='^')
//      return true;
//  return false;
//}

//void inorder(Et *root)
//{
//    if(root == NULL)
//        return;
//    inorder(root->left);
//    cout<<" "<<root->value<<endl;
//    inorder(root->right);
//}

//Et* newNode(int v)
//{
//  Et *temp = new Et();
//  temp->left = temp->right = NULL;
//  temp->value = v;
//  return temp;
//}

//Et *constructTree(char *postfix)
//{
//  stack<Et *> st;
//  Et *t, *t1, *t2;

//  for(int i =0; i<strlen(postfix);i++)
//  {
//     if(!isOperator(postfix[i]))
//     {
//        t = newNode(postfix[i]);
//        st.push(t);
//     }

//     else
//     {
//       t = newNode(postfix[i]);
//       t1 = st.top();
//       st.pop();
//       t2 = st.top();
//       st.pop();

//       t->right = t1;
//       t->left  = t2;
//       st.push(t);
//     }
//  }

//  t = st.top();
//  st.pop();
//  return t;
//}


//int main()
//{

//  char postfix[] = "ab+ef*g*-";
//  Et *root = constructTree(postfix);
//  inorder(root);
//  return 0;
//}



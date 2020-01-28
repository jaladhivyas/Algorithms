//#include<iostream>
//using namespace std;


//void rotateArray(int a[],int b[], int stepSize)
//{
//  if(stepSize > 4)
//      return;
//  else
//  {

//    for(int i=0;i<5;i++)
//    {
//        if(i+stepSize < 5)
//          b[i]= a[i+stepSize];
//        else
//          b[i]=a[(i+stepSize)-5];
//    }

//    for(int i=0;i<5;i++)
//    {
//      cout<<"Value is"<< b[i]<<endl;
//    }
//  }
//}


//void subMatrixSum()
//{

// int m,n;
// cout<<"enter dimension"<<endl;
// cin>>m>>n;

// int a[m][n], data;

// cout<<"Enter data"<<endl;
// int j=0; int k=0;
// for(int i=0;i<m*n;i++)
// {
//   cin>>data;
//   a[j][k]= data;
//   k++;
//   if(k==n)
//   {
//       k=0;
//       j++;
//   }
// }

// int sum  =0;
// int x1,y1,x2,y2;
// cout<<"Enter Dimension"<<endl;
// cin>>x1>>y1>>x2>>y2;

// for(int i= x1-1;i<x2;i++)
// {
//     for(int j= y1-1;j<y2;j++)
//     {
//       cout<<" "<<a[i][j]<<endl;
//       sum= sum + a[i][j];
//     }
// }

// cout<<"Sum is"<<sum<<endl;

//}

//int main()
//{
//  int a[5] = {1,2,3,4,5};
//  int b[5] = {0};
//  int stepSize = 3;

//  //rotateArray(a,b,stepSize);
//  subMatrixSum();

//  return 0;

//}





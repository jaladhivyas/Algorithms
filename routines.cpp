#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define N 4
void sumOfNumbersInString(string &s1)
{
    size_t sum =0;
    char cArray[s1.size()+1];
    strcpy(cArray, s1.c_str());
    //stringstream stream(s1);
  for(size_t i=0;i<strlen(cArray);i++)
  {
      while(isdigit(cArray[i]) && i<strlen(cArray))
      {
        sum = (sum*10) + (cArray[i]-'0');
       i++;
      }
  }
  cout<<"Sum is"<<sum;
}

template<typename T>
void printSortedMatrix(T matrix[])
{
 int a1[N]={0};
 int a2[N][N];
 for(int i=0;i<N;i++)
 {
     a1[i] = i*N;
 }

 int i=0;
 while(i < N*N)
 {
   for(int j=0;j<N;j++)
   {
     for(int k=0;k<N;k++)
     {
       a2[j][k] = matrix[i++];
     }
   }
 }
}

int main()
{
  string s1 = "abc23de3";
  sumOfNumbersInString(s1);
  int matrix[N*N]= {10,20,30,40,15,25,35,45,27,29,37,48,32,33,39,50};
  printSortedMatrix(matrix);

}

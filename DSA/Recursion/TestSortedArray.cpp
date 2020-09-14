#include<iostream>
#include<algorithm>
using namespace std;

int TEST_INPUT1[]={1,2,3,4,5,6,7};
int TEST_INPUT2[]={3,1,6,5,7,8,4};

int isArraySorted(int A[],int n)
{
  if(n==1)
    return 1;
  return A[n-1] < A[n-2] ? 0 : isArraySorted(A,n-1);
}

int main()
{
  cout << "Check whether the given array is in sorted order with recursion" << endl;
  cout << "Testing ..." << endl;
  cout << "Input 1 = ";
  for_each(begin(TEST_INPUT1),end(TEST_INPUT1),[](int x){ cout << x << " "; });
  cout << endl;

  if(isArraySorted(TEST_INPUT1,sizeof(TEST_INPUT1)/sizeof(TEST_INPUT1[0]))==1)
    cout << "Array is sorted !!!" << endl;
  else
    cout << "Array is not sorted :(" << endl;

  cout << "Input 2 = ";
  for_each(begin(TEST_INPUT2),end(TEST_INPUT2),[](int x){ cout << x << " "; });
  cout << endl;
  if(isArraySorted(TEST_INPUT2,sizeof(TEST_INPUT2)/sizeof(TEST_INPUT2[0]))==1)
    cout << "Array is sorted !!!" << endl;
  else
    cout << "Array is not sorted :(" << endl;

}

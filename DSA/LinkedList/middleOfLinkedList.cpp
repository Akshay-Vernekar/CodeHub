/*
 * Problem-24 : How will you find the middle of the linked list?
 * 
 */
#include<iostream>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  Node(int data):data(data),next(NULL){}
};
void getMiddleElement(Node* head)
{
  Node *slowPtr,*fastPtr,*prev;
  slowPtr=fastPtr=head;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    prev=slowPtr;
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  cout << "Middle Element : " << slowPtr->data << endl;
  cout << "Median : ";
  if(!fastPtr)
  {
    cout << "(" << prev->data << " + " << slowPtr->data << ") / 2 = " << (prev->data+slowPtr->data)/2 << endl;
    return;
  }
  cout << slowPtr->data << endl;
}

int main()
{
  int n=0,*arr,dummy;
  cout << "Enter No. Of elements : " ;
  cin >> n;
  arr = new int[n];
  cout << "Enter the elements of LL: ";
  for(int i=0;i<n;i++)
  {
    cin >> dummy;
    arr[i] = dummy;
  }
  Node* LinkedList=NULL;
  Node* tmp;
  for(int i=n-1;i>=0;--i)
  {
    tmp = new Node(arr[i]);
    tmp->next = LinkedList;
    LinkedList = tmp;
  }
  delete []arr;
  getMiddleElement(LinkedList);
}
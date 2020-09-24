/*
 * Problem 11 : Check whether the given linked list is either NULL-terminated or ends in a cycle (cyclic).
 *              If there is a cycle find the start node of the loop. 
 *
 * Problem 14 : Check whether the given linked list is NULL-terminated. If there is a cycle, find the length of the loop. 
 */
#include<iostream>
#include<thread>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
  Node(int val):data(val),next(NULL){}
};
void display(Node *head)
{
  while(head!=NULL)
  {
    cout << head->data << " " ;
    head=head->next;
  }
}
void LengthOfLoop(Node* ptr)
{
  int length=1;
  Node* tmp=ptr->next;
  while(tmp!=ptr)
  {
    tmp=tmp->next;
    ++length;
  }
  cout << "(LOOP LENGTH : " << length << ")" ;
}
int detectLoop(Node* head)
{
  Node *slowPtr,*fastPtr;
  slowPtr=fastPtr=head;
  bool loop=false;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr)
    {
      loop=true;
      break;
    }
  }
  if(!loop)
    return -1;
  thread thrdObj(LengthOfLoop,slowPtr);
  thrdObj.join();
  slowPtr=head;
  while(slowPtr!=fastPtr)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next;
  }
  return slowPtr->data;
}

int main()
{
  int n=0;
  int* arr,dummy;
  cout << "Creating Linked List with Loop " << endl;
  cout << "Enter the number of elements in LL : " ;
  cin >> n;
  arr = new int[n];
  cout << "Enter the elements of LL : ";
  for(int i=0;i<n;i++)
  {
    cin >> dummy;
    arr[i]=dummy;
  }
  cout << "Enter a location to form Loop: ";
  cin >> dummy;
  if(dummy>n || dummy-1 == -1) return -1;
  Node* LinkedList=NULL;// = new Node(arr[n-1]);
  Node* tmp;
  Node *l;
  for(int i=n-1;i>=0;--i)
  {
    tmp = new Node(arr[i]);
    if(i==dummy-1)
      l=tmp;
    tmp->next = LinkedList;
    LinkedList = tmp;
  }
  delete []arr;
  display(LinkedList);cout << l->data << endl;
  tmp=LinkedList;
  while(tmp->next)
    tmp=tmp->next;
  tmp->next=l;
  cout << "Loop found at element : " << detectLoop(LinkedList) << endl;
  return 0;
}
 
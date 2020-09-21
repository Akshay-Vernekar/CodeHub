/*
 * Problem 6 : Check whether the given linked list is either NULL-terminated or ends in a cycle (cyclic).
 */
#include<iostream>
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
int detectLoop(Node* head)
{
  Node *slowPtr,*fastPtr;
  slowPtr=fastPtr=head;
  while(slowPtr && fastPtr && fastPtr->next)
  {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
    if(slowPtr == fastPtr)
      return 1;
  }
  return 0;
}
int main()
{
  int n=0;
  cout << "Creating Linked List " << endl;
  cout << "List L1 : ";
  Node* ListWithoutLoop =  new Node(10);
  Node* tmp;
  for(int i=9;i>0;--i)
  {
    tmp = new Node(i);
    tmp->next = ListWithoutLoop;
    ListWithoutLoop = tmp;
  }
  display(ListWithoutLoop);cout << endl;
  cout << "List L2 : ";
  Node* ListWithLoop = new Node(99);
  Node *l;
  for(int i=9;i>0;--i)
  {
    tmp = new Node(i);
    if(i==5)
      l=tmp;
    tmp->next = ListWithLoop;
    ListWithLoop = tmp;
  }
  display(ListWithLoop);cout << l->data << endl;
  tmp=ListWithLoop;
  while(tmp->next)
    tmp=tmp->next;
  tmp->next=l;
  if(detectLoop(ListWithoutLoop))
    cout << "L1 has LOOP" << endl;
  else
    cout << "L1 has NO LOOP" << endl;
  if(detectLoop(ListWithLoop))
    cout << "L2 has  LOOP" << endl;
  else
    cout << "L2 has NO LOOP" << endl;
}
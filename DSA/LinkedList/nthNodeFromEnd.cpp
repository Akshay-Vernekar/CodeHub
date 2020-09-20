/*
 * Find nth     node    from    the     end     of      a       Linked  List.
 *
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
  cout << endl;
}

void getNthNodeFromEnd(Node* head,int n)
{
  Node *fastPtr,*slowPtr;
  fastPtr=slowPtr=head;
  int i=0;
  //Progress the fastPtr by n places
  while(fastPtr && ++i<n)
    fastPtr = fastPtr->next;
  if(fastPtr==NULL)
  {
    cout << n << " is greater than Length of Linked List" << endl;
    return;
  }
  //Now fastPtr as the reference progress slowPtr
  while(fastPtr->next)
  {
    fastPtr=fastPtr->next;
    slowPtr=slowPtr->next;
  }
  cout << slowPtr->data << endl;
}

int main()
{
  int n=0;
  cout << "Creating Linked List of 10 elements " << endl;
  Node* head =  new Node(10);
  Node* tmp;// = head;
  for(int i=9;i>0;--i)
  {
    tmp = new Node(i);
    tmp->next=head;
    head=tmp;
  }
  display(head);
  cout << "Insert the value for n : ";
  cin >> n;
  cout << n << "th Node from end is : ";
  getNthNodeFromEnd(head,n);
}
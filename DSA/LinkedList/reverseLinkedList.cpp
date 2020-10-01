/*
 *
 * Problem 16 : Reverse Linked List
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

Node* recursiveReverseLinkedList(Node* head)
{
  if(head==NULL)
    return NULL;
  if(head->next==NULL)
    return head;
  Node* secondNode = head->next;
  head->next = NULL;
  Node* reverseList = recursiveReverseLinkedList(secondNode);
  secondNode->next=head;
  return reverseList;
}
void reverseLinkedList(Node** LinkedList)
{
  Node *current,*prev,*next;
  prev=next=NULL;
  current=*LinkedList;
  while(current)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *LinkedList=prev;
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
  cout << "After reversing the Linked List : ";
  reverseLinkedList(&LinkedList);
  display(LinkedList);
  LinkedList=recursiveReverseLinkedList(LinkedList);
  cout << "Reversing using recursive approach : ";
  display(LinkedList);
  return 0;
}

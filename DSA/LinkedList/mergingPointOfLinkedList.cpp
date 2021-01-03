/*
 * Problem 17 : Suppose there are two singly linked lists both of which intersect at some point and become a single linked list. The head or
 start pointers of both the
 *              lists are known, but the intersecting node is not known. Also, the number of nodes in each of the lists before they intersec
t is unknown and may be 
 *              different in each list. List1 may have n nodes before it reaches the intersection point, and List2 might have m nodes before
 it reaches the 
 *              intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for finding the merging point.
 */
#include<iostream>
#include <cstdlib>
#include <ctime>
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
int getRandomMergingPoint(int n,int m)
{
  srand((unsigned int)time(0));
  if(n > m)
    return (rand()%n);
  else
	return (rand()%m);
}
int getLength(Node* head)
{
  int length=0;
  while(head)
  {
    head = head->next;
    ++length;
  }
  return length;
}
int mergingPoint(Node* LinkedList1, Node* LinkedList2)
{
  int diff=0;
  Node *head1,*head2;
  head1=head2=NULL;
  int length1=getLength(LinkedList1);
  int length2=getLength(LinkedList2);
  if(length1 > length2)
  {
    diff = length1 - length2;
    head1=LinkedList1;
    head2=LinkedList2;
  }
  else
  {
    diff = length2 - length1;
    head1=LinkedList2;
    head2=LinkedList1;
  }
  while(diff--)
    head1=head1->next;
  while(head1 && head2)
  {
    if(head1==head2)
      return head1->data;
    head1 = head1->next;
    head2 = head2->next;
  }
  return -1;
}

int main()
{
  // Preparing data for testing
  int m,n;
  m=n=0;
  int* arr,dummy;
  cout << "Enter the number of elements in LL1 : " ;
  cin >> n;
  cout << "Enter the number of elements in LL2 : ";
  cin >> m;
  int mergePoint = getRandomMergingPoint(n,m);
  int flag = n > m ? 1 : 2 ;
  cout << "Merging point in Larger List will be : " << mergePoint << endl;
  arr = new int[n];
  cout << "Enter the elements of LL1 : ";
  for(int i=0;i<n;i++)
  {
    cin >> dummy;
    arr[i]=dummy;
  }
  Node* LinkedList1=NULL;
  Node* tmp,*mp;
  for(int i=n-1;i>=0;--i)
  {
    tmp = new Node(arr[i]);
    if(flag == 1 && i==mergePoint)
      mp=tmp;
    tmp->next = LinkedList1;
    LinkedList1 = tmp;
  }
  delete []arr;
  arr = new int[m];
  cout << "Enter the elements of LL2 : ";
  for(int i=0;i<m;i++)
  {
    cin >> dummy;
    arr[i]=dummy;
  }
  Node* LinkedList2=NULL;
  tmp=NULL;
  for(int i=m-1;i>=0;--i)
  {
    tmp = new Node(arr[i]);
    if(flag == 2 && i==mergePoint)
      mp=tmp;
    tmp->next = LinkedList2;
    LinkedList2 = tmp;
  }
  delete []arr;
  Node* LL = n < m ? LinkedList1 : LinkedList2 ;
  while(LL->next)
    LL=LL->next;
  LL->next=mp; //comment this line remove merging
  // Data preparation Complete
  cout << "Length of LL1 : " << getLength(LinkedList1) << " ELEMENT : "; display(LinkedList1) ; cout << endl;
  cout << "Length of LL2 : " << getLength(LinkedList2) << " ELEMENT : "; display(LinkedList2) ; cout << endl;
  cout << "Merging Point value : " << mergingPoint(LinkedList1,LinkedList2) << endl;
  return 0;
}
             
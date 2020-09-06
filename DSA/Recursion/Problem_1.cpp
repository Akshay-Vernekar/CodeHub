/*
 * Problem - 1 :  Tower of Honai
 */
 
/***********************
Sample trace for 3 digits
MAINCALL(3,ACB)
	N=3 CALL1(2,ABC)
		N2 CALL1(1,ACB)
			N1 MOVE D1 FROM A -> C
		N2 	MOVE D2 FROM A -> B
		N2 CALL2(1,CBA)
			N=1 MOVE D1 FROM C -> B
	N3 		MOVE D3 FROM A -> C
	N3 CALL2(2,BCA)
		N2 CALL1(1,BAC)
			N1	MOVE D1 FROM B -> A
		N2 		MOVE D2 FROM B -> C
		N=2 CALL2(1,ACB)
			N1	MOVE D1 FROM A -> C

***********************/

#include<iostream>
using namespace std;

void TowerOfHonai(int n,char fromPeg, char toPeg, char auxPeg)
{
  if(n==1)
  {
    cout << "Move disk1 from " << fromPeg << " to " << toPeg << endl;
	return;
  }
  TowerOfHonai(n-1,fromPeg,auxPeg,toPeg);
  cout << "Move disk " << n << " from " << fromPeg << " to " << toPeg << endl;
  TowerOfHonai(n-1,auxPeg,toPeg,fromPeg);
}

int main()
{
  int n=0;
  cout << "Tower of Honai " << endl;
  cout << "Source Peg		: A " << endl;
  cout << "Auxiliary Peg 	: B " << endl;
  cout << "destination Peg	: C " << endl;
  cout << "Enter the no. of disks : " ;
  cin >> n;
  TowerOfHonai(n,'A','B','C');
  return 0;
}
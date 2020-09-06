/*
 *  Problem - 3 : Generate all the strings of n bits. Assume A[0..n – 1] is an array of size n
 *  Problem - 4 : Generate all the strings of length n drawn from 0... k – 1.
 */
 
#include<iostream>
using namespace std;

char A[5];

//Problem 3
void Binary(int n)
{
	if(n < 1)
	{
		cout << A << endl;
	}
	else
	{
		A[n-1]='0';
		Binary(n-1);
		A[n-1]='1';
		Binary(n-1);
	}
}

//Problem 4
void k-ary(int n,int k)
{
    if(n<1)
        cout << A << endl;
    else
    {
        for(int j=0;j<k;j++)
        {
            A[n-1]='0'+j;
            k-ary(n-1,k);
        }
    }
}

int main()
{
	int n;
	cout << "Enter array size (<5) : ";
	cin >> n;
	if(n > 5)
	{
		cout << "Dumbo !!" << endl;
		return 0;
	}
	cout << "Problem 3 : Binary combination : " << endl;
	Binary(n);
	cout << "Problem 4 : K-ary combination : " << endl;
	k-ary(n,3);
}
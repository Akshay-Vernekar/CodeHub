/* Read input from STDIN. Print your output to STDOUT*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> split(int num)
{
    vector<int> tmp;
    while(num>0)
    {
        tmp.push_back(num%10);
        num=num/10;
    }
    return tmp;
}

int main(int argc, char *a[])
{
    int T,N;
    vector<int > arr;
    set<unsigned int> sums;
    int tmp=0;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> tmp;
            arr.push_back(tmp);
        }
        int table[N][N];
        memset(table,0,sizeof(table[0][0])*N*N);
        for(int i=0;i<N;i++)
        {
            vector<int> sp(split(arr[i]));
            set<int> master_set(sp.begin(),sp.end());
            for(int j=0;j<N;j++)
            {
                if(i==j) continue;
                sp.clear();sp=split(arr[j]);
                set<int> intermediate=master_set;
                intermediate.insert(sp.begin(),sp.end());
                if(master_set.size()+sp.size() == intermediate.size())
                {
                    table[i][j]=1;
                    master_set=intermediate;
                }
                intermediate.clear();
                
            }
        }
        
        for(int i=0;i<N;i++)
        {
            int s=arr[i];
            for(int j=0;j<N;j++)
            {
                if(table[i][j]==1)
                    s+=arr[j];
            }
            sums.insert(s);
        }
        //set<unsigned int>::iterator it=sums.rbegin();
        cout<<*--sums.end()<<endl;
        
    }
    
}

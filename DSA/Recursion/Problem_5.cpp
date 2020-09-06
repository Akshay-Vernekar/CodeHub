/*
 * Problem 5 : 
 * Finding the length of connected cells of 1s (regions) in an matrix of Os and
 * 1s: Given a matrix, each of which may be 1 or 0. The filled cells that are connected form a
 * region. Two cells are said to be connected if they are adjacent to each other horizontally,
 * vertically or diagonally. There may be several regions in the matrix. How do you find the
 * largest region (in terms of number of cells) in the matrix?
 *
 */
#include<iostream>
using namespace std;

int matrix[5][5]={
                {1,1,0,0,0},
                {0,1,1,0,0},
                {0,0,1,0,1},
                {1,0,0,0,1},
                {0,1,0,1,1},
                  };
                  
bool** create2darr(int rmax,int colmax)
{
    bool** flag=0;
    flag=new bool*[rmax];
    for(int i=0;i<rmax;i++)
        flag[i] = new bool[colmax];
        
    for(int i=0;i<rmax;i++)
        for(int j=0;j<colmax;j++)
            flag[i][j]=false;
            
    return flag;
}

int getVal(int (*A)[5],int i, int j, int L, int H)
{
    if(i < 0 || j < 0 || i >= L || j>= H)
      return 0;
    else
      return A[i][j];
}

void findMaxBlock(int (*A)[5],int r,int c,int L, int H, int size,bool **cntarr, int &maxsize)
{
    if(r >=L ||c >= H)
      return;
    cntarr[r][c]=true;
    size++;
    if(size > maxsize)
      maxsize=size;
    int direction[][2]={
                        {-1,0},
                        {-1,-1},
                        {0,-1},
                        {1,-1},
                        {1,0},
                        {1,1},
                        {0,1},
                        {-1,1},
                        };
                        
    for(int i=0;i<8;i++)
    {
        int newi = r + direction[i][0];
        int newj = c + direction[i][1];
        int val = getVal(A,newi,newj,L,H);
        if(val > 0 && cntarr[newi][newj]==false)
          findMaxBlock(A,newi,newj,L,H,size,cntarr,maxsize);
    }
    cntarr[r][c]=false;
}

int getMaxOnes(int (*A)[5],int rmax, int colmax)
{
    int maxSize=0;
    bool **cntarr=create2darr(rmax,colmax);
    for(int i=0;i<rmax;i++)
        for(int j=0;j<colmax;j++)
            if(matrix[i][j]==1)
                findMaxBlock(A,i,j,rmax,colmax,0,cntarr,maxSize);
                
    return maxSize;
}

int main()
{
    cout << getMaxOnes(matrix,5,5);	
}
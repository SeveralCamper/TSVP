#include <iostream>
#define inf 100000
using namespace std;

#define SIZE 7

   int a[SIZE][SIZE] = {
              {0,	3,	4,	3,	0,	0, 0},
              {3,	0,	1,	0,	0,	0, 2},
              {4,	1,	0,	2,	1,	0, 1},
              {3,	0,	2,	0,	2,	4, 0},
              {0,	0,	1,	2,	0,	1, 3},
              {0,	0,	0,	4,	1,	0,6},
              {0,	2,	1,	0,	3,	6,0}
  };

struct Edges{
int u, v, w;
};
const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;

int i, j, n, e, start;
Edges edge[Emax];
int d[SIZE];


void bellman_ford(int n, int s)
{
int i, j;
 
for (i=0; i<n; i++) 
d[i]=inf;
  
d[s]=0;
 
for (i=0; i<n-1; i++)
for (j=0; j<e; j++)
if (d[edge[j].v]+edge[j].w<d[edge[j].u])
d[edge[j].u]=d[edge[j].v]+edge[j].w;
 
for (i=0; i<n; i++) 
cout<<endl<<start<<"->"<<i+1<<"="<<d[i];

  int ver[SIZE]; 
  int end = 6; 

  ver[0] = end + 1; 
  int k = 1;        
  int weight = d[end]; 

  while (end != 0)
  {
    for (int i = 0; i < SIZE; i++) 
      if (a[i][end] != 0)         
      {
        int temp =  weight - a[i][end]; 
        if (temp == d[i]) 
        { 
          weight = temp; 
          end = i; 
          ver[k] = i + 1; 
          k++;
        }
      }
  }

  printf("\nВывод кратчайшего пути\n");
  for (int i = k - 1; i >= 0; i--)
    printf("%3d ", ver[i]);

    printf("\n");
}

int main()
{
setlocale(LC_ALL, "Rus");
int w;



  
for (i=0; i<SIZE; i++)
for (j=0; j<SIZE; j++)
{

if (a[i][j]!=0) 
{
edge[e].v=i;
edge[e].u=j;
edge[e].w=a[i][j];
e++;}

}
 
start=1;
bellman_ford(SIZE, start-1);
}
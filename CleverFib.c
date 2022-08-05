#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int **mul(int **a,int **b)
{int **ar;
ar=(int**)malloc(2*sizeof(int *));
ar[0]=(int* )malloc(2*sizeof(int));
ar[1]=(int* )malloc(2*sizeof(int));
    ar[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%2021;
ar[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%2021;
ar[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%2021;
ar[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%2021;
return ar;
}

int **fib(int **arr,long long int n)
{if (n==1)
return arr;
 else if (n % 2 == 0)
        return mul(fib(arr,n/2), fib(arr,n/2));
    else
    {
        return mul(mul(fib(arr,n/2), fib(arr,n/2)),arr);
    }
}



int cleverFib(long long int n)
{int **arr;
arr=(int**)malloc(2*sizeof(int *));
arr[0]=(int*)malloc(2*sizeof(int));
arr[1]=(int* )malloc(2*sizeof(int));
arr[0][0]=1;
arr[0][1]=1;
arr[1][0]=1;
arr[1][1]=0;
int **mat=fib(arr,n);
return mat[0][0];
}

int main()
{
    long long int n;
    scanf("%lld",&n);
    int rem;
clock_t start_t, end_t;
double total_t;
start_t = clock();
rem=cleverFib(n-1);
end_t = clock();
total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
long double time=total_t;
printf("Total time taken: %lf\n", time);
printf("\nF(%lld) mod 2021 = %d",n,rem);
return 0;
}
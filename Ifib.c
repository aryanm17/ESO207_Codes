#include<stdio.h>
#include<time.h>
int ifib(long long int n)
{
    if (n==0)
return 0;
else if(n==1)
return 1;
else
{
 long long int a=0,b=1,temp;
for(int i=2;i<=n;i++)
{temp=b;
b=(a+b);
a=temp;
}
return b%2021;
}
}


int main()
{
    long long int n;
    scanf("%lld",&n);
    int rem;
clock_t start_t, end_t;
double total_t;
start_t = clock();
rem=ifib(n);
end_t = clock();
total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
long double time=total_t;
printf("Total time taken: %lf\n", time);
printf("\nF(%lld) mod 2021 = %d",n,rem);
return 0;
}
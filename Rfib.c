#include<stdio.h>
#include<time.h>

int rfib(long long int n)
{if (n==0)
return 0;
else if(n==1)
return 1;
else
return (((rfib(n-1))+rfib(n-2))%2021);
}
    
int main()
{
    long long int n;
    scanf("%lld",&n);
    int rem;
clock_t start_t, end_t;
double total_t;
start_t = clock();
rem=rfib(n);
end_t = clock();
total_t = (double)(end_t - start_t) / (CLOCKS_PER_SEC);

printf("Total time taken: %f\n", total_t);
printf("\nF(%lld) mod 2021 = %d",n,rem);
return 0;
}
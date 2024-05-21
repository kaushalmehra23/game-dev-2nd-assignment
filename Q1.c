#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<time.h>
int Max(int a ,int b){
    return (a>b)? a:b;
}
int Min(int a ,int b){
    return (a<b)? a:b;
}

int  minimax(int depth, int nodeindex, bool player,int evals[],int alpha,int beta)
{
    if(depth == 0 ){
        return evals[nodeindex-15];
    }
    if (player)
    {
        int min = INT_MIN;
        for (int i = 1; i <= 2; i++)
        {
            int child = minimax(depth-1,nodeindex*2+i,!player,evals,alpha,beta);
            min = Max(min,child);
            alpha = Max(min,alpha);
            if (alpha>=beta)
            {
                break;
            }
        }
        return min;
    }
    else{
        int max = INT_MAX;
        for (int i = 1; i <= 2; i++)
        {
            int child = minimax(depth-1,nodeindex*2+i,!player,evals,alpha,beta);
            max = Min(max,child);
            beta = Min(max,beta);
            if (alpha>=beta)
            {
                break;
            }
        }
        return max;
    }
    
}

int main()
{
    clock_t t;
    t = clock();
	int evals[] = {3, 5, 2, 9, 12, 5, 7, -6,3,4,-3,9,-8,-3,-100,2};
	int res = minimax(4, 0, true, evals,-1000,1000);
	printf("The optimal value is :%d\n",res);
    t = clock() - t;
    printf("No. of clicks %ld click (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    
	return 0;
}

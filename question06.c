#include <stdio.h>
#include<stdlib.h>
int count = 0;

int main(int argc, char *argv[])
{
    int j;
    double temp;
    double csum = 0, cmax;
    FILE *numbers;
    numbers = fopen(argv[1],"r");
    int count1 = 0,c;
    if((numbers=fopen(argv[1],"r"))==NULL)
    {
	    printf("Error in opening file\n");
	    exit(1);
    }
    while((c = getc(numbers)) != EOF)
        if(c == '\n')
        count1 += 1;
    numbers = fopen(argv[1],"r");
    fscanf(numbers,"%lf",&cmax);
    count1 -= 1;
    for(j=0;j<count1;j++)
    { 
        fscanf(numbers, "%lf",&temp);
        csum += temp;
        count += 1;
        if(csum > cmax) {
            cmax = csum;
            count += 1;
        }
        if(csum < 0) {
            csum = 0;
            count += 1;
        }
    }    
    printf("%lf is the maximum subsequence in %d instruction \n",cmax,count);
    return 0;
}



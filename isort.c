#include <stdio.h>
#define LEN 5
void shift_element(int* arr, int i)
{
    
for(int j=0;j<i;j++)
{
    *(arr+i-j)=*(arr+i-j-1);
}

}
void insertion_sort(int* arr , int len)
{
    int temp;
    for(int i=0;i<len;i++)
    {
        temp=*(arr+i);
        int counter=0;
        for(int j=i-1;j>=0;j--)
        {
            if(temp>*(arr+j))
            {
                break;
            }
            counter++;
        }   
        shift_element((int*)(arr+i-counter),counter);
        *(arr+i-counter)=temp;
    }
}

void print_arr(int* arr,int len)
{
 for(int i=0;i<len-1;i++)
    {
        printf("%d,",*(arr+i));
    }
     printf("%d\n",*(arr+len-1));
}


int main()
{
    int arr[LEN];
    for(int i=0;i<LEN;i++)
    {
       scanf("%d",&*(arr+i));
    }
    insertion_sort(arr,LEN);
    print_arr(arr,LEN);
}

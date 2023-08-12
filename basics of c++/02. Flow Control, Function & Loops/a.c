#include <stdio.h>

int main()
{
    int arr[10],count=0;

    for (int i = 0; i < 10; i++)
    {
        
        printf("enter no %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        
        for (int j = i+1; j < 10; j++)
        {
           
            if((arr[i]==arr[j])){
                count++;
            }
        }
        if(count !=0){
        printf("element %d i.e., %d is repeating %d times in the array \n",i+1,arr[i],count+1);
        }
        count =0;
    }
   
    
    
    return 0;
}

#include <stdio.h>

int main()
{
    int arr[10],arr_count[10]={0};

    for (int i = 0; i < 10; i++)
    {
        
        printf("entet no %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        
        for (int j = 0; j < 10; j++)
        {
           
            if((arr[i]==arr[j]) && (i!=j)){
                arr_count[i]=arr_count[i]+1;
            }
        }
         if((arr_count[i] !=0)&&()){
        printf("element %d i.e., %d is repeating %d times in the array \n",i+1,arr[i],arr_count[i]);
        }
        
        
    }
   
    
    
    return 0;
}
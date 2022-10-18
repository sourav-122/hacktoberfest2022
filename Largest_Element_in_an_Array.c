#include<stdio.h>
#define MAX 100

int MaxElem(int []);
int n;

int main()
{
    int arr1[MAX],hstno,i;
	printf("\n\n Recursion : Get the largest element of an array :\n");
	printf("------------------------------------------------------\n");

      printf(" Input the number of elements to be stored in the array :");
       scanf("%d",&n);
   
       printf(" Input %d elements in the array :\n",n);
       for(i=0;i<n;i++)
        {
	      printf(" element - %d : ",i);
	      scanf("%d",&arr1[i]);
	    }	
    hstno=MaxElem(arr1);//call the function MaxElem to return the largest element
    printf(" Largest element of the array is: %d\n\n",hstno);
    return 0;
}
int MaxElem(int arr1[])
{
    static int i=0,hstno =-9999;
    if(i < n)
    {
         if(hstno<arr1[i])
           hstno=arr1[i];
      i++;
      MaxElem(arr1);//calling the function MaxElem itself to compare with further element
    }
    return hstno;
}

/*

Sample Output:

 Recursion : Get the largest element of an array :                                                            
------------------------------------------------------                                                        
 Input the number of elements to be stored in the array :5                                                    
 Input 5 elements in the array :                                                                              
 element - 0 : 5                                                                                              
 element - 1 : 10                                                                                             
 element - 2 : 15                                                                                             
 element - 3 : 20                                                                                             
 element - 4 : 25                                                                                             
 Largest element of the array is: 25 
 
 */

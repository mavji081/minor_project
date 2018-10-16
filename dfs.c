#include<stdio.h>
#include<stdlib.h>
#define size 5

void main()
{
    int choice , n=-1 , a[size] , value , pos ;
    while(1)
    {
        printf("\n 1. Insert: ");
        printf("\n 2. Delete: ");
        printf("\n 3. Update: ");
        printf("\n 4. Display: ");
        printf("\n 5. Exit: ");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                   printf("Enter value for Insertion");
                   scanf("%d",&value);
                   printf("Enter position");
                   scanf("%d",&pos);
                   if(pos>=size || pos < 0)
                   {
                       printf("Invalid position");
                       break;
                   }
                   if(pos>n)
                   {
                       n=n+1;
                       a[n]=value;
                   }
                   else
                   {
                       insert(a , &n , value , pos);
                   }
                   break;

            case 2:
                   printf("Enter position");
                   scanf("%d",&pos);
                   if(pos<0 || pos > n)
                   {
                       printf("Invalid position \n ");
                   }
                   else
                   {
                       value=del (a , &n , pos);
                        printf("deleted value is %d : \n ",value);
                   }

                   break;

            case 3:
                   printf("Enter position");
                   scanf("%d",&pos);
                   printf("Enter value");
                   scanf("%d",&value);
                   if(pos < 0 || pos > n)
                   {
                       printf("Invalid position");
                       break;
                   }
                   else
                   {
                       update(a , value , pos);
                   }
                   break;

            case 4:
                  display(a,n);
                  break;

            case 5:
                   exit(0);
            default:
                    printf("Enter valid position");
        }


    }
}

void insert(int a[] , int *n , int value , int pos)
{
    int i;
    if(*n == size-1)
    {
        printf("No space");
        return;
    }
    else
    {
        for(i=*n;i>=pos;i--)
        {
            a[i+1]=a[i];

        }
        a[pos]=value;
        *n=*n+1;
    }
}

void display(int a[] , int n)
{
    int i;
    if(n==-1)
    {
        printf("Array is empty: ");
        return;
    }
    printf("Element are");
    for(i=0;i<=n;i++)
    {
        printf("\n a[%d]=%d \n",i,a[i]);
    }
}

void del(int a[], int *n , int pos)
{
    int i , value;
    if(*n==-1)
    {
        printf("Array is empty: ");
        return;
    }
    value=a[pos];
    for(i=pos+1;i<=*n;i++)
    {
        a[i-1]=a[i];
    }
    *n=*n-1;
    return value;
}

void update(int a[] , int value , int pos)
{
    a[pos]=value;
}

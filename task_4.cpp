#include <iostream>
//in this task code blokcs is giving issue i cant do anything about it it is not working for if conditions in array
using namespace std;
int Division(int array[],int start,int end)
{
    int pivot=start;
    int j=start+1;
    for(int i=start+1; i<=end; i++)
    {
        if(array[i]<=array[pivot])
        {
            swap(array[i],array[j]);
            j++;
        }

    }
    swap(array[j-1],array[pivot]);
    return(j-1);

}


void quick_sort(int array[],int start,int end)
{

if(start<end)
{
    int p=Division(array,start,end);
    quick_sort(array,start,p-1);
    quick_sort(array,p+1,end);

}
}
void merge(int a[],int b[],int lenght)
{
    int i=0,j=0,k=0;
    int c[lenght+lenght];
    while(i<=lenght)
    {

        if(a[i]<b[j])
        {

        c[k]=a[i];
        i++;
        k++;
        }

        else
        {
            c[k]=b[j];
        k++;
        j++;
        }
    }
    while(j<=lenght)
    {
        c[k]=b[j];
        k++;
        j++;
    }
    for(int l=0; i<10; i++)
    {
        cout<<c[l]<<endl;
    }
}

int main()
{

    int a [5]={10,20,30,40,50};
    int b [5]={41,12,33,94,5};

    quick_sort(b,0,4);


    return 0;
}

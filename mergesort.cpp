#include<iostream>
using namespace std;
class sorting{
private:
  int array[10]={0};
  int i=0;
  int count=0;
public:
  void Add(int value)
  {
    if(i<=10)
      {
        array[i]=value;
      }
      if(i!=0)
      insert(array,i);
      i++;
  }
  void  insert(int x[], int index)
  {
    for(int k=index; k>0; k--)
    {

      if(x[k]<x[k-1])
        {
          int temp=x[k];
          x[k]=x[k-1];
          x[k-1]=temp;
        }
      }
  }
  void move_min(int x[],int index)
  {
    int minimum=99999;
    int temp=0;
    for(int k=count; k<index; k++)
    {
      if(x[k]<=minimum)
          {
            minimum=x[k];
            temp=k;
          }
      }
      int temp2=x[count];
      x[count]=minimum;
      x[temp]=temp2;
      count++;
      return;
  }
	void merge_sort(int *array, int left, int right)
	{
	    int mid;
      //when left will equal to 0  and right will also b zero when 1/2 happen
	    if (left < right){
	        //divide the array i can also give condition if left!=0
	        mid=(left+right)/2;
	        merge_sort(array,left,mid);
	        merge_sort(array,mid+1,right);

          merge(array,left,right,mid);

	    }
	}
	// Merge sort
	void merge(int *array, int left, int right, int mid)
	{
    //i will check left to mid

    //j will check from mid to end mean right side
	    int i, j, k, temp[50];
	    i = left;
	    k = left;
	    j = mid + 1;
	    while (i <= mid && j <= right) {
	        if (array[i] < array[j]) {
	            temp[k] = array[i];
	            k++;
	            i++;
	        }
	        else  {
	            temp[k] = array[j];
	            k++;
	            j++;
	        }
	    }
      //This will work for remaining value on left side
	    while (i <= mid) {
	        temp[k] = array[i];
	        k++;
	        i++;
	    }
      //This will work for remaining value on right side

	    while (j <= right) {
	        temp[k] = array[j];
	        k++;
	        j++;
	    }
      //  i will work on same array later by shifting
      //backward shiting to array
	    for (i = left; i < k; i++)  {
	        array[i] = temp[i];
	    }

	}
  void Display()
      {
        for(int k=0; k<10; k++)
          {
            if(array[k]!=0)
            std::cout  <<"index:"<<k<< "  Value:" <<array[k]<<'\n';
          }
        }


};
class Heap{
  int array[10]={-1};
  int i=0;
public:
  void Add(int value)// I cant use parent of left right in private because the dont change with runnig time so direct numbers are more easy
  //if I use direct num then no sapce will b cosumed for int data type
  {
    if(i>=0 || i<10)
    {
      array[i]=value;
      int k=i;
      check(k);
      i++;
    }
    else
    std::cout << "Array is  Full:" << '\n';
    return;
  }

  void check(int k)
  {
    if(k==0)
    return;
    if(array[k]<array[(k-1)/2])
    {
      int temp=array[(k-1)/2];
      array[(k-1)/2]=array[k];
      array[k]=temp;
    }
    k--;
    check(k);
  }
  void remove()
  {
    if(i==0)
      {
        array[0]=0;
      }
      else
    {
      int temp=array[0];
      int k=--i;
      array[0]=array[k];
      array[k]=temp;
    }
    return;
  }

    void Display()
        {
          for(int k=0; k<10; k++)
            {
              std::cout  <<"index:"<<k<< "  Value:" <<array[k]<<'\n';
            }
          }

};
int main()
{

  sorting s;
  Heap obj;
        int condition,data;
      do {
          std::cout << "Press 1 to add value in Heap:" << '\n';
          std::cout << "Press 2 to remove value in Heap:" << '\n';
          std::cout << "Press 3 to Display Heap:" << '\n';
          std::cout << "Press 4 to sort array by merge sort:" << '\n';
          std::cin >> condition;
        switch (condition)
        {
        case 1:
            std::cout << "Give the value you want to add:" << '\n';
            std::cin >> data;
            obj.Add(data);
            std::cout << "************************" << '\n';
            obj.Display();
            std::cout << "************************" << '\n';
            break;
        case 2:
        std::cout << "Removing......" << '\n';
            obj.remove();
        case 3:
            std::cout << "************************" << '\n';
            obj.Display();
            std::cout << "************************" << '\n';
            break;
      case 4:
      int myarray[100], num;
            cout<<"Enter number of elements you want to Add:";
            cin>>num;
      for (int i = 0; i < num; i++)
          {
            cout<<"Enter "<<num<<" elements to be sorted:";
            cin>>myarray[i];
            }

            s.merge_sort(myarray, 0, num-1);
            cout<<"Sorted array\n";
            std::cout << "************************" << '\n';
            for (int i = 0; i < num; i++)
            {
                cout<<myarray[i]<<endl;
            }
            std::cout << "************************" << '\n';

            break;
            default:
            std::cout << "You have given a wrong input:" << '\n';
            break;

          }
            std::cout << "If you want to continue Press any number else Press ..0.." << '\n';
            std::cin >> condition;

      } while(condition!=0);


return(0);
}

#include <iostream>
#include <time.h>
using namespace std;
class sorting{
private:
  int index=0;
public:
  void quick_sort(int array[],int start,int end)
  {
    if(start<end)
    {
      int p=Division(array,start,end);
      quick_sort(array,start,p-1);
      quick_sort(array,p+1,end);
    }
    return;
  }
  int Division(int array[],int start,int end)
  {
    int pivot=end;
    int j=-1;
    for(int i=start; i<end; i++)
    {
      if(array[i]<=array[pivot])
      {
        j++;
        swap(array[i],array[j]);

      }
    }
    swap(array[j+1],array[end]);
    return(j+1);
  }
  void Display(int array[],int end)
  {
    std::cout << "Array:" << '\n';
    for(int i=0; i<end; i++)
    {
      std::cout<<"Index: "<<i << "Value: "<<array[i]<<'\n';
    }
  }
};
int main()
{
  srand(time(NULL));
  sorting s;
  int myarray[100];
  int num;

  int condition;

  do {
    std::cout << "Press 1 to Add Value in Array and sort by quick sort: " << '\n';
    std::cout << "Press 2 to Add Value in Array and sort by quick sort using random variable: " << '\n';
    std::cin >> condition;
    switch (condition) {
      case 1:
            cout<<"Enter number of elements you want to Add:";
            cin>>num;
      for (int i = 0; i < num; i++)
          {
            cout<<"Enter "<<num<<" elements to be sorted:";
            cin>>myarray[i];
            }
            s.Division(myarray,0,num-1);
            s.Display(myarray,num);
            break;
      case 2:
            cout<<"Enter number of elements you want to Add:";
            cin>>num;
      for (int i = 0; i < num; i++)
          {
            cout<<"Enter "<<num<<" elements to be sorted:";
            cin>>myarray[i];
            }
            for(int i=0; i<num-1; i++)
            {
              int k=rand()%16;
              if(k==0)
                k=1;
              s.Division(myarray,0,k);
            }
            s.Display(myarray,num);
            break;
    }
    std::cout << "If you want to end program press 0 else 1:" << '\n';
    std::cin >> condition;
  } while(condition!=0);
  return(0);
}

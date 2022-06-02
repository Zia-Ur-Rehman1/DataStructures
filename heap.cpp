#include<iostream>
using namespace std;
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
    }
    else
    std::cout << "Array is  Full:" << '\n';
    i++;
  }
  void check(int k)
  {
    if(k==0)
    return;
    if(array[k]>array[(k-1)/2])
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
    int temp=0;
    int k=--i;
    array[temp]=array[k];
    array[k]=-1;
    for( k=0; k<i; k++)
    {
      if(array[2*k+1]<array[2*k+2])
      {
          if(array[k]<array[2*k+2])
          {
            int temp2=array[2*k+2];
            array[2*k+2]=array[k];
            array[k]=temp2;
          }
      }
      else
      {
        if(array[k]<array[2*k+1])
        {
          int temp2=array[2*k+1];
          array[2*k+1]=array[k];
          array[k]=temp2;
        }
    }


    }

  }
  void heap_check()
  {
    for (int k=0; k<i; k++)
    {
      if(array[k]!=-1)
      continue;
      else
      {
        std::cout << "It is not a heap:" << '\n';
        break;
      }
      if(array[(k-1)/2]>array[k])
      continue;
      else
      {
        std::cout << "It is not a heap:" << '\n';
        break;

      }
    }
    std::cout << "It is a heap:" << '\n';
  }
  void Top()
  {
    std::cout << "Array Top:" << array[0]<<'\n';
  }

    void Display()
        {
          for(int k=0; k<i; k++)
            {
              std::cout  <<"index:"<<k<< "  Value:" <<array[k]<<'\n';
            }
          }

};
int main()
{
  Heap obj;
  int condition,data;
do {
    std::cout << "Press 1 to add value:" << '\n';
    std::cout << "Press 2 to remove value:" << '\n';
    std::cout << "Press 3 to Display:" << '\n';
    std::cout << "Press 4 to check heap or not:" << '\n';
    std::cout << "Press 5 to check Top of heap:" << '\n';
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
      obj.heap_check();
      break;
  case 5:
  obj.Top();
      default:
      std::cout << "You have given a wrong input:" << '\n';
      break;
    }
      std::cout << "If you want to continue Press any number else Press ..0.." << '\n';
      std::cin >> condition;

} while(condition!=0);
  return(0);
}

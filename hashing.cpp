#include<iostream>
using namespace std;
class Hashing{
private:
  int array[31]={0};
  int key,i=0;
  int counter=0;
public:
  //There was not much time
  //later on i will merge Search and delete with colllison giving collion a unique key
  //the function checking full will also help mee to move backward
  int Hash(int value)
  {
      return(key=value%31);

  }
  void Add(int value)
  {
    counter++;
    if(counter>=32)
    {
      std::cout << "There is no space to Add:" << '\n';
      return;
    }
    key=Hash(value);
    if(array[key]==0 || array[key]==-1)
    {
      array[key]=value;
    }
    else
    {
      key=collision(key,value);
      array[key]=value;
    }
    return;
  }
  int collision(int key,int value)
  {
    i++;
    key=(Hash(value)+i)%31;
    if(array[key]==value)
    {
      return(-1);
    }
    if(array[key]==0 || array[key]==-1)
    {
      return key;
    }
    else collision(key,value);
  }
  void Search(int value)
  {
    key=Hash(value);
    if(array[key]==value)
    {
      std::cout << "Value has Been Found At index:" << key<<'\n';
    }
    else
    {
      key=collision(key,value);
      if(key==-1)
      {
        std::cout << "Value has been Found:" << '\n';
      }
      else
      std::cout << "There is no such value:" << '\n';
    }
  }
  void Del(int value)
  {
    key=Hash(value);
    if(array[key]==value)
    {
      std::cout << "Value has Been Found:" <<'\n';
      array[key]=-1;
      std::cout << "Value has been removed....." << '\n';
      counter--;
    }
    else
    {
      key=collision(key,value);
      if(key==-1)
      {
        std::cout << "Value has been Found:" << '\n';
        array[key]=-1;
        std::cout << "Value has been removed....." << '\n';
        counter--;

      }
      else
      std::cout << "There is no such value:" << '\n';
    }
    return;
  }

  void Full()
  {
    if(counter>=32)
    std::cout << "Array is Full:" << '\n';
    else
    std::cout << "Array is not Full:" << '\n';

  }
  void Empty()
  {
    if(counter>=32)
    std::cout << "Array is Not Empty:" << '\n';
    else
    std::cout << "Array is Empty:" << '\n';
  }
  void Display()
  {
    for(int i=0; i<31; i++)
    {
      std::cout  <<"index:"<<i<< "  Value:" <<array[i]<<'\n';
    }
  }
};
int main()
{
  Hashing h;
  for(int i=1;i<32; i++)
  h.Add(9);
  int condition,data;
  do {
      std::cout << "Press 1 to Insert:" << '\n';
      std::cout << "Press 2 to Remove:" << '\n';
      std::cout << "Press 3 to Display:" << '\n';
      std::cout << "Press 4 to SEARCH:" << '\n';
      std::cout << "Press 5 to check if Full:" << '\n';
      std::cout << "Press 6 to check if Empty:" << '\n';


      std::cin >> condition;
    switch (condition) {
      case 1:
      std::cout << "Give the value you want to add:" << '\n';
      std::cin >> data;
      h.Add(data);
      break;
      case 2:
      std::cout << "Give the value you want to remove:" << '\n';
      std::cin >> data;
      h.Del(data);
      break;
      case 3:
      h.Display();
      break;
      case 4:
      std::cout << "Give the value you want to Search:" << '\n';
      std::cin >> data;
      h.Search(data);
      break;
      case 5:
      h.Full();
      break;
      case 6:
      h.Empty();
      break;
      default:
      std::cout << "You have Given Wrong Input:" << '\n';

    }
    std::cout << "Press 0 to exit else press 1:" << '\n';
    std::cin >> condition;
  } while(condition!=0);

  return(0);
}

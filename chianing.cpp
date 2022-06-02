#include<iostream>
using namespace std;
class Node
{
  private:
    int data;
    Node *next;
  public:
    Node(){

    }
    Node(int d)
    {
    data=d;
    next=NULL;
    }
    void setdata(int d)
    {
      data=d;
    }
    void setnext(Node *n)
    {
      next=n;
    }
    int getdata()
    {
      return(data);
    }
    Node* getnext()
    {
      return(next);
    }
};
class LinkedList
{
private:
  Node *first;
public:
  LinkedList()
  {
    first=NULL;
  }
    void addatstart(int x)//checked
    {
        Node *temp=new Node(x);
        Node *temp2=first;//temp 2 ko first pass kr dia
        first=temp;//first main temp a gia
        first->setnext(temp2);//first k next main temp 2 a gia
      }

    void    addatend(int y)//checked
        {
          Node *temp=new Node(y);
          Node *temp2=first;
          if(first==NULL)
          {
            addatstart(y);
          }
          else
          {
            while (temp2->getnext()!=NULL)
            {
              temp2=temp2->getnext();
            }
          temp2->setnext(temp);
          }
        }

          int display_length()//checked
          {
            int count=1;
            Node *temp=first;
            if(first==NULL)
            {
              return(0);
            }
            else{
            while(temp->getnext()!=NULL)
            {
              temp=temp->getnext();
              count++;
            }
            return(count);
          }

          }
          int check_value_exiting(int value)
          {
            Node *user=new Node(value);
            Node *temp=first;
            while(temp!=NULL)
            {

            if(temp->getdata()==user->getdata())
            return(1);
            else
            temp=temp->getnext();
              }
              return(0);
          }

          //checked
          int remove_specific_value(int k)
          {
            int check=check_value_exiting(k);
            Node *temp=new Node(k);
            Node *temp2=first;

            if(check==0)
            {
              std::cout << "There is no such value " << '\n';
              return(0);
            }
                if(temp->getdata()==first->getdata())
                {
                  remove_at_start();
                  return(0);
                }
                  else
                    {

                      while (temp2->getnext()->getdata()!=temp->getdata())
                      {
                          temp2=temp2->getnext();
                        }
              temp2->setnext(temp2->getnext()->getnext());
              std::cout << "Your value is removed" << '\n';
              return 1;
                  }
                      }

                      void remove_at_start()//first=first->getnext()
                      { //it is equal to NULL so it was creating segmentation fault
                        if(first==NULL)
                        {
                          std::cout << "There is no value to remove" << '\n';

                        }
                          else
                          {
                            Node *temp=new Node;
                            temp=first;
                            first=temp->getnext();
                            std::cout << "Your value is removing..." << '\n';

                            }
                      }
                      void show_value(int k)
                      {
                        Node *temp=first;
                        if (temp==NULL)
                        {
                          std::cout << "There is no value to show:" << '\n';
                        }
                        else
                        {
                          while(temp!=NULL)
                          {
                            if(temp->getdata()==k)
                            {
                              std::cout << "value has been found:" << '\n';
                              return;
                            }
                          }
                          std::cout << "There is no such value:" << '\n';
                        }

                      }


};
class Hashing{
private:
  int array[31]={0};
  int key,i=0;
  int counter=0;
public:
  int Hash(int value)
  {
      return(key=value%31);

  }

};
class chaining{
private:
LinkedList array[10];
Hashing h;
public:
  void  add_chain(int value)
  {
    int key=h.Hash(value);
    array[key].addatstart(value);
  }
  void del(int value)
  {
    int key=h.Hash(value);
    array[key].remove_specific_value(value);
  }
  void search(int value)
  {
    int key=h.Hash(value);
    array[key].show_value(value);
  }
};
int main()
{
chaining c;
  int condition,data;
  do {
      std::cout << "Press 1 to Insert:" << '\n';
      std::cout << "Press 2 to Remove:" << '\n';
      std::cout << "Press 3 to Search:" << '\n';


      std::cin >> condition;
    switch (condition) {
      case 1:
      std::cout << "Give the value you want to add:" << '\n';
      std::cin >> data;
      c.add_chain(data);
      break;
      case 2:
      std::cout << "Give the value you want to remove:" << '\n';
      std::cin >> data;
      c.del(data);
      break;
      case 3:
      std::cout << "Give the value you want to Search:" << '\n';
      std::cin >> data;
      c.search(data);
      break;
      default:
      std::cout << "You have Given Wrong Input:" << '\n';

    }
    std::cout << "Press 0 to exit else press 1:" << '\n';
    std::cin >> condition;
  } while(condition!=0);

  return(0);
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;
public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
    void setNext(Node *next)
    {
        this -> next = next;
    }
    void setData(int data)
    {
        this -> data = data;
    }
    Node* getNext()
    {
        return next;
    }
    int getData()
    {
        return data;
    }
};

class LinkList
{
private:
    Node *root;
public:
    LinkList()
    {
        root = NULL;
    }
    void addAtStart(int data)
    {
        Node *temp2 = root;
        Node *temp = new Node(data);
        root = temp;
        root -> setNext(temp2);
        //temp2 = root;
    }
    void display()
    {
        Node *temp = root;
        if(temp!=NULL){
            cout<<temp->getData();
            temp=temp->getNext();
        }
        while(temp != NULL)
        {
            cout <<"->"<<temp->getData();
            temp = temp->getNext();
        }
        cout<<endl;
    }

    void addAtEnd(int data)
    {
        if (root == NULL)
        {
            root=new Node(data);
        }
        else
        {
            Node *temp2 = root;
            Node *temp = new Node(data);
            while (temp2 -> getNext() != NULL)
            {
                temp2 = temp2->getNext();
            }
            temp2 -> setNext(temp);
        }
    }
    int getSize()
    {
        int a = 0;
        Node *temp = root;
        while(temp != NULL)
        {
            temp = temp->getNext();
            a++;
        }
        return a;
    }
//error was in this fucntion it lose the data after that index so i corrected it
    void addAtIndex(int index, int data)
    {
        if (index < 0)
        {
            addAtStart(data);
        }
        else if(index > getSize())
        {
            addAtEnd(data);
        }
        else
        {
            Node *temp = new Node(data);
            Node *temp2 = root;
            int i = 0;
            while(i != index-1)
            {
                temp2 = temp2->getNext();
                i++;
            }
          Node  *temp3=temp2->getNext();
            temp2->setNext(temp);
            temp->setNext(temp3);

        }
    }

};
int main()
{

    LinkList list;
    list.addAtEnd(5);
    list.addAtStart(13);
    list.addAtStart(12);
    list.addAtStart(4);
    list.addAtEnd(9);
    list.addAtIndex(3,6);
    int k=list.getSize();
    list.display();
    std::cout << "Value of lenght:" << k<<'\n';

    return 0;
}

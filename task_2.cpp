#include <iostream>
#include <string>
using namespace std;
class Node
{
private:
    int data;
    Node  *next;
public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void setdata(int data)
    {
        this->data = data;
    }
    int getdata()
    {
        return data;
    }
    Node* getnext()
    {
        return next;
    }
    void setnext(Node *next)
    {
        this->next = next;
    }

};



Node *first = NULL;
Node *end=NULL;
class Queue
{
//my first and end were not working in this compiler so i make it global
//end is always at last value
//so it adds there

public:
    void enqueue(int data)
    {
        Node *temp = new Node(data);
        Node *temp2 = first;
        if(first == NULL)
        {
            first = temp;
            end=first;
        }
        else if(first->getnext() == NULL)
        {
            first->setnext(temp);
            end=first->getnext();
        }
        else
        {
            end->setnext(temp);
            end=end->getnext();

        }
    }

    void dequeue()
    {
        if(first == NULL)
        {
            cout << "~Empty~" << endl;
        }
        else if(first->getnext()== NULL)
        {
            first = NULL;
        }
        else
        {
            first = first->getnext();
        }
    }

    void peek()
    {
        if(first == NULL)
        {
            cout << "~Empty~" << endl;
        }
        else
        {
            cout << "Peek :" << first->getdata() << endl;
        }
    }

    void back()
    {
        if(first == NULL)
        {
            cout << "~Empty~" << endl;
        }
        else
        {
            Node *temp = first;
            while(temp->getnext() != NULL)
            {
                temp = temp->getnext();
            }
            cout << "Back: " << temp->getdata() << endl;
        }
    }



    void display()
    {
        Node *temp = first;
        if(first == NULL)
        {
            cout << "~Empty~" << endl;
        }
        else
        {
            while(temp != NULL)
            {
                cout <<temp->getdata() <<" ";
                temp = temp->getnext();
            }
            cout<<endl;
        }
    }

}; // End of Queue class

int main()
{

    Queue que;
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(7);

    que.display();
    que.dequeue();

    que.display();

    return 0;
}

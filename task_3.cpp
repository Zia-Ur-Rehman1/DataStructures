#include <iostream>

using namespace std;

class Node
{
private:
    Node *right;
    Node *left;
    int data;
public:
    Node(int d)
    {
        right=NULL;
        left=NULL;
        data=d;
    }

    int getData()
    {
        return data;
    }

    Node* getLeft()
    {
        return left;
    }

    Node* getRight()
    {
        return right;
    }

    void setLeft(Node *n)
    {
        left=n;
    }

    void setRight(Node *n)
    {
        right=n;
    }
    void setData(int d)
    {
        data=d;
    }



};
Node *root;
class BST
{


public:

    BST()
    {
        root=NULL;
    }


    void add(int d)
    {
        Node *temp_new=new Node(d);
        Node *temp = root;
        if(root==NULL)
        {
            root=temp_new;
            return;
        }
        else
        {
            while(1)
            {
                if(d<temp->getData())
                {
                    if(temp->getLeft()==NULL)
                    {
                        temp->setLeft(temp_new);
                        return;
                    }
                    else
                        temp=temp->getLeft();
                }
                else if(d>temp->getData())
                {
                    if(temp->getRight()==NULL)
                    {
                        temp->setRight(temp_new);
                        return;
                    }
                    else
                        temp=temp->getRight();
                }
            }
        }
    }
    void display(Node *root){
    /** your code goes here **/
    if(root==NULL)
    {
      cout<<"Nothing to display:"<<endl;
      return;
    }
    if(root->getLeft()!=NULL)
    {
        display(root->getLeft());

    }
    if(root->getRight()!=NULL)
    {
        display(root->getRight());

    }
    if(root->getLeft()==NULL && root->getRight()==NULL)
    {
      cout<<root->getData()<<endl;
    }
        }

};

int main()
{
    BST bst;

    bst.add(10);
    bst.add(20);
    bst.add(15);
    bst.add(16);
    bst.add(122);
    bst.add(8);
    bst.add(7);
    bst.add(9);
    bst.add(3);
    bst.display(root);

    return 0;
}

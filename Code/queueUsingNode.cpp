#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*front = NULL , *rear = NULL;

void enqueue(int x)
{
    Node *t = new Node;
    if (t==NULL)
    {
        /* code */
        cout << "Queue is full!" << endl;
    }
    else
    {
        t->data = x;
        t->next = NULL;

        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
        
    }
    
}

int dequeue()
{
    int x = -1;
    Node *t;

    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }

    return x;
}

void displayQueue()
{
    Node *p = front;

    if (p == NULL)
    {
        cout << "Queue is empty!" << endl;
    }
    else{
        

        while(p != NULL){
            cout << p->data << " ";
            p = p->next;
        }
    }
}

// int main()
// {
//     enqueue(12221);
//     enqueue(1245);
//     enqueue(132);

//     cout << dequeue() << endl;
//     cout << dequeue() << endl;
//     cout << dequeue() << endl;

//     displayQueue();


//     return 0;
// }
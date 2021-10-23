#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std; 

struct Node{
    int val; 
    int n = 0; 
    Node *prev; 
    Node *next; 

    Node(int x){
        this->val = x; 
        prev = NULL;
        next = NULL;        
    }
};

struct Deque{
    private: 
        Node *head;
        Node *tail;
        int n = 0; 
    public:
        Deque(){
            head= NULL;
            tail= NULL;
        }
    void push_front(int x){
        Node *item = new Node(x);

        if(n==0){
            head = item; 
            tail = item; 
        }
        else if(n==1){
            head = item; 
            tail->next = head;
            head->prev = tail;
        }else{
            item->prev = head; 
            head -> next = item; 
            head = item;  
        }
        n++; 
    }
    void push_back(int x){
        Node *item = new Node(x); 
        if (n==0)
        {
            head = item;
            tail = item;
        }
        else if(n==1)
        {
            tail = item;
            tail->next = head;
            head->prev = tail;
        }else{
            item->next =tail; 
            tail->prev = item; 
            tail = item; 
        }
        n++; 
    }
    int pop_front(){
        if(n>1){
            int x = head->val; 
            head = head->prev; 
            n--; 
            return x; 
        }else if(n==1){
            int x = head->val; 
            head = NULL; tail = NULL; 
            n--; 
            return x; 
        }else{
            cout<<"error"<<endl; 
            return 0; 
        }
    }
    int pop_back(){
        if(n>1){
            int x = tail->val;
            tail = tail ->next; 
            n--; 
            return x;
        }else if(n==1)
        {
            int x = tail->val; 
            head = NULL;tail= NULL;
            n--; 
            return x;
        }else{
            cout<<"error"<<endl; 
            return 0; 
        }
    }
    int front(){
        return head->val; 
    }
    int back(){
        return tail->val; 
    }
    void clear(){
        while(head!=NULL)
        {
            pop_front();
        }
    }
    int size(){
        return n; 
    }
}; 

int main()
{
   
    Deque *Deq = new Deque();

    string statement; 
    int number; 

    while (cin>>statement)
    {
        if(statement == "push_front")
        {
            cin>>number; 
            Deq->push_front(number);
            cout<<"ok"<<endl; 
        }
        else if(statement=="push_back")
        {
            cin>>number;
            cout<<"ok"<<endl;
            Deq->push_back(number);
             
        }
        else if(statement=="pop_front"){
            if(Deq->size()==0)
            {
                cout<<"error"<<endl; 
            }   
            else{
                cout<<Deq->pop_front()<<endl; 
            }
        }
        else if(statement=="pop_back")
        {
            if(Deq->size()==0)
            {
                cout<<"error"<<endl; 
            } 
            else{
                cout<<Deq->pop_back()<<endl; 
            }
        }
        else if(statement=="front")
        {
            if(Deq->size()==0)
            {
                cout<<"error"<<endl;
            }
            else{
            cout<<Deq->front()<<endl; 
            }
        }
        else if(statement=="back"){
            if(Deq->size()==0)
            {
                cout<<"error"<<endl;
            }else{
            cout<<Deq->back()<<endl;
            }
        }

        else if(statement=="size"){
            cout<<Deq->size()<<endl;
        }
        else if(statement=="clear"){
            Deq->clear(); 
            cout<<"ok"<<endl; 
        }
        else if(statement=="exit")
        {
            cout<<"bye"<<endl; 
            break; 
        }
    }
    

    return 0; 
}
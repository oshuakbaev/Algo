#include <iostream>

using namespace std; 


struct Node{
    int val;
    long long n = 0;
    Node *prev;
    Node *next;
    Node (int x){
        this -> val = x;
        prev = NULL;
        next = NULL;
    }
};

struct queu{
    private: 
        Node *head;
        Node *tail;
        long long n = 0;
    public:
        queu(){
            head = NULL;
            tail = NULL;
        }
    
    void push(int x){
        Node *item = new Node(x);
        //n++;
        if (n == 0){
            head = item;
            tail = item;          
        }
        else if (n == 1) {
          tail = item;
          tail->prev = head;
          head->next = tail;          
        }
        else{
            item->prev = tail;
            tail->next = item;
            tail = item;
        }
        n++;
    }

    void pop(){
        if(n > 1){            
            int x = head->val;
            head = head->next;
            n--;
        }
        else if (n == 1) {
          int x = head->val;
          head = NULL; tail = NULL;
          n--;
        }
    }

    int front(){      
       return head->val;
    }

    void clear(){
        while(head != NULL){
            pop();
        }
    }

    int size(){
        return n;
    }
    


};


int main()
{
    int player1[5];
    int player2[5];
    int cnt = 1;
    for (int i = 0; i < 5; i++)
    { 
        cin>>player1[i];
    }
    for (int i = 0; i < 5; i++)
    { 
        cin>>player2[i];  
    }


    queu *player1_q = new queu();
    queu *player2_q = new queu();

    for (int i = 0; i < 5; i++)
    {
        player1_q->push(player1[i]);
        player1_q->push(player2[i]); 
    }
    
    while(cnt<=1e7)
    {
        int a = player1_q->front(), b = player2_q->front(); 
        player1_q->pop(), player2_q->pop(); 
        if(a==0 && b == 9)
        {
            player1_q->push(0);
            player1_q->push(9);
        }else if(a==9 && b==0)
        {
            player2_q->push(0);
            player2_q->push(9);
        }else{
            if(a>b)
            {
                player1_q->push(a);
                player1_q->push(b);
            }else{
                player2_q->push(a);
                player2_q->push(b);
            }
        }
        if(player1_q->size() == 0)
        {
            cout<<"second "<<cnt; 
            return 0; 
        }
        if(player2_q->size() == 0)
        {
            cout<<"first "<<cnt; 
            return 0; 
        }
        cnt++; 
    }
    
    cout<<"botva"; 

    return 0; 
}
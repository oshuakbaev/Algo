#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int n = 0;
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
        int n = 0;
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

    int pop(){
        if(n > 1){            
            int x = head->val;
            head = head->next;
            n--;
            return x;
        }
        else if (n == 1) {
          int x = head->val;
          head = NULL; tail = NULL;
          n--;
          return x;
        }
        else{
            cout << "error\n";
            return 0;
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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    queu *s = new queu();

    string statement;
    int number;


    while(cin >> statement){
        if(statement == "push"){
            cin >> number;
            s->push(number);
            cout << "ok" << endl;
        }

        else if(statement == "pop"){
            if(s->size() == 0){
                cout << "error" << endl;
            }
            else{
                cout << s->pop() << endl;
            }
        }



        else if(statement == "front"){
            if(s->size() == 0){
                cout << "error" << endl;
            }
            else{
                cout << s->front() << endl;
            }
        }



        else if(statement == "size"){
            cout << s ->size() << endl;
        }  

        else if(statement == "clear"){
            s->clear();
            cout << "ok" << endl;
        }

        else if(statement == "exit"){
            cout << "bye" << endl;
            break;
        }

    }


    return 0;
}
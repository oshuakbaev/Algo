#include <bits/stdc++.h>
using namespace std;

struct Node{
    string val;
    int n = 0;
    Node *prev;
    Node *next;
    Node (string x){
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
        void init(){
            head = NULL;
            tail = NULL;
        }
    
    void push(string x){
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

    string pop(){
        if(n > 1){            
            string x = head->val;
            head = head->next;
            n--;
            return x;
        }
        else if (n == 1) {
          string x = head->val;
          head = NULL; tail = NULL;
          n--;
          return x;
        }
        else{
            cout << "error\n";
            return 0;
        }
    }

    string front(){      
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
    //queu *s = new queu();
    vector<queu> a(3);
    for (int i = 0; i < 3; i++) {
      a[i].init(); 
    }
    int cl;
    while (cin >> cl) {
      string name; cin >> name;
      int c = cl - 9;
      a[c].push(name);
    }
    for (int i = 0; i < 3; i++) {
      while (a[i].size()) {
        cout << i + 9 << ' ';
        cout << a[i].pop() << '\n';
      }
    }
    return 0;
}
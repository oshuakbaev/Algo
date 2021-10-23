#include <iostream>

using namespace std; 

class st{
    private:
    int * a; 
    int TopIndex; 

    public:
        st(int n){
            a = new int[n]; 
            TopIndex = -1; 
        }
        int top(){
            if(TopIndex==-1 ) return -1; 
            return a[TopIndex]; 
        }
        void push(int x){
            TopIndex++; 
            a[TopIndex] = x;
        }
        void pop(){
            if(TopIndex!= -1){
                TopIndex--;
            }
        }
};


int main()
{

    int d[] = {4,55,5,53,6,75,5};

    int n = sizeof(d)/sizeof(d[0]);

    st s(n); 

    for (int i = 0; i < n; i++)
    {
        s.push(d[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout<<s.top()<<endl; 
        s.pop(); 
    }
    
    return 0; 
    


    return 0; 
}
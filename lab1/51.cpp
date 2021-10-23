#include <iostream>

using namespace std; 

struct Brackets{

    bool Left_bracket(char c)
    {
        return ('(' == c || '{' == c || '[' == c);
    }
    bool Fit(char lb , char rb)
    {
        return(('(' == lb && ')' == rb) || ('[' == lb && ']'==rb) || ('{' == lb && '{' == rb));
    }
}; 


struct st{
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
        void push(char x){
            TopIndex++; 
            a[TopIndex] = x;
        }
        void pop(){
            // if(TopIndex!= -1){
            //     TopIndex--;
            // }
            for (int i = 0; i < s.size()-1; i++)
            {
                
            }
            
        }
        int empty()
        {
            int size = sizeof(a)/sizeof(a[0]);
            return size; 
        }
};

int main()
{
    string s = "(}})"; 
    Brackets Brackets_s; 
    st st_s(s.size()); 
    for (int i = 0; i < s.size(); i++)
    {
        if(Brackets_s.Left_bracket(s[i]))    
        {
            st_s.push(s[i]); 
        }else if(Brackets_s.Fit(st_s.top(),s[i]))
        {
            st_s.pop(); 
        }else{
            st_s.push(s[i]); 
            break; 
        }
    }

    cout<<st_s.empty()<<endl;

    if(st_s.empty())
    {
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
    

    return 0; 
}
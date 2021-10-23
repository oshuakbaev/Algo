#include <iostream>
#include <stack>

using namespace std;


int main()
{
    string s; 
    stack<int> st; 

    while(cin>>s) 
    {
        if(s=="+"||s=="-"||s=="*")
        {
            int a,b; 
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();

            if(s=="+")
                st.push(a+b);
            if(s=="-")
                st.push(b-a);
            if(s=="*")
                st.push(a*b);
        }else{
            st.push(stoi(s));
        }
    }

    cout<<st.top();

    return 0; 
}
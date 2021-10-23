#include <iostream>
using namespace std; 

long long gcd(int a,int b)
{
    if(b==0)
    {
        return a; 
    }
    return gcd(b,a%b); 
}


long long gears(int a,int b)
{
    return (a/gcd(a,b))*b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;

    cout<<gears(a,b)<<endl;

    
    return 0;
}
#include <iostream> 

using namespace std; 

string isPrime(int prime)
{
    int i = 2; 
    string answer = "prime"; 
    while(i<=prime/2)
    {
        int rem = prime%i; 
        if(rem!=0){
            i+=1;
        }
        else{    
            answer = "composite"; 
            break;
        }
    }
    return answer; 
}

int main()
{
    int prime;
    cin>>prime;
    
    cout<<isPrime(prime)<<endl;
   
    return 0; 
}
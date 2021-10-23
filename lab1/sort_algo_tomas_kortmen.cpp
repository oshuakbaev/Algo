#include <iostream> 

using namespace std; 


int main()
{
    int A[6] = {31,41,59,26,41,58}; 
    int n = sizeof(A)/sizeof(A[0]); 
    // for (int j = 1 ; j < n; j++)
    // {
    //     int key = A[j]; 
    //     int i = j-1; 
    //     while(i>=0 and A[i]>key)
    //     {
    //         A[i+1] = A[i]; 
    //         i -= 1; 
    //     }
    //     A[i+1] = key; 
    // }
    
    for (int i = -1 ; i < n; i++)
    {
        int next = A[i+1];
        int prev = A[i];
        if(A[i]>A[i+1])
        {
            A[i+1] = A[i]; 
            A[i] = next; 
        }
    }

    
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" "; 
    }
    

    return 0; 
}
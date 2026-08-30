#include<bits/stdc++.h>
using namespace std;
void SieveOfEratosthenes(int n)
{
	bool answer[n+1];
    memset(answer,true,sizeof(answer));
    for(int i=2;i*i<=n;i++){
        if(answer[i]){
            for(int j=i*i;j<=n;j+=i){
                answer[j]=false;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(answer[i])
            cout<<i<<" ";
    }
}
int main()
{
	int n;
    cin>>n;
    if(n<=1)cout<<"There Is No Prime Number"<<"\n";
    else SieveOfEratosthenes(n);
	return 0;
}
// for checking prime or not a given number
// bool isPrime(int x)
// {
//     if (x <= 1)
//         return false;
 
//     for (int i = 2; i * i <= x; i++) {
//         if (x % i == 0)
 
//             // Return not prime
//             return false;
//     }
 
//     // If prime return true
//     return true;
// }
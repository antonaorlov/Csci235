#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Recursions make code shorter, cleaner
//it takes a lot of stack space
//uses more processor time
//dificult to debug


int factorial(int n){
    if(n>1){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}
int main(){
   int n, result=4;

    result = factorial(n);
    cout << "Factorial of " << n << " = " << result; // 24=4*3*2*1

}
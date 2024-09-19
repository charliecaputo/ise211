#include <iostream>

bool isPrime(int x){

    for (int i = 2; i < x; i++){
        if (x%i == 0){
            return false;
        }
    }
    return true;
}

int main (){
    int x = 3;
    bool prime = false;
    prime  = isPrime(x); 
    std::cout<<"the number is prime = "<<prime;

    return 0; 
}
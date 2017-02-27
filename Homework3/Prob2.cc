#include <iostream>

long int Factorial(int);

int main()
{
    
 int n;
 
 std::cout << "Please enter a positive integer number less than 20." << std:: endl;
 std::cin >> n;
 
 while(n > 20)
 {
 std::cout << "Please enter a positive integer number less than 20." << std:: endl;
 std::cin >> n;
 }
 
 std::cout << "The factorial of "<< n << " is: " << Factorial(n);
 
 return 0;
 
}

long int Factorial(int n)
{
    
 int i;
 long int factorial = 1;
 
 for(int i = n; i >0; i--)
 {
    factorial = factorial * i;
 }   
 return factorial;
}

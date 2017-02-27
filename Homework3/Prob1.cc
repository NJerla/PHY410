#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>

int main()
{
    
 float xi=0.,yi=0.; 
 float x_min = 0;
 float y_min = 0;
 float magnitude;
 float minimum_magnitude = FLT_MAX;
 
 std::cout << "Please enter a sequence of numbers followed by a space to make a set of vectors. Input has form x1 y1 x2 y2 ect.... List will terminate when first non-number is entered." << std::endl;

 while( std::cin >> xi >> yi )
    {    
        
    magnitude = sqrt( (xi*xi) + (yi*yi) );
      
     if(minimum_magnitude >= magnitude)
     {
        minimum_magnitude = magnitude;
        x_min = xi;
        y_min = yi;
     }
     
    }
    
    std::cout << x_min << "," << y_min << " The minimum magnitude of our set of vectors is: " << minimum_magnitude <<  std::endl;
    
    return 0;
}

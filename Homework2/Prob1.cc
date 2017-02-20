#include <iostream>

int main(void)
{

  float x1, y1, x2, y2;
  float midpoint;
  float midpointXval;
  float midpointYval;
  float slope;
  float yintercept;
  float perpslope;
  float perpyintercept;

  std::cout << "Please enter first (x1,y1) coordinates followed by the coordinates (x2,y2) of the second point." << std::endl;

  std::cin >> x1;
  std::cin >> y1;
  std::cin >> x2;
  std::cin >> y2;
  
    midpointXval = (x1 + x2)/2;
    midpointYval = (y1 + y2)/2;
    slope = (y2 - y1)/(x2 - x1);
    yintercept = (y1 - slope*x1);
    perpslope = (-1)* ((x2 - x1)/(y2 - y1));
    perpyintercept = (y1 - perpslope*x1);

   if(x1 == x2)
      {
	std::cout << "Your two points were (x1,y1) = " << "(" << x1 << "," << y1 << ") and (x2,y2) = " << "(" << x2 << "," << y2 << ")."  << std::endl;
	std::cout << "The midpoint of your two points are (x,y) = " << "(" << midpointXval << "," << midpointYval  << ")" << " but you were naughty and divided "
	" by zero. Your slope is infinite with no y-intercept!! The equation of your line is x = " << x1 << " with a line perpendicular to the first point being y = " << y1 << std::endl;
      }
   else
      {
	std::cout << "Your two points were (x1,y1) = " << "(" << x1 << "," << y1 << ") and (x2,y2) = " << "(" << x2 << "," << y2 << ")."  << std::endl;
	std::cout << "The midpoint of your two points are (x,y) = " << "(" << midpointXval << "," << midpointYval  << ")" << " with a slope of m = " << slope << " and a y-intercept of b = "
	   << yintercept << "." << " The equation of your line is y = " << slope << "x + " << yintercept << ". Equation of line perpendicular to first point entered is y = "
	   << perpslope << "x + " << perpyintercept << "." <<  std::endl;
      }
 
  return 0;
}

#include <iostream>
#include <cmath>
#include <limits>

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

 if(std::abs(x1-x2) < 0.000001)
      {
	midpointXval = (x1 + x2)/2;
	midpointYval = (y1 + y2)/2;
	std::cout << "Your two points were (x1,y1) = " << "(" << x1 << "," << y1 << ") and (x2,y2) = " << "(" << x2 << "," << y2 << ")."  << std::endl;
	std::cout << "The midpoint of your two points are (x,y) = " << "(" << midpointXval << "," << midpointYval  << ")" << " but you were naughty and divided "
	" by zero. Your slope is infinite with no y-intercept!! The equation of your line is x = " << x1 << " with a line perpendicular to the first point being y = " << y1 << std::endl;
      }
 else
      {
	midpointXval = (x1 + x2)/2;
	midpointYval = (y1 + y2)/2;
	slope = (y2 - y1)/(x2 - x1);
	yintercept = (y1 - slope*x1);
	std::cout << "Your two points were (x1,y1) = " << "(" << x1 << "," << y1 << ") and (x2,y2) = " << "(" << x2 << "," << y2 << ")."  << std::endl;
	std::cout << "The midpoint of your two points are (x,y) = " << "(" << midpointXval << "," << midpointYval  << ")" << " with a slope of m = " << slope << " and a y-intercept of b = "
		  << yintercept << "." << " The equation of your line is y = " << slope << "x + " << yintercept << std::endl;
	if(std::abs(y1-y2) < 0.000001)
	  {
	    std::cout << "The line perpendicular to your origional one has a infinite slope, Naughty!!! The eqation of the line passing through your first point is of the form x = " << y1 << std::endl;
	  }
	else
	  {
	    perpslope = (-1)* ((x2 - x1)/(y2 - y1));
	    perpyintercept = (y1 - perpslope*x1);
	    std::cout << " Equation of line perpendicular to first point entered is y = " << perpslope << "x + " << perpyintercept << "." <<  std::endl;
	  }
      }
 
  return 0;
}

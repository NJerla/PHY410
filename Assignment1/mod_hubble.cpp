#include <cmath>
#include <iostream>
using namespace std;

const int n = 9;   // number of groups determined from Table 1                                                                                                                                                                                                                                                             

double r[n] = {     // distances in Mpc                                                                                                                                                                                                                                                                                    
  0.033, 0.214, 0.271, 0.576, 0.9, 0.9, 0.95, 1.2, 1.94
};

double v[n] = {     // velocities in km/s                                                                                                                                                                                                                                                                                  
  +230,-130, -158.33, +252, -30, +400, +710, +483.3, +840
};

int main() {

  // declare and initialize various sums to be computed                                                                                                                                                                                                                                                                    
  double s_x = 0, s_y = 0, s_xx = 0, s_xy = 0;

  if ( n < 2 ) {
    cout << "Error! Need at least two data points!" << endl;
    return 0;
  }

  // compute the sums                                                                                                                                                                                                                                                                                                      
  for (int i = 0; i < n; i++) {
    s_x += r[i];
    s_y += v[i];
    s_xx += r[i] * r[i];
    s_xy += r[i] * v[i];
  }

  cout << s_x << " " << s_y << " " << s_xx << " " << s_xy << endl;

  // evaluate least-squares fit forumlas                                                                                                                                                                                                                                                                                   
  double denom = n * s_xx - s_x * s_x;

  if ( fabs(denom) < 0.000001 ) {
    cout << "Error! Denominator is zero!" << endl;
    return 0;
  }

  double a = (s_xx * s_y - s_x * s_xy) / denom;
  double b = (n * s_xy - s_x * s_y) / denom;

  cout << denom << " " << a << " " << b << endl;

  // estimate the variance in the data set                                                                                                                                                                                                                                                                                 
  double sum = 0;
  for (int i = 0; i < n; i++) {
    double v_of_r_i = a + b * r[i];
    double error = v[i] - v_of_r_i;
    sum += error * error;
  }

  double sigma = (n > 2) ? sqrt(sum / (n - 2)) : 0;    // estimate of error bar in v                                                                                                                                                                                                                                        
  // estimate errors in a and b                                                                                                                                                                                                                                                                                            
  double sigma_a = sqrt(sigma * sigma * s_xx / denom);
  double sigma_b = sqrt(sigma * sigma * n / denom);

  // print results                                                                                                                                                  
  cout.precision(4);
  cout << " Least-squares fit of " << n << " data points (groups of galaxies)\n"
       << " -----------------------------------\n"
       << " Hubble's constant slope   b  =  " << b
       << " +- " << sigma_b << " km/s/Mpc\n"
       << " Intercept with r axis     a  =  " << a
       << " +- " << sigma_a << " km/s\n"
       << " Estimated v error bar sigma  =  " << sigma << " km/s" << endl;
}

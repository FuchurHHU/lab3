#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

complex<double> tan_func(double phi);

int main(){
  
  ofstream out("lab3_1b_output.dat");
  
  int N = 100;
  double phi[N];
  
  complex<double> z[N];

  for (int i=0; i < N; i++){
  
    phi[i] = (i*2*M_PI)/(N-1) - M_PI; 
    
    z[i] = tan_func(phi[i]);
  }
  // Example how to declare a single complex variable:
  
  for (int i=0; i < N; i++){
  
    out << phi[i] << "\t" << real(z[i]) << "\t" << imag(z[i]) << "\t" << abs(z[i]) << endl;
  }
  
  out.close();
  
  
  
  return 0;
}

complex<double> tan_func(double phi){

  complex<double> ii = complex<double> (0.0,1.0); 
  complex<double> z = tan(phi*(1.0+ii));
  return z;
}
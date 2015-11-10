#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
  
  ofstream out("lab3_1a_output.dat");
  
  int N = 100;
  double phi[N];
  
  complex<double> ii = complex<double> (0.0,1.0);
  complex<double> f[N];

  for (int i=0; i < N; i++){
  
    phi[i] = (i*2*M_PI)/(N-1); 
    
    f[i] = exp(phi[i]*ii);
  }
  // Example how to declare a single complex variable:
  
  for (int i=0; i < N; i++){
  
    out << phi[i] << "\t" << real(f[i]) << "\t" << imag(f[i]) << "\t" << abs(f[i]) << endl;
  }
  
  out.close();
  
  
  
  return 0;
}

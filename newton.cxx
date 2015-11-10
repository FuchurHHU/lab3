#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

int iteration(complex<double> z);

int main(){

  int N = 100;
  
  complex<double> z0[N];
  int N_it;
  
  for (double re = -2.0 ; re <= 2 ; re+=0.01 ){
    for (double im = -2.0 ; im <= 2 ; im+=0.01 ){
     complex<double> zo = complex<double> (re,im);
     N_it = iteration(zo);
     cout << real(zo) <<"\t" <<imag(zo) <<"\t" <<N_it << endl;
      
    }
      
    
  }
  
  

  return 0;
}


int iteration(complex<double> z){
  
  double eps = 1e-8;
  int Nmax = 400;
  double diff_initial = eps + 1.0;
  double diff = diff_initial;
  int N_it = 0;
 
  while ( N_it <=Nmax && diff > eps){
	complex<double> z1 = z - (z*z*z - 1.0)/(3.0 * z*z);
	
	N_it++;
	diff = abs(z1 -z);
	z = z1;
  }
  
  
  return N_it;
}
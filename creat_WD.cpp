#include<iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <array>
#include <math.h>
#define M_PI 3.1415926
using namespace std;
class white_dwarf{
  private:
    int N; //number of bins
    array<double,N> rho_array;
    array<double,N> pres_array;
    const double Radius;
    const double Mass;
    // inital physical consts radius and total mass
    double length_cof;
    double density_cof;
    double pres_cof;
    double vel_cof;
    double dr;
  public:
    white_dwarf(const Gamma=5.0/3,Radius=,Mass=){
      const double n=1.0/(Gamma-1);
      array<double,N> ksi;
      const double alpha=sqrt((n+1)/4/M_PI);
      const double dksi=3.5/M;
      dr=dksi*alpha;
      for(int i=0;i<N;i++)
        ksi[i]=i*dksi;
      rho_array[0]=1.0;
      rho_array[1]=1.0;
      for(i=2;i<N;i++){
        rho_array[i]=(-pow(rho_array[i-1],n)-(rho_array[i-2]-2*rho_array[i-1])/dksi/dksi+rho_array[i-2]/ksi[i-1]/dksi)/(1.0/dksi/dksi+1.0/(dksi*ksi[i-1]));
        if(rho_array[i]<=0)
          rho_array[i]=0;
      }
      for(i=0;i<N;i++){
          rho_array[i]=pow(rho_array[i],n);
          pres_array=pow(rho,Gamma);
      }  
      double mass_sum=0;
      for(int i=0;i<N;i++){
        mass_sum+=4*M_PI*r*r*rho_array[i]*dr*pow(length_cof,3);
      }
      dens_cof=Mass/mass_sum;
      pres_cof=;
      vel_cof=sqrt(pres_cof/dens_cof);
    }
}

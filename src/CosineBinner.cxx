/** @file CosineBinner.cxx
@brief Define the CosineBinner class 

@author T. Burnett

$Header: /nfs/slac/g/glast/ground/cvs/ScienceTools-scons/healpix/src/CosineBinner.cxx,v 1.7 2012/02/11 01:14:27 gudlaugu Exp $
*/


#include "healpix/CosineBinner.h"
#include <cmath>
#include <stdexcept>

namespace{
    const double pi4( M_PI/4.0), pi2(M_PI/2.);

}
using namespace healpix;

double CosineBinner::s_cosmin=0.0;
size_t CosineBinner::s_nbins=40;  /// the number of bins for each cosine range
bool   CosineBinner::s_sqrt_weight=true;
size_t CosineBinner::s_phibins=0;

auto CosineBinner::nphibins() -> size_t{return s_phibins;}
void   CosineBinner::setPhiBins(size_t n){s_phibins=n;}
auto CosineBinner::cosmin() -> double { return s_cosmin;}
auto CosineBinner::nbins() -> size_t {return s_nbins;}

auto CosineBinner::cosine_index(double costheta) -> size_t
{
    double f ( (1.-costheta)/(1-s_cosmin) );
    if(s_sqrt_weight) f=sqrt(f);
    return static_cast<size_t>(f*s_nbins);
}
auto CosineBinner::folded_phi(double phi) -> double
{
    if( phi<0) phi+= 2*M_PI;
    return  1.- fabs(pi4-fmod(phi, pi2) )/pi4 ;
}
auto CosineBinner::phi_index(double phi) -> size_t
{
    return static_cast<size_t>(folded_phi(phi)*s_phibins);
}

//----------------------- Instance functions ------------------------------
CosineBinner::CosineBinner()
{
    resize(s_phibins==0? s_nbins: s_nbins*(1+s_phibins) );
}

/// the binning function: add value to the selected bin
void CosineBinner::fill(double costheta, double value)
{
    if( costheta<=s_cosmin ) return;
    (*this)[costheta] += value;
}
/// the binning function: add value to the selected bin
auto CosineBinner::fill(double costheta, double phi, double value) -> size_t
{
    if( costheta<=s_cosmin ) return std::string::npos;
    size_t ci ( cosine_index(costheta) );
    if (ci >= s_nbins) {
       ci = s_nbins - 1;
    }
    this->at(ci)+= value;
    // get the phi index and index into the array
    size_t pi ( ( phi_index(phi)+1) * s_nbins + ci ) ;
    this->at(pi) += value;
    return pi;
}

auto CosineBinner::operator[](double costheta) -> float&
{
    double f = (1.-costheta)/(1-s_cosmin);
    if(s_sqrt_weight) f=sqrt(f);
    size_type i=static_cast<int>(f*s_nbins); 
    if( i>= s_nbins){
        i=s_nbins-1;
    }
    return at(i);
}

auto CosineBinner::operator[](double costheta)const -> const float&
{
    double f = (1.-costheta)/(1-s_cosmin);
    if(s_sqrt_weight) f=sqrt(f);
    return at( static_cast<int>(static_cast<int>(f*s_nbins)));
}


auto CosineBinner::operator()(double costheta, double phi)const -> const float&
{
    double f = (1.-costheta)/(1-s_cosmin);
    if(s_sqrt_weight) f=sqrt(f);
    int k( static_cast<int>(static_cast<int>(f*s_nbins)));
    if( phi<0) return at(k); 
    int n ( phi_index(phi) );
    return at((k+1)*nphibins()+n);
}

/// cos(theta) for the iterator
auto CosineBinner::costheta(std::vector<float>::const_iterator i)const -> double
{
    int bin = (i-begin()) % nbins();
    double f = (bin+0.5)/s_nbins;
    if( s_sqrt_weight) f=f*f;
    return 1. - f*(1-s_cosmin); 
}

/// phi for the iterator: note only 0-pi/4 (0-45 degrees)
auto CosineBinner::phi(std::vector<float>::const_iterator i) const -> double
{
    if( nphibins() ==0){
        throw std::runtime_error("CosineBinner::phi: request for phi value, but phi not set up");
    }
    size_t check = i-begin(); // should be greater than nbins()
    size_t bin( check/nbins() -1  ); // subtract off the costheta part
    double f( (bin+0.5)/ nphibins() );

    return M_PI/4. * f;
}


auto CosineBinner::thetaBinning() -> std::string{ 
    if( s_sqrt_weight) {
        return "SQRT(1-COSTHETA)";
    }else{
        return "COSTHETA";
    }
}

void CosineBinner::setBinning(double cosmin, size_t nbins, bool sqrt_weight)
{
    s_cosmin=cosmin, s_nbins=nbins, s_sqrt_weight=sqrt_weight;
}


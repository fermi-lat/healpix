/** @file CosineBinner.cxx
@brief Define the CosineBinner class 

@author T. Burnett

$Header: /nfs/slac/g/glast/ground/cvs/healpix/src/CosineBinner.cxx,v 1.1 2007/11/23 01:30:27 burnett Exp $
*/


#include "healpix/CosineBinner.h"
#include <cmath>
using namespace healpix;

double CosineBinner::s_cosmin=0.0;
size_t CosineBinner::s_nbins=40;
bool   CosineBinner::s_sqrt_weight=true;

CosineBinner::CosineBinner()
{
    resize(s_nbins);
}

/// the binning function: add value to the selected bin
void CosineBinner::fill(double costheta, double value)
{
    if( costheta<=s_cosmin ) return;
    (*this)[costheta] += value;
}

float& CosineBinner::operator[](double costheta)
{
    double f = (1.-costheta)/(1-s_cosmin);
    if(s_sqrt_weight) f=sqrt(f);
    size_type i=static_cast<int>(f*s_nbins); 
    if( i>= s_nbins){
        i=s_nbins-1;
    }
    return at(i);
}
const float& CosineBinner::operator[](double costheta)const
{
    double f = (1.-costheta)/(1-s_cosmin);
    if(s_sqrt_weight) f=sqrt(f);
    return at( static_cast<int>(static_cast<int>(f*s_nbins)));
}
/// cos(theta) for the iterator
double CosineBinner::costheta(std::vector<float>::const_iterator i)const
{
    int bin = i-begin();
    double f = (bin+0.5)/s_nbins;
    if( s_sqrt_weight) f=f*f;
    return 1. - f*(1-s_cosmin); 
}

std::string CosineBinner::thetaBinning(){ 
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

double CosineBinner::cosmin() { return s_cosmin;}
size_t CosineBinner::nbins() {return s_nbins;}

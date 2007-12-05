/** @file Map.h
@brief Wrapper for the JPL healpix class of a sky map, including Optimal Filters for the sphere

@author M. Roth 

$Header: /nfs/slac/g/glast/ground/cvs/healpix/healpix/Map.h,v 1.6 2007/11/21 16:44:35 burnett Exp $
*/
#include <string>
#include <vector>
#include "src/base/healpix_map.h"
#include "astro/SkyFunction.h"
#include "healpix/HealPixel.h"


namespace healpix {

    template<typename T> class Map : public astro::SkyFunction {
        /**
        @class Map<T>
        @brief Encapsulates the healpix C++ class Healpix_Map, a map data array
        see "healpix_map.h" for more information on methods

        The fits file needs to be in a healpix_map format (fits format can be generated from ROOT files with Convolution package)

        Usage:
        @verbatim

        Map<double> map("map.fits",level);
        map.mfcn(lmax);  //applies a matched filter to the data

        @endverbatim

        */	
    public:
        /**@brief constructor takes healpix fits filename and bin level (level = 12*2**nside)
        @param file  FITS file location   "X:\\folder\\folder\\file.fits"
        @param level  binning level defined by energy binner from map_tools package
        */
        Map<T>(const std::string &file, int level);

        /**@brief constructor with empty map and a bin level
        @param level  binning level defined by energy binner from photon_data package
        */
        Map<T>(int level);

        /**@brief returns a reference to the Healpix map
        */
        Healpix_Map< T>* map();

        Healpix_Map< T> cmap() const { return m_hm;}

        /**@brief applies a matched filter . The filter kernel is derived from a 
        fits file "LHOOD.fits"
        @param psffile  FITS file location   "X:\\folder\\folder\\file.fits"
        @param lmax  maximum multipole moment
        */
        void mfcn(const std::string &psffile,int lmax);

        /**@brief applies a matched filter with assumed shape of photon likelihood
        @param lmax  maximum multipole moment
        */
        void mfcn(int lmax);

        /**@brief applies a matched filter with a varied background
        @param noise  file of noise
        @param lmax  maximum multipole moment
        */
        void mfvn(const std::string &noise, int lmax);

        /**@brief writes a FITS file out in the HEALpix convention
        @param out  FITS file location   "X:\\folder\\folder\\file.fits"
        */
        void writemap(std::string &out);

        double operator()(const astro::SkyDir & sd) const{ return m_hm[m_hm.nest2ring(healpix::HealPixel(sd,m_hm.Order()).index())];}

    private:
        double m_factor;              //binning factors: E = s_minenergy*m_factor**(level-s_minlevel)
	Healpix_Map< T> m_hm; //wrapped HEALpix package map object
        static const int s_minlevel = 6;
        static const int s_minenergy = 100;
    };

} //namespace

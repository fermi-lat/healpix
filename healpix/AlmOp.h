/** @file AlmOp.h
@brief Wrapper for the JPL healpix class of spherical harmonics, with the addition of operators required for filtering

@author M. Roth 

$Header: /nfs/slac/g/glast/ground/cvs/users/echarles/healpix_changes/healpix/healpix/AlmOp.h,v 1.4 2015/03/05 19:58:38 echarles Exp $
*/

// EAC, update include path
#include "alm.h"

namespace healpix {

    template<typename T> class AlmOp  {
        /**
        @class AlmOp<T>
        @brief Encapsulates the healpix C++ class Alm, a spherical harmonics data array
        see "alm.h" for more information on methods

        Usage: global methods defined in alm_powspec_tools/alm_map_tools/alm_filter_tools
        are the only necessary reasons for having this class
        @verbatim

        AlmOp<double> al(lmax,mmax);
        Map<double> map(level);
        map2alm_iter(map.map(),al.Alms(),0);

        @endverbatim

        The spherical harmonic coefficients of map will then be stored in 'al'

        */

    public:
        /**@brief default constructor
        */
        AlmOp<T>();

        /**@brief constructor
        @param lmax  maximum multipole moment
        @param mmax  maximum order
        */
        AlmOp<T>(int lmax,int mmax);

        /**@brief returns a reference to the embedded spherical harmonics class (for normal function calls)
        */
        auto Alms() -> Alm<T>*;

        /**@brief multiplies the corresponding elements of two equal-dimensioned Spherical Harmonic objects
        */
        auto operator*(AlmOp<T> x) -> AlmOp<T>;

        /**@brief adds the corresponding elements of two equal-dimensioned Spherical Harmonic objects
        */
        auto operator+(AlmOp<T> x) -> AlmOp<T>;

        /**@brief returns the conjugate of a spherical harmonic object
        */
        auto conjugate() -> AlmOp<T>;

    private:
        Alm<T> m_alm; //HEALpix library spherical harmonic object
    };

} //namespace

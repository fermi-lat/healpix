# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.12 2009/01/27 04:31:02 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-02-01

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

progEnv.Tool('healpixLib')
libEnv.Tool('healpixLib', depsOnly = 1)
progEnv.Tool('registerObjects', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h','src/base/*.h']),
      libraries = [libEnv.SharedLibrary('healpix', 
                    listFiles(['src/*.cxx', 'src/base/*.cc', 'src/base/*.c']))],
      testApps = [progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))],
      )
	      

# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.11 2009/01/22 22:31:44 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-02-00

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
	      

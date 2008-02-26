# @file SConscript
# @brief build info for package healpix
#
#$Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.6 2008/02/26 03:27:53 glastrm Exp $

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('healpixLib', depsOnly = 1)
progEnv.Tool('registerObjects', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h']),
      libraries = [libEnv.SharedLibrary('healpix', 
                    listFiles(['src/*.cxx', 'src/base/*.cc', 'src/base/*.c']))],
      testApps = [progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))],
      )
	      
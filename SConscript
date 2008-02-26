# @file SConscript
# @brief build info for package healpix
#
#$Header: /nfs/slac/g/glast/ground/cvs/ScienceTools-scons/healpix/SConscript,v 1.5 2008/02/23 00:29:19 burnett Exp $

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('healpixlib', depsOnly = 1)
progEnv.Tool('registerObjects', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h']),
      libraries = [libEnv.SharedLibrary('healpix', 
                    listFiles(['src/*.cxx', 'src/base/*.cc', 'src/base/*.c']))],
      testApps = [progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))],
      )
	      
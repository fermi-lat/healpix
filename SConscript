# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/ScienceTools-scons/healpix/SConscript,v 1.17 2009/07/15 18:36:03 glastrm Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-02-04

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

progEnv.Tool('healpixLib')
libEnv.Tool('healpixLib', depsOnly = 1)

healpixLib = libEnv.SharedLibrary('healpix', 
                                  listFiles(['src/*.cxx', 'src/base/*.cc',
                                             'src/base/*.c']))
test_healpix = progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))

progEnv.Tool('registerTargets', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h','src/base/*.h']),
      libraryCxts = [[healpixLib, libEnv]],
      testAppCxts = [[test_healpix, progEnv]]
      )


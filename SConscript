# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.27 2010/07/29 16:52:57 burnett Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-03-05

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='healpix', toBuild='shared')
progEnv.Tool('healpixLib')

healpixLib = libEnv.SharedLibrary('healpix', 
                                  listFiles(['src/*.cxx', 'src/base/*.cc',
                                             'src/base/*.c']))
test_healpix = progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))

progEnv.Tool('registerTargets', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h','healpix/base/*.h']),
      libraryCxts = [[healpixLib, libEnv]],
      testAppCxts = [[test_healpix, progEnv]]
      )


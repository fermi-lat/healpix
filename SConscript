# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.26 2010/02/24 20:17:09 jrb Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-03-04

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


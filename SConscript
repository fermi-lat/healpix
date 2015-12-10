# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.32 2015/12/04 18:41:10 echarles Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-05-01

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='healpix', toBuild='shared')

# EAC: switch to using healpix as an external, so remove healpix/base stuff
healpixLib = libEnv.SharedLibrary('healpix', 
                                  listFiles(['src/*.cxx']))

# EAC: add dependence on healpix externals
progEnv.Tool('healpixLib')
test_healpix = progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))

# EAC: switch to using healpix as an external, so remove healpix/base stuff
progEnv.Tool('registerTargets', 
      package = 'healpix', 
      includes = listFiles(['healpix/*.h']),
      libraryCxts = [[healpixLib, libEnv]],
      testAppCxts = [[test_healpix, progEnv]]
      )


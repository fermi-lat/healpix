# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/users/echarles/healpix_changes/healpix/SConscript,v 1.4 2015/03/05 19:58:37 echarles Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>
# Version: healpix-02-03-06

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


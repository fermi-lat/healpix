# -*- python -*-
# @file SConscript
# @brief build info for package healpix
#
# $Header: /nfs/slac/g/glast/ground/cvs/healpix/SConscript,v 1.35 2017/03/29 18:42:50 heather Exp $
# Authors: T. Burnett <tburnett@u.washington.edu>, E. Charles <echarles@slac.stanford.edu>
# Version: healpix-02-05-03

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='healpix', toBuild='shared')
libEnv.Append(CPPDEFINES = "_GLIBCXX_USE_CXX11_ABI=0")

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


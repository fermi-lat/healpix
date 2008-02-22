#$Id: SConscript,v 1.3 2008/02/20 19:18:41 burnett Exp $

Import('baseEnv')
Import('listFiles')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

if libEnv['PLATFORM'] == "win32":
	libEnv.AppendUnique(CPPFLAGS = "/wd4068")
	if libEnv['MSVS_VERSION'] == "8.0":
		libEnv.AppendUnique(CPPFLAGS = "/wd4812")

healpixSharedLib = libEnv.SharedLibrary('healpix', listFiles(['src/*.cxx', 'src/base/*.cc', 'src/base/*.c']))
# note that this only builds a shared library -- no need to also build a static library
progEnv.Tool('healpixLib')
test_healpix = progEnv.Program('test_healpix', listFiles(['src/test/*.cxx']))

progEnv.Tool('registerObjects', 
              package = 'healpix', 
              libraries = [healpixSharedLib],
              testApps = [test_healpix],
	      includes = listFiles(['healpix/*.h']))
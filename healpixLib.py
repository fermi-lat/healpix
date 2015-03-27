#$Id: healpixLib.py,v 1.4 2015/03/05 19:58:37 echarles Exp $
def generate(env, **kw):
    if not kw.get('depsOnly',0):
        env.Tool('addLibrary', library = ['healpix'])
    # EAC, add dependece on externals
    env.Tool('addLibrary', library=env['healpixlibs'])  
    env.Tool('astroLib')
    
def exists(env):
    return 1;

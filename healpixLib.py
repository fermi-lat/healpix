#$Id: healpixLib.py,v 1.2 2008/02/20 17:07:39 golpa Exp $
def generate(env, **kw):
    if not kw.get('depsOnly',0):
        env.Tool('addLibrary', library = ['healpix'])
    env.Tool('astroLib')
    
def exists(env):
    return 1;

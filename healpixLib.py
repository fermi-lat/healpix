#$Id: healpixLib.py,v 1.1 2008/02/16 02:37:35 golpa Exp $
def generate(env, **kw):
    env.Tool('addLibrary', library = ['healpix'])
    env.Tool('astroLib')
    
def exists(env):
    return 1;

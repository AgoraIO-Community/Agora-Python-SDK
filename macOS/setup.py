from distutils.core import setup
from Cython.Build import cythonize
from Cython.Distutils import Extension
import os
os.environ['LDFLAGS'] = "-framework AVFoundation -framework CoreWLAN -framework AppKit"
os.environ['CFLAGS'] = "-mmacosx-version-min=10.7 -std=c++11 --stdlib=libc++"
setup(ext_modules=cythonize(Extension(
    'IAgoraRtcEngine',
    ['IAgoraRtcEngine_pyx.pyx'],
    libraries=['AgoraRtcEngineKit'],
    library_dirs=['./lib'],
    include_dirs=['./include']
)))
'''
export CFLAGS="-mmacosx-version-min=10.7 -std=c++11 --stdlib=libc++"
'''
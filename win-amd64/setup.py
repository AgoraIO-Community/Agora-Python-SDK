from distutils.core import setup
from Cython.Build import cythonize
from Cython.Distutils import Extension


setup(ext_modules=cythonize(Extension(
    'IAgoraRtcEngine',
    ['IAgoraRtcEngine_pyx.pyx'],
    libraries=['agora_rtc_sdk'],
    library_dirs=['./lib'],
    include_dirs=['./include']
)))
'''
setup(ext_modules=cythonize(Extension(
    'vector',
    ['vector_pyx.pyx'],
    libraries=['vector'],
    library_dirs=['.'],
    include_dirs=['.']
)))
'''
# Convert Agora C++ API to Python API on macOS
Wrap Agora C++ API to Python API based on Cython and libclang on macOS platform.

## Requirements
- OS X 10.5 or higher
- Python 2.7 or 3.6

## Download
Download Clang 3.7 from [here](http://releases.llvm.org/download.html) and put `libclang.dylib` to the root directory.

## Install Python Packages
```bash
pip install Cython clang==3.7
```

## Generate Cython Codes
Firstly, to generate Cython codes from `IAgoraRtcEngine.h`, run
```bash
python C2py.py --head_path='include/IAgoraRtcEngine.h' --callback_wrapper='EventHandlerWrapper.h' --target_file_name='IAgoraRtcEngine'  --mode='new'
```
Then, to add Cython codes from `IAgoraMediaEngine.h`, run
```bash
python C2py.py --head_path='include/IAgoraMediaEngine.h' --callback_wrapper='VideoFrameObserverWrapper.h' --target_file_name='IAgoraRtcEngine'  --mode='add'  --extern_pxd='extern_pxd.txt'  --extern_pyx='extern_pyx.txt'
```
After running the above two commands, two files are generated: `IAgoraRtcEngine.pxd` and `IAgoraRtcEngine_pyx.pyx`. At this stage, the Cython codes can be compiled successfully. However, to make the extension work perfectly for Agora API, some neccessary modifications should be made based on `modify.txt`. There are still some other trivial changes needed, please consult the author of this project. The `IAgoraRtcEngine.pxd` and `IAgoraRtcEngine_pyx.pyx` files which have been modified are provided here.

## Build Python Extension
Run:
```bash
python setup.py build_ext  --inplace 
```
This will generate Python extension `.so`. 
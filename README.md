# pcl_mex
Example of using the [pcl library](http://pointclouds.org/) inside matlab via mex.

# Building
## Linux
**Tested under Archlinux**
### Inside Matlab
```matlab
mex -v pcl_transform.cpp pcl_mex_conversions.cpp ...
    -L/usr/lib/ ...
    -lpcl_common ...
    -I/usr/include/pcl-1.8/pcl/ ...
    -I/usr/include/pcl-1.8/ ...
    -I/usr/include/eigen3/ ...
    -I/usr/include/
```
**NOTE:** the matlab startup script modifies `LD_LIBRAY_PATH` which leads to an
old version of glibc being used. This can be circumvented with **ONE** of the 
following measures:

1. (using bash) run matlab with:
 `LD_PRELOAD="/usr/lib/libstdc++.so.6" matlab`
2. symlink library in `$MATLABROOT/TODO` to the system library

## Windows
**Tested under Win10**

Download and install the 
[PCL 1.6.0 All-in-on installer](http://pointclouds.org/downloads/windows.html), 
which includes the pcl libraries and all needed dependencies.

### Inside Matlab
```matlab
mex -v pcl_transform.cpp pcl_mex_conversions.cpp ...
    -L"C:\Program Files\PCL 1.6.0\lib" ...
    -lpcl_common_release ...
    -I"C:\Program Files\PCL 1.6.0\include\pcl-1.6" ...
    -I"C:\Program Files\PCL 1.6.0\include\pcl-1.6\pcl" ...
    -I"C:\Program Files\PCL 1.6.0\3rdParty\Eigen\include" ...
    -I"C:\Program Files\PCL 1.6.0\3rdParty\Boost\include"
```
### Visual Studio
- open the solution file pcl_mex_visual_studio/pcl_mex_visual_studio.sln 
- the path to Matlab/PCL can be adjusted in the `Property Manager` -> `matlab`/`pcl` -> `User Macros` 
- alternatively you can edit the files `pcl.props` and `matlab.props` directly
- a post build step will copy the built mex file to pcl_mex_visual_studio/../pcl_mex_transform.mexw64

# Usage 
See `pcl.m` for examples.

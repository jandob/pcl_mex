%% Compile the pcl interface to mex file
mex -v pcl_transform.cpp pcl_mex_conversions.cpp ...
    -L/usr/lib/ -lpcl_common ...
    -I/usr/include/pcl-1.8/pcl/ ...
    -I/usr/include/pcl-1.8/ ...
    -I/usr/include/eigen3/ ...
    -I/usr/include/ ...
% NOTE: the matlab startup script modifies LD_LIBRAY_PATH which leads to an
% old version of glibc being used and leads to errors in linking process.
% This can be circumvented with the following measures:
% 1. (using bash) matlab needs to be run with:
%  LD_PRELOAD="/usr/lib/libstdc++.so.6" matlab
% 2. symlink libraries in $MATLABROOT/TODO to system libraries

%% run the mex file
cloud = [1 0 0; 2 0 0; 3 0 0; 4 0 0; 5 0 0];
theta = pi/2;
rotAroundX = [cos(theta)  sin(theta)  0 0;
              -sin(theta) cos(theta)  0 0;
              0           0           1 0;
              0           0           0 1];

cloud_rotated = pcl_transform(cloud, rotAroundX)
%pcshow(cloud); %TODO not working with LD_PRELOAD

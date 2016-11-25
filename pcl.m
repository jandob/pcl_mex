%% run the mex file
cloud = zeros(5/0.1 + 1, 3);
cloud(:,1) = 0:0.1:5;
theta = -pi/2;
rotAroundX = [cos(theta)  sin(theta)  0 0;
              -sin(theta) cos(theta)  0 0;
              0           0           1 0;
              0           0           0 1];

cloud_rotated = pcl_transform(cloud, rotAroundX);

pcshow([cloud; cloud_rotated], 'MarkerSize', 100); %TODO not working with LD_PRELOAD

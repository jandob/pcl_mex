#pragma once

void mxArrayToPointCloud(const mxArray *mxIn,
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

mxArray* pointCloudToMxArray(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

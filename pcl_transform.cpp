// c system headers
#include <point_cloud.h>
#include <pcl/common/transforms.h>
#include <Eigen/Core>

// cpp system headers
#include <iostream>

// other headers
#include "mex.h"
#include "./pcl_mex_conversions.h"


/* The gateway function */
void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[]) {
    double *inMatrix;               /* Mx3 input matrix */
    double *inTransform;               /* 4x4 transform matrix */
    double *outMatrix;              /* output matrix */

    /* check for proper number of arguments */
    if (nrhs != 2) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nrhs", "Two inputs required.");
    }
    if (nlhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:nlhs", "One output required.");
    }

    /* make sure the second input argument is type double */
    if ( !mxIsDouble(prhs[1]) ||
         mxIsComplex(prhs[1])) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notDouble", "Input matrix must be type double.");
    }

    /* check that number of columns in first input argument is 1 */
    if (mxGetN(prhs[0]) != 3) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:not3Columns", "Input must have 3 columns.");
    }
    if (mxGetM(prhs[1]) != 4 || mxGetN(prhs[1]) != 4) {
        mexErrMsgIdAndTxt("MyToolbox:arrayProduct:not3Columns", "Transform must be 4x4 matrix.");
    }

    /* create a pointer to the real data in the input matrix  */
    inMatrix = mxGetPr(prhs[0]);
    inTransform = mxGetPr(prhs[1]);

    /* get dimensions of the input matrix */
    mwSize nrows = mxGetM(prhs[0]);


    pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
    mxArrayToPointCloud(prhs[0], source_cloud);


    Eigen::Map<Eigen::Matrix4d> transformEigenTemp(inTransform, 4, 4);
    Eigen::Matrix4f transformEigen = transformEigenTemp.cast <float> ();

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZ> ());

    pcl::transformPointCloud(*source_cloud, *transformed_cloud, transformEigen);

    std::cout << *transformed_cloud << std::endl;
    for (size_t i = 0; i < transformed_cloud->points.size(); ++i) {

        std::cout << "    " << transformed_cloud->points[i].x
                  << " "    << transformed_cloud->points[i].y
                  << " "    << transformed_cloud->points[i].z << std::endl;
    }

    plhs[0] = pointCloudToMxArray(transformed_cloud);
}

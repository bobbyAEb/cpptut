#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
using namespace std;

int main(int argc, char const *argv[])
{
    Eigen::Matrix3d rotation_m = Eigen::Matrix3d::Identity();
    Eigen::AngleAxisd rotation_v(M_PI / 4, Eigen::Vector3d(0, 0, 1));
    cout.precision(3);
    cout << "rotation_m=:\n" << rotation_v.matrix() << endl;
    rotation_m = rotation_v.toRotationMatrix();
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_v * v;
    cout << "(1,0,0) after rotation=" << v_rotated.transpose() << endl;
    v_rotated = rotation_m * v;
    cout << "(1,0,0) after rotation=" << v_rotated.transpose() << endl;
    Eigen::Vector3d euler_angles = rotation_m.eulerAngles(2, 1, 0);
    cout << "y p r" << euler_angles.transpose() << endl;
    /* 欧式变换用isometry */
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_v);
    // T.pretranslate(Eigen::Vector3d(1, 3, 4));
    cout << "Transform matrix\n" << T.matrix() << endl;
    Eigen::Vector3d v_transform = T * v;
    cout << v_transform.transpose() << endl;
    return 0;
}

//
// Created by leonhardt on 2020/11/3.
//
#include <iostream>
#include <cmath>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include "sophus/se3.hpp"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv){
    Matrix3d R = AngleAxisd(M_PI / 2, Vector3d(0, 0, 1)).toRotationMatrix();
    Quaterniond q(R);
    Sophus::SO3d SO3_R(R);
    Sophus::SO3d SO3_q(q);

    cout << "SO(3) from matrix: \n" << SO3_R.matrix() << endl;
    cout << "SO(3) from quaternion : \n" << SO3_q.matrix() << endl;
    cout << "they are equal!" << endl;

    Vector3d so3_r = SO3_R.log();
    cout << "so3 = " << so3_r.transpose() << endl;
    cout << "so3 hat = \n" << Sophus::SO3d::hat(so3_r) << endl;
    cout << "so3 hat vee = " << Sophus::SO3d::vee(Sophus::SO3d::hat(so3_r)).transpose() << endl;

    Vector3d update_so3(1e4, 0, 0);
    Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3) * SO3_R;
    cout << "SO3 update = \n " << SO3_updated.matrix() << endl;
};
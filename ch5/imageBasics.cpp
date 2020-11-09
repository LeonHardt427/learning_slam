//
// Created by leonhardt on 2020/11/4.
//
#include <iostream>
#include <chrono>

using namespace std;

#include <opencv2//core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv){
    cv::Mat image;
    image = cv::imread(argv[1]);

    if (image.data == nullptr){
        cerr << "file " << argv[1] << "is not exists." << endl;
        return 0;
    }

    cout << "image width is " << image.cols << ", " << "height is " << image.rows
         << " channel number is " << image.channels() << endl;
    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}
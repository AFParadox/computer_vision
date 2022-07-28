#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "minmax_filters.hpp"

using namespace std;
using namespace cv;

int main() {
    
    Mat img = imread("image_grayscale.jpg", IMREAD_GRAYSCALE);
    namedWindow("original_img", WINDOW_NORMAL);
    imshow("original_img", img);
    waitKey(0);
    
    Mat img_max = max_filter(7, img);
    namedWindow("After_max_filter", WINDOW_NORMAL);
    imshow("After_max_filter", img_max);
    waitKey(0);

    Mat img_min = min_filter(7, img);
    namedWindow("After_min_filter", WINDOW_NORMAL);
    imshow("After_min_filter", img_min);
    waitKey(0);

    return 0;
}

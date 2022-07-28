#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/types.hpp>

using namespace std;
using namespace cv;

int main() {

    Mat img = imread("image.jpg", IMREAD_GRAYSCALE);
    namedWindow("original_img");
    imshow("original_img", img);
    waitKey(0);

    Mat img_median;
    medianBlur(img, img_median, 7);
    namedWindow("After_median_filter");
    imshow("After_median_filter", img_median);
    waitKey(0);

    Mat img_gauss;
    GaussianBlur(img, img_gauss, Size(15,15), 3);
    namedWindow("After_Gaussian_filter");
    imshow("After_Gaussian_filter", img_gauss);
    waitKey(0);


    return 0;
}

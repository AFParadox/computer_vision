#include <opencv2/highgui.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;

int main(){

    string path1 = cv::samples::findFile("Lena_color.jpg");
    cv::Mat lena = cv::imread(path1);
    cout << '1' << endl;
    cv::namedWindow("Lena");
    cv::imshow("Lena", lena);
    cout << '2' << endl;
    cv::waitKey(0);

    cv::Mat lena_greyscale = cv::imread("Lena_grayscale.jpg");
    cout << '3' << endl;
    cv::namedWindow("Lena_grayscale");
    cv::imshow("Lena_grayscale", lena);
    cout << '4' << endl;
    cv::waitKey(0);

    cv::Mat gurus = cv::imread("DL_gurus.jpg");
    cout << '5' << endl;
    cv::namedWindow("Gurus");
    cv::imshow("Gurus", gurus);
    cout << '6' << endl;
    cv::waitKey(0);

    return 0;
}
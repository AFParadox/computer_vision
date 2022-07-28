// OpenImg.cpp
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;

int main(){

	cv::Mat Lena_color_obj = cv::imread("Lena_color.jpg");
	cv::namedWindow("Lena_color");
	cv::imshow("Lena_color", Lena_color_obj);
	cv::waitKey(0);
	
	cv::Mat Lena_grayscale_obj = cv::imread("Lena_grayscale.jpg");
	cv::namedWindow("Lena_grayscale");
	cv::imshow("Lena_grayscale", Lena_grayscale_obj);
	cv::waitKey(0);

	cv::Mat gurus_obj = cv::imread("DL_gurus.jpg");
	cv::namedWindow("DL_gurus");
	cv::imshow("DL_gurus", gurus_obj);
	cv::waitKey(0);

	
	return 0;
}
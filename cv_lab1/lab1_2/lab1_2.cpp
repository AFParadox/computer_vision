// OpenImg.cpp
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;

int main(){

	cv::Mat gurus_obj = cv::imread("DL_gurus.jpg");

	int numChannels = gurus_obj.channels();

	cv::namedWindow("DL_gurus");
	cv::imshow("DL_gurus", gurus_obj);
	char keyValue = cv::waitKey(0);

	cout << "# Channels: " << numChannels << endl;
	cout << "Value of waitKey: " << keyValue << endl;

	cv::Mat lena_grayscale_obj = cv::imread("Lena_grayscale.jpg", 0);

	int numChannels_gray = lena_grayscale_obj.channels();

	cv::namedWindow("Lena_grayscale");
	cv::imshow("Lena_grayscale", lena_grayscale_obj);
	char keyValue2 = cv::waitKey(0);

	cout << endl;
	cout << "# Channels: " << numChannels_gray << endl;
	cout << "Value waitKey: " << keyValue2 << endl;


	
	return 0;
}
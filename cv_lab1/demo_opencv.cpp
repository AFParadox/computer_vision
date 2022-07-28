#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>


int main(){
	
	cv::Mat img = cv::imread("Lena_color.jpg");
	cv::namedWindow("demo_window");
	cv::imshow("demo_window1", img);
	cv::waitKey(0);
	
	return 0;
}
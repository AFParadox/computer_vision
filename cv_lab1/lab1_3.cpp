#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/hal/interface.h>

using namespace std;
using namespace cv;

int main(){

	Mat img1 = Mat(256, 256, CV_8UC1);
	Mat img2 = Mat(256, 256, CV_8UC1);

	cout << "img1 = " << endl << " " << img1 << endl << endl;
	cout << "img2 = " << endl << " " << img2 << endl << endl;

	namedWindow("Vertical Gradient");
	imshow("Vertical Gradient", img1);
	waitKey(0);

	for(int i = 0; i < 256; i++){
		for(int j = 0; j < 256; j++){
			img1.at<int>(i,j) = i;
			img2.at<int>(i,j) = j;
		}

	}
	

	return 0;
}	
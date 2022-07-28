#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat gurus_obj = imread("DL_gurus.jpg");

	int numChannels = gurus_obj.channels();

	namedWindow("DL_gurus");
	imshow("DL_gurus", gurus_obj);
	char keyValue = waitKey(0);

	cout << "# Channels: " << numChannels << endl;
	cout << "Value of waitKey: " << keyValue << endl;

    if(numChannels == 3){

        Mat ch1, ch2, ch3;
        vector<Mat> channels(3);
        split(gurus_obj, channels);
        ch1 = channels[0];
        ch2 = channels[1];
        ch3 = channels[2];

        namedWindow("First_channel");
        imshow("First_channel", ch1);
        waitKey(0);

        namedWindow("Second_channel");
        imshow("Second_channel", ch2);
        waitKey(0);

        namedWindow("Third_channel");
        imshow("Third_channel", ch3);
        waitKey(0);
    }
}

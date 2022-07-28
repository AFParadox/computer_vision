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
        
        cout << "Number of channel: 3" << endl;

                
        Mat ch1, ch2, ch3;
        vector<Mat> channels(3);
        split(gurus_obj, channels);
        channels[0].copyTo(ch1);
        channels[1].copyTo(ch2);
        channels[2].copyTo(ch3);
        
        cout << "Setting first channel to zero." << endl;
        channels[0] = Mat::zeros(channels[0].size(), channels[0].type());
        merge(channels, gurus_obj);

        namedWindow("channel1_tozero");
	    imshow("channel1_tozero", gurus_obj);
	    waitKey(0);

        ch1.copyTo(channels[0]);

        cout << "Setting second channel to zero." << endl;
        channels[1] = Mat::zeros(channels[1].size(), channels[1].type());
        merge(channels, gurus_obj);

        namedWindow("channel2_tozero");
        imshow("channel2_tozero", gurus_obj);
        waitKey(0);

        ch2.copyTo(channels[1]);

        merge(channels, gurus_obj);
        namedWindow("normalimg");
        imshow("normalimg", gurus_obj);
        waitKey(0);

        cout << "Setting third channel to zero.\n";
        channels[2] = Mat::zeros(channels[2].size(), channels[2].type());
        merge(channels, gurus_obj);

        namedWindow("channel3_tozero");
        imshow("channel3_tozero", gurus_obj);
        waitKey(0);

    }


    return 0;
}

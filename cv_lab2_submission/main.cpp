//Compilation done in fedora linux (fedora 35)
//Command used from project folder :
//g++ -g main.cpp minmax_filters.cpp -o main -I/usr/local/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "minmax_filters.hpp" //header for task 2
#include <opencv2/core/types.hpp>


using namespace std;
using namespace cv;

int main(int, char**) {
    
    Mat img = imread("image.jpg");

    //TASK 1
    //------variables needed:
    Mat img_grayscale;
    //------showing the image:
    namedWindow("original_Img");
    imshow("original_Img", img);
    waitKey(0);
    //------conversion to grayscale, showing it and saving on new file
    cvtColor(img, img_grayscale, COLOR_BGR2GRAY, 1);
    namedWindow("grayscale_Img");
    imshow("grayscale_Img", img_grayscale);
    waitKey(0);
    imwrite("image_grayscale.jpg", img_grayscale);

    //TASK 2
    //both kernels are set to 7 as it seems a large enough value to blur the electricity cables
    //------applying max filter and showing the result
    Mat img_max = max_filter(7, img_grayscale);
    namedWindow("After_max_filter");
    imshow("After_max_filter", img_max);
    waitKey(0);
    //------applying min filter and showing the result
    Mat img_min = min_filter(7, img_grayscale);
    namedWindow("After_min_filter");
    imshow("After_min_filter", img_min);
    waitKey(0);

    //TASK3
    //variables needed
    Mat img_median, img_gauss;
    //-----application of median filter
    medianBlur(img_grayscale, img_median, 7);
    namedWindow("After_median_filter");
    imshow("After_median_filter", img_median);
    waitKey(0);
    //-----application of gaussian filter
    GaussianBlur(img_grayscale, img_gauss, Size(15,15), 3);
    namedWindow("After_Gaussian_filter");
    imshow("After_Gaussian_filter", img_gauss);
    waitKey(0);

    //TASK 4
    //variables needed
    Mat histogram;
    int histSize = 256;
    float range[] = { 0, 256 } ; //the upper boundary is exclusive
    const float* histRange = { range };
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    //------computation of the histogram and plotting
    calcHist(&img_grayscale, 1, 0, Mat(), histogram, 1, &histSize, &histRange);

    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar(255,255,255));

    normalize(histogram, histogram, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for(int i = 1; i < histSize; i++){
        line(histImage, Point( bin_w*(i-1), hist_h - cvRound(histogram.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(histogram.at<float>(i)) ),
                       Scalar( 0, 0, 0), 2, 8, 0);
    }
    namedWindow("Histogram");
    imshow("Histogram", histImage);
    waitKey(0);

    //TASK 5
    //variable needed
    Mat equalized_img;
    //equalization and plotting
    equalizeHist(img_grayscale, equalized_img);
    namedWindow("Equalized_img");
    imshow("Equalized_img", equalized_img);
    waitKey(0);

    return 0;
}

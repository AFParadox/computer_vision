#ifndef PanoramicImg
#define PanoramicImg

#include <opencv2/core.hpp>

using namespace cv;

class PanoramicImg
{
private:
    Mat full_img;
public:
    PanoramicImg(String[] images);
    ~PanoramicImg();
};

PanoramicImg::PanoramicImg(/* args */)
{
}

PanoramicImg::~PanoramicImg()
{
}



#endif //PanoramicImg.h
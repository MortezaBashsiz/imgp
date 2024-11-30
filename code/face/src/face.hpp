#pragma once

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>

#include "eyes.hpp"
#include "mouth.hpp"
#include "nose.hpp"

using namespace cv;
using namespace std;

class face {
public:
    face();
    ~face();
    eyes eyes_;
    mouth mouth_;
    nose nose_;

    void find(Mat& frame, std::string faceCascadeXml);
};

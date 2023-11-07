#ifndef FINDCASCADE_HPP
#define FINDCASCADE_HPP

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void findCascade(Mat& img, CascadeClassifier& cascade, vector<Rect>& cascades);

#endif // define FINDCASCADE_HPP
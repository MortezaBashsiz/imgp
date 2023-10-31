#ifndef FACE_HPP
#define FACE_HPP

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void findFace(Mat& img, CascadeClassifier& cascade, vector<Rect>& faces);

#endif // define FACE_HPP
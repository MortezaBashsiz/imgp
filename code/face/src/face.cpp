#include "face.hpp"

using namespace std;
using namespace cv;

face::face()
{

}
face::~face()
{

}

void face::find(Mat& frame)
{
	Mat grayFrame;
	cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
}
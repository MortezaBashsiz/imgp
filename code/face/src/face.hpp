#ifndef FACE_HPP
#define FACE_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>

#include "eyes.hpp"
#include "nose.hpp"
#include "mouth.hpp"

using namespace cv;
using namespace std;

class face
{
public:
	face();
	~face();
	eyes eyes_;
	mouth mouth_;
	nose	nose_;

	void find(Mat& frame);
};

#endif // define FACE_HPP
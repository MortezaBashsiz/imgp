#include <iostream>
#include "square.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat myImage;
	namedWindow("Video Player");
	VideoCapture cap(0);
	cap.set(CAP_PROP_FRAME_WIDTH,800);
	cap.set(CAP_PROP_FRAME_HEIGHT,600);
	if (!cap.isOpened()){
		cout << "No video stream detected" << endl;
		system("pause");
		return-1;
	}
	while (true){
		cap >> myImage;
		if (myImage.empty()){
			break;
		}
		vector<vector<Point> > squares;
		findSquares(myImage, squares);
		polylines(myImage, squares, true, Scalar(0, 255, 0), 3, LINE_AA);
		imshow("Video Player", myImage);
		char c = (char)waitKey(25);
		if (c == 27){
			break;
		}
	}
	cap.release();
	return 0;
}

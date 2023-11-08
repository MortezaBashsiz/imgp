#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "face.hpp"
#include "general.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	CommandLineParser parser(argc, argv,
			"{help h||}"
			"{cascade|./haarcascade_frontalface_alt.xml|}"
			"{width|640|}"
			"{height|480|}"
			"{camera|0|}"
	);
	if (parser.has("help"))
	{
			help(argv);
			return 0;
	}
	int width = parser.get<int>("width");
	int height = parser.get<int>("height");
	int camera = parser.get<int>("camera");
	Mat frame;
	face face_;
	namedWindow("Result");
	VideoCapture cap(camera);
	cap.set(CAP_PROP_FRAME_WIDTH,	width);
	cap.set(CAP_PROP_FRAME_HEIGHT,	height);
	if (!cap.isOpened()){
		cout << "No video stream detected" << endl;
		system("pause");
		return-1;
	}
	while (true){
		cap >> frame;
		normalize(frame, frame, 0, 255, NORM_MINMAX);
		face_.find(frame);
		if (frame.empty()){
			break;
		}
		imshow("Result", frame);
		char c = (char)waitKey(25);
		if (c == 27){
			break;
		}
	}
	cap.release();
	return 0;
}
#include <iostream>

#include "square.hpp"
#include "findCascade.hpp"

using namespace cv;
using namespace std;

static void help(char** argv)
{
		cout << "Usage:\n"
				<<  argv[0]
				<<  "   [--cascade=<cascade_path>]\n"
						"		[--width]\n"
						"		[--height]\n"
						"   [--camera]\n\n"
						"example:\n"
				<<  argv[0]
				<<  " --cascade=./haarcascade_frontalface_alt.xml --width=640 --height=480 --camera=0 \n";
}

string cascadeName;

int main(int argc, char** argv)
{
	cv::CommandLineParser parser(argc, argv,
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
	cascadeName = parser.get<string>("cascade");
	CascadeClassifier cascade ;
	if (!cascade.load(samples::findFile(cascadeName)))
	{
			cerr << "ERROR: Could not load classifier cascade" << endl;
			help(argv);
			return -1;
	}
	Mat Frame, Gray, Yuv, Xyz, Ycrcb;
	namedWindow("BGR");
	// namedWindow("GRAY");
	// namedWindow("YUV");
	// namedWindow("XYZ");
	// namedWindow("YCRCB");
	VideoCapture cap(camera);
	cap.set(CAP_PROP_FRAME_WIDTH,	width);
	cap.set(CAP_PROP_FRAME_HEIGHT,	height);
	if (!cap.isOpened()){
		cout << "No video stream detected" << endl;
		system("pause");
		return-1;
	}
	while (true){
		cap >> Frame;
		normalize(Frame, Frame, 0, 255, NORM_MINMAX);
    // cvtColor(Frame, Gray, COLOR_BGR2GRAY);
    // cvtColor(Frame, Yuv, COLOR_BGR2YUV);
    // cvtColor(Frame, Xyz, COLOR_BGR2XYZ);
    // cvtColor(Frame, Ycrcb, COLOR_BGR2YCrCb);
		if (Frame.empty()){
			break;
		}
		vector<vector<Point> > squares;
		vector<Rect> cascades;
		// findSquares(Frame, squares);
		findCascade(Frame, cascade, cascades);
		polylines(Frame, squares, true, Scalar(0, 255, 0), 3, LINE_AA);
		imshow("BGR", Frame);
		// imshow("GRAY", Gray);
		// imshow("YUV", Yuv);
		// imshow("XYZ", Xyz);
		// imshow("YCRCB", Ycrcb);
		char c = (char)waitKey(25);
		if (c == 27){
			break;
		}
	}
	cap.release();
	return 0;
}

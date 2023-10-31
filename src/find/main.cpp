#include <iostream>
#include "square.hpp"

using namespace cv;
using namespace std;

static void help(char** argv)
{
    cout << "Usage:\n"
        <<  argv[0]
        <<  "   [--cascade=<cascade_path> this is the primary trained classifier such as frontal face]\n"
        		"		[--width]\n"
        		"		[--height]\n"
            "   [--camera]\n\n"
            "example:\n"
        <<  argv[0]
        <<  " --cascade=\"./haarcascade_frontalface_alt.xml\" --width=800 --height=600 --camera=0 \n";
}

int main(int argc, char** argv)
{
	
	cv::CommandLineParser parser(argc, argv,
			"{help h||}"
			"{cascade|data/haarcascades/haarcascade_frontalface_alt.xml|}"
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
	Mat Frame;
	namedWindow("Video Player");
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
		if (Frame.empty()){
			break;
		}
		vector<vector<Point> > squares;
		findSquares(Frame, squares);
		// detectAndDraw(Frame, cascade, nestedCascade, scale, tryflip );
		polylines(Frame, squares, true, Scalar(0, 255, 0), 3, LINE_AA);
		imshow("Video Player", Frame);
		char c = (char)waitKey(25);
		if (c == 27){
			break;
		}
	}
	cap.release();
	return 0;
}

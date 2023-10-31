#include "face.hpp"

void findFace(Mat& img, CascadeClassifier& cascade, vector<Rect>& faces)
{
	int scale = 1;
	const static Scalar colors[] =
	{
		Scalar(255,0,0),
		Scalar(255,128,0),
		Scalar(255,255,0),
		Scalar(0,255,0),
		Scalar(0,128,255),
		Scalar(0,255,255),
		Scalar(0,0,255),
		Scalar(255,0,255)
	};
	Mat gray, smallImg;
	cvtColor( img, gray, COLOR_BGR2GRAY );
	double fx = 1 / scale;
	resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT );
	equalizeHist( smallImg, smallImg );
	cascade.detectMultiScale( smallImg, faces,
			1.1, 2, 0
			//|CASCADE_FIND_BIGGEST_OBJECT
			//|CASCADE_DO_ROUGH_SEARCH
			|CASCADE_SCALE_IMAGE,
			Size(30, 30) );
	for ( size_t i = 0; i < faces.size(); i++ )
	{
		Rect r = faces[i];
		Mat smallImgROI;
		Point center;
		Scalar color = colors[i%8];
		int radius;
		double aspect_ratio = (double)r.width/r.height;
		if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
		{
			center.x = cvRound((r.x + r.width*0.5)*scale);
			center.y = cvRound((r.y + r.height*0.5)*scale);
			radius = cvRound((r.width + r.height)*0.25*scale);
			circle( img, center, radius, color, 3, 8, 0 );
		}
		else
			rectangle( img, Point(cvRound(r.x*scale), cvRound(r.y*scale)),
								 Point(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),
								 color, 3, 8, 0);
	}
}
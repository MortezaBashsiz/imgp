#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

double angle( Point pt1, Point pt2, Point pt0 );
void findSquares( const Mat& image, vector<vector<Point> >& squares );

#endif // define SQUARE_HPP
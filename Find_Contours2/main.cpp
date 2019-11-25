#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/types_c.h> 
#include<vector>
//#include <unistd.h>
#include <string>
#include<random>
#include<strstream>
#include <fstream>


#define max_size 100
#define max_pro 100
using namespace cv;
using namespace std;

//Windows仕様コード
int img_run(Mat image1);
vector<Mat>  Paper_Reed();
Point max(vector<Point> P);
Point min(vector<Point> P);


int main() {
	printf("test \n");
	return 0;
}
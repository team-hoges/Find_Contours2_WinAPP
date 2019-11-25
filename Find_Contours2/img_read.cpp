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


vector<Mat>  Paper_Reed() {

	vector<Mat> Papers;
	vector<string>file_names;

	string Paper_num = "0";
	string num;
	string Paper_name;
	Mat sta_img;

	for (size_t i = 0; i < max_pro; i++) {
		num = to_string(i);
		Paper_name = num + ".jpg";//ファイル名指定
		sta_img = imread(Paper_name);
		if (true == sta_img.empty()) {
			if (i == 0) {
				//例外判定を追加する.
			}
			break; //読み込めなくなったら終了
		}
		Papers.push_back(imread(Paper_name));
	}
	return Papers;
}

#include <iostream>
#include <memory>
#include<stdexcept>
#include<Windows.h>
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
#include <filesystem>

#define max_size 100
#define max_pro 100
#define input_dir_name input
using namespace cv;
using namespace std;

//Windows仕様コード
vector<Mat> img_run(Mat image1,string filename);//画像処理関数
vector<Mat>  Paper_Reed(vector<string> Paper_name);//画像読み込み関数
vector<vector<Mat>> sort_img(vector<vector<Mat>> imgs);
int  Paper_output(vector<vector<Mat>> out);
Point max(vector<Point> P);
Point min(vector<Point> P);


namespace fs = std::filesystem;

int main() {
	//string read_file = "./input_file/";
	HANDLE hFind;
	int per_num = 0;//答案枚数
	int i = 0;
	string dir_name ="./input/";
	vector<string> read_files;

	vector<Mat> Pre_processing_data;
	vector < vector<Mat> >out_ans;
	
	vector<string> file_name;
	std::string extension[3] = { "png" ,"jpg", "bmp" };

	Pre_processing_data=Paper_Reed(file_name);//画像読み込み.

	bool files_know = fs::exists("input");

	if (files_know == false) {
		filesystem::create_directory("input");
	}

	
	string ser_name = dir_name + "*." + extension[i];

	for (const fs::directory_entry& x : fs::recursive_directory_iterator(dir_name)) {//ファイル検索
		
		file_name.push_back(x.path().string());
	}
	
	

	cout << file_name.size() << endl;
	per_num = file_name.size();
	Pre_processing_data = Paper_Reed(file_name);

	i = 0;
	for (auto imgs : Pre_processing_data) {
		out_ans.push_back(	img_run(imgs,file_name.at(i)));
		i++;
	}


	
	Paper_output(out_ans);//一時的にoutput;





	


	return 0;
}







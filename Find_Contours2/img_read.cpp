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
#define per_nums_par 11
using namespace cv;
using namespace std;
namespace fs = std::filesystem;




vector<Mat>  Paper_Reed(vector<string> Paper_name) {//ファイル読み込み
	vector<Mat> img_datas;
	Mat out_mat;
	for (auto Paper_data : Paper_name) {
		cout << Paper_data << endl;
		out_mat = imread(Paper_data);

		if (out_mat.empty()) {
			cout << "read Error!!!" << endl;
			exit(1);
		}

		img_datas.push_back(out_mat);
	}

	return img_datas;
}


int Paper_output(vector<vector<Mat>> out, vector<Mat> out_ans) {//ファイル出力.
	string Folder_names="./Regular_test/";
	string ser_name;
	string img_data_name;
	//string current_paths = fs::current_path();
	int een=0;
	//fs::path ans_path=fs::current_path();//作業パスの出力
	fs::path out_path;
	int test_num = 0;

	for (auto a: out) {
		if (een < a.size()) {//一番大問数が多い問題を念の為取得
			een = a.size();
		}
	}

	

	
	if (true != fs::exists(Folder_names + "/version_" + to_string(0))) {
			fs::create_directories(Folder_names + "/version_" + to_string(0));//ディレクトリ作成		
	}
	
	fs::current_path(Folder_names + "/version_" + to_string(0));



	if (false == fs::exists("./test_" + to_string(0))) {
		fs::create_directories("./test_" + to_string(0));

	}


	fs::current_path("./test_" + to_string(0));
	int t = 0;

	for (auto ans_per : out_ans) {
		imwrite(fs::absolute(fs::current_path()).string() + "/" + "test_" + to_string(t) + ".jpg", ans_per);
		t++;
	}

	fs::current_path("../");

	for (size_t i = 1; i < out.size(); i++)
	{
		if (out.at(i).size() > per_nums_par) {
			test_num = out.at(i).size();
		}	
		else
		{
			test_num = per_nums_par;
		}
		
		for (size_t j = 1; j < test_num; j++) {

			if (false == fs::exists("./test_" + to_string(j))) {
				fs::create_directories("./test_" + to_string(j));
			}
			fs::current_path("./test_" + to_string(j));

			
			if(out.at(i).size() > j)
				imwrite(fs::absolute(fs::current_path()).string() +"/" +to_string(i) + ".jpg",out.at(i).at(j));
	
			fs::current_path("../");
		}
	}
	return 0;
}



vector<vector<Mat>> sort_img(vector<vector<Mat>> imgs) {
	Mat hsv_test;
	for (auto test : imgs) {
		for (auto cvt : imgs) {
			cvtColor(cvt, hsv_test, CV_BGR2HSV);
					
		 }
	}


	return imgs;
}
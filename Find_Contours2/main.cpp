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
	string read_file = "./input_file";
	string dir_name = "test";
	vector<string> read_files;
	HANDLE hFind;
	WIN32_FIND_DATA win32fd;

	vector<string> file_name;
	std::string extension[3] = { "png" ,"jpg", "bmp" };


	for (size_t i = 0; i < 3; i++)
	{
		string ser_name=dir_name+ "*." + extension[i];
		hFind = FindFirstFile(ser_name.c_str(), &win32fd);
		if (hFind == INVALID_HANDLE_VALUE) {
			continue;
		}do {
			if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			}
			else {
				file_name.push_back(win32fd.cFileName);
			}
		} while (FindNextFile(hFind, &win32fd));

		FindClose(hFind);
	}


	for ( auto files:file_name)
	{
		cout << files << endl;
	}
	
	return 0;
}







#include <iostream>
#include <windows.h> 
#include <io.h>
#include <string>
#include <direct.h>
#include <filesystem>

#include <direct.h>
using namespace std;


void work(string name,string folderName, string newFolderName,int &i);

int main()
{
	cout << "폴더 이름을 입력하세요" << endl;
	
	int i = 0;
	string name;
	cin >> name;
	cout << "--------------------------------------------------------------------------------------------------\n\n\n\n\n" << endl;
			//renaming하고 싶은 폴더의 이름
			string folderName = "front\\";
			//만약 새로운 폴더로 파일들을 옮기고 싶다면 그 폴더의 이름을, 현재 폴더에 그대로 저장하려면 현재 폴더의    //이름을 입력합니다.
			string newFolderName = "front\\";
			work(name,folderName,newFolderName,i);
	
			i -=  2;
			//renaming하고 싶은 폴더의 이름
			 folderName = "side\\";
			//만약 새로운 폴더로 파일들을 옮기고 싶다면 그 폴더의 이름을, 현재 폴더에 그대로 저장하려면 현재 폴더의    //이름을 입력합니다.
			 newFolderName = "side\\";
			 work(name, folderName, newFolderName, i);
			 i -= 2;
			//renaming하고 싶은 폴더의 이름
			 folderName = "back\\";
			//만약 새로운 폴더로 파일들을 옮기고 싶다면 그 폴더의 이름을, 현재 폴더에 그대로 저장하려면 현재 폴더의    //이름을 입력합니다.
			 newFolderName = "back\\";
			 work(name, folderName, newFolderName, i);

			 cout << "\n\n\n\n\n--------------------------------------------------------------------------------------------------" << endl;
			 cout << "완료되었습니다" << endl;
}

	void work(string name,string folderName, string newFolderName,int &i) {
		// 작업 경로를 문자열 형태로 저장할 변수
		char path[128];
		// 프로그램의 현재 작업 경로를 얻는다.
		if (GetCurrentDirectoryA(128, path) > 0) {
			// 작업 경로를 얻었다면 화면에 출력한다.
			printf("Working Directory : %s\n", path);
		}
		string a(path);
		//renaming하고 싶은 데이터가 들어있는 폴더가 있는 경로를 적으세요
		string dataSetPath(a+"\\"+name+"\\");


	//	cout << dataSetPath << endl; dataSetPath 경로


		string folderPath = dataSetPath + folderName;
		//타겟 폴더의 경로
		string newFolderPath = dataSetPath + newFolderName;
		//폴더 내의 모든 파일을 읽기위해 확장자를 *.*로 지정

		string p = folderPath + "*.*";

		//renaming하기 위한 이름

		string fileNameTag = name+"_";
		//원래 파일의 이름경로를 저장할 변수
		string oldName;
		//새로운 파일의 이름 경로를 저장할 변수
		string newName;
		intptr_t handle;
		//폴더 내부의 파일 이름들을 저장할 변수
		struct _finddata_t fd;

		//만약 폴더 내부가 비어있다면 "No file in directory!"를 출력

		//비어있지 않다면 fd에 모든 파일들의 이름을 저장

		if ((handle = _findfirst(p.c_str(), &fd)) == -1L)

			cout << "No file in directory!" << endl;





		//파일의 이름을 하나하나 읽어 rename함수를 이용해 renaming해주는 작업입니다.

		//fd.name을 출력해보면 파일 fd에 들어있는 파일들의 이름을 확인할 수 있습니다.

		//to_string(i-2)를 한 이유는 fd의 첫 번째 값과 두 번째 값이 file의 이름이 아닌 .과 ..이 들어있기 때문입니다.

		//그 이유를 잘 몰라 저는 파일의 이름이 등장하는 2번째 값부터 renaming을 시작했습니다.

		do {

			if (i > 1) {

				oldName = folderPath + fd.name;
				newName = newFolderPath + fileNameTag + to_string(i - 2) + ".jpg"; //png 로 저장 
				rename(oldName.c_str(), newName.c_str());	

			}

			i++;

		} while (_findnext(handle, &fd) == 0);

		_findclose(handle);

	}
#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Explorer {
public:
	fs::path dir;
	Explorer()
	{
		dir = getCurrentDir();
	}

	fs::path getCurrentDir() {
		return fs::current_path();
	}

	fs::path changeDir(string mod) {
		if (mod == "..") {
			fs::current_path("../");
			dir = fs::current_path();
			return dir;
		}
		else {
			fs::path p { mod };
			try {
				if (fs::exists(p)) {
					fs::current_path(p);
					dir = fs::current_path();
					return dir;
				}
				else
				{
					cout << "Path does not exists" << endl;
					return dir;
				}
			}
			catch (fs::filesystem_error) {
				cout << "Wrong property for change directory:need name of folder,not name of folder" << endl;
				return dir;
			}
		}
	}

	fs::path createDir(string mod) {
		if (fs::create_directory(mod)) {
			cout << "Folder successfully created" << endl;
			return dir;
		}
		else {
			cout << "Can't create folder witch choosed params" << endl;
			return dir;
		}
	}

	void removeDir(string mod) {
		if (fs::exists(mod)) {
			fs::current_path(mod);
			if (dir != fs::current_path()) {
				fs::current_path("../");
				if (fs::remove_all(mod)) {
					cout << "Folder seccesfully removed" << endl;
				}
				else {
					cout << "Can't not remove coosen dir" << endl;
				}
			}
			else {
				cout << "Can not remode current dir" << endl;
			}
		}
		else {
			cout << "Path doesn't exists" << endl;
		}
	}

	vector <fs::path> getCurrentDirEnv() {
		vector <fs::path> env;
		fs::directory_iterator dirIterator(dir);
		for (const auto& entry : dirIterator) {
			env.push_back(entry.path().filename());
		}
		return env;
	}
	void printPath(vector<fs::path>vec) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec.at(i) << endl;
		}
	}
};

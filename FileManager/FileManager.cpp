#include "FileName.h"
using namespace std;

int main() {
	Explorer explorer;
	cout << explorer.getCurrentDir() << endl;
	explorer.printPath(explorer.getCurrentDirEnv());
	explorer.createDir("test");
	explorer.removeDir("test");
}
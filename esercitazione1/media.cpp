#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        cerr << "ERR: not enough args or too many." <<endl;
        return 1;
    }

    string filename;
    filename = argv[1];

    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "ERR: File non found." << endl;
        return 1;
    }

    while (!ifs.eof()) {
        string location;
        double temp;
        double media = 0;
        ifs >> location;

        for (int i=0; i<4; i++){
            ifs >> temp;
            media += temp;
        }
        media /=4;
        cout << location << " " << media << endl;
    }
    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[])
{

    // Quanti valori delle temperature devo leggere
    int N = 4;

    if (argc != 2) {
        cerr << "ERR: not enough args or too many." <<endl;
        cerr << "    media <filepath>" <<endl;
        return 1;
    }

    string filename;
    filename = argv[1];

    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "ERR: File non found." << endl;
        return 1;
    }

    string location;
    
    while (ifs >> location) {
        // Controllo errori di lettura generici
        if (ifs.fail() && !ifs.eof()) {
            cerr << "ERR: Errore generico nella lettura del file." << endl;
            return 1;
        }

        double temp;
        double media = 0;

        for (int i=0; i < N; i++){
            if (!(ifs >> temp)){
                cerr << "ERR: lettura temperatura non riuscita per " << location << "\n Esco..." << endl;
                return 1;
            }
            media += temp;
        }

        media /= N;
        cout << location << " " << media << endl;
    }

    ifs.close();
    return 0;
}
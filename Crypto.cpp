/******************************************************************************\
| Program:  Crypto.cpp
| Problem:  Prompt the user to enter a secret key and use it to compute the 
|           seed of a random number generator
|           Prompt the user to give the names of an input file and the 
|           output coded/decoded
|           Create the sequence of random bytes from a random number generator 
|           with the seed obtained from user's secret key. 
\******************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char key[100];          // Input key
    unsigned int password;  // Generated password
    int i;                  // index counter
    char infname[100];      // Input file name
    char outfname[100];     // Output file name
    char c;                 // Character to hold the output
    int size=0;             // File size counter

    cout << endl;
    cout << "ENCRYPTION / DECRYPTION FOR ALL FILE TYPES" << "\n\n";
    cout << "Key (any string) = ";
    cin >> key;

    for(password=0, i=0; key[i]; i++)
    {
        cout << "Password: " << password << " = Key: " << key[i] << endl;
        password = (password+3) * key[i];
        cout << "Password: " << password << " = Key: " << key[i] << endl;
        cout << "-------------------------------\n";
    }
    srand(password);

    cout << "\nPassword = " << password << " (" << hex<<password<<dec<< ")\n\n";
    
    // Input file
    cout << "Input File: ";
    cin >> infname;
    ifstream IS(infname, ios::in | ios::binary);
    if(!IS) 
    {
        cout << "\nFile open error\n";
        exit(1);
    }

    // Output file
    cout << "\nOutput File: ";
    cin >> outfname;
    ofstream OS(outfname, ios::out | ios::binary);
    if(!OS) 
    {
        cout << "\nFile open error\n";
        exit(1);
    }

    // While getting one binary char -> encode and write to the output file
    while(IS.get(c))
    {
        c ^= (rand() % 8);
        OS << c;
        size++; // counting file size
    }
    IS.close();
    OS.close();

    cout << "\nFile '" << outfname << "' created...\n";
    cout << "\nFile size: " << size << "\n\n";   
    
  system("pause");   
    return 0;    
}

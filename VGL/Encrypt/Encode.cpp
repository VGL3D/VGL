//
// Created by soham on 1/8/23.
//

#include "Encode.hpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readData() {
    string line;
    ifstream myfile ("/home/soham/Documents/python/Encryption/p1.jpg");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void hexdump(void *ptr, int buflen)
{
    unsigned char *buf = (unsigned char*)ptr;
    int i, j;
    for (i=0; i<buflen; i+=16) {
//        printf("%06x: ", i);
//        for (j=0; j<16; j++) {
//            if (i+j < buflen)
//                printf("%02x ", buf[i+j]);
//            else
//                printf("   ");
//        }
        printf(" ");
        for (j=0; j<16; j++) {
            if (i+j < buflen)
                //printf("%c", isprint(buf[i+j]) ? buf[i+j] : '.');
                cout<<buf[i+j];
        }
        printf("\n");
    }
    //cout<<buf[0]<<"\n";
    printf("%s",buf);
}

int main()
{
//    ifstream in;
//
//    in.open("/home/soham/Documents/python/Encryption/p1.jpg", ios::in | ios::binary);
//
//    if(in.is_open())
//    {
//        // get the starting position
//        streampos start = in.tellg();
//
//        // go to the end
//        in.seekg(0, std::ios::end);
//
//        // get the ending position
//        streampos end = in.tellg();
//
//        // go back to the start
//        in.seekg(0, std::ios::beg);
//
//        // create a vector to hold the data that
//        // is resized to the total size of the file
//        std::vector<char> contents;
//        contents.resize(static_cast<size_t>(end - start));
//
//        // read it in
//        in.read(&contents[0], contents.size());
//
//        // print it out (for clarity)
//        hexdump(contents.data(), contents.size());
//    }
    readData();
}


//int main(int argc,char *argv[]) {
//    long size;
//    char *filename = "/home/soham/Documents/python/Encryption/p1.jpg";
//    char *out_filename = "/home/soham/Documents/gameclion/VGL/Encrypt/filename1.txt";
//    ifstream openFile;
//    openFile.open(filename, ios::in | ios::binary);
//    if (!openFile)
//    {
//        cout << "Unable to open file:" << filename << endl;
//        return 0;
//        }
//    openFile.seekg(0, ios::end);
//    size = openFile.tellg();
//    cout << "size of file " << size << endl;
//
//    char temp[size];
//    //temp = new char[size];
//
//    openFile.read((char *) temp, size);
//
//    cout<<temp[0]<<"\n";
//
////    ofstream out(out_filename,ios::binary);
////    out.write((char *) temp, size);
//    openFile.close();
////    out.close();
//
//    delete[] &temp;
//    return 0;
//}
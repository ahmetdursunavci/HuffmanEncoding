//
// Created by hp on 27.12.2020.
//

#ifndef FORCLASS_READFILE_H
#define FORCLASS_READFILE_H
#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
class ReadFile {
public:
    string Read(string path) {

        fstream file(path);
        if(!file) {
            printf("file does not exist");
            return "";
        }
        else{
                string input;
                getline(file,input);
            return input;


        }

    }
   vector<string> Read2(string path) {
        vector<string> freq_vector;
        fstream file(path);
        if(!file) {
            printf("file does not exist");
            return vector<string>();
        }
        else{

            while (file.good()) {
                string input;
                getline(file, input);
                char commandarray[input.length()];
                strcpy(commandarray, input.c_str());
                char split[] = ":";
                char *str = strtok(commandarray, ":");

                int i = 0;

                while (str) {
                    freq_vector.push_back(str);
                    str = strtok(NULL, split);

                }



            }
            return freq_vector;
            }
        }








};







#endif //FORCLASS_READFILE_H

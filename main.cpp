#include <iostream>
#include "BinaryTree.h"
#include<bits/stdc++.h>
#include "BuildTree.h"
using namespace std;

int main(int argc, const char **argv) {
    string path;
    string secondcommand;
    string thirdcommand;
    string firstcommand = argv[1];
    if(argc>2) {
    path =argv[2];
    secondcommand=argv[3];
    }
    if(argc>4) {
    thirdcommand=argv[4];
    }
    if(firstcommand=="-i") {
        if(secondcommand=="-encode") {
            ReadFile read;
            string input = read.Read(path);
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            BinaryTree tree;
            string input2=read.Read(path);
            transform(input2.begin(), input2.end(), input2.begin(), ::tolower);
            tree.get_input(input);
            input=tree.transfer_input();
            map<char, int> char_map;
            for (char ch: input) {
                char_map[ch]++;
            }
            string str;
           tree.Huffman_code(char_map);
           tree.encode(tree.root,str,"MyTree.txt");
           if(thirdcommand=="-s") {
               for(int i = 5 ; i < argc;i+=2) {
                   if(argv[i]!="") {
                       tree.print(argv[i]);
                   }
               }
           }
           else {
               tree.print(input2);
           }

        }
        else if(secondcommand=="-decode") {
            BuildTree buildTree;

            ReadFile read;
            string decode_input;
            decode_input=read.Read(path);


           vector<string> freq_vector=read.Read2("MyTree.txt");
           map<char,string> freq_map;

            for(auto i=freq_vector.begin(); i < freq_vector.end() ; ++i) {
                string a = *i;
                ++i;
                string b = *i;
                freq_map[a.at(0)]=b;
                //++i;
            }

            buildTree.Building_Tree(freq_map);
            buildTree.decode(decode_input);

        }



    }
    else if(firstcommand=="-l") {

        BuildTree buildTree;

        ReadFile read;
        string decode_input;


        vector<string> freq_vector=read.Read2("MyTree.txt");
        map<char,string> freq_map;

        for(auto i=freq_vector.begin(); i < freq_vector.end() ; ++i) {
            string a = *i;
            ++i;
            string b = *i;
            freq_map[a.at(0)]=b;
            //++i;
        }

        buildTree.Building_Tree(freq_map);
        string str="";
        buildTree.Lists_tree(str,buildTree.root);



    }

}

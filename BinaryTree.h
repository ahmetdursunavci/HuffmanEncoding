//
// Created by hp on 27.12.2020.
//

#ifndef FORCLASS_BINARYTREE_H
#define FORCLASS_BINARYTREE_H
#include <queue>
#include "ReadFile.h"
#include "iostream"
#include<bits/stdc++.h>


using namespace std;
class BinaryTree {
public:
    map<char,string> encode_map;
    string input_encoding;

    void get_input(string input) {
        input_encoding=input;

    }

    string transfer_input() {
        return input_encoding;
    }


    struct TreeNode{
        int freq;
        char letter;
        TreeNode *left;
        TreeNode *right;

    }*root;

    void write(string output,string path) {
        ofstream outfile;
        outfile.open(path, ios_base::app);
        outfile << output;
    }
    struct compare {
        bool operator()(TreeNode *left, TreeNode *right) {
            if (left->freq == right->freq) {
                if (left->letter == right->letter) {
                    if (left->left != nullptr && right->left != nullptr) {
                        return left->left->letter < right->left->letter;
                    }
                }

            return left->letter > right->letter;
        }

        return ((left->freq > right->freq));

    }
    };


    void arrange_chs() {

        for(int i = 0 ; i<input_encoding.length()-1;i++) {
            for(int j =i+1;j<input_encoding.length();j++) {
                if(input_encoding[j]<input_encoding[i]) {
                    char a =input_encoding[i];
                    input_encoding[i]=input_encoding[j];
                    input_encoding[j]=a;
                }


            }
        }


    }
    TreeNode* get_Node(char letter, int freq, TreeNode* left= nullptr, TreeNode* right= nullptr)
    {
        TreeNode* new_node = new TreeNode();

        new_node->letter = letter;
        new_node->freq = freq;
        new_node->left = left;
        new_node->right = right;

        return new_node;
    }

    bool isLeaf(TreeNode* leaf) {
        return leaf->left == nullptr && leaf->right == nullptr;
    }

    void encode(TreeNode *temp_root,string str,string path) {

        if(root==NULL) {
            return ;
        }

        if(isLeaf(temp_root)) {
            if(str=="") {
                encode_map[temp_root->letter]="1";
                write(temp_root->letter+":1\n",path);
                //return encode_map;
            }
            else {
                char b = temp_root->letter;
                string s(1, b);
                write(s+":"+str+"\n",path);
                encode_map[temp_root->letter]=str;
               // return encode_map;
            }
        }
        else {
            encode(temp_root->left,str+"0",path);
            encode(temp_root->right,str+"1",path);
        }


    }



   void Huffman_code(map<char, int> char_map) {
       priority_queue<TreeNode*, vector<TreeNode*>, compare > node_queue;



       for(auto item : char_map) {
           //cout<<item.first<<":"<<item.second;
           node_queue.push(get_Node(item.first,item.second));
       }

       while(node_queue.size()!=1) {
           TreeNode *node_left=node_queue.top();
          // cout<<node_left->letter<<endl;

           node_queue.pop();
          TreeNode * node_right=node_queue.top();
           //cout<<node_right->letter<<endl;
           node_queue.pop();
           TreeNode *newnode = new TreeNode();
           newnode->letter=' ';
           newnode->freq=node_left->freq+node_right->freq;
           newnode->left=node_left;
           newnode->right=node_right;

           node_queue.push(newnode);
          // cout<<endl;



       }
       root=node_queue.top();
       node_queue.pop();

    }
    void print(string str) {

        for(char ch : str) {
            cout<<encode_map[ch];
        }
	cout<<endl;

    }
};


#endif //FORCLASS_BINARYTREE_H

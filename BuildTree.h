

#ifndef FORCLASS_BUILDTREE_H
#define FORCLASS_BUILDTREE_H

#include "iostream"
#include<bits/stdc++.h>

using namespace std;
class BuildTree{
public:
    struct Node{
        char letter='x';
        int freq;
        Node *left= nullptr;Node *right = nullptr;

    }*root;


    bool isLeaf(Node* leaf) {
        return leaf->left == nullptr && leaf->right == nullptr;
    }

    void Building_Tree(map<char,string> freq_map) {
        root=new Node();
        for(auto i : freq_map) {

            Node *temp=root;
            for(char ch : i.second) {
                if(ch=='0') {
                    if(temp->left== nullptr) {
                        Node *left= new Node();
                        temp->left=left;
                        temp=temp->left;
                    }
                    else {
                        temp=temp->left;
                    }

                }
                else {
                    if(temp->right== nullptr) {
                        Node *right = new Node();
                        temp->right=right;
                        temp=temp->right;
                    }
                    else {
                        temp=temp->right;
                    }
                }
            }
            temp->letter=i.first;
        }
    }


    void decode(string decode_input) {
        Node *temp = root;
        for(int i = 0 ; i < decode_input.length();i++) {
            if(decode_input[i]=='0') {
                temp=temp->left;
            }
            else {
                temp=temp->right;
            }

            if(isLeaf(temp)) {
                cout<<temp->letter;
                temp=root;
            }
        }
	cout<<endl;
    }

    void Lists_tree(string str,Node *temp) {

        if(root== nullptr) {
            return;
        }
        if(temp==root) {
            cout<<"+- root"<<endl;
            cout<<"   +- left_branch"<<endl;
            if(root->left!= nullptr) {
                Lists_tree(str+"0", temp->left);
            }
            cout<<"   +- right_branch"<<endl;
            if(root->right!= nullptr) {
                Lists_tree(str+"1", temp->right);
            }
        }
        else {
            if(isLeaf(temp)) {
                for(int i = 0 ; i < str.length();i++) {
                    cout<<"   |";
                }
                char b = temp->letter;
                string s(1, b);
                cout<<"   +- grandchild-"+s+":"+str<<endl;
            }
            else {
                for(int i = 0 ; i < str.length();i++) {
                    cout<<"   |";
                }
                cout<<"   +- Parent-"+str<<endl;
                if(temp->left!= nullptr) {
                    Lists_tree(str+"0",temp->left);
                }
                if(temp->right!= nullptr) {
                    Lists_tree(str+"1",temp->right);
                }
            }
            }
        }












};
#endif //FORCLASS_BUILDTREE_H
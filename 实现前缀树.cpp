#include<iostream>
#include<vector>
using namespace std;
/*
题目要求写一个前缀树，前缀树每个节点都有26个子节点以及一个isend标识符，标志单词是否结束。
*/
class Trie {
    vector<Trie*> child;
    bool isend;
public:
    Trie() {
        child.assign(26,nullptr);
        isend=false;
    }
    
    void insert(string word) {
        int length=word.length();
        Trie* temp=this;
        for(int i=0;i<length;i++){
            int ch=word[i]-'a';
            if(temp->child[ch]==nullptr)
            {
                temp->child[ch]=new Trie;
                temp=temp->child[ch];
            }else{
                temp=temp->child[ch];
            }
            
        }
        temp->isend=true;
        
    }
    
    bool search(string word) {
        int length=word.length();
        Trie* temp=this;
        for(int i=0;i<length;i++){
            int ch=word[i]-'a';
            if(temp->child[ch]==nullptr)
            {
                return false;
            }else{
                temp=temp->child[ch];
            }
        }
        if(temp->isend==false)
        {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        int length=prefix.length();
        Trie* temp=this;
        for(int i=0;i<length;i++){
            int ch=prefix[i]-'a';
            if(temp->child[ch]==nullptr)
            {
                return false;
            }else{
                temp=temp->child[ch];
            }
        }
        return true;
    }
    
};

#include<bits/stdc++.h>
using namespace std;

fstream rd,wrt;

const int min_sup_count = 2;

bool custom(pair<int,string> &A,pair<int,string> &B){
    if(A.first == B.first) return A.second < B.second;
    return A.first > B.first;
}

struct Node{
    string item;
    int freq;
    Node* child[10];
    bool isEnd;
    Node(string x){
        item = x;
        freq = 0;
        isEnd = false;
        for(int i = 0; i < 10;i++) child[i] = NULL;
    }
};


void insert_fp_tree(vector<string> &A,Node *root){
    Node *curr = root;
    for(auto i : A){
        int ind = stoi(i.substr(1));
        if(!curr->child[ind]) curr->child[ind] = new Node(i);
        curr->freq += 1;
        curr = curr->child[ind];
    }
    curr->freq += 1;
    curr->isEnd = true;
}

void traverse_fp_tree(Node *root,vector<Node*> &curr_path,vector<vector<Node*>> &Ans){
    if(!root) return;
    if(root->isEnd){
        curr_path.push_back(root);
        Ans.push_back(curr_path);
        curr_path.pop_back();
    }
    //cout<<root->item<<' '<<root->isEnd<<'\n';
    for(int i = 0;i < 10;i++){
        curr_path.push_back(root);
        traverse_fp_tree(root->child[i],curr_path,Ans);
        curr_path.pop_back();
    }
} 


vector<string> split(string &A){
    stringstream obj(A);
    vector<string> res;
    string x;
    int k = 0;
    while(obj>>x){
        if(k != 0) res.push_back(x);
        k++;
    }
    return res;
}

vector<vector<string>> trasaction_reader(string filename){
    rd.open(filename,ios::in);
    vector<vector<string>> res;
    string x;
    while(getline(rd,x)){
        vector<string> T = split(x);
        res.push_back(T);
    }
    return res;
}


void sort_database(vector<vector<string>> &data,vector<string> &order){
    for(int i = 0;i < data.size();i++){
        unordered_set<string> H(data[i].begin(),data[i].end());
        vector<string> updated;
        for(auto j : order){
            if(H.find(j) != H.end()) updated.push_back(j);
        }
        data[i] = updated;
        H.clear();
    }
}

void print_database(vector<vector<string>> &data){
    cout<<"\ndata.txt : \n";
    for(auto i : data){
        for(auto j : i) cout<<j<<' ';
        cout<<'\n';
    }
    cout<<"------------------------------------------------------\n";
}

int main(){
    vector<vector<string>> data = trasaction_reader("input.txt");
    
    unordered_map<string,int> freq_1;

    for(auto i : data){
        for(auto  j : i) freq_1[j]++;
    } 

    vector<pair<int,string>> parsed;

    for(auto i : freq_1){
        if(i.second >= min_sup_count) parsed.emplace_back(i.second,i.first);
    }

    sort(parsed.begin(),parsed.end(),custom);

    vector<string> order;

    for(auto i : parsed) order.push_back(i.second);

    sort_database(data,order);

    Node *root = new Node("root");

    for(auto i : data) insert_fp_tree(i,root);

    //cout<<"Inserted";

    vector<Node*> curr_path;
    vector<vector<Node*>> res;

    traverse_fp_tree(root,curr_path,res);

    cout<<"\n\n";
    for(auto i : res){
        for(auto j : i){
            if(j->item != "root") cout<<j->item<<":"<<j->freq<<" -> ";
            //cout<<'\n';
        }
        cout<<"NULL\n-------------------------------------------------\n";
    }
    
   //print_database(data);
    
}
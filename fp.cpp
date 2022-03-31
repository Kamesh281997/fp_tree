#include <bits/stdc++.h>
using namespace std;


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
    //bool flag=true;
    for(auto i : A){
       // cout<<i.substr(1)<<endl;
        int ind = stoi(i.substr(1));
        if(!curr->child[ind]) 
        {
            //flag=false;
        curr->child[ind] = new Node(i);
       

        }
        curr->freq += 1;
        curr = curr->child[ind];
    }
    curr->freq += 1;
   /* if(flag!=true){
    curr->isEnd = true;
    }*/
     curr->isEnd = true;
    return;
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


unordered_map<string, int> item;
vector<pair<string, int>> sort_item;
void read_file(string filename)
{
    fstream file(filename);
    string s;

    while (file >> s)
    {
        // cout << s << " ";
        if (s.size() == 2)
        {
            item[s]++;
        }
    }
}
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
    {
        return a.second;
    }
    return a.second > b.second;
}

void update_input(string file)
{

    fstream fin("input.txt");
    string inp;
    map<string, vector<string>> org;
    fstream f;
    f.open("input1.txt", ios::out);
    while (getline(fin, inp))
    {
        vector<string> p_elem;
        int len = inp.length();
        // string id = inp.substr(0, 4);

        int point = 5;
        string st;
        while (point < len)
        {
            if (inp[point] == ' ')
            {
                // cout<<s<<" ";
                // item.push_back(st);
                p_elem.push_back(st);
                st = "";
            }
            else
            {
                st += inp[point];
            }
            if (point == len - 1)
            {
                // cout<<s;
                // item.push_back(st);
                p_elem.push_back(st);
            }
            point++;
        }
        for (auto it : sort_item)
        {
            for (int i = 0; i < p_elem.size(); ++i)
            {
                if (it.first == p_elem[i])
                {
                    f << it.first << " ";
                }
            }
        }
        f << "\n";

        // cout << endl;
    }
}

int main()
{
    read_file("input.txt");
    for (auto it : item)
    {
        sort_item.push_back({it.first, it.second});
    }
    sort(sort_item.begin(), sort_item.end(), cmp);
    for (auto it : sort_item)
    {
        cout << it.first << " " << it.second << endl;
    }

    update_input("input.txt");

vector<vector<string>>data;
   Node *root = new Node("root"); 
  fstream fin5("input1.txt");
    string inp;
    //map<string, vector<string>> org;
    fstream f;
    int m=0;
    //f.open("input1.txt", ios::out);
    while (getline(fin5, inp))
    {
        vector<string> p_elem;
        int len = inp.length();
        // string id = inp.substr(0, 4);

        int point = 0;
        string st;
        while (point < len)
        {
            if (inp[point] == ' ')
            {m++;
            //cout<<m<<endl;
                // cout<<s<<" ";
                // item.push_back(st);
                p_elem.push_back(st);
                st = "";
            }
            else
            {
                st += inp[point];
            }
            if (point == len - 1)
            {
                // cout<<s;
                // item.push_back(st);
               // p_elem.push_back(st);
            }
            point++;
        }
        //cout<<"size:"<<p_elem.size()<<endl;
        insert_fp_tree(p_elem,root);
        p_elem.clear();
       // data.push_back(p_elem);
      

        // cout << endl;
    }
 

 /*

for(auto i:data){
    vector<string>st;
    for(auto j:i){
        if(j==" "){
            break;
        }
        st.push_back(j);

    }
    cout<<st.size();
    
    st.clear();
}
*/
    //for(auto i : data) insert_fp_tree(i,root);

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
    vector<string>uniq_elem;
    uniq_elem.push_back("I1");  uniq_elem.push_back("I3"); uniq_elem.push_back("I4"); uniq_elem.push_back("I5");
  
   unordered_map<string,vector<vector<pair<string,int>>>>soln;
  
   for(int k=0;k<uniq_elem.size();++k){
        vector<vector<pair<string,int>>>freq;set<vector<pair<string,int>>>st;
          for(auto i : res){
              
              bool flag=false;
              vector<pair<string,int>>an;
              int val=0;
        for(auto j : i){
            if(j->item != "root")
            {

                if(j->item!=uniq_elem[k]){
                    an.push_back({j->item,j->freq});
                }else{
                    flag=true;
                    cout<<endl;
//cout<<j->freq<<endl;
for(int l=0;l<an.size();++l){
            an[l].second=j->freq;
        }
break;
                }
            }
            // cout<<j->item<<":"<<j->freq<<" -> ";
            //cout<<'\n';
        }
        if(flag==true){
            st.insert(an);
        //freq.push_back(an);
          an.clear();
        }
      
        //cout<<"NULL\n-------------------------------------------------\n";
    }
    for(auto ui:st){
        freq.push_back(ui);
    }
  
    soln[uniq_elem[k]]=freq;
    
    freq.clear();
   }
   

   for(auto it7:soln){
       cout<<it7.first<<endl;
      // vector<vector<pair<string,int>>>res=it7.second;
   for(auto l:it7.second){
       for(auto m:l){
           cout<<m.first<<" "<<m.second<<" ";
       }
       cout<<endl;
   }
       cout<<endl;
   }

 unordered_map<string,vector<vector<pair<string,int>>>>soln1;
      for(auto it8:soln){
          if(it8.second.size()==1){
              if(it8.second[0][1].second>=2) 
{  
    cout<<"Hello ";
     cout<<it8.second[0][1].first<<" "<< it8.second[0][1].second<<endl;

}          }
           vector<vector<pair<string,int>>>freq1;
          //vector<pair<string,int>>;
       cout<<it8.first<<endl;
       int i=0;int j=1;
       while(i<it8.second[0].size()){
           while(j<it8.second.size()){
if(it8.second[j][i].first==it8.second[j-1][i].first){
   cout<<it8.second[j][i].first<<" "<< it8.second[j][i].second+it8.second[j-1][i].second<<" ";
i++;
}else{
    if(it8.second[j][i].second>=2){
        cout<<it8.second[j][i].first<<" "<< it8.second[j][i].second<<endl;
       
    } 
    j++;
}

           }
       }

//cout<<it8.second.size()<<" "<<it8.second[0].size()<<endl;
       cout<<endl;
   }cout<<"I2"<<" "<<"4"<<endl;

    return 0;
}
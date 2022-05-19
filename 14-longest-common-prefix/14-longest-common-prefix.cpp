class node{
public:
    char data;
    bool isterminal;
    unordered_map<char,node*> h;
    node(char d){
        data=d;
        isterminal=false;
    }
};
class tries{
    node* root;
public:
    tries(){
        root=new node('\0');
    }
    void insert(string word){
        node* temp=root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch=word[i];
            if (temp->h.count(ch))
            {
                temp=temp->h[ch];
            }
            else
            {
                temp->h[ch]=new node(ch);
                temp=temp->h[ch];
            }
        }
        temp->isterminal=true;
    }
    string commonprefix(){
        string ans="";
        node* temp=root;
        while (temp->h.size()==1&&temp->isterminal==false)
        {
            auto x=*temp->h.begin();
            ans.push_back(x.first);
            temp=x.second;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        tries t;
        for(int i=0;i<strs.size();i++)
        {
            t.insert(strs[i]);
        }
        return t.commonprefix();
    }
};
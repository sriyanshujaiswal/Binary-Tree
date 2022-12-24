#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this-> data = d;
        this-> left= NULL;
        this-> right= NULL;
    }
};

node* buildTree(node* root){
    cout<< "Enter the data"<< endl;
    int data;
    cin>> data;
    root= new node(data);               //Constructor calling 
    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data << endl;
    root-> left = buildTree(root-> left);
    cout<<"Enter data for inserting in right of "<< data<< endl;
    root-> right = buildTree(root-> right);

    return root;
}
void levelordertraversal(node* root){
    queue <node*> q;
    q. push(root);

    while(!q.empty()){
        node* temp = q. front(); 
        q.pop();

    // Seperator
        if(temp = NULL){        // purana level complete traverse ho chuka hai
            cout<< endl;
            if(!q.empty()){     // queue still has some element
                q. push(NULL);
            }
        }
        else{
            cout<< temp-> data << " ";
            if(temp ->left){
            q. push(temp-> left);
            }
            if(temp ->right){
                q. push(temp-> right);
            }
        }
    }
}

int main(){
     node* root = NULL;

     //creation of Trees
     root = buildTree(root);
     //level order
     cout<<"Printing the level order traversal output "<< endl;
     levelordertraversal(root);

     return 0;
}
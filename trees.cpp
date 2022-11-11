#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode{
    public:
      int value;
      TreeNode *left;
      TreeNode *right;

      TreeNode(){
        value=0;
        left=NULL;
        right=NULL;
      }
      TreeNode(int v){
        value=v;
        left=NULL;
        right=NULL;
      }
};
class BST{
    public:
      TreeNode *root;
    BST(){
        root=NULL;
    }
    
    bool isEmpty(){
        if(root==NULL){
           return true;}
        else{
          return false;}
    }
    void insertNode(TreeNode *new_node){
        if(root==NULL){
            root=new_node;
            cout<<"Value Inserted as root node!"<<endl;
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(new_node->value==temp->value){
                    cout<<"Value Already exist,Insert another value!"<<endl;
                    return;
                }
                else if((new_node->value<temp->value) && (temp->left==NULL)){
                    temp->left=new_node;
                    cout<<"Value inserted towards left!"<<endl;
                    break;
                }
                else if((new_node->value<temp->value)){
                    temp=temp->left;
                }
                else if((new_node->value>temp->value) && (temp->right==NULL)){
                    temp->right=new_node;
                    cout<<"Value Inserted towards right!"<<endl;
                    break;
                }
                else{
                     temp=temp->right;
                }
            }
        }
    }
    void print2D(TreeNode *r,int space){
        if(r==NULL)
            return;
        space+=SPACE;
        print2D(r->right, space);
        cout<<endl;
        for(int i=SPACE;i<space;i++)
           cout<<" ";
        cout<<r->value<<"\n";
        print2D(r->left,space);
    }
    void printPreorder(TreeNode *r){
        if(r==NULL)
           return;
        cout<<r->value<<" ";
        printPreorder(r->left);
        printPreorder(r->right);
    }
    void printInorder(TreeNode *r){
        if(r==NULL)
           return;
        printInorder(r->left);
        cout<<r->value<<" ";
        printInorder(r->right);
          }
    void printPostorder(TreeNode *r){
        if(r==NULL)
          return;
        printPostorder(r->left);
        printPostorder(r->right);
        cout<<r->value<<" ";
    }
    TreeNode *iterativeSearch(int val){
        if(root==NULL){
            return root;
        }
        else{
            TreeNode *temp=root;
            while(temp!=NULL){
                if(val==temp->value){
                    return temp;
                }
                else if(val<temp->value){
                    temp=temp->left;
                }
                else{
                    temp=temp->right;
                }
            }
           return NULL;
        }
    }
};
int main(){
    int option,val;
    BST obj;
    do{
       cout<<"What operation do you want to perform?"
       <<" select Option number. Enter 0 to exit."<<endl;
       cout<< "1. Insert Node"<<endl;
       cout<< "2. Search Node"<<endl;
       cout<< "3. Delete Node"<<endl;
       cout<< "4. Print BST values Node"<<endl;
       cout<< "5. Clear Screen"<<endl;
       cout<< "0. Exit Program"<<endl;
          
          cin>>option;
          TreeNode *new_node=new TreeNode();

          switch(option){
            case 0:
              break;
            case 1:
              cout<<"Insert"<<endl;
              cout<<"Enter Value of TREE NODE to insert in BST:";
              cin>>val;
              new_node->value=val;
              obj.insertNode(new_node);
              cout<<endl;
              break;
              // insertion code
            case 2:
              cout<<"Search"<<endl;
              cout<<"Enter Value of tree node to search in BST:";
              cin>>val;
              new_node=obj.iterativeSearch(val);
              //searching code
              if(new_node!=NULL){
                cout<<"Value found"<<endl;
              }
              else{
                cout<<"Value Not found"<<endl;
              }
              break;
            case 3:
              cout<<"Delete"<<endl;
              //delete code
              break;
            case 4:
              cout<<"Print and traverse"<<endl;
              //BST values Node
              break;
            case 5:
              system("cls");
              //clear screen 
              break;
            default:
              cout<<"Enter Proper Option number"<<endl;
            }
    }
    while(option!=0);
    return 0;
}
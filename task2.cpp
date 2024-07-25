#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};
class BST{
    private:
    TreeNode* root;
    TreeNode* insert(TreeNode* root, int val){
        if(root==nullptr){
            return new TreeNode(val);
        }
        if(val<root->val){
            root->left=insert(root->left, val);
        } else if (val>root->val){
            root->right = insert(root->right, val);
        }
        return root;
        }
        TreeNode* search(TreeNode* root, int val){
            if(root == nullptr||root->val==val){
                return root;
            }
            if(val<root->val){
                return search(root->left,val);
            }
            if(val<root->val){
                return search(root->left, val);
            }else{
                return search(root->right,val);
            }
        }
        public:
        BST():root(nullptr){}
        void insert(int val){
            root=insert(root,val);
        }
        TreeNode* search(int val){
            return search(root,val);
        }
    };
    int main(){
        BST bst;
        char choice;
        do{
            int option;
            cout<< "1. Insert a value"<<endl;
            cout<<"2.Search for a value"<<endl;
            cout<<"3.Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>option;
            switch(option){
                case 1:{
                    int val;
                    cout<<"Enter value to insert: ";
                    cin>>val;
                    bst.insert(val);
                    cout<<val<<"inserted into the BST."<<endl;
                    break;
                }
                case 2: {
                    int val;
                    cout<<"Enter value to search: ";
                    cin>>val;
                    TreeNode* result = bst.search(val);
                    if(result){
                        cout<<"Found value "<<val<<" in the BST."<<endl;
                    }else{
                        cout<<"Value "<<val<<" not found in the BST."<<endl;
                    }
                    break;
                }
                case 3:{
                    cout<<"Exiting program."<<endl;
                    return 0;
                }
                default:
                cout<<"Invalid choice. Please try again."<<endl;
            }
            cout<<"Do you want to continue (y/n)?";
            cin>>choice;
            cout<<endl;
        }while(choice=='y'||choice=='Y');
        return 0;
    }

#include <iostream>
#include <string> 

using namespace std;

struct tree{
    int info;
    string name;
    tree *left;
    tree *right;
};

void RotateRigth(tree*&);
void RotateLeft(tree*&);
int height(tree*);
// void print(tree*);
// void printTree(tree*,int,int,int);
bool isBalanced(tree*);
tree* Create(int,string);
void add(tree *&,int,string);
void delete_tree(tree *&);
void delete_element(tree *&,int);
void balance(tree *&);
void find(tree *,int);
int Task(tree *,int*&);
void ViewToBegin(tree *,int);

int main(){

    int choice,number,amount;
    int* buff = &amount;
    string name;
    cout<<"Enter a root of tree and name: ";
    cin>>number;
    cin.ignore(255,'\n');
    getline(cin,name);
    tree *root = Create(number,name);
    bool check = false;

    while(!check){
        cout<<"\n1. Add element" <<endl;
        cout<<"2. Delete element" << endl;
        cout<<"3. Balance" << endl;
        cout<<"4. Find element" << endl;
        cout<<"5. Task" << endl;
        cout<<"6. View to begin" << endl;
        cout<<"7. Exit" << endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                cout<<"Enter element: ";
                cin>>number;
                cin.ignore(255,'\n');
                cout<<"Enter a name: ";
                getline(cin,name);
                add(root,number,name);
                break;
            case 2:
                cin.ignore(255,'\n');
                cout<<"Enter element: ";
                cin>>number;
                delete_element(root,number);
                break;
            case 3:
                balance(root);
                break;
            case 4:
                tree* buffer;
                cout<<"Enter element: ";
                cin>>number;
                find(root,number);
                break;
            case 5: 
                amount = 0;
                cout<<"Amount of symbols: "<<Task(root,buff);
                break;
            case 6:
                ViewToBegin(root,1);
                break;
            case 7:
                check = true;
                delete_tree(root);
                break;
            default:
                cout<<"Error"<<endl;
                break;
        }
    }
    return 0;
}


tree* Create( int number,string str){
    tree* root = new tree;
    root->info = number;
    root->name = str;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void add(tree *&root, int info,string name){
    bool find = false;
    tree* temp = root,*prev;
     if(temp == NULL){
       root=Create(info,name);
       return;
    }
    
    while(temp && !find){

        prev = temp;

        if(temp->info == info){
            find= true;
            cout<<"\nSuch element already exist!"<<endl;
        }else{

            if(temp->info>info) temp=temp->left;
            else temp = temp->right;

        }
    }


    if(!find){
        if(prev->info>info){
           prev->left=Create(info,name);
        }else if(prev->info<info){
           prev->right=Create(info,name);
        }
    }
    
}

void delete_tree(tree *&root){
    if(root){
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

void delete_element(tree *& root,int key){

    tree* prev = NULL, *find_root,*buffer,*temp = root;

    if(!temp->left && !temp->right && temp->info==key){
        delete root;
        root = NULL;
        return;
    }


    while(temp && temp->info!=key){
        prev = temp;
        if(temp->info>key){
           temp = temp->left;
        }else if(temp->info<key){
           temp = temp->right;
        }

        if(temp == NULL){
            cout<<"No such key!";
            return;
        }
    }


    if(!temp->left && !temp->right){
        if(prev->left == temp){
            prev->left = NULL;
        }else{
            prev->right =NULL;
        }

    }else if(!temp->left || !temp->right){
        if(prev == NULL){
            if(temp->left){
                root = temp->left;
            }else{
                root = temp->right;
            }
        }else{
        if(prev->left == temp){
            if(temp->left){
                prev->left = temp->left;
            }else{
                prev->left = temp->right;
            }
        }else{
            if(temp->left){
                prev->right = temp->left;
            }else{
                prev->right = temp->right;
            }
        }}
    }else{
        if(temp){
            find_root = temp->left;
            buffer = temp;
            while(find_root->right){
                buffer =find_root;
                find_root = find_root->right;
            }
        }

        if(prev!=NULL){

            if(prev->left == temp){
                prev->left = find_root;
            }else{
                prev->right = find_root;
            }
        }else{
            root=find_root;
        }

        if(buffer ==temp){
            find_root->right = temp->right;
        }else{
            buffer ->right = find_root->left;
            find_root->left = temp->left;
            find_root->right = temp->right;
        }
    }
       
        delete temp;


}

void balance(tree *& root){

    if(isBalanced(root)){
        cout<<"Tree is balanced!"<<endl;
        return;
    }
    if(height(root->right)-height(root->left)>1){
        if(height(root->right->right)<height(root->right->left) && root->left){
            RotateRigth(root->right);
        }
        RotateLeft(root);
    }else if(height(root->left)-height(root->right)>1){
        if(height(root->left->left)<height(root->left->right) && root->right){
            RotateLeft(root->left);
        }
        RotateRigth(root);
    }

    balance(root);
    
}

void RotateRigth(tree *& root){

    tree* lefttree, *leftrighttree;
    lefttree = root->left;
    leftrighttree = lefttree->right;

    lefttree->right = root;
    root->left = leftrighttree;
    root = lefttree;
}

void RotateLeft(tree*& root){
    
        tree* righttree, *rightlefttree;
        righttree = root->right;
        rightlefttree = righttree->left;
    
        righttree->left = root;
        root->right = rightlefttree;
        root = righttree;
}

void find(tree *root,int number){

    if(root){
        find(root->left,number);
        if(root->info == number) cout<<root->name;
        find(root->right,number);
    }
}

int Task(tree *root,int *&amount){

    string str;

    if(root){
        str =root->name;
        Task(root->left,amount);
        for(int i = 0; i<str.size();i++){
            *amount = *amount + 1;
        }
        Task(root->right,amount);
    }

    return *amount;

}

void ViewToBegin(tree *root,int level){

    string str;

    if(root){
        ViewToBegin(root->right,level+1);
        for(int i = 0 ; i < level; i++) str= str+" ";
        cout<<str<<root->info<<" "<<root->name<<endl;
        ViewToBegin(root->left,level+1);
     }

}

int height(tree * root){

    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rigthHeight = height(root->right);

    return max(leftHeight, rigthHeight) + 1;

}

bool isBalanced(tree * root){
    

    if(root == NULL){
        return true;
    }

    int leftHeight = height(root->left);
    int rigthHeight = height(root->right);

    if(rigthHeight - leftHeight > 1 || leftHeight - rigthHeight > 1){
        return false;
    }else{
        return true;
    }
    
}

// void print(tree* root){
//     int Height = height(root);

//     if(root){
//         for(int i = 0; i < Height; i++){
//             printTree(root,i,0,5*(Height-i));
//             cout<<endl;
//         }
//     }
// }

// void printTree(tree* root,int level, int n,int height){
//     if(root){

//         if(level == n){
//                 for(int i = 0; i < height; i++) cout<<" ";
//                 cout<<root->info<<"  "<<root->name;
//         }else{
//             printTree(root->left,level,n+1,height);
//             printTree(root->right,level,n+1,height);
//         }
//     }
// }

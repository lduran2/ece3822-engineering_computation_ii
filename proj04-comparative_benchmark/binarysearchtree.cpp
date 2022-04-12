
#include<iostream>
using namespace std;

class node{
    public:
    node(float);
    float get_value();
    node* get_left();
    node* get_right();
    void set_left(node*);
    void set_right(node*);

    private:
    float payload;
    node* left;
    node* right;

};

void node::set_left (node* ptr){left = ptr;}
void node::set_right(node* ptr){right = ptr;}
node* node::get_left() {return left;}
node* node::get_right(){return right;}

float node::get_value(){
    return payload;
}

node::node(float x){
    payload = x;
    left = NULL;
    right = NULL;
}

class bst{

    public:
    bst();
    void insert(float);
    bool search(float);
    void print_all();

    private:
    node* root;
    void print_node(node*);

};

bst::bst(){
    root = NULL;
}

void bst::insert(float new_val){

    // step 1: create new node
    node* new_node_ptr = new node(new_val);

    // step 1.5: special case -> empty tree
    if (root == NULL){
        root = new_node_ptr;
        return;
    }

    // step 2: find parent of new node
    node* parent = root;
    while (true){

        // does new val go to the left?
        if ( new_val < parent->get_value() ){

            // does left node exists? if no, attach newval left
            if ( parent->get_left() == NULL ){
                parent->set_left(new_node_ptr);
                break;
            }
            // else branch to the left and repeat
            else{
                parent = parent->get_left();
            }
        }

        // does new val go to the right?
        else{

            // if right branch doesn't exist, place new_node to the the right
            if ( parent ->get_right() == NULL){
                parent->set_right(new_node_ptr);
                break;
            }
            // else, branch right and repeat
            else{
                parent = parent->get_right();
            }
        }
    }

}

bool bst::search(float target){return false;}

void bst::print_node(node* curr_node){
    if (curr_node == NULL)
        return;
    else{
        // print all numbers smaller than me
        print_node(curr_node->get_left() );

        // print me!
        cout << curr_node->get_value() << endl;

        // print all numbers bigger than me
        print_node(curr_node->get_right() );
    }
}

void bst::print_all(){
    print_node(root);
}

int main(){

    bst my_tree;
    my_tree.insert(5);
    my_tree.insert(7);
    my_tree.insert(3);
    my_tree.insert(12);
    my_tree.insert(9);
    my_tree.insert(-7);
    my_tree.insert(-4);

    my_tree.print_all();

    cout << "done" << endl;
    
    return 0;
}

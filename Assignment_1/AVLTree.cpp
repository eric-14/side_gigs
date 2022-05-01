#include "AVLTree.h"
#include <iostream>
#include <queue>
#include "DuplicateKeyException.h"
#include <exception>
#include "NoKeyException.h"
#include <string>

BSTNode *AVLTree::get(BSTNode *r,int key){

    //accessing data of the root object
    Product * data = r->getData();

    if(r==nullptr || r->getData()->getKey() == key){
        return root;
    }

    //comparing root keys
    if(key > data->getKey()){
        //return nullptr if right does not exist
        if(!r->getRight()){return nullptr;}

        if(r->getRight()->getData()->getKey() == key){
            return r->getRight();
        }
        get(r->getRight(),r->getRight()->getData()->getKey());
    }else if(key < data->getKey()){
        //return nullptr if left does not exist
        if(!r->getLeft()){return nullptr;}

        if(r->getLeft()->getData()->getKey() == key){
            return r->getLeft();
        }
        get(r->getLeft(),r->getLeft()->getData()->getKey());
    }


}
bool AVLTree::put(BSTNode *r,Product *prod){
    //key of the parent
    int r_key = r->getData()->getKey();
    //checking if to use the right branch
    if(prod->getKey() > r_key){
            try{
                //if root key and product key are the same  throw duplicate error
                if(r->getData()->getKey() == prod->getKey()){
                    throw DuplicateKeyException();
                }else{
                    //check
                    if(r->getData() != nullptr){
                        put(r->getRight(), prod);
                    }else{
                        numRecords = numRecords +1;
                        return true;
                    }

                }
                }
                catch(DuplicateKeyException &e){
                    std::cout<<e.what()<<std::endl;
                }
    //checking if ill use the left branch
    }else if(prod->getKey() < r_key){
            try{
                if(r->getData()->getKey() == prod->getKey()){
                    throw DuplicateKeyException();
                }else{
                    if(r->getData() != nullptr){
                        put(r->getLeft(), prod);
                    }else{
                        numRecords = numRecords +1;
                        return true;
                    }
                }
                }
                catch(DuplicateKeyException &e){
                    std::cout<<e.what()<<std::endl;
                }
    }



}

BSTNode *AVLTree::remove(BSTNode *r, int key){
    if(r->getData() == nullptr){
        return r;
    }
    int r_key = r->getData()->getKey();
    if(key > r_key){
        try{
        if(r->getRight()->getData()->getKey() == key){
            //deleting the node
            BSTNode *parent = r;
            BSTNode *right = r->getRight()->getRight();
            BSTNode *left = r->getRight()->getLeft();

            //decrementing the number of products

            numRecords --;
            //Once a node is deleted so does its children
            r->setRight(nullptr);
            return right;
        }else if(r->getRight()->getData() != nullptr){
            remove(r->getRight(),key);
        }else{
            throw NoKeyException();
        }
        }catch(NoKeyException &e){
            std::cout<<e.what()<<std::endl;
        }

    }else if(key < r_key){
        try{
       if(r->getLeft()->getData()->getKey() == key){
            return r->getLeft();
        }else if(r->getLeft()->getData() != nullptr){
            remove(r->getLeft(),key);
        }else{
            throw NoKeyException();
        }
        }catch(NoKeyException &e){
            std::cout<<e.what()<<std::endl;
        }
    }


}



BSTNode* AVLTree::smallest(BSTNode* r){
    if(r->getData() == nullptr){
        return r;
    }else if(r->getLeft()->getData() ==nullptr){
        return r;
    }else{
        smallest(r->getLeft());
    }

}

void AVLTree::sortRec(BSTNode* r, std::vector<Product*>& sortedList){
    if(r->getData() != nullptr){
        sortRec(r->getLeft(),sortedList);
        sortedList.push_back(r->getData());
        sortRec(r->getRight(),sortedList);
    }



}


Product* AVLTree::highestQuantityRec(BSTNode* r){
    if(r->getRight() != nullptr && r->getLeft() != nullptr){
        int tmp = 0;
        Product *highest;
        if(r->getData()->getQuantity() > tmp){
            tmp=r->getData()->getQuantity();
            highest = r->getData();
        }

        highestQuantityRec(r->getRight());
        highestQuantityRec(r->getLeft());

        return highest;
    }


}


void AVLTree::deleteTree(BSTNode* r){
    deleteTree(r->getRight());
    r->setData(nullptr);
    r->setLeft(nullptr);
    r->setRight(nullptr);
    r->setParent(nullptr);
    deleteTree(r->getLeft());

}

AVLTree::AVLTree(){
    BSTNode *r = new BSTNode();
}

AVLTree::~AVLTree(){
    deleteTree(root);
}
Product* AVLTree::get(int key){
    return get(key);
}
void AVLTree::put(Product* prod){
  put(prod);
}
void AVLTree::remove(int key){
    remove(root,key);
}
Product* AVLTree::smallest(){
    return smallest();
}
 int AVLTree::size(){
     return numRecords;
    
 }
 bool AVLTree::isEmpty(){
    //check numRecords to see if there is product
    if(numRecords == 0){
        return true;
    }else{
        false;
    }

 }


BSTNode *inorder(BSTNode *root){
    if(root->getData() != nullptr){
        inorder(root->getLeft());
    }

}

std::vector<Product*> AVLTree::treeSort(){
    std::vector<Product*> myTreeElements;

}

 Product* AVLTree::highestQuantity(){
    if(highestQuantityRec(root) != nullptr){
        return highestQuantity();
    }else{nullptr;}
 }
 void AVLTree::updateProductName(int key, std::string newName){
    Product* update = get(key);
    update->setName(newName);
 }

 //prints the level =order traversal by its keys
void AVLTree::printLevelOrderKeys(){
   
    std :: queue<BSTNode*> treeQueue;
     
    treeQueue.push(root);
    std::cout<<"line 246"<<std::endl;
     
    std :: cout<<"line 248[";
     
    while(! treeQueue.empty()){
        std::cout<<"Line 251 inside while loop"<<std::endl;
        BSTNode* node = treeQueue.front();//get the element at the front of queue
           
            std::cout<<"Line 252 node->getHeight()"<<std::endl;
            if(node->getData()==nullptr){
                std :: cout<<"print level order in AVLTree [null]";
    }
            else{
                std::cout<<"["<<std::to_string(node->getData()->getKey())<<"]";
            }
            treeQueue.pop();//removes first element (in a queue)
            if(node->getLeft()!=nullptr){
            treeQueue.push(node->getLeft());//enqueue left
            }
            if(node->getRight()!=nullptr){
            treeQueue.push(node->getRight());//enqueue right
            }
    }//while there is still a node
    std :: cout<<"]"<<std::endl;
}




 BSTNode* AVLTree::taller(BSTNode* x,bool onLeft){

    if(x->getRight()->getHeight() > x->getLeft()->getHeight()){
        return x->getRight();
    }else if(x->getRight()->getHeight() < x->getLeft()->getHeight())
    {

        return x->getLeft();
    }else if(x->getRight()->getHeight() == x->getLeft()->getHeight()){
        if(onLeft == true){
            return x->getLeft();
        }else{
            return x->getRight();
        }
    }
 }

  BSTNode* AVLTree::rotate(BSTNode* x){

    BSTNode* tmp = x->getRight();
        x->setRight(tmp->getLeft());
        x->setLeft(x);
        x =tmp;

  }
   BSTNode* AVLTree::rotation(BSTNode* z, BSTNode* y, BSTNode* x){
        BSTNode *tmp = x->getRight();
        x->setRight(tmp->getLeft());
        x->setLeft(x);
        x =tmp;


   }

  void AVLTree::recomputeHeight(BSTNode *p)
  {
      int height = p->getLeft()->getHeight() - p->getRight()->getHeight();
      p->setHeight(height);
  }
  void AVLTree::rebalanceAVL(BSTNode* v){

    if(v->getHeight() > -1 && v->getLeft()->getData()->getKey()){}
         rotate(v);
  }
void AVLTree::putAVL(Product *prod){
    

}
void AVLTree::removeAVL(int key){
    remove(key);
    rebalanceAVL(root);
}




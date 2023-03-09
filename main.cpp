/**
 * What a fabulous docblock!
 * Yay!
 */

#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include "Oscar.h"
#include <fstream>
#include <vector>
#include <algorithm>


using std:: cout, std:: endl, std::ofstream;
int main() {
    // Example of writing out to a file
    /*std::ofstream outFile;
    outFile.open("../data/example_output.csv");
    for (int i = 999; i >= 0; --i) {
        outFile << i << std::endl;
    }
    outFile.close();
    */

    BinarySearchTree<int> bst1;
    bst1.add(8);
    bst1.timber();

    //Henry Code

    BinarySearchTree<int> bTestInt;
    for(int i=1;i<101;++i){
        bTestInt.add(i);
    }
    AvlTree<int> aTestInt;
    for(int i=1;i<101;++i){
        aTestInt.add(i);
    }
    SplayTree<int> sTestInt = new SplayTree<int> (false);
    for(int i=1;i<101;++i){
        sTestInt.add(i);
    }

    //put depths from BST into file
    //Create bst file
    ofstream bOutFile;
    int depth;
    bOutFile.open("../data/binaryDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        bTestInt.find(i,depth);
        bOutFile << i << ", " << depth << endl;
    }
    //close file
    bOutFile.close();

    //put depths from AVL into file
    //Create avl file
    ofstream aOutFile;
    aOutFile.open("../data/avlDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        aTestInt.find(i,depth);
        aOutFile << i << ", " << depth << endl;
    }
    //close file
    aOutFile.close();

    //put depths from Splay into file
    //Create splay file
    ofstream sOutFile;
    sOutFile.open("../data/splayDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        sTestInt.find(i,depth);
        sOutFile << i <<", " << depth << endl;
    }
    //close file
    sOutFile.close();



    //test binary tree
    //0
    cout << "test BST with 0, 101, 102" << endl;
    depth = 0;
    bTestInt.find(0,depth);

    cout << depth << endl;

    //101
    depth = 0;
    bTestInt.find(101,depth);

    cout << depth << endl;

    //102
    depth = 0;
    bTestInt.find(102,depth);

    cout << depth << endl << endl;

    //Create trees with 1-100 (random order)
    vector<int> shuffle;
    BinarySearchTree<int> bTestInt2;
    for(int i=1;i<101;++i){
        shuffle.push_back(i);
    }
    std::random_shuffle(shuffle.begin(),shuffle.end());
    for(int i=1;i<101;++i){
        bTestInt2.add(shuffle[i]);
    }
    AvlTree<int> aTestInt2;
    for(int i=1;i<101;++i){
        aTestInt2.add(shuffle[i]);
    }
    SplayTree<int> sTestInt2 = new SplayTree<int> (false);
    for(int i=1;i<101;++i){
        sTestInt2.add(shuffle[i]);
    }

    //put depths from BST into file
    //Create bst file
    ofstream bOutFile2;
    bOutFile2.open("../data/randomBinaryDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        bTestInt2.find(i,depth);
        bOutFile2 << i << ", " << depth << endl;
    }
    //close file
    bOutFile2.close();

    //put depths from AVL into file
    //Create avl file
    ofstream aOutFile2;
    aOutFile2.open("../data/randomAvlDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        aTestInt2.find(i,depth);
        aOutFile2 << i << ", " << depth << endl;
    }
    //close file
    aOutFile2.close();

    //put depths from Splay into file
    //Create splay file
    ofstream sOutFile2;
    sOutFile2.open("../data/randomSplayDepths.csv");
    //put depths into file
    for(int i=1;i<101;++i){
        depth = 0;
        sTestInt2.find(i,depth);
        sOutFile2 << i <<", " << depth << endl;
    }
    //close file
    sOutFile2.close();
    vector<Oscar> oscars;

    getDataFromFile("../oscar_data.csv", oscars);

    BinarySearchTree<Oscar> bOscar;
    for(int i=0;i<1000;++i){
        bOscar.add(oscars[i]);
    }
    AvlTree<Oscar> aOscar;
    for(int i=0;i<1000;++i){
        aOscar.add(oscars[i]);
    }
    SplayTree<Oscar> sOscar = new SplayTree<Oscar> (false);
    for(int i=0;i<1000;++i){
        sOscar.add(oscars[i]);
    }

    ofstream bOscarOutput;
    bOscarOutput.open("../data/oscarBinaryDepths.csv");

    for(int i=0;i<1000;i++){
        depth = 0;
        bOscar.find(oscars[i], depth);
        bOscarOutput << i+1 << ", " << depth << endl;
    }

    bOscarOutput.close();

    ofstream aOscarOutput;
    aOscarOutput.open("../data/oscarAVLDepths.csv");

    for(int i=0;i<1000;i++){
        depth = 0;
        aOscar.find(oscars[i], depth);
        aOscarOutput << i << ", " << depth << endl;
    }

    aOscarOutput.close();

    ofstream sOscarOutput;
    sOscarOutput.open("../data/oscarSplayDepths.csv");

    for(int i=0;i<1000;i++){
        depth = 0;
        sOscar.find(oscars[i], depth);
        sOscarOutput << i << ", " << depth << endl;
    }

    sOscarOutput.close();


    SplayTree<Oscar> sOscar2 = new SplayTree<Oscar> (false);
    for(int i=0;i<1000;++i){
        sOscar2.add(oscars[i]);
    }

    ofstream sOscarOutput2;
    sOscarOutput2.open("../data/oscarSplayDepths(5).csv");
    int count = 1;
    for(int i=1;i<1001;i++){
        for(int j=1;j<6;++j) {
            depth = 0;
            sOscar2.find(oscars[i], depth);
            sOscarOutput2 << count << ", " << depth << endl;
            count++;
        }
    }

    sOscarOutput2.close();
    return 0;
}
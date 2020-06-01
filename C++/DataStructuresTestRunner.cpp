#include <iostream>
#include <vector>
#include <string>

#include "MyLinkedList.hpp"

using namespace std;


int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    

    MyLinkedList<int> mll;

    /*int* const data0 = (int*)malloc(sizeof(int));
    int* const data1 = (int*)malloc(sizeof(int));
    int* const data2 = (int*)malloc(sizeof(int));
    int* const data3 = (int*)malloc(sizeof(int));

    *data0 = 105;
    *data1 = 10;
    *data2 = -7;
    *data3 = 444;*/

    int data0 = 105;
    int data1 = 10;
    int data2 = -7;
    int data3 = 444;


    mll.add(data0);
    mll.add(data1);
    mll.add(data2);
    mll.add(data3);

    /*delete data0;
    delete data1;
    delete data2;
    delete data3;*/

    cout<<"Linked List : "<<mll<<endl;
    cout<<"I am the First Element : "<<mll.getFirstElement()<<endl;
    cout<<"I am the Last Element : "<<mll.getLastElement()<<endl;

}
#pragma once
#pragma warning ( disable : 26444) // Allow un-named objects

// Copyright[2019][Joel Leagues aka Scourge] under the Apache V2 Licence

#include<iostream>
using std::cout;
using std::endl;

#include "xvector.h"
#include "OS.h"
extern OS os;

void ex_open_n_delete() 
{    
	// all static OS functions start with an Upper_Case

    os.RM("./test_folder1");
    os.RM("./test_folder2");

    os.MKDIR("./test_folder1/nested_folder_a");
    os.MKDIR("./test_folder1/nested_folder_b");
    os.MKDIR("./test_folder1/nested_folder/double_nested_folder");

    os.Open("./test_folder1/nested_folder/double_nested_folder/file1", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder/double_nested_folder/file2", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder/double_nested_folder/file3", 'w').Write("test data");

    os.Open("./test_folder1/nested_folder_a//file1", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder_a//file2", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder_a//file3", 'w').Write("test data");

    os.Open("./test_folder1/nested_folder_b//file1", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder_b//file2", 'w').Write("test data");
    os.Open("./test_folder1/nested_folder_b//file3", 'w').Write("test data");

    os.Open("./test_folder1///file1", 'w').Write("test data");
    os.Open("./test_folder1///file2", 'w').Write("test data");
    os.Open("./test_folder1///file3", 'w').Write("test data");
    
    cout << "******************************************************" << endl;
    cout << "file   = " << os.Has("./test_folder1///file3") << endl; // true
    cout << "folder = " << os.Has("./test_folder1/nested_folder_b/") << endl; // true
    cout << "zilch  = " << os.Has("./asdfasdf/") << endl; // false
    cout << "******************************************************" << endl;

    cout << "\n------------------ Current Dirs -----------------------\n";
    for (auto&i : os.Dir("./test_folder1", 'r', 'd', 'f'))
        cout << "item = " << i << endl;

    os.Close();
    os.MoveDir("./test_folder1", "./test_folder2");
    
    cout << "\n------------------ Moved Dirs -------------------------\n";
    for (auto&i : os.Dir("./test_folder2", 'r', 'd', 'f'))
        cout << "item = " << i << endl;

    os.RemoveDir("./test_folder2");

    cout << "\n------------------ Removed Dirs 1 ---------------------\n";
    for (auto&i : os.Dir("./test_folder1", 'r', 'd', 'f'))
        cout << "item = " << i << endl;

    cout << "\n------------------ Deleted Dirs 2 ---------------------\n";
    for (auto&i : os.Dir("./test_folder2", 'r', 'd', 'f'))
        cout << "item = " << i << endl;

    cout << "\n\n\n";
}





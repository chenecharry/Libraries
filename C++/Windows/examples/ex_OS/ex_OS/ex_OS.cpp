#include<iostream>
#include<vector>
#include<string>

#include "ord.h"
#include "OS.h"
extern OS os;

#include "include\ex_open_n_delete.h"
#include "include\ex_file_managment.h"
#include "include\ex_bash_style.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

extern OS os;

int main() {

	ex_open_n_delete();
	ex_file_managment();
	ex_bash_style();

	return 0;
}
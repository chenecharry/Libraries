#include "stdafx.h"

#include "sys.h"
#include "os.h"

#include "ex_sys.h"
#include "ex_open_n_delete.h"
#include "ex_file_managment.h"

extern OS os;

int main(int argc, char** argv)
{

	sys.set_args(argc, argv);

	//ex_sys();

	ex_open_n_delete();
	//ex_file_managment();



    return 0;
}

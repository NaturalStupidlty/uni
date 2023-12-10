#include "Menu.h"
#include "Functions.h"

int main()
{
	int err = 0;
	prepare((char *)"Directors.bin",
          (char*)"Garbage collector.bin",
          (char*)"Indexes.bin",
          (char*)"Movies.bin",
          err);
	
	start();
	close(err);
}

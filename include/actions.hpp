#ifndef __ACTIONS__
#define __ACTIONS__

#include <string>

void config(int argcount,const char* args[], std::string *action);
int add();
int remove();
int change();
void list();

#endif
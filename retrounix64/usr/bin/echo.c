#include "sys.h"
static unsigned long strlen(const char* s){unsigned long n=0; while(s[n]) n++; return n;}
int main(int argc,char**argv){for(int i=1;i<argc;++i){if(i>1) sys_write(1," ",1); sys_write(1,argv[i],strlen(argv[i]));} sys_write(1,"\n",1); return 0;}

#include "sys.h"
static void catfd(int fd){char buf[4096]; for(;;){long n=sys_read(fd,buf,sizeof(buf)); if(n<=0) break; long off=0; while(n>0){long w=sys_write(1,buf+off,n); if(w<0) return; off+=w; n-=w;}}}
int main(int argc,char**argv){if(argc==1){catfd(0);}else{for(int i=1;i<argc;++i){long fd=sys_open(argv[i],0,0); if(fd<0){const char msg[]="cat: cannot open file\n"; sys_write(2,msg,sizeof(msg)-1); continue;} catfd(fd); sys_close(fd);}} return 0;}

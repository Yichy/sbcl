/* test to build and run so that we know if we have dladdr
 */

/* bloody FSF dlcfn.h won't give us dladdr without this */
#define _GNU_SOURCE

#include <stdlib.h>
#include <dlfcn.h>

int main ()
{
#ifdef __NetBSD__
  /* dladdr(3) is broken on NetBSD currently, don't forget to replace
     with a version check when they fix it */
  return 1;
#else
   void * handle = dlopen((void*)0, RTLD_GLOBAL | RTLD_NOW);
   void * addr = dlsym(handle, "printf");
   Dl_info * info = (Dl_info*) malloc(sizeof(Dl_info));
   if (dladdr(addr, info) == 0) {
       return 1;
   } else {
       return 104;
   }
#endif
}

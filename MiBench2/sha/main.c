/* NIST Secure Hash Algorithm */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../bareBench.h"
#include "sha.h"
#include "input.h"

#if 1
void app_main(void) {
#else
int main()
#endif
{
  SHA_INFO sha_info;

  sha_stream(&sha_info, inputString);
  sha_print(&sha_info);
  
  return(0);
}

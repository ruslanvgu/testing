
#ifdef __cplusplus
extern "C" {
#endif

#include "../lib/libmessage.h"

#ifdef __cplusplus
}
#endif

//func1

int main (int argc, char** argv) {

    printMessage (); // using function from static library libmessage

    return 0;
}
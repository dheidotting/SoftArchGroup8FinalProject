// LibCore.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "LibCore.h"


// This is an example of an exported variable
LIBCORE_API int nLibCore=0;

// This is an example of an exported function.
LIBCORE_API int fnLibCore(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CLibCore::CLibCore()
{
    return;
}

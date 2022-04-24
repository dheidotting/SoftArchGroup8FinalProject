// TopLevelSession.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "TopLevelSession.h"


// This is an example of an exported variable
TOPLEVELSESSION_API int nTopLevelSession=0;

// This is an example of an exported function.
TOPLEVELSESSION_API int fnTopLevelSession(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CTopLevelSession::CTopLevelSession()
{
    return;
}

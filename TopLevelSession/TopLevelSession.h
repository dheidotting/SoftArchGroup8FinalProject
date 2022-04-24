// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the TOPLEVELSESSION_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// TOPLEVELSESSION_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TOPLEVELSESSION_EXPORTS
#define TOPLEVELSESSION_API __declspec(dllexport)
#else
#define TOPLEVELSESSION_API __declspec(dllimport)
#endif

// This class is exported from the dll
class TOPLEVELSESSION_API CTopLevelSession {
public:
	CTopLevelSession(void);
	// TODO: add your methods here.
};

extern TOPLEVELSESSION_API int nTopLevelSession;

TOPLEVELSESSION_API int fnTopLevelSession(void);

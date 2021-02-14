// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLLEXPORTPROJECT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLLEXPORTPROJECT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLEXPORTPROJECT_EXPORTS
#define DLLEXPORTPROJECT_API __declspec(dllexport)
#else
#define DLLEXPORTPROJECT_API __declspec(dllimport)
#endif

// This class is exported from the dll
class DLLEXPORTPROJECT_API CDllExportProject {
public:
	CDllExportProject(void);
	double Add(double num1, double num2);
	// TODO: add your methods here.
};

extern DLLEXPORTPROJECT_API int nDllExportProject;
extern DLLEXPORTPROJECT_API int nDllExportProject2;

DLLEXPORTPROJECT_API int fnDllExportProject(void);

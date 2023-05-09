// DllExportProject.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "DllExportProject.h"


// This is an example of an exported variable
DLLEXPORTPROJECT_API int nDllExportProject = 0;
DLLEXPORTPROJECT_API int nDllExportProject2 = 1;

// This is an example of an exported function.
DLLEXPORTPROJECT_API int fnDllExportProject(void)
{
	return 0;
}

// This is the constructor of a class that has been exported.
CDllExportProject::CDllExportProject()
{
	return;
}

double CDllExportProject::Add(double num1, double num2)
{
	return num1 + num2;
}


// zhen.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "afx.h"

// CzhenApp:
// See zhen.cpp for the implementation of this class
//

class CzhenApp : public CWinApp
{
public:
	CzhenApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

typedef struct {
	CString name;
	double  points;
	double  price;
	BOOL isRet;
} MY_ITEMDATA, *PMYITEMDATA;

extern CzhenApp theApp;
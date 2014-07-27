// getcityname.h : main header file for the GETCITYNAME application
//

#if !defined(AFX_GETCITYNAME_H__2DEE2E51_5A9F_4F55_A32D_6E5D4CADA56B__INCLUDED_)
#define AFX_GETCITYNAME_H__2DEE2E51_5A9F_4F55_A32D_6E5D4CADA56B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetcitynameApp:
// See getcityname.cpp for the implementation of this class
//

class CGetcitynameApp : public CWinApp
{
public:
	CGetcitynameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetcitynameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetcitynameApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCITYNAME_H__2DEE2E51_5A9F_4F55_A32D_6E5D4CADA56B__INCLUDED_)

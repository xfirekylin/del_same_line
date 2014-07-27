// getcitynameDlg.h : header file
//

#if !defined(AFX_GETCITYNAMEDLG_H__F2110C27_ADEC_4886_BA09_D34566E8CA97__INCLUDED_)
#define AFX_GETCITYNAMEDLG_H__F2110C27_ADEC_4886_BA09_D34566E8CA97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetcitynameDlg dialog

class CGetcitynameDlg : public CDialog
{
// Construction
public:
	CGetcitynameDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetcitynameDlg)
	enum { IDD = IDD_GETCITYNAME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetcitynameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetcitynameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETCITYNAMEDLG_H__F2110C27_ADEC_4886_BA09_D34566E8CA97__INCLUDED_)

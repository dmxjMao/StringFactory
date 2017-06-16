
// StringFactoryDlg.h : header file
//

#pragma once

#include "InputDlg.h"
#include "FmtControlDlg.h"
#include "OutputDlg.h"
#include "BindInfoDlg.h"

// CStringFactoryDlg dialog
class CStringFactoryDlg : public CDialogEx
{
// Construction
public:
	CStringFactoryDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STRINGFACTORY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CMFCOutlookBarTabCtrl m_tab;
	CInputDlg m_inputDlg;
	CFmtControlDlg m_fmtControlDlg;
	COutputDlg m_outputDlg;
	CBindInfoDlg m_bindInfoDlg;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};

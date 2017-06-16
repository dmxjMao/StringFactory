#pragma once
#include "afxwin.h"
#include "MyEdit1.h"
#include "MyBitmapButton1.h"
#include "afxext.h"

// CInputDlg dialog

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)
	DECLARE_MESSAGE_MAP()
public:
	CInputDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInputDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Input };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//CSize m_whDlg;
	
public:
	virtual BOOL OnInitDialog();
protected:
	CMyEdit1 m_edtInput;
	CBitmapButton m_btnInputSample;
	CBitmapButton m_btnFmtSample;
	//CMyBitmapButton1 m_btnInputSample;
	//CMyBitmapButton1 m_btnFmtSample;
	CToolTipCtrl m_tip;
	//CMyEdit1 m_edtTip;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBtnClickInputSample();

};

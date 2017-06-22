#pragma once
//#include "afxwin.h"
#include "define.h"
#include "MyStatic1.h"

// COutputDlg dialog

class COutputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COutputDlg)
	DECLARE_MESSAGE_MAP()
public:
	COutputDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~COutputDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Output };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:
	CComboBox m_cboReturn;
	//CStatic m_stsOK;
	CMyStatic1 m_stsOK;
private:
	OUTPUT_STATUS m_status = OUTPUT_NOTYET;
public:
	virtual BOOL OnInitDialog();
};

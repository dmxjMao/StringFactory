#pragma once


// CBindInfoDlg dialog

class CBindInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBindInfoDlg)

public:
	CBindInfoDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBindInfoDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BindInfo };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

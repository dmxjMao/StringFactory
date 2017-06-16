#pragma once


// CFmtControlDlg dialog

class CFmtControlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFmtControlDlg)

public:
	CFmtControlDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFmtControlDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Fmt };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

#pragma once
#include "define.h"

//#define TB_NUM 2	//工具条个数
// CFmtControlDlg dialog

class CFmtControlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFmtControlDlg)
	DECLARE_MESSAGE_MAP()

public:
	CFmtControlDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFmtControlDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Fmt };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

protected:
	CMFCToolBar m_tb[TB_NUM];
	CMenu m_tbmu[TB_NUM][TB_MENU_NUM];
public:
	virtual BOOL OnInitDialog();
};

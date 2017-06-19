#pragma once
#include "afxwin.h"


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
	CStatic m_stsOK;
private:
	CImageList m_imgList;
	//HBITMAP m_bm;//Êä³ö×´Ì¬
	CBitmap m_bmp;//Êä³ö×´Ì¬
public:
	virtual BOOL OnInitDialog();
};

// FmtControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "FmtControlDlg.h"
#include "afxdialogex.h"


// CFmtControlDlg dialog

IMPLEMENT_DYNAMIC(CFmtControlDlg, CDialogEx)

CFmtControlDlg::CFmtControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Fmt, pParent)
{

}

CFmtControlDlg::~CFmtControlDlg()
{
}

void CFmtControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFmtControlDlg, CDialogEx)
END_MESSAGE_MAP()


// CFmtControlDlg message handlers

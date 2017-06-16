// OutputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "OutputDlg.h"
#include "afxdialogex.h"


// COutputDlg dialog

IMPLEMENT_DYNAMIC(COutputDlg, CDialogEx)

COutputDlg::COutputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Output, pParent)
{

}

COutputDlg::~COutputDlg()
{
}

void COutputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutputDlg, CDialogEx)
END_MESSAGE_MAP()


// COutputDlg message handlers

// BindInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StringFactory.h"
#include "BindInfoDlg.h"
#include "afxdialogex.h"


// CBindInfoDlg dialog

IMPLEMENT_DYNAMIC(CBindInfoDlg, CDialogEx)

CBindInfoDlg::CBindInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BindInfo, pParent)
{

}

CBindInfoDlg::~CBindInfoDlg()
{
}

void CBindInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBindInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// CBindInfoDlg message handlers

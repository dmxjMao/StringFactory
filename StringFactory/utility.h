#pragma once


//#define GET_DLG_WH \
//	{CRect rc;\
//	GetClientRect(&rc);\
//	m_whDlg.cx = rc.Width(); \
//	m_whDlg.cy = rc.Height();}


// 得到 CImageList 中的资源
void GetListImage(CImageList &ImageList, CBitmap &Bitmap, int nImageIdx);
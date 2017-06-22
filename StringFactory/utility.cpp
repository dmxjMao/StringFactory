#include "stdafx.h"
#include "utility.h"



// 得到 CImageList 中的资源
void GetListImage(CImageList &ImageList, CBitmap &Bitmap, int nImageIdx)
{
	CClientDC   dcClient(NULL);

	IMAGEINFO   ImageInfo;
	ImageList.GetImageInfo(nImageIdx, &ImageInfo);
	int   nWidth = abs(ImageInfo.rcImage.right - ImageInfo.rcImage.left);
	int   nHeight = abs(ImageInfo.rcImage.bottom - ImageInfo.rcImage.top);
	Bitmap.CreateCompatibleBitmap(&dcClient, nWidth, nHeight);
	CDC            dcMemory;
	dcMemory.CreateCompatibleDC((CDC*)NULL);
	CBitmap  *   pBmpOld = dcMemory.SelectObject(&Bitmap);
	dcMemory.FillSolidRect(0, 0, nWidth, nHeight, RGB(255, 255, 255));
	ImageList.Draw(&dcMemory, nImageIdx, CPoint(0, 0), ILD_NORMAL);
	dcMemory.SelectObject(pBmpOld);
	dcMemory.DeleteDC();
	::DeleteObject(ImageInfo.hbmImage);
	::DeleteObject(ImageInfo.hbmMask);
}
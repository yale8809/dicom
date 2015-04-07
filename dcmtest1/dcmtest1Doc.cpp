
// dcmtest1Doc.cpp : Cdcmtest1Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "dcmtest1.h"
#endif
#include "atlimage.h"
#include "dcmtest1Doc.h"
#include <Windows.h>
#include <propkey.h>
#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtest1View.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cdcmtest1Doc

IMPLEMENT_DYNCREATE(Cdcmtest1Doc, CDocument)

BEGIN_MESSAGE_MAP(Cdcmtest1Doc, CDocument)
	//ON_COMMAND(ID_FILE_OPEN, &Cdcmtest1Doc::OnFileOpen)
END_MESSAGE_MAP()

// DicomImage *pDicomImg ;
// DcmFileFormat *pDcmFileFormat ;
// void *pDicomDibits;
// int m_WindowCenter;
// int m_WindowLevel;
// Cdcmtest1Doc 构造/析构
//CString strPicPath;    //打开的图片文件文件名
CString extname;    //打开的图片文件的扩展名
// CBitmap m_bitmap;    //创建位图对象
// CImage m_MyImage;    //用于读取与显示jpg等格式的图像文件

Cdcmtest1Doc::Cdcmtest1Doc()
	: dcm(NULL),
	m_Pathname(_T("")),
	strPicPath(_T("")),
	pDicomDibits(NULL),
	m_curWC(0),
	m_curWW(0)
{
	// TODO: 在此添加一次性构造代码

}

Cdcmtest1Doc::~Cdcmtest1Doc()
{
}

BOOL Cdcmtest1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

BOOL Cdcmtest1Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	//CFileDialog dig(TRUE,NULL,NULL,OFN_ALLOWMULTISELECT,NULL,NULL);
	//dcm = new DicomImage(lpszPathName,CIF_UseAbsolutePixelRange,0,0);

	pDicomFile = new DcmFileFormat();
	pDicomFile->loadFile(lpszPathName);
	pDataset = pDicomFile->getDataset();
	E_TransferSyntax xfer=pDataset->getOriginalXfer();
	dcm = new DicomImage(pDataset,xfer);

	if( dcm->getStatus() != EIS_Normal)
	{
		AfxMessageBox(DicomImage::getString(dcm->getStatus()));
	}

	m_lpBMIH = (LPBITMAPINFOHEADER) new char[sizeof(BITMAPINFOHEADER)
	+sizeof(RGBQUAD)*256];
	m_lpBMIH->biSize = sizeof(BITMAPINFOHEADER);
	m_lpBMIH->biWidth =dcm->getWidth();
	m_lpBMIH->biHeight = dcm->getHeight();
	m_lpBMIH->biPlanes = 1;
	m_lpBMIH->biBitCount = 24;
	m_lpBMIH->biCompression = BI_RGB;
	m_lpBMIH->biSizeImage = 0;
	m_lpBMIH->biXPelsPerMeter = 0;
	m_lpBMIH->biYPelsPerMeter = 0;
	
		
	
	OFString wc,ww;
	if (pDataset->findAndGetOFString(DCM_WC, wc).good()&&
		pDataset->findAndGetOFString(DCM_WW, ww).good())
	{
		m_curWC = atof(wc.c_str());
		m_curWW = atof(ww.c_str());
		dcm->setWindow(m_curWC,m_curWW);
	}

	if(pDicomDibits!=NULL)
		delete[]pDicomDibits;
	int size = dcm->createWindowsDIB(pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}

	return TRUE;
}

BOOL Cdcmtest1Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return TRUE;
}



// Cdcmtest1Doc 序列化

void Cdcmtest1Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Cdcmtest1Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Cdcmtest1Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Cdcmtest1Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cdcmtest1Doc 诊断

#ifdef _DEBUG
void Cdcmtest1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cdcmtest1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cdcmtest1Doc 命令


void Cdcmtest1Doc::OnFileOpen()
{
	CFileDialog *dlg = new CFileDialog(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("All Files (*.*)|*.*||"));
	if (IDOK==dlg->DoModal())
	{
		strPicPath.Format(_T("%s"),dlg->GetPathName());
		extname = dlg->GetFileExt();             //返回选定文件的扩展文件名
		extname.MakeLower();        //将后缀名变成小写的
		//Invalidate();
	}
	m_Pathname = dlg->GetPathName();

	//theApp->OpenDocumentFile(m_Pathname);
	this->UpdateAllViews(NULL);




	// TODO: 在此添加命令处理程序代码
}
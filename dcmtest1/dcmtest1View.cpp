
// dcmtest1View.cpp : Cdcmtest1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "dcmtest1.h"
#endif

#include "dcmtest1Doc.h"
#include "dcmtest1View.h"
#include "TagInfoDialog.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cdcmtest1View

IMPLEMENT_DYNCREATE(Cdcmtest1View, CView)

BEGIN_MESSAGE_MAP(Cdcmtest1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_SHOW_TAG , OnShowTag)
	ON_UPDATE_COMMAND_UI(ID_SHOW_TAG , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_WCWW_FULL , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_WCWW_Default , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Display , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_WW_Setting , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_ABD , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_Angio , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_Bone , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_Brain , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_Chest , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_CT_Lungs , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_1 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_2 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_3 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_4 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_5 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_6 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_7 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Other_WW_8 , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_Inverse , OnUpdateTagMenu)
	ON_COMMAND(ID_WCWW_Default , OnUpdateDefaultWCWW)
	ON_COMMAND(ID_WCWW_FULL , OnUpdateFullWCWW)
//	ON_WM_ERASEBKGND()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_COMMAND(ID_CT_ABD, &Cdcmtest1View::OnCtAbd)
ON_COMMAND(ID_CT_Angio, &Cdcmtest1View::OnCtAngio)
ON_COMMAND(ID_CT_Bone, &Cdcmtest1View::OnCtBone)
ON_COMMAND(ID_CT_Brain, &Cdcmtest1View::OnCtBrain)
ON_COMMAND(ID_CT_Chest, &Cdcmtest1View::OnCtChest)
ON_COMMAND(ID_CT_Lungs, &Cdcmtest1View::OnCtLungs)
ON_COMMAND(ID_Other_WW_1, &Cdcmtest1View::OnOtherWw1)
ON_COMMAND(ID_Other_WW_2, &Cdcmtest1View::OnOtherWw2)
ON_COMMAND(ID_Other_WW_3, &Cdcmtest1View::OnOtherWw3)
ON_COMMAND(ID_Other_WW_4, &Cdcmtest1View::OnOtherWw4)
ON_COMMAND(ID_Other_WW_5, &Cdcmtest1View::OnOtherWw5)
ON_COMMAND(ID_Other_WW_6, &Cdcmtest1View::OnOtherWw6)
ON_COMMAND(ID_Other_WW_7, &Cdcmtest1View::OnOtherWw7)
ON_COMMAND(ID_Other_WW_8, &Cdcmtest1View::OnOtherWw8)
ON_COMMAND(ID_Inverse, &Cdcmtest1View::OnInverse)
END_MESSAGE_MAP()

// Cdcmtest1View 构造/析构

Cdcmtest1View::Cdcmtest1View()
	: dcm(NULL),
	pDicomFile(NULL),
	pDataset(NULL),
	m_bShowTagEnable(false),
	m_destX(0),
	m_destY(0),
	m_destWidth(0),
	m_destHeight(0),
	m_pixelX(0),
	m_pixelY(0),
	m_pixelValue(0),
	isResetWindow(false)
{
	// TODO: 在此处添加构造代码
	//AllocConsole();                     // 打开控制台资源

	//freopen( "CONOUT$", "w+t", stdout );// 申请写
	//freopen( "CONIN$", "r+t", stdin );  // 申请读
}

Cdcmtest1View::~Cdcmtest1View()
{
	//FreeConsole();                      // 释放控制台资源
}

BOOL Cdcmtest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cdcmtest1View 绘制

void Cdcmtest1View::OnDraw(CDC* pDC)
{

	Cdcmtest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
// 	SB_BitmapInfoHeader infoHeader;
// 	infoHeader.biSize = sizeof(SB_BitmapInfoHeader);
// 	infoHeader.biWidth = pDoc->dcm->getHeight();
// 	infoHeader.biHeight = pDoc->dcm->getWidth();
// 	infoHeader.biPlanes = 1;
// 	infoHeader.biBitCount = 
	//dcm =  new DicomImage(pDoc->strPicPath,0,0,0);
	//pDicomFile = new DcmFileFormat();
	//pDicomFile->loadFile("D:\\Guo_Yu\\Project\\dcmdata\\AELQYFNH\\I1000000");
	//pDataset = pDicomFile->getDataset();
	//E_TransferSyntax xfer=pDataset->getOriginalXfer();
	//dcm = new DicomImage(pDataset,xfer);
	/*DicomImage* temp*/
	//dcm = new DicomImage("D:\\Guo_Yu\\Project\\dcmdata\\\layer8\\IM8",CIF_UseAbsolutePixelRange,0,0);

	//dcm = tempdcm->createClippedImage(100,100,tempdcm->getWidth()-200,tempdcm->getHeight()-200);
	//Uint32 size = dcm->getOutputDataSize();
	//Uint8 *pixelData = (Uint8 *)(dcm->getOutputData(8 /* bits per sample */));
 //   if (pixelData != NULL)
 //   {
 //     /* do something useful with the pixel data */
 //   }

	//for(int i=0; i<size; i++)
	//{
	//	if(pixelData[i]!=128)
	//	{
	//		pixelData[i];
	//	}
	//}

	//Set the view background color
	CBrush   backBrush(RGB(0, 0,0));
              //   保存旧刷子  
    pDC->SelectObject(&backBrush);  
    CRect   rect;
	GetClientRect(&rect);
    //pDC->GetClipBox(&rect);           //   擦除所需的区域  
    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY); 

	if(pDoc->dcm != NULL)
	{		
		//CRect rect;
		//GetClientRect(&rect);
		m_destHeight = rect.Height();
		m_destWidth = pDoc->m_lpBMIH->biWidth*m_destHeight/pDoc->m_lpBMIH->biHeight;
		m_destX = (rect.Width() - m_destWidth)/2;
		m_destY = 0;


		StretchDIBits(pDC->GetSafeHdc(),m_destX,m_destY,m_destWidth,
			m_destHeight,0,0,pDoc->m_lpBMIH->biWidth,
			pDoc->m_lpBMIH->biHeight,pDoc->pDicomDibits,
			(LPBITMAPINFO)pDoc->m_lpBMIH,DIB_PAL_COLORS,SRCCOPY);
		m_bShowTagEnable = true;
		
		//UpdateLabelText();
		UpdateLabelText(pDC);
		UpdateMenu();
	}

	// TODO: 在此处为本机数据添加绘制代码
}

void Cdcmtest1View::OnShowTag()
{	
	Cdcmtest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || !pDoc->dcm)
		return;
	TagInfoDialog tagDlg(pDoc->pDataset);
	tagDlg.DoModal();
	//AfxMessageBox("Show Tag");
}

void Cdcmtest1View::OnUpdateTagMenu(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_bShowTagEnable);
}


void Cdcmtest1View::OnUpdateDefaultWCWW()
{
	Cdcmtest1Doc* pDoc = GetDocument();
	OFString wc,ww;
	if (pDoc->pDataset->findAndGetOFString(DCM_WC, wc).good()&&
		pDoc->pDataset->findAndGetOFString(DCM_WW, ww).good())
	{
		pDoc->m_curWC = atof(wc.c_str());
		pDoc->m_curWW = atof(ww.c_str());
		pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);
	}
	
		
	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

void Cdcmtest1View::OnUpdateFullWCWW()
{
	Cdcmtest1Doc* pDoc = GetDocument();
	double min,max;
	pDoc->dcm->getMinMaxValues(min,max);
	pDoc->m_curWW = (max-min)/2;
	pDoc->m_curWC = (max+min)/2;
	pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);

	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

// Cdcmtest1View 诊断

#ifdef _DEBUG
void Cdcmtest1View::AssertValid() const
{
	CView::AssertValid();
}

void Cdcmtest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdcmtest1Doc* Cdcmtest1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdcmtest1Doc)));
	return (Cdcmtest1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdcmtest1View 消息处理程序

void Cdcmtest1View::UpdateLabelText(CDC* pDC)
{	
	Cdcmtest1Doc* pDoc = GetDocument();

	int txt_width = 240;
	int txt_height = 20;
    CRect   rect;
    GetClientRect(&rect);
	int view_width = rect.Width();
	int view_height = rect.Height();

	pDC->SetTextColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	
	OFString tempstring;
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientName, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 0, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientID, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientBirth, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 2*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientSex, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width/6, 2*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_Institution, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 3*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PPSID, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 4*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_StudyDes, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 5*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_SeriesDes, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 6*txt_height, tempstring.data());
	}

	char wc_ww[10];
	itoa(pDoc->m_curWC, wc_ww, 10);
	pDC->TextOutA(0, view_height-txt_height, wc_ww);

	itoa(pDoc->m_curWW, wc_ww, 10);
	pDC->TextOutA(txt_width/2, view_height-txt_height, wc_ww);

	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnDate, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, view_height-txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnTime, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width/2, view_height-txt_height, tempstring.data());
	}
		
	if(m_pixelX!=0&&m_pixelY!=0)
	{
		CString value;
		value.Format("X:%d Y:%d value:%d",m_pixelX,m_pixelY,m_pixelValue);
		pDC->TextOutA(0, view_height-2*txt_height,value);
	}

}

void Cdcmtest1View::UpdateMenu()
{
}

void Cdcmtest1View::SetWindow(int windowcenter, int windowwidth)
{
	Cdcmtest1Doc* pDoc = GetDocument();
	pDoc->m_curWC = windowcenter;
	pDoc->m_curWW = windowwidth;
	pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);

	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

//BOOL Cdcmtest1View::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CBrush   backBrush(RGB(0, 0,0));
//              //   保存旧刷子  
//    pDC->SelectObject(&backBrush);  
//    CRect   rect;  
//    pDC->GetClipBox(&rect);           //   擦除所需的区域  
//    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY);  
//    //pDC->SelectObject(pOldBrush);
//
//	return CView::OnEraseBkgnd(pDC);
//}


void Cdcmtest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);

	m_startPoint.x = point.x;
	m_startPoint.y = point.y;
	m_curPoint.x = point.x;
	m_curPoint.y = point.y;
	printf("m_startPoint.x = %d, m_startPoint.y = %d \r\n",m_startPoint.x, m_startPoint.y);
	isResetWindow = true;
}


void Cdcmtest1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);

	isResetWindow = false;
}


void Cdcmtest1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
	Cdcmtest1Doc* pDoc = GetDocument();
	
	int txt_width = 240;
	int txt_height = 20;
	CRect   rect;
	GetClientRect(&rect);
	int view_width = rect.Width();
	int view_height = rect.Height();

	if(pDoc->dcm!=NULL)
	{
		if (isResetWindow) 
		{
			if(abs(point.x-m_curPoint.x)+abs(point.y-m_curPoint.y)>10)
			{
				printf("m_curPoint.x = %d, m_curPoint.y = %d \r\n",m_curPoint.x, m_curPoint.y);
				printf("point.x = %d, point.y = %d \r\n",point.x, point.y);
				pDoc->m_curWC=pDoc->m_curWC+(-point.x+m_curPoint.x);
				pDoc->m_curWW=pDoc->m_curWW+(point.y-m_curPoint.y);
				m_curPoint.x=point.x;
				m_curPoint.y=point.y;
				if(pDoc->m_curWC>2047)
					pDoc->m_curWC=2047;
				if(pDoc->m_curWC<-2048)
					pDoc->m_curWC=-2048;
				if(pDoc->m_curWW>2047)
					pDoc->m_curWW=2047;
				if(pDoc->m_curWW<-2048)
					pDoc->m_curWW = -2048;
				ASSERT_VALID(pDoc);
				pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);
				if(pDoc->pDicomDibits!=NULL)
					delete[]pDoc->pDicomDibits;
				int m_iDibSize=pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
				if(m_iDibSize==0)
					AfxMessageBox("createWindowsDIB创建DIB文件出错！");
				Invalidate();
			}
		}

		if (point.x>m_destX && point.y >m_destY && 
			point.x < (m_destX+m_destWidth) && point.y < (m_destY+m_destHeight))
		{
			m_pixelX = (point.x - m_destX)*pDoc->m_lpBMIH->biWidth/m_destWidth;
			m_pixelY = (point.y - m_destY)*pDoc->m_lpBMIH->biHeight/m_destHeight;

			//Uint8 *pixelData = (Uint8 *)(pDoc->dcm->getOutputData(8 /* bits per sample */));
			void *pixelData = (void *)pDoc->dcm->getInterData()->getData();
			if (pixelData != NULL)
			{
				EP_Representation pixelRep = pDoc->dcm->getInterData()->getRepresentation();
   
				switch(pixelRep)
				{
					case EPR_Uint8:
						// UCHAR;
						m_pixelValue = ((Uint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint8:
						//CHAR
						m_pixelValue = ((Sint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Uint16:
						//USHORT
						m_pixelValue = ((Uint16*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint16:
						// SHORT
						m_pixelValue = ((Sint16*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Uint32:
						//UINT
						m_pixelValue = ((Uint32*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint32:
						//INT
						m_pixelValue = ((Sint32*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
				   default:
						m_pixelValue = ((Uint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
			   }
			}

		}
		else
		{
			m_pixelX = 0;
			m_pixelY = 0;
		}
		
		InvalidateRect(CRect(0,view_height-2*txt_height,240,view_height-txt_height));//刷新value显示区域的内容
	}

}

void Cdcmtest1View::OnCtAbd()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(60,400);
}


void Cdcmtest1View::OnCtAngio()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(300,600);
}


void Cdcmtest1View::OnCtBone()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(300,1500);
}


void Cdcmtest1View::OnCtBrain()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(40,80);
}


void Cdcmtest1View::OnCtChest()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(40,400);
}


void Cdcmtest1View::OnCtLungs()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(-400,1500);
}


void Cdcmtest1View::OnOtherWw1()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(20,40);
}


void Cdcmtest1View::OnOtherWw2()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(40,80);
}


void Cdcmtest1View::OnOtherWw3()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(80,160);
}


void Cdcmtest1View::OnOtherWw4()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(160,320);
}


void Cdcmtest1View::OnOtherWw5()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(320,640);
}


void Cdcmtest1View::OnOtherWw6()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(640,1280);
}


void Cdcmtest1View::OnOtherWw7()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(1280,2560);
}


void Cdcmtest1View::OnOtherWw8()
{
	// TODO: 在此添加命令处理程序代码
	SetWindow(2560,5120);
}


void Cdcmtest1View::OnInverse()
{
	// TODO: 在此添加命令处理程序代码
	Cdcmtest1Doc* pDoc = GetDocument();
	EP_Polarity polarity= pDoc->dcm->getPolarity();
	if(polarity == EPP_Normal)
	{
		pDoc->dcm->setPolarity(EPP_Reverse);
	}
	else
	{
		pDoc->dcm->setPolarity(EPP_Normal);
	}

	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

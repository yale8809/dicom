// RichStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "dcmtest1.h"
#include "RichStatic.h"


// CRichStatic

IMPLEMENT_DYNAMIC(CRichStatic, CStatic)

CRichStatic::CRichStatic():  
    m_clrText(RGB(255,255,255)), m_clrBackground(RGB(0,0,0))
{

}

CRichStatic::~CRichStatic()
{
}


BEGIN_MESSAGE_MAP(CRichStatic, CStatic)   
   ON_MESSAGE(WM_SETTEXT,OnSetText)  
   ON_WM_ERASEBKGND()  
END_MESSAGE_MAP()

// CRichStatic 消息处理程序  
  
  
void CRichStatic::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)  
{  
    if (m_clrBackground != CLR_NONE)    // 若背景色不为CLR_NONE（CLR_NONE表示无背景色），则绘制背景  
    {  
        RECT rect;  
        GetWindowRect(&rect);  
        CBrush brush;  
        brush.CreateSolidBrush(m_clrBackground);  
        ::SelectObject(lpDrawItemStruct->hDC, brush.m_hObject);    // 设置画刷颜色  
        //::SelectObject(lpDrawItemStruct->hDC, GetStockObject(NULL_PEN));    // 设置笔为空笔（不绘制边界）  
        Rectangle(lpDrawItemStruct->hDC, 0, 0,rect.right - rect.left, rect.bottom - rect.top);  
    }  
  
  
    CString strCaption;    // 标题文字  
    GetWindowText(strCaption);  
    //if (m_hFont != NULL)  
    //{  
    //    ::SelectObject(lpDrawItemStruct->hDC, m_hFont);  
    //}  
  
  
    //// 计算输出字串的横纵坐标   
    //int x = 0, y = 0;
    //if (X_LEFT != m_xAlignment || Y_TOP != m_yAlignment)    // 不是左对齐或不是顶对齐  
    //{  
    //    CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);  
    //    CRect crect;  
    //    GetWindowRect(&crect);  
    //    CSize size = pDC->GetTextExtent(strCaption);  
    //    if (X_RIGHT == m_xAlignment)    // 右对齐  
    //    {  
    //        x = crect.Width() - size.cx;  
    //    }  
    //    else if (X_CENTER == m_xAlignment)   // X居中对齐  
    //    {  
    //        x = (crect.Width()- size.cx) / 2;  
    //    }  
  
  
    //    if (Y_BOTTOM == m_yAlignment)   // 顶对齐  
    //    {  
    //        y = crect.Height() - size.cy;  
    //    }  
    //    else if (Y_CENTER == m_yAlignment)   // Y居中对齐  
    //    {  
    //        y = (crect.Height() - size.cy) / 2;  
    //    }  
    //}  
    // 设置dc字串颜色  
    ::SetTextColor(lpDrawItemStruct->hDC, m_clrText);  
    TextOut(lpDrawItemStruct->hDC, 0, 0, strCaption, strCaption.GetLength());  
}  
  
  
void CRichStatic::PreSubclassWindow()  
{  
    CStatic::PreSubclassWindow();  
    ModifyStyle(0, SS_OWNERDRAW);  
}  
  
  
//void CRichStatic::SetFont(CString strFaceName, LONG nHeight)  
//{  
//    if (m_selfCreated && m_hFont != NULL)  
//    {  
//        DeleteObject(m_hFont);    // 若字体对象为对象自己创建并且不为NULL，则销毁掉以释放内核对象  
//    }  
//    CFont cfont;  
//    LOGFONT lf;  
//    memset(&lf, 0, sizeof lf);    // 清空LOGFONT结构体，之后对其赋值  
//    lf.lfHeight = nHeight;  
//    _tcscpy_s(lf.lfFaceName, strFaceName.GetBuffer());    // 将字体名拷贝到LOGFONT结构体中  
//    VERIFY(cfont.CreateFontIndirect(&lf));    // 创建新的字体  
//    m_hFont = (HFONT)cfont.m_hObject;  
//    m_selfCreated = TRUE;    // 标记字体为自己创建的  
//}
  
  
BOOL CRichStatic::OnEraseBkgnd(CDC* pDC)  
{  
    // 当背景色为透明时，需要保存与拷贝显示主框的显示区域  
    if (m_clrBackground == CLR_NONE)  
    {  
        if (m_Bmp.GetSafeHandle() == NULL)  
        {  
            CRect Rect;  
            GetWindowRect(&Rect);  
            CWnd *pParent = GetParent();  
            ASSERT(pParent);  
            pParent->ScreenToClient(&Rect);  // 将坐标转换为与主对话框相对应  
        
            // 拷贝对应区域主框显示的内容  
            CDC *pDC = pParent->GetDC();  
            CDC MemDC;  
            MemDC.CreateCompatibleDC(pDC);  
            m_Bmp.CreateCompatibleBitmap(pDC,Rect.Width(),Rect.Height());  
            CBitmap *pOldBmp = MemDC.SelectObject(&m_Bmp);  
            MemDC.BitBlt(0,0,Rect.Width(),Rect.Height(),pDC,Rect.left,Rect.top,SRCCOPY);  
            MemDC.SelectObject(pOldBmp);  
            MemDC.DeleteDC();    // 删除内存DC，否则内存泄漏  
            pParent->ReleaseDC(pDC);  
        }  
        else // 将主框显示的内容拷贝回去  
        {  
            CRect Rect;  
            GetClientRect(Rect);  
            CDC MemDC;  
            MemDC.CreateCompatibleDC(pDC);  
            CBitmap *pOldBmp = MemDC.SelectObject(&m_Bmp);  
            pDC->BitBlt(0,0,Rect.Width(),Rect.Height(),&MemDC,0,0,SRCCOPY);  
            MemDC.SelectObject(pOldBmp);  
            MemDC.DeleteDC();    // 删除内存DC，否则内存泄漏  
        }  
    }  
  
  
    return TRUE;  
}  
  
  
LRESULT CRichStatic::OnSetText(WPARAM wParam,LPARAM lParam)  
{  
    LRESULT Result = Default();  
    Invalidate();  
    UpdateWindow();  
    return Result;  
}

// CRichStatic 消息处理程序



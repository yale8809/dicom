#pragma once


// CRichStatic

class CRichStatic : public CStatic
{
	DECLARE_DYNAMIC(CRichStatic)

public:
	CRichStatic();
	virtual ~CRichStatic();

protected:    
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
    afx_msg LRESULT OnSetText(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();  
  
private:  
    COLORREF m_clrText;          // 文字前景色  
    COLORREF m_clrBackground;    // 文字背景色  
    //CFont *m_pTextFont;          // 文字字体  
    CBitmap m_Bmp;               // 保存背景用的位图对象  
public:  
    // 设置背景色（若clr为CLR_NONE，则背景透明）  
    void SetBackgroundColor(COLORREF clr){m_clrBackground = clr;}  
    // 设置文字前景色  
    void SetTextColor(COLORREF clr){m_clrText = clr;}  
    // 设置文字字体  
    //void SetFont(CString strFaceName, LONG nHeight);  
  
public:  
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/); 
};




// dcmtest1View.h : Cdcmtest1View 类的接口
//

#pragma once

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcfilefo.h"
//#include "RichStatic.h"
#include <afxwin.h>

#define DCM_PatientName     DcmTagKey(0x0010, 0x0010)
#define DCM_PatientID		DcmTagKey(0x0010, 0x0020)
#define DCM_PatientBirth    DcmTagKey(0x0010, 0x0030)
#define DCM_PatientSex		DcmTagKey(0x0010, 0x0040)
#define DCM_Institution		DcmTagKey(0x0008, 0x0080)
#define DCM_PPSID			DcmTagKey(0x0020, 0x0010)
#define DCM_StudyDes		DcmTagKey(0x0008, 0x1030)
#define DCM_SeriesDes		DcmTagKey(0x0008, 0x103e)
#define DCM_WC				DcmTagKey(0x0028, 0x1050)
#define DCM_WW				DcmTagKey(0x0028, 0x1051)
#define DCM_CtnDate			DcmTagKey(0x0008, 0x0023)
#define DCM_CtnTime			DcmTagKey(0x0008, 0x0033)

class Cdcmtest1View : public CView
{
public: // 仅从序列化创建
	//DicomImage *pDicomImg;
	//DcmFileFormat *pDicomFile;
	//OFCondition Fcond;
	//Cdcmtest1View(DicomImage *p , DcmFileFormat *q);//OFCondition F);
	Cdcmtest1View();
	DECLARE_DYNCREATE(Cdcmtest1View)

// 特性
public:
	Cdcmtest1Doc* GetDocument() const;
	
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~Cdcmtest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnShowTag();
	afx_msg void OnUpdateTagMenu(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDefaultWCWW();
	afx_msg void OnUpdateFullWCWW();
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	void UpdateLabelText();
public:
	DicomImage *dcm;
	DcmFileFormat *pDicomFile;
	DcmDataset *pDataset;

private:
	bool m_bShowTagEnable;
	CStatic m_textPatName;
	CStatic m_textPatID;
	CStatic m_textPatBirth;
	CStatic m_textPatGender;
	CStatic m_textInstitution;
	CStatic m_textPPSID;
	CStatic m_textStudyDes;
	CStatic m_textSeriesDes;	
	CStatic m_textPixelValue;
	CStatic m_textWC;
	CStatic m_textWW;
	CStatic m_textCtnDate;
	CStatic m_textCtnTime;

	double m_curWC;
	double m_curWW;
	int m_WCWWtype;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // dcmtest1View.cpp 中的调试版本
inline Cdcmtest1Doc* Cdcmtest1View::GetDocument() const
   { return reinterpret_cast<Cdcmtest1Doc*>(m_pDocument); }
#endif


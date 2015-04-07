
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
#define DCM_Modality        DcmTagKey(0x0008, 0x0060)

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
	void UpdateLabelText(CDC* pDC);
	void UpdateMenu();
	void SetWindow(int windowcenter, int windowwidth);
public:
	DicomImage *dcm;
	DcmFileFormat *pDicomFile;
	DcmDataset *pDataset;

private:
	bool m_bShowTagEnable;

	bool isResetWindow;
	CPoint m_startPoint;
	CPoint m_curPoint;
	CPoint m_endPoint;
	int m_destX;
	int m_destY;
	int m_destWidth;
	int m_destHeight;
	int m_pixelX;
	int m_pixelY;
	int m_pixelValue;
public:
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCtAbd();
	afx_msg void OnCtAngio();
	afx_msg void OnCtBone();
	afx_msg void OnCtBrain();
	afx_msg void OnCtChest();
	afx_msg void OnCtLungs();
	afx_msg void OnOtherWw1();
	afx_msg void OnOtherWw2();
	afx_msg void OnOtherWw3();
	afx_msg void OnOtherWw4();
	afx_msg void OnOtherWw5();
	afx_msg void OnOtherWw6();
	afx_msg void OnOtherWw7();
	afx_msg void OnOtherWw8();
	afx_msg void OnInverse();
};

#ifndef _DEBUG  // dcmtest1View.cpp 中的调试版本
inline Cdcmtest1Doc* Cdcmtest1View::GetDocument() const
   { return reinterpret_cast<Cdcmtest1Doc*>(m_pDocument); }
#endif


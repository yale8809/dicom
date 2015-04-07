
// dcmtest1Doc.h : Cdcmtest1Doc 类的接口
//

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include <afx.h>
#pragma once


class Cdcmtest1Doc : public CDocument
{
protected: // 仅从序列化创建
	Cdcmtest1Doc();
	DECLARE_DYNCREATE(Cdcmtest1Doc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Cdcmtest1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();

public:
	DicomImage *dcm;
	LPBITMAPINFOHEADER m_lpBMIH;
	void *pDicomDibits ;
	DcmFileFormat *pDicomFile;
	DcmDataset *pDataset;
	double m_curWC;
	double m_curWW;

private:
	CString m_Pathname;
	CString strPicPath;

};

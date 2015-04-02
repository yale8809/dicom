#pragma once

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcelem.h"
#include "afxcmn.h"


// TagInfoDialog 对话框

class TagInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TagInfoDialog)

public:
	TagInfoDialog(DcmItem* pDSet, CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TagInfoDialog();

// 对话框数据
	enum { IDD = IDD_TAGINFODIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_tagList;

private:
	DcmItem* m_dataSet;
};

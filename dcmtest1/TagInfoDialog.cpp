// TagInfoDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "dcmtest1.h"
#include "TagInfoDialog.h"
#include "afxdialogex.h"


// TagInfoDialog 对话框

IMPLEMENT_DYNAMIC(TagInfoDialog, CDialogEx)

TagInfoDialog::TagInfoDialog(DcmItem* pDSet, CWnd* pParent /*=NULL*/)
	: CDialogEx(TagInfoDialog::IDD, pParent)
{
	m_dataSet = pDSet;
}

TagInfoDialog::~TagInfoDialog()
{
}

void TagInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAG_LIST, m_tagList);
}

BOOL TagInfoDialog::OnInitDialog()   
{   
    CDialogEx::OnInitDialog();    
  
    // TODO: Add extra initialization here   
    CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    m_tagList.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_tagList.SetExtendedStyle(m_tagList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
  
    // 为列表视图控件添加三列   
    m_tagList.InsertColumn(0, _T("Tag ID"), LVCFMT_CENTER, rect.Width()/4, 0);   
    m_tagList.InsertColumn(1, _T("VR"), LVCFMT_CENTER, rect.Width()/10, 1); 
    m_tagList.InsertColumn(2, _T("VM"), LVCFMT_CENTER, rect.Width()/10, 2); 
    m_tagList.InsertColumn(3, _T("Length"), LVCFMT_CENTER, rect.Width()/5, 3); 
    m_tagList.InsertColumn(4, _T("Value"), LVCFMT_CENTER, rect.Width()*4/10, 4);

	if(m_dataSet != NULL)
	{  
		DcmStack stack;
		DcmObject *dobj = NULL;
		DcmTag tag;
		DcmElement *delm = NULL;
		int i = 0;
		OFCondition status = m_dataSet->nextObject(stack, OFTrue);
		while (status.good())
		{
			dobj = stack.top();
			tag = dobj->getTag();
			{
				CString tag_id;
				char int_value[10];
				tag_id.Format("(%.4x,%.4x)",tag.getGroup(), tag.getElement());
				m_tagList.InsertItem(i, tag_id);
				m_tagList.SetItemText(i, 1, tag.getVR().getVRName());
				ltoa(dobj->getVM(),int_value,10);
				m_tagList.SetItemText(i, 2, int_value);
				ltoa(dobj->getLength(),int_value,10);
				m_tagList.SetItemText(i, 3, int_value);
				//m_tagList.SetItemText(i, 3, ltoa(dobj.getLengthFiled()));

				if(tag.getEVR() != EVR_SQ && tag.getEVR() != EVR_na)
				{
					char* value;
					delm = (DcmElement*)dobj;
					delm->getString(value);
					m_tagList.SetItemText(i, 4, value);
				}
				i++;
			}
			status = m_dataSet->nextObject(stack, OFTrue);
		}
	}
  
    return TRUE;  // return TRUE  unless you set the focus to a control   
} 

BEGIN_MESSAGE_MAP(TagInfoDialog, CDialogEx)
END_MESSAGE_MAP()


// TagInfoDialog 消息处理程序

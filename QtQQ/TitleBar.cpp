#include "TitleBar.h"
#include <QHBoxLayout>

#define BUTTON_HEIGHT 27 //按钮高度
#define BUTTON_WINDTH 27 //按钮宽度
#define TITLE_HEIGHT  27 //标题栏高度


TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent)
	,m_isPressed(false)
	,m_buttonTypen(MIN_MAX_BUTTON)
{
	initControl();
	initConnections();
	loadStyleSheet("Title");

}

TitleBar::~TitleBar()
{
}

//初始化控件
void TitleBar::initControl() 
{
	m_pIcon = new QLabel(this);
	m_pTitleContent = new QLabel(this);

	m_pButtonMin = new QPushButton(this);
	m_pButtonRestore = new QPushButton(this);
	m_pButtonMax = new QPushButton(this);
	m_pButtonClose = new QPushButton(this);

	//按钮设置固定大小
	m_pButtonMin->setFixedSize(QSize(BUTTON_WINDTH, BUTTON_HEIGHT));
	m_pButtonRestore->setFixedSize(QSize(BUTTON_WINDTH, BUTTON_HEIGHT));
	m_pButtonMax->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_HEIGHT));
	m_pButtonClose->setFixedSize(QSize(BUTTON_HEIGHT, BUTTON_HEIGHT));

	//设置对象名
	m_pTitleContent->setObjectName("TitleContent");
	m_pButtonMin->setObjectName("ButtonMin");
	m_pButtonRestore->setObjectName("ButtonRestore");
	m_pButtonMax->setObjectName("ButtonMax");
	m_pButtonClose->setObjectName("ButtonClose");

	//设置布局
	QHBoxLayout* mylayout = new QHBoxLayout(this);
	mylayout->addWidget(m_pIcon);
	mylayout->addWidget(m_pTitleContent);

	mylayout->addWidget(m_pButtonMin);
	mylayout->addWidget(m_pButtonRestore);
	mylayout->addWidget(m_pButtonClose);

	mylayout->setContentsMargins(5, 0, 0, 0); //设置布局的间隙
	mylayout->setSpacing(0); //设置布局里布局间的间隙

	m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setFixedHeight(TITLE_HEIGHT);
	setWindowFlags(Qt::FramelessWindowHint); //无边框

}

//信号与槽的连接
void TitleBar::initConnections() 
{
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));


}


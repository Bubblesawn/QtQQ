#include "titlebar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include <QRectF>
#include <QWidget>
#include <QFile>
#include <QMouseEvent>


#define BUTTON_HEIGHT 27
#define BUTTON_WIDTH 27
#define TITLE_HEIGHT 27




TitleBar::TitleBar(QWidget *parent)
        :QWidget(parent)
        ,m_isPressed(false)
        ,m_buttonType(MIN_MAX_BUTTON)
{
    initControl();
    initConnections();
    loadStyleSheet("Title");
}

TitleBar::~TitleBar()
{

}

void TitleBar::initControl()
{
    m_pIcon = new QLabel(this);

    m_pButtonMin = new QPushButton(this);
	m_pButtonRestore = new QPushButton(this);
	m_pButtonMax = new QPushButton(this);
    m_pButtonClose = new QPushButton(this);

    //按钮设置固定大小
	m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

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
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);
    
	mylayout->setContentsMargins(5, 0, 0, 0);  //设置布局边距
    mylayout->setSpacing(0);                   //设置部件间的间隙
    
    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setFixedHeight(TITLE_HEIGHT);              //设置标题栏高度
	setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口

}

//信号槽的连接
void TitleBar::initConnections()
{
    connect(m_pButtonMin, SIGNAL(clicked), this, SLOT(onButtonMinClicked));
    connect(m_pButtonRestore,SIGNAL(clicked), this, SLOT(onButtonRestoreCliced));
    connect(m_pButtonMax, SIGNAL(clicked), this, SLOT(onButtonMaxClicked));
    connect(m_pButtonClose, SIGNAL(clicked), this, SLOT(onButtonCloseClicked));
}

//设置标题栏图标
void TitleBar::setTitleIcon(const QString& filepath) {
    QPixmap titleIcon(filepath);
    m_pIcon->setFixedSize(titleIcon.size());
    m_pIcon->setPixmap(titleIcon);
}

//设置标题栏内容
void TitleBar::setTitleContent(const QString& titlecontent){
	m_pTitleContent->setText(titlecontent);
	m_titleContent = titlecontent;//保存标题内容
}

//设置标题栏长度
void TitleBar::setTitleWidth(int width) {
    m_pTitleContent->setFixedWidth(width);
}

//设置按钮类型
void TitleBar::setButtonType(ButtonType buttontype){
	m_buttonType = buttontype;
    switch (m_buttonType) {
        case MIN_BUTTON:
			m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
            break;
        case MIN_MAX_BUTTON:
            m_pButtonRestore->setVisible(false);
            break;
        case ONLY_CLOSS_BUTTON:
            m_pButtonMin->setVisible(false);
            m_pButtonRestore->setVisible(false);
            m_pButtonMax->setVisible(false);
            break;
		default:
            break;
	}

}

//保存当前窗口的位置信息和大小
void TitleBar::saveRestoreInfo(const QPoint &point, const QSize &size) {
    m_restorePos = point;
    m_restoreSize = size;
}

//获取当前窗口的位置信息和大小
void TitleBar::getRestoreInfo(QPoint& point, QSize& size) {
    point = m_restorePos;
    size = m_restoreSize;
}

//绘制标题栏
void TitleBar::paintEvent(QPaintEvent* event) {
    //设置背景色
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill); //设置填充规则
    pathBack.addRoundedRect(QRect(0,0,width(),height()),3,3);//添加圆角矩形到绘图路径
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    //当窗口最大化或者还原后，窗口长度改变，标题栏相应做出改变
    // parentWidget() 返回父部件
    if (width() != parentWidget()->width()) {
        setFixedWidth(parentWidget()->width());
    }
   
}

  //双击响应事件，主要实现双击标题栏进行最大化最小化的操作
void TitleBar::mouseDoubleClickEvent(QMouseEvent* event) {
    //只有存在最小化、最大化才有效
    if (m_buttonType == MIN_MAX_BUTTON) {
        if (m_pButtonMax->isVisible()) {
            onButtonMaxClicked();
        }
        else {
            onButtonRestoreCliced();
        }
    }
    return QWidget::mouseDoubleClickEvent(event);
}
//通过鼠标按下、鼠标释放、鼠标移动事件实现标题栏达到移动窗口效果

void TitleBar::mousePressEvent(QMouseEvent* event) {
    QPointF posF = event->globalPosition();
    if (m_buttonType == MIN_MAX_BUTTON) {
        //在窗口最大化时禁止拖动
        if (m_pButtonMax->isVisible()) {
            m_isPressed = true;
            m_startMovePos = posF.toPoint();  // 如果你只需要整数
        }
    }
    else {
        m_isPressed = true;
        m_startMovePos = posF.toPoint();
    }
    return QWidget::mousePressEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent* event) {
    QPointF posF = event->globalPosition();
    if (m_isPressed) {
        QPoint movePoint = posF.toPoint(); - m_startMovePos;
        QPoint widgetPos = parentWidget()->pos();
        m_startMovePos = posF.toPoint();
        parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
    }
    
    return QWidget::mouseMoveEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
    m_isPressed = false;
    return QWidget::mouseReleaseEvent(event);

}

//加载样式表

void TitleBar::loadStyleSheet(const QString& sheetName) {

    QFile file(":/Resources/QSS " + sheetName + ".css");
    if (file.isOpen()) {
        QString styleSheet = this->styleSheet();
        styleSheet += QLatin1String(file.readAll());
		setStyleSheet(styleSheet);

     }

}

void TitleBar::onButtonMinClicked() {
    emit signalButtonMinClicked();
}


void TitleBar::onButtonRestoreCliced() {
    m_pButtonRestore->setVisible(false);
    m_pButtonMax->setVisible(true);
    emit signalButtonRestoreClicked();

}

void TitleBar::onButtonMaxClicked() {
    m_pButtonRestore->setVisible(true);
    m_pButtonMax->setVisible(false);
    emit signalButtonMaxClicked();
}

void TitleBar::onButtonCloseClicked() {
    emit signalButtonCloseClicked();
}


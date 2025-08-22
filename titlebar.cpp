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

    //��ť���ù̶���С
	m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
    m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

    //���ö�����
    m_pTitleContent->setObjectName("TitleContent");
	m_pButtonMin->setObjectName("ButtonMin");
	m_pButtonRestore->setObjectName("ButtonRestore");
	m_pButtonMax->setObjectName("ButtonMax");
    m_pButtonClose->setObjectName("ButtonClose");

    //���ò���
	QHBoxLayout* mylayout = new QHBoxLayout(this);
    mylayout->addWidget(m_pIcon);
	mylayout->addWidget(m_pTitleContent);
    mylayout->addWidget(m_pButtonMin);
	mylayout->addWidget(m_pButtonRestore);  
    mylayout->addWidget(m_pButtonMax);
    mylayout->addWidget(m_pButtonClose);
    
	mylayout->setContentsMargins(5, 0, 0, 0);  //���ò��ֱ߾�
    mylayout->setSpacing(0);                   //���ò�����ļ�϶
    
    m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	setFixedHeight(TITLE_HEIGHT);              //���ñ������߶�
	setWindowFlags(Qt::FramelessWindowHint);   //�����ޱ߿򴰿�

}

//�źŲ۵�����
void TitleBar::initConnections()
{
    connect(m_pButtonMin, SIGNAL(clicked), this, SLOT(onButtonMinClicked));
    connect(m_pButtonRestore,SIGNAL(clicked), this, SLOT(onButtonRestoreCliced));
    connect(m_pButtonMax, SIGNAL(clicked), this, SLOT(onButtonMaxClicked));
    connect(m_pButtonClose, SIGNAL(clicked), this, SLOT(onButtonCloseClicked));
}

//���ñ�����ͼ��
void TitleBar::setTitleIcon(QString& filepath) {
    QPixmap titleIcon(filepath);
    m_pIcon->setFixedSize(titleIcon.size());
    m_pIcon->setPixmap(titleIcon);
}

//���ñ���������
void TitleBar::setTitleContent(QString& titlecontent){
	m_pTitleContent->setText(titlecontent);
	m_titleContent = titlecontent;//�����������
}

//���ñ���������
void TitleBar::setTitleWidth(int width) {
    m_pTitleContent->setFixedWidth(width);
}

//���ð�ť����
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

//���浱ǰ���ڵ�λ����Ϣ�ʹ�С
void TitleBar::saveResoreInfo(const QPoint &point, const QSize &size) {
    m_restorePos = point;
    m_restoreSize = size;
}

//��ȡ��ǰ���ڵ�λ����Ϣ�ʹ�С
void TitleBar::getResoreInfo(QPoint& point, QSize& size) {
    point = m_restorePos;
    size = m_restoreSize;
}

//���Ʊ�����
void TitleBar::paintEvent(QPaintEvent* event) {
    //���ñ���ɫ
    QPainter painter(this);
    QPainterPath pathBack;
    pathBack.setFillRule(Qt::WindingFill); //����������
    pathBack.addRoundedRect(QRect(0,0,width(),height()),3,3);//���Բ�Ǿ��ε���ͼ·��
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    //��������󻯻��߻�ԭ�󣬴��ڳ��ȸı䣬��������Ӧ�����ı�
    // parentWidget() ���ظ�����
    if (width() != parentWidget()->width()) {
        setFixedWidth(parentWidget()->width());
    }
   
}

  //˫����Ӧ�¼�����Ҫʵ��˫�����������������С���Ĳ���
void TitleBar::mouseDoubleClickEvent(QMouseEvent* event) {
    //ֻ�д�����С������󻯲���Ч
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
//ͨ����갴�¡�����ͷš�����ƶ��¼�ʵ�ֱ������ﵽ�ƶ�����Ч��

void TitleBar::mousePressEvent(QMouseEvent* event) {
    QPointF posF = event->globalPosition();
    if (m_buttonType == MIN_MAX_BUTTON) {
        //�ڴ������ʱ��ֹ�϶�
        if (m_pButtonMax->isVisible()) {
            m_isPressed = true;
            m_startMovePos = posF.toPoint();  // �����ֻ��Ҫ����
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

//������ʽ��

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
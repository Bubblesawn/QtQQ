#include "basicwindow.h"
#include <QFile>
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <titleBar.h>

#include "CommonUtils.h"
#include "NotifyManager.h"


BasicWindow::BasicWindow(QWidget *parent)
	: QDialog(parent)
{
	m_colorBackGround = CommonUtils::getDefaultSkinColor();
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground, true); //设置窗口透明
	connect(NotifyManager::getInstance(),SIGNAL(signalSkinChanged(const QColor& )),this,SLOT(onSignalSkinChanged(const QColor&)));
}

BasicWindow::~BasicWindow()
{
}

void BasicWindow::onSignalSkinChanged(const QColor& color)
{
	m_colorBackGround = color;
	loadStyleSheet(m_styleName); //更新窗口以应用新的背景颜色
}

void BasicWindow::setTitleBarTitle(const QString& title, const QString& icon) {
	_titleBar ->setTitleIcon(icon);
	_titleBar ->setTitleContent(title);
}

void BasicWindow::initTitleBar(ButtonType buttontype) {
	_titleBar = new TitleBar(this);
	_titleBar ->setButtonType(buttontype);
	_titleBar ->move(0, 0);

	connect(_titleBar, SIGNAL(signalButtonMinCliked()), this, SLOT(onButtonMinClicked()));
	connect(_titleBar,SIGNAL(signalButtonRestoreClicked()),this,SLOT(onButtonRestoreCliced));
	connect(_titleBar,SIGNAL(signalButtonMaxClicked()),this,SLOT(onButtonMaxClicked()));
	connect(_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));

}

void BasicWindow::loadStyleSheet(const QString& sheetName) {
	m_styleName = sheetName;
	QFile file(":/Resources/QSS/" + sheetName + ".css");
	file.open(QFile::ReadOnly);

	if (file.isOpen()) {

		setStyleSheet("");
		QString qsstyleSheet = QLatin1String(file.readAll());

		//获取用户当前的背景的RGB值
		QString r = QString::number(m_colorBackGround.red());
		QString g = QString::number(m_colorBackGround.green());
		QString b = QString::number(m_colorBackGround.blue());

		qsstyleSheet += QString("QWidget[titleskin=true]\
								{background-color:rgb(%1,%2,%3);\
								border-top-left-radius:4px;}\
								QWidget[bottomskin=true]\
								{border-top:1px solid rgba(%1,%2,%3,100);\
								background-color:rgba(%1,%2,%3,50);\
								border-bottom-left-radius:4px;\
								border-bottom-right-radius:4px;}")
			.arg(r).arg(g).arg(b);
		setStyleSheet(qsstyleSheet);


	}
	file.close();	
}	
//背景图
void BasicWindow::initBackGroundColor() {
	QStyleOption opt;
	opt.initFrom(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

//子类化部件时，需要重写绘图事件设置背景图
void BasicWindow::paintEvent(QPaintEvent* event) {
	initBackGroundColor();
	QDialog::paintEvent(event);
}

//头像转圆头像
QPixmap BasicWindow::getRoundImage(const QPixmap& src, QPixmap& mask, QSize maskSize) {
	if (maskSize == QSize(0, 0)) {
		maskSize = mask.size();
	}
	else {
		mask = mask.scaled(maskSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	}

	QImage resultImage(maskSize, QImage::Format_ARGB32_Premultiplied);
	QPainter painter(&resultImage);
	painter.setCompositionMode(QPainter::CompositionMode_Source);
	painter.fillRect(resultImage.rect(), Qt::transparent);
	painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
	painter.drawPixmap(0, 0, mask);
	painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
	painter.drawPixmap(0, 0, src.scaled(maskSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	painter.end();
	return QPixmap::fromImage(resultImage);
}

void BasicWindow::onShowClose(bool) {
	close();
}

void BasicWindow::onSHowMin(bool) {
	showMinimized();
}

void BasicWindow::onShowHide(bool) {
	hide();
}

void BasicWindow::onShowNormal(bool) {
	show();
	activateWindow();
}

void BasicWindow::onShowQuit(bool) {
	QApplication::quit();
}

void BasicWindow::mouseMoveEvent(QMouseEvent* e) {
	if (m_mousePressed && (e->buttons() && Qt::LeftButton))
	{
	/*	move(e->globalPos() - m_mouseePoint);*/
		window()->move(e->globalPosition().toPoint() - m_mouseePoint);

		e->accept();
	}

}

//鼠标按下事件
void BasicWindow::mouseEvent(QMouseEvent* e) {
	if (e->button() == Qt::LeftButton) {
		m_mousePressed = true;
		/*m_mouseePoint = e->globalPos() -pos();*/
		window()->move(e->globalPosition().toPoint() - m_mouseePoint);

		accept();
	}
}

//鼠标释放事件
void BasicWindow::mouseRleaseEvent(QMouseEvent* e) {
	m_mousePressed = false;
}

void BasicWindow::onButtonMinClicked() {
	if(Qt::Tool == (windowFlags()& Qt::Tool))
		hide();
	else
	showMinimized();
}

void BasicWindow::onButtonMaxClicked() {
	// 保存窗口最大化前的大小和位置
	_titleBar->saveRestoreInfo(pos(), QSize(width(), height()));

	// 获取当前屏幕（这里用主屏幕，你也可以用 screenAt(QCursor::pos())）
	QScreen* screen = QGuiApplication::primaryScreen();
	if (!screen)
		return;

	QRect desktopRect = screen->availableGeometry();
	QRect factRect(desktopRect.x() - 3, desktopRect.y() - 3,
		desktopRect.width() + 6, desktopRect.height() + 6);

	setGeometry(factRect);
}

void BasicWindow::onButtonRestoreCliced() {
	QPoint windowPos;
	QSize windowSize;
	_titleBar->getRestoreInfo(windowPos, windowSize);
	setGeometry(QRect(windowPos, windowSize));
}

void BasicWindow::onButtonCloseClicked() {
	close();
}
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QtWidgets>
#include<QList>

#include"ctoplabel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    //托盘图标
    QSystemTrayIcon* trayIcon;

    //注册热键
    void registerGlobalKey();

    //开始截图热键ID
    int hotkeyShotBgId;

    QList<CTopLabel*> topLabelList;

    //初始化托盘;
    void initTray();

    //是否正在截图
    bool isShotting;

    //本地事件
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);




private slots:

    //开始截图
    void hotkeyShotBgReceived();

    void clearShots();





public slots:
    //关闭
    void clearShot(int i);

    //设置isShotting为false，允许再次截屏
    void allowShot();


signals:

    //开始截屏热键按下
    void hotkeyShotBgPressed();

};

#endif // MAINWINDOW_H

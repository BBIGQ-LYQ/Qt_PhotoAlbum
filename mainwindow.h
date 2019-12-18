#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString findFrontFile();
    QString findNextFile();
    void showPic(double mul);

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_REFLASH_clicked();

    void on_FRONT_clicked();

    void on_NEXT_clicked();

    void on_BIG_clicked();

    void on_SMALL_clicked();

    void on_SHUN_clicked();

    void on_DAO_2_clicked();

private:
    Ui::MainWindow *ui;

    //当前图片
    QString curPic;

    //展示倍数(初始化为1)
    double mul = 1;
};
#endif // MAINWINDOW_H

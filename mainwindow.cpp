#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>  //文件窗体
#include <QPixmap>
#include <QDebug>
#include <QMatrix>

static QStringList files;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::findFrontFile()
{
    QString temp;
    for(int i = 0; i < files.size(); i++)
    {
        if(files.at(i) == curPic)
        {
            if(i == 0)
                temp = files.at(files.size()-1);
            else
                temp = files.at(i-1);
        }

    }
    return temp;
}

QString MainWindow::findNextFile()
{
    QString temp;
    for(int i = 0; i < files.size(); i++)
    {
        if(files.at(i) == curPic)
        {
            if(i == (files.size()-1))
                temp = files.at(0);
            else
                temp = files.at(i+1);
        }

    }
    return temp;
}

void MainWindow::showPic(double mul)
{
    // 定义一个图片处理类
    QPixmap pic(curPic);
    //根据label的大小去设置
    QPixmap temp = pic.scaled(ui->SHOWPIC->width() * mul, ui->SHOWPIC->height() * mul);
    //把图片显示到标签中
    ui->SHOWPIC->setPixmap(temp);
}

void MainWindow::on_REFLASH_clicked()
{
    //获取多文件
    QStringList temp = QFileDialog::getOpenFileNames(
                             this,
                             "Select one or more files to open",
                             "/home/bbigq/workspace/QT",     //获取的路径
                             "Anyfile (*)");     //获取所有文件


    for(int i = 0; i < temp.size(); i++)
    {
         ui->listWidget->addItem(temp.at(i));   // 将文件名添加到listWidget上
         files.append(temp.at(i));
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    curPic = item->text();
    //显示在当前图片的label上
    QString msg = item->text();
    QStringList list = msg.split("/");
    ui->now_pic->setText(list.at(list.size()-1));

    showPic(1);
}


void MainWindow::on_FRONT_clicked()
{
    mul = 1;
    if(!files.isEmpty())
    {
        curPic = findFrontFile();

        //显示在当前图片的label上
        QStringList list = curPic.split("/");
        ui->now_pic->setText(list.at(list.size()-1));

        showPic(mul);
    }
    else
        qDebug() << "files is empty";
}



void MainWindow::on_NEXT_clicked()
{
    mul = 1;

    if(!files.isEmpty())
    {
        curPic = findNextFile();

        //显示在当前图片的label上
        QStringList list = curPic.split("/");
        ui->now_pic->setText(list.at(list.size()-1));

        showPic(mul);
    }
    else
        qDebug() << "files is empty";
}

void MainWindow::on_BIG_clicked()
{
    if(mul <= 2.0)
    {
        mul += 0.2;
        showPic(mul);
    }
}

void MainWindow::on_SMALL_clicked()
{
    if(mul >= 0.4)
    {
        mul -= 0.2;
        showPic(mul);
    }
}


void MainWindow::on_SHUN_clicked()
{
    QMatrix rpic;
    rpic.rotate(90);

    ui->SHOWPIC->setPixmap(ui->SHOWPIC->pixmap()->transformed(rpic, Qt::SmoothTransformation));
}

void MainWindow::on_DAO_2_clicked()
{
    QMatrix rpic;
    rpic.rotate(-90);

    ui->SHOWPIC->setPixmap(ui->SHOWPIC->pixmap()->transformed(rpic, Qt::SmoothTransformation));
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#pragma execution_character_set("utf-8")
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mTimeShow->display("00:00");
    secs = 0;
    //初始化timer
    timer = new QTimer;
    QObject::connect(timer,&QTimer::timeout,this,&MainWindow::updateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime(){
    secs++;
    QString str = QString("%1%2:%3%4").arg(secs/600).arg((secs/60)%10).arg((secs%60)/10).arg((secs%60)%10);
    ui->mTimeShow->display(str);
}


void MainWindow::on_mBegin_clicked(bool checked)
{
    if(checked){
        secs=0;
        ui->mBegin->setText("停止");
        ui->mCheckNum->clear();
        makeNums();
        timer->start(1000);
    }
    else{
        timer->stop();
        ui->mBegin->setText("开始");
        ui->mTestNum->clear();
    }
}

void MainWindow::makeNums(){
    int count = ui->mInput->text().toInt();
    QTime time = QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    nums.clear();
    for(int i=0;i<count;i++){
        int n = qrand()%10;
        nums.append(QString("%1").arg(n));
    }
    ui->mTestNum->setText(nums);
}

void MainWindow::on_mTextShow_clicked(bool checked)
{
    if(checked){
        ui->mTextShow->setText("屏蔽");
        ui->mTestNum->setText(nums);
    }
    else{
        ui->mTextShow->setText("显示");
        ui->mTestNum->clear();
    }
}

void MainWindow::on_mCheck_clicked()
{
    if(ui->mCheckNum->toPlainText() == nums){
        ui->mInfo->setText("检测通过");
    }
    else{
        ui->mInfo->setText("检测不通过");
    }
}

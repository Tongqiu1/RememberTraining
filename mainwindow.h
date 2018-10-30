#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void makeNums();

public slots:
    void updateTime();

private slots:
    void on_mBegin_clicked(bool checked);

    void on_mTextShow_clicked(bool checked);

    void on_mCheck_clicked();

private:
    Ui::MainWindow *ui;
    int secs;
    QTimer* timer;
    QString nums;
};

#endif // MAINWINDOW_H

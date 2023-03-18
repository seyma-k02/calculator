#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();



    void on_Temizle_clicked(bool checked);
    void on_Display_inputRejected();
    void on_Display_editingFinished();
    void on_Display_cursorPositionChanged(int arg1, int arg2);
};
#endif // MAINWINDOW_H

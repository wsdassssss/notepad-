#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QFileDialog"
#include "QFile"
#include "QTextStream"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionSave_As_triggered();

    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackColor_triggered();

    void on_actionBackground_color_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};

#endif // MAINWINDOW_H

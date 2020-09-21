#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFontDialog"
#include "QFont"
#include "QColor"
#include "QColorDialog"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    setWindowTitle("Notepadd");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionnew_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}

void MainWindow::on_actionopen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly |QFile::Text)){
        QMessageBox::warning(this,"wrong","file not opne");
        return;
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->textEdit->setText(text);
    file.close();
    setWindowTitle(file_path);
}

void MainWindow::on_actionsave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"wrong","file not save");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"Save As the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"wrong","file not save as");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_triggered()
{
    QString about_text="Author:FYL \nFunction:TextEdit \nTime:2020-0909-1618";
    QMessageBox::about(this,"About notepad(jia)",about_text);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok){
        ui->textEdit->setFont(font);
    }else return;
}

void MainWindow::on_actionColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionBackColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }
}

void MainWindow::on_actionBackground_color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"choose color");
    //QColor color=QColorDialog::getColor(QColor(255,0,0));
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }
}

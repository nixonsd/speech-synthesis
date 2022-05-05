#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  QObject::connect(ui->pushButton, &QPushButton::clicked, this,
                   &MainWindow::onButtonClick);
  QObject::connect(ui->actionExit, &QAction::triggered, this,
                   &MainWindow::onExitAction);
  QObject::connect(ui->actionInfo, &QAction::triggered, this,
                   &MainWindow::onInfoAction);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onButtonClick() {}

void MainWindow::onInfoAction() {
  QMessageBox msg;
  msg.setIcon(QMessageBox::Information);
  msg.setWindowTitle("Information Message");
  msg.setText(
      "The program has been designed for educational purposes. For more "
      "information, please contact me (Bohdan Kiselov) by e-mail: "
      "kiselov.bohdan2@gmail.com");
  msg.exec();
}

void MainWindow::onExitAction() { this->close(); }

#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QObject::connect(ui->pushButton, &QPushButton::clicked, this,
                   &MainWindow::onExecuteButtonClick);

  QObject::connect(ui->actionExit, &QAction::triggered, this,
                   &MainWindow::exit);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onExecuteButtonClick() {
  test_source t;

  if (t.test()) {
    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
  }
}

void MainWindow::exit() { this->close(); }

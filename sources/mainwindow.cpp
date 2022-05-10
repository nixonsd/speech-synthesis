#include "mainwindow.h"

#include "./ui_mainwindow.h"

SpeechSynthesis::EspeakInterface *espeakInterface = nullptr;
SpeechSynthesis::EspeakOptions espeakOptions = {AUDIO_OUTPUT_SYNCH_PLAYBACK,
                                                500, NULL, 0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  espeakInterface =
      SpeechSynthesis::EspeakInterface::GetInstance(espeakOptions);
  ui->setupUi(this);
  QObject::connect(ui->pushButton, &QPushButton::clicked, this,
                   &MainWindow::onButtonClick);
  QObject::connect(ui->actionExit, &QAction::triggered, this,
                   &MainWindow::onExitAction);
  QObject::connect(ui->actionInfo, &QAction::triggered, this,
                   &MainWindow::onInfoAction);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::onButtonClick() {
  QString qstr = ui->textEdit->toPlainText();
  QByteArray qbyte = qstr.toLocal8Bit();
  espeakInterface->Synth(qbyte.data());
}

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

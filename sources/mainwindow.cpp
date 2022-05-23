#include "mainwindow.h"

#include "./ui_mainwindow.h"

#ifdef WIN32 
  #define ESPEAK_DATA_PATH "./"
#else
  #define ESPEAK_DATA_PATH NULL
#endif

SpeechSynthesis::EspeakInterface *espeakInterface = nullptr;
SpeechSynthesis::EspeakOptions espeakOptions = {AUDIO_OUTPUT_SYNCH_PLAYBACK,
                                                500, ESPEAK_DATA_PATH, 0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  espeakInterface =
      SpeechSynthesis::EspeakInterface::GetInstance(espeakOptions);

  ui->setupUi(this);

  QObject::connect(ui->pushButton, &QPushButton::clicked, this,
                   &MainWindow::onButtonClick);
  QObject::connect(ui->actionAbout, &QAction::triggered, this,
                   &MainWindow::onAboutAction);
  QObject::connect(ui->actionOpen, &QAction::triggered, this,
                   &MainWindow::onOpenAction);

  ui->textEdit->installEventFilter(this);
}

MainWindow::~MainWindow() { delete ui; }

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
  if (obj == ui->textEdit && event->type() == QEvent::KeyPress) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (keyEvent->key() == Qt::Key_Return &&
        keyEvent->modifiers() != Qt::ShiftModifier) {
      ui->pushButton->click();
      return true;
    }
  }
  return QMainWindow::eventFilter(obj, event);
}

void MainWindow::onButtonClick() {
  QString qstr = ui->textEdit->toPlainText();
  QByteArray qbyte = qstr.toLocal8Bit();
  espeakInterface->Synth(qbyte.data());
}

void MainWindow::onOpenAction() {
  QFileDialog *dialog = new QFileDialog(this, tr("Choose file to open..."),
                                        nullptr, tr("Text files (*.txt)"));
  QString fileName = dialog->getOpenFileName();
  if (!fileName.isEmpty()) {
    QFile *file = new QFile(fileName);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox msg;
      QString errMsg = "Cannot open file " + fileName;
      msg.setIcon(QMessageBox::Icon::Critical);
      msg.setWindowTitle("Error reading file");
      msg.setText(errMsg);
      msg.exec();
    } else {
      QTextStream textStream(file);
      QString readText = textStream.readAll();
      ui->textEdit->setPlainText(readText);
      file->close();
    }
    delete file;
  }
  delete dialog;
}

void MainWindow::onAboutAction() {
  QMessageBox msg;
  msg.setIcon(QMessageBox::Icon::Information);
  msg.setWindowTitle("Information Message");
  msg.setText(
      "The program has been designed for educational purposes. For more "
      "information, please contact me (Bohdan Kiselov) by e-mail: "
      "kiselov.bohdan2@gmail.com");
  msg.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <espeak-interface.h>

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  bool eventFilter(QObject *obj, QEvent *ev) override;

 private:
  Ui::MainWindow *ui;
  void onButtonClick();
  void onInfoAction();
};
#endif  // MAINWINDOW_H

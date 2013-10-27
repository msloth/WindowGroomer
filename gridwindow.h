#ifndef GRIDWINDOW_H
#define GRIDWINDOW_H

#include <QApplication>
#include <QSystemTrayIcon>
#include <QxtGlobalShortcut>
#include <QWidget>
#include <QDesktopWidget>

#include <QSize>
#include <QKeySequence>
#include <QDialog>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>

#include <QMessageBox>
#include <QString>

#include <QtCore/qmath.h>

#include "gridwidget.h"
#include "nativewindow.h"

class GridWindow : public QDialog
{
  Q_OBJECT
public:
  explicit GridWindow(QWidget *parent = 0);

  QSize sizeHint();

public slots:
  void receiveGrid(const QRect &grid);

private slots:
  void iconActivated(QSystemTrayIcon::ActivationReason reason);
  void shortcutPressed();

  void showAbout();
  void showPrefs();

private:
  void initWindow();
  void initActions();
  void initTray();

  void showWindow();

  QxtGlobalShortcut *shortcut;

  // Grid positioning window
  GridWidget *gridSelect;
  int sqArea;

  // TODO(aarmea): Keep track of windows positioned with WindowGroomer and
  // what windows they're next to.
  NativeWindow window;

  // Tray icon and context menus
  QSystemTrayIcon *trayIcon;
  QMenu *trayMenu;
  // TODO(aarmea): Create a preferences menu
  QAction *prefsAction;
  QAction *aboutAction;
  QAction *quitAction;
};

QRect getAreaFromCells(QRect cells, QSize gridSize, QRect availArea);

#endif

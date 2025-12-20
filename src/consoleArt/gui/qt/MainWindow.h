#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include "../../controller/ControllerQt.h"

namespace consoleart
{

class MainWindow : public QMainWindow
{
private:
	Q_OBJECT
	ControllerQt controller;
public:
	explicit MainWindow(QWidget *parent = nullptr);
signals:
};

}

#endif // MAINWINDOW_H

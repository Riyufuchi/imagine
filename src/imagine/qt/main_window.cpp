#include "main_window.h"

#include <QIcon>

imagine::MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent}
{
	resize(800, 600);
	setWindowTitle(consoleart::general_tools::IMAGINE_APP_VERSION);
	setToolTip("Still work in progress");
	setWindowIcon(QIcon(":/img/main_icon"));
}


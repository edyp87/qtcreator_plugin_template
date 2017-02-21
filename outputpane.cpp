#include "outputpane.h"
#include <QtWidgets/QTextEdit>

OutputPane::OutputPane(QObject *parent) : Core::IOutputPane(parent)
{

}

QWidget *OutputPane::outputWidget(QWidget *parent)
{
    return new QTextEdit(parent);
}

QList<QWidget *> OutputPane::toolBarWidgets() const
{
    return {};
}

QString OutputPane::displayName() const
{
    return "Example output pane";
}

int OutputPane::priorityInStatusBar() const
{
    return 1;
}

void OutputPane::clearContents()
{

}

void OutputPane::visibilityChanged(bool visible)
{
    Q_UNUSED(visible);
}

void OutputPane::setFocus()
{

}

bool OutputPane::hasFocus() const
{
    return false;
}

bool OutputPane::canFocus() const
{
    return false;
}

bool OutputPane::canNavigate() const
{
    return true;
}

bool OutputPane::canNext() const
{
    return true;
}

bool OutputPane::canPrevious() const
{
    return true;
}

void OutputPane::goToNext()
{

}

void OutputPane::goToPrev()
{

}

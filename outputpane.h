#ifndef OUTPUTPANE_H
#define OUTPUTPANE_H

#include <coreplugin/ioutputpane.h>

class OutputPane : public Core::IOutputPane
{
Q_OBJECT

public:
    OutputPane(QObject *parent = nullptr);

    QWidget *outputWidget(QWidget *parent) override;
    QList<QWidget *> toolBarWidgets() const override;
    QString displayName() const override;

    int priorityInStatusBar() const override;

    void clearContents() override;
    void visibilityChanged(bool visible) override;

    void setFocus() override;
    bool hasFocus() const override;
    bool canFocus() const override;

    bool canNavigate() const override;
    bool canNext() const override;
    bool canPrevious() const override;
    void goToNext() override;
    void goToPrev() override;
};

#endif // OUTPUTPANE_H

#ifndef OPTIONS_H
#define OPTIONS_H

#include <coreplugin/dialogs/ioptionspage.h>

class Options : public Core::IOptionsPage
{
    Q_OBJECT
public:
    explicit Options(QObject * parent = nullptr);

    QWidget *widget() override;
    void apply() override;
    void finish() override;
};

#endif // OPTIONS_H

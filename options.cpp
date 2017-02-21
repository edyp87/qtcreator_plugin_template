#include "options.h"
#include "qtcreatorpluginconstants.h"
#include <QtWidgets/QTextEdit>

Options::Options(QObject *parent) : Core::IOptionsPage(parent)
{
    setId(Core::Id("OptionsID"));
    setDisplayName(tr("QtCreator Plugin"));
    setCategory(QtCreatorPlugin::Constants::MYOPTIONSPAGE_CATEGORY);
    setDisplayCategory(QtCreatorPlugin::Constants::MYOPTIONSPAGE_CATEGORY_TR_CATEGORY);
}

QWidget *Options::widget()
{
    // here create your widget
    return new QTextEdit;
}

void Options::apply()
{
    // what happen when user click apply?
}

void Options::finish()
{
    // what happen when user click finish?
}

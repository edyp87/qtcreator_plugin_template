#include "qtcreatorpluginplugin.h"
#include "qtcreatorpluginconstants.h"
#include "options.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace QtCreatorPlugin {
namespace Internal {

QtCreatorPluginPlugin::QtCreatorPluginPlugin()
{
}

QtCreatorPluginPlugin::~QtCreatorPluginPlugin()
{
}

bool QtCreatorPluginPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    auto * command = createCommand();
    setShortcut(command);
    createMenu(command);
    createOptionsPage();

    return true;
}

void QtCreatorPluginPlugin::extensionsInitialized()
{

}

ExtensionSystem::IPlugin::ShutdownFlag QtCreatorPluginPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}

void QtCreatorPluginPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from QtCreatorPlugin."));
}

Core::Command *QtCreatorPluginPlugin::createCommand()
{
    auto * action = createAction();
    return Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                               Core::Context(Core::Constants::C_GLOBAL));
}

QAction *QtCreatorPluginPlugin::createAction()
{
    auto * action = new QAction(tr("QtCreatorPlugin Action"), this);
    connectActionToTrigger(action);
    return action;
}

void QtCreatorPluginPlugin::setShortcut(Core::Command *command)
{
    command->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
}

void QtCreatorPluginPlugin::createMenu(Core::Command *command)
{
    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("QtCreatorPlugin"));
    menu->addAction(command);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);
}

void QtCreatorPluginPlugin::connectActionToTrigger(QAction * action)
{
    connect(action, &QAction::triggered, this, &QtCreatorPluginPlugin::triggerAction);
}

void QtCreatorPluginPlugin::createOptionsPage()
{
    addAutoReleasedObject(new Options);
}

} // namespace Internal
} // namespace QtCreatorPlugin

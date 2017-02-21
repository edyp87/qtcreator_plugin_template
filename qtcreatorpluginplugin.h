#pragma once

#include "qtcreatorplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace Core
{
    class Command;
}

class QAction;

namespace QtCreatorPlugin {
namespace Internal {

class QtCreatorPluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorPlugin.json")

public:
    QtCreatorPluginPlugin();
    ~QtCreatorPluginPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
    Core::Command * createCommand();
    QAction * createAction();
    void setShortcut(Core::Command * command);
    void createMenu(Core::Command * command);
    void connectActionToTrigger(QAction * action);
    void createOptionsPage();
    void createOutputPane();
};

} // namespace Internal
} // namespace QtCreatorPlugin

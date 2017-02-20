#pragma once

#include "qtcreatorplugin_global.h"

#include <extensionsystem/iplugin.h>

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
};

} // namespace Internal
} // namespace QtCreatorPlugin

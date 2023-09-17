#include "App.h"

App* App::_app = nullptr;

App::App(int& argc, char* argv[]) : QApplication(argc, argv),
    _dataManager(nullptr),
    _qmlAppEngine(nullptr)
{
  //qDebug()<< "(App) Constructor";
  Q_ASSERT(_app == nullptr);
  _app = this;

  // Main Data Manager Class
  _dataManager = new DataManager();

  // Set Application Icon
  _app->setWindowIcon(QIcon(":/resources/icon_app.png"));

  // Set Application Version
  _app->setApplicationVersion(APP_VERSION);
}

App::~App()
{

}

QObject* App::_rootQmlObject(void)
{
  return _qmlAppEngine->rootObjects()[0];
}

QObject* dataManagerQmlGlobalSingletonFactory(QQmlEngine*, QJSEngine*)
{
  return App::_app->dataManager();
}

void App::initCommon(void)
{
  qDebug() << "(App) Init Common functionalities..";

  // Register Classes to be accesible from QML
  qmlRegisterSingletonType<DataManager>("DataManager", 1, 0, "DataManager", dataManagerQmlGlobalSingletonFactory);
}

bool App::loadQmlEngine(void)
{
  qDebug() << "(App) Init QML engine";

  _qmlAppEngine = new QQmlApplicationEngine(this);

  qDebug() << "(App).. registering qml files";

  _qmlAppEngine->addImportPath("qrc:/qml");
  _qmlAppEngine->load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

  return true;
}

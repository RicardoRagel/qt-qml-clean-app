#include "DataManager.h"
#include <QRandomGenerator>

/** *********************************
 *  DataManager Initizalization
 ** ********************************/

DataManager::DataManager()
{

  qDebug() << "(DataManager) Initialization ...";

  _timer = new QTimer(this);
  connect(_timer, &QTimer::timeout, this, QOverload<>::of(&DataManager::update));
  _timer->start(10);

  // It is necessary to pass the parent to the Item children so we can
  // access them from a Q_INVOKABLE frunction passing the ownership to QML
  // so we avoid a possible seg fault
  _item_map["ABC"].init(0, "yellow", this);
  _item_map["DEF"].init(1, "red", this);

  _qml_item_list.append(&_item_map["ABC"]);
  _qml_item_list.append(&_item_map["DEF"]);

  emit itemListChanged();
}

DataManager::~DataManager()
{

}

void DataManager::update()
{
    //qDebug() << "(DataManager) Updating item list...";

    static int number = 0;

    _item_map["ABC"].update(number, "yellow");
    _item_map["DEF"].update(number + 100, "red");

    emit itemListChanged();

    number ++;
}

QObject* DataManager::getItem(QString key)
{
    return &_item_map[key.toStdString()];
}

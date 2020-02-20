#include <iostream>
#include <list>
#include <vector>

class QAbstractButton : public QWidget {};
class QAbstractSlider : public QWidget {};
class QCheckBox : public QAbstractButton {};
class QPushButton : public QAbstractButton {};
class QWidget {
 public:
  virtual ~QWidget() = 0;
};
class QSize {};

using namespace std;

vector<QAbstractButton*> fun(list<QWidget*>& lst, const QSize& sz, vector<const QWidget*>& w) {
  vector<QAbstractButton*> temp;
  for (auto it = lst.begin(); it != lst.end(); ++it) {
    if (*it != nullptr) {
      if ((*it)->sizeHint() == sz) {
        w.push_back((*it)->clone());
        if (dynamic_cast<QAbstractSlider*>(*it) == nullptr) {
          delete *it;
          lst.erase(it);
          --it;
        } else if (typeid(**it) == typeid(QCheckBox) || typeid(**it) == typeid(QPushButton)) {
          temp.push_back(static_cast<QAbstractButton*>(*(lst.erase(it))));
          --it;
        }
      }
    }
  }
  return temp;
}
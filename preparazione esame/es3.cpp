#include <iostream>
#include <vector>

class Component;

class Container {
 public:
  virtual ~Container();
  std::vector<Component*> getComponents() const;
};

class Component : public Container {};

class Button : public Component {
 public:
  std::vector<Container*> getContainers() const;
};

class MenuItem : public Button {
 public:
  void setEnabled(bool b = true);
};

class NoButton {};

Button** Fun(const Container& c) {
  std::vector<Button*> temp;
  std::vector<Component*> containers = c.getComponents();
  bool flag = false;

  for (std::vector<Component*>::iterator it = containers.begin(); it < containers.end(); ++it) {
    Button* b = dynamic_cast<Button*>(*it);
    if (b != nullptr) {
      flag = true;
      temp.push_back(b);
    }
    MenuItem* m = dynamic_cast<MenuItem*>(*it);
    if (m != nullptr && m->getComponents().size() >= 2) {
      m->setEnabled(false);
    }
  }
  if (flag) {
    return &temp.front();
  } else {
    return nullptr;
  }
}
/// Esercizio 11.18

#include <string>
#include <vector>

class FileAudio {  // Base astratta e polimorfa
 private:
  std::string titolo;
  double size;

 public:
  double getSize() const { return size; };
  virtual bool operator==(const FileAudio& f) {
    return (titolo == f.titolo && size == f.size);
  }
  virtual bool qualita() const = 0;
  // costruttore di copia polimorfa
  virtual FileAudio* clone() const = 0;
  virtual ~FileAudio() {}  //! IMPORTANTE
};

class MP3 : public FileAudio {
 private:
  unsigned int bitrate;
  static unsigned int QU;  // soglia di qualità

 public:
  unsigned int getBitRate() const { return bitrate; };
  virtual bool operator==(const FileAudio& f) {
    if (typeid(const MP3&) != typeid(f)) {
      return false;
    }
    const MP3* p = static_cast<const MP3*>(&f);

    return FileAudio::operator==(f) && bitrate == p->bitrate;

    // return FileAudio::operator==(f) && typeid(const MP3&) == typeid(f) &&
    // bitrate == static_cast<const MP3&>(f).bitrate;
  }
  virtual bool qualita() const { return bitrate >= QU; }
  virtual MP3* clone() const { return new MP3(*this); }  //! USO LA COVARIANZA
};
unsigned int MP3::QU = 256;

class WAW : public FileAudio {
 private:
  unsigned int frequenza;
  bool lossless;
  static unsigned int QU;  // soglia di qualità

 public:
  bool getLossLess() { return lossless; }
  virtual bool operator==(const FileAudio& f) {
    if (typeid(const WAW&) != typeid(f)) {
      return false;
    }
    const WAW* p = static_cast<const WAW*>(&f);

    return FileAudio::operator==(f) && frequenza == p->frequenza &&
           lossless == p->lossless;
  }
  virtual bool qualita() const { return frequenza >= QU; }
  virtual WAW* clone() const { return new WAW(*this); }
};
unsigned int WAW::QU = 96;

class iZod {
 private:
  class Brano {
   public:
    // la richiesta della gestione della memoria per un puntatore può essere
    // implicita
    FileAudio* ptr;  // puntatore (super)polimorfo
    Brano(FileAudio* p) : ptr(p->clone()) {}
    Brano(const Brano& b) : ptr(b.ptr->clone()) {}
    Brano& operator=(const Brano& b) {
      if (this != &b) {
        delete ptr;  //! IMPORTANTE (la distruzione è polimorfa perchè il
                     //! distruttore di FileAudio è virtual)
        ptr = b.ptr->clone();
      }
      return *this;
    }
    ~Brano() { delete ptr; }
    // Se "interfaccia pubblica oppoturna" va implementato l'operatore * e
    // l'operatore ->
  };
  std::vector<Brano> brani;

 public:
  std::vector<MP3> mp3(double dim, int br) const {
    MP3* p = nullptr;
    std::vector<MP3> v;
    // siamo dentro un metodo costante quindi è const_interator e non iterator
    // auto cit = brani.begin();  // C++11
    for (std::vector<Brano>::const_iterator cit = brani.begin();
         cit != brani.end(); ++cit) {
      p = dynamic_cast<MP3*>(cit->ptr);
      // cit->ptr (oppure *(cit).ptr) è FileAudio const*
      if (p != nullptr && p->getSize() > dim && p->getBitRate() > br) {
        v.push_back(*p);  //*p perchè dereferenzio MP3* in MP3
      }
    }
  }

  std::vector<FileAudio*> fileDiQualita() const {
    WAW* p = nullptr;
    std::vector<FileAudio*> v;
    // siamo dentro un metodo costante quindi è const_interator e non iterator
    // auto cit = brani.begin();  // C++11
    for (std::vector<Brano>::const_iterator cit = brani.begin();
         cit != brani.end(); ++cit) {
      if (cit->ptr->qualita()) {
        p = dynamic_cast<WAW*>(cit->ptr);
        if (p != nullptr && p->getLossLess()) {
          v.push_back(p);
        } else {
          v.push_back(cit->ptr);
        }
      }
    }
  }

  void insert(MP3* m) {
    for (auto cit = brani.begin(); cit != brani.end(); ++cit) {
      if (*m == *(cit->ptr)) {
        return;
      }
      brani.push_back(m);
    }
  }
};
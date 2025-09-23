/*
Q3 (d) Bookshop example: media base class with read() and show() virtual, and derived Book and Audio. [15 marks]

Design idea (brief):

class Media has common data (title, publication) and virtual functions read() and show() (or maybe show() only for display and read() for reading a book or streaming audio).

Book adds numPages and overrides show() to display pages info; Audio adds playTime and overrides show() to display audio length.

Use pointers to Media to store mixed objects; calling show() on each calls correct derived version.

Short code outline:

class Media {
protected:
  string title;
  string publisher;
public:
  Media(string t, string p): title(t), publisher(p) {}
  virtual void show() const = 0; // pure virtual
  virtual ~Media() {}
};

class Book : public Media {
  int pages;
public:
  Book(string t, string p, int pg): Media(t,p), pages(pg) {}
  void show() const override {
    cout << "Book: " << title << ", pages: " << pages << '\n';
  }
};

class Audio : public Media {
  double playTime;
public:
  Audio(string t, string p, double pt): Media(t,p), playTime(pt) {}
  void show() const override {
    cout << "Audio: " << title << ", play time: " << playTime << " min\n";
  }
};

*/
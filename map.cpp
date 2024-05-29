#include "main.h"

enum ElementType
{
    PATH,
    WALL,
    FAKE_WALL
};
enum MovingObject
{
    SHERLOCK,
    WATSON,
    CRIMINAL,
    ROTBOT
};

class Position
{
private:
    int r, c;

public:
    Position(int r = 0, int c = 0);
    Position(const string &str_pos);
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const;
    bool isEqual(int in_r, int in_c) const;
};

class MapElement
{
protected:
    ElementType type;

public:
    MapElement(ElementType in_type);
    virtual ~MapElement(){};
    virtual ElementType getType() const;
};

class Path : public MapElement
{
public:
    Path();
};

class Wall : public MapElement
{
public:
    Wall();
};

class FakeWall : public MapElement
{
private:
    int req_exp; //! EXP tối thiểu mà Watson cần có để phát hiện ra bức tường.
public:
    FakeWall(int in_req_exp);
    int getReqExp() const;
    void setReqExp(int req_exp);
};

class Map
{
private:
    int num_rows, num_cols;
    MapElement ***map;

public:
    Map(int num_rows, int num_cols, int num_walls, Position *array_walls, int num_fake_walls, Position *array_fake_walls);

    ~Map();

    int getNumRows() const;
    int getNumCols() const;
    ElementType getElementType(int i, int j) const;

    bool isValid(int i, int j, MovingObject object, int exp) const;
};
void configuration(string fileName);
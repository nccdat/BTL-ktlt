#include "moving.h"
const Position Position::npos = Position(-1, -1);
/*
 * CLASS: MapElement
 */
MapElement::MapElement(ElementType in_type)
{
    // TODO: constructor
}

MapElement::~MapElement() {}

ElementType MapElement::getType() const
{
    // TODO: get
}
/*
 * CLASS: Path
 */
Path::Path()
    : MapElement(PATH) {}
/*
 * CLASS: Wall
 */
Wall::Wall()
    : MapElement(WALL) {}
/*
 * CLASS: FakeWall
 */
FakeWall::FakeWall(int in_req_exp)
    : MapElement(ElementType::FAKE_WALL)
{
    // TODO: constructor
}
int FakeWall::getReqExp() const
{
    // TODO: get
}
/*
 * CLASS: Position
 */

Position::Position(int r, int c)
{
    // TODO: constructor
}
Position::Position(const string &str_pos)
{
    // TODO: constructor
}
int Position::getRow() const
{
    // TODO: get
}
int Position::getCol() const
{
    // TODO: get
}
void Position::setRow(int r)
{
    // TODO: set
}
void Position::setCol(int c)
{
    // TODO: set
}
string Position::str() const
{
    // TODO: trả về chuỗi "(<r>,<c>)"
}
bool Position::isEqual(Position position) const
{
    // TODO: so sánh tọa độ với Position khác
}

/*
 * CLASS: MovingObject
 */
MovingObject::MovingObject(int index, const Position pos, Map *map, const string &name)
{
    // TODO: constructor
}
Position MovingObject::getCurrentPosition() const
{
    // TODO: get
}
/*
 * CLASS: Character kế thừa class MovingObject
 */
Character::Character(int index, const Position pos, Map *map, const string &name)
    : MovingObject(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}
/*
 * CLASS: Sherlock kế thừa class Character
 */

Sherlock::Sherlock(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}

Position Sherlock::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
}
void Sherlock::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
}
string Sherlock::str() const
{
    //  TODO: trả về chuỗi "Sherlock[index=<index>;pos=<pos>;moving_rule=<moving_rule>]"
}

MovingObjectType Sherlock::getObjectType() const
{
    // TODO: get
}

int Sherlock::getHP() const
{
    // TODO: get
}
int Sherlock::getEXP() const
{
    // TODO: get
}
void Sherlock::setHP(int hp)
{
    // TODO: set
}

void Sherlock::setEXP(int exp)
{
    // TODO: set
}
/*
 * CLASS: Watson kế thừa class Character
 */

Watson::Watson(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}

Position Watson::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
}

void Watson::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
}
string Watson::str() const
{
    //  TODO: trả về chuỗi "Watson[index=<index>;pos=<pos>;moving_rule=<moving_rule>]"
}

MovingObjectType Watson::getObjectType() const
{
    // TODO: get
}

int Watson::getHP() const
{
    // TODO: get
}

int Watson::getEXP() const
{
    // TODO: get
}

void Watson::setHP(int hp)
{
    // TODO: set
}

void Watson::setEXP(int exp)
{
    // TODO: set
}
/*
 * CLASS: Map
 */
Map::Map(int num_rows, int num_cols, int num_walls, Position *array_walls, int num_fake_walls, Position *array_fake_walls)
{
    // TODO: constructor
}
Map::~Map()
{
    // TODO: destructor
}

int Map::getNumRows() const
{
    // TODO: get
}
int Map::getNumCols() const
{
    // TODO: get
}
ElementType Map::getElementType(int i, int j) const
{
    // TODO: get
}
bool Map::isValid(const Position pos, MovingObject *mv_obj) const
{
    // TODO: kiểm tra đối tượng có thể di chuyển vào vị trí hay không
}
/*
 * CLASS: Criminal kế thừa class Character
 */

Criminal::Criminal(int index, const Position &init_pos, Map *map, Sherlock *sherlock, Watson *watson)
    : Character(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}
Position Criminal::getNextPosition()
{
    // TODO: tính vị trí tiếp theo dựa theo nước đi kế tiếp
}
void Criminal::move()
{
    // TODO: di chuyển đến vị trí tiếp theo và cập nhật nước đi tiếp theo
}

string Criminal::str() const
{
    // TODO: trả về chuỗi "Watson[index=<index>;pos=<pos>]"
}

MovingObjectType Criminal::getObjectType() const
{
    // TODO: get
}
int Criminal::getCount() const
{
    // TODO: get
}

/*
 * CLASS: Robot kế thừa class MovingObject
 */
Robot::Robot(int index, const Position &pos, Map *map, RobotType robot_type, Criminal *criminal, const string &name)
    : MovingObject(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}
Robot *Robot::create(int index, Map *map, Criminal *criminal, Sherlock *sherlock, Watson *watson)
{
    // TODO: trả về đối tượng class kế thừa từ Robot phù hợp
}
MovingObjectType Robot::getObjectType() const
{
    // TODO: get
}
/*
 *CLASS: RobotC kế thừa class Robot
 */
RobotC::RobotC(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal)
    : Robot(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
    // OPTIONAL: Thêm thuộc tính nextPosition khởi tạo bằng vị trí tiếp theo của criminal
}

int RobotC::getDistance(Sherlock *sherlock)
{
    // TODO: get
}

int RobotC::getDistance(Watson *watson)
{
    // TODO: get
}
// TODO implement các phương thức getNextPosition, move, str, getType, getDistance
Position RobotC::getNextPosition()
{
    // TODO: tìm vị trí liền sau của Criminal
}
void RobotC::move()
{
    // TODO: di chuyển theo Criminal
}
string RobotC::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=C;dist=<distance>]"
}
int RobotC::getDistance() const
{
    // TODO: get
}
RobotType RobotC::getType() const
{
    // TODO: get
}
/*
 * CLASS: RobotW kế thừa class Robot
 */

RobotW::RobotW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Watson *watson)
    : Robot(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}

Position RobotW::getNextPosition()
{
    // TODO: tìm vị trí tiếp theo gần Watson nhất
}

void RobotW::move()
{
    // TODO: di chuyển về phía Watson
}

string RobotW::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=W;dist=<distance>]"
}

RobotType RobotW::getType() const
{
    // TODO: get
}

int RobotW::getDistance() const
{
    // TODO: get
}
/*
 * CLASS: RobotS kế thừa class Robot
 */
RobotS::RobotS(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock)
    : Robot(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}

Position RobotS::getNextPosition()
{
    // TODO: tìm vị trí tiếp theo gần Sherlock nhất
}
void RobotS::move()
{
    // TODO: di chuyển về phía Sherlock
}

string RobotS::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=S;dist=<distance>]"
}

RobotType RobotS::getType() const
{
    // TODO: get
}

int RobotS::getDistance() const
{
    // TODO: get
}
/*
 * CLASS: RobotSW kế thừa class Robot
 */
RobotSW::RobotSW(int index, const Position &init_pos, Map *map, RobotType robot_type, Criminal *criminal, Sherlock *sherlock, Watson *watson)
    : Robot(
          // TODO: constructor class cha
      )
{
    // TODO: constructor
}

// TODO implement các phương thức getNextPosition, move, str, getType, getDistance
Position RobotSW::getNextPosition()
{
    // TODO: tìm vị trí tổng giá trị khoảng cách Sherlock và Watson nhỏ nhất
}
string RobotSW::str() const
{
    // TODO: trả về chuỗi "Robot[pos=<pos>;type=S;dist=<distance>]"
}
RobotType RobotSW::getType() const
{
    // TODO: get
}
int RobotSW::getDistance() const
{
    // TODO: get tổng khoảng cách đến Sherlock và Watson
}
void RobotSW::move()
{
    // TODO: di chuyển đến gần cả Sherlock và Watson
}
/*
 * CLASS: ArrayMovingObject
 */

ArrayMovingObject::ArrayMovingObject(int capacity)
{
    // TODO: constructor
}
ArrayMovingObject::~ArrayMovingObject()
{
    // TODO: destructor
}
bool ArrayMovingObject::isFull() const
{
    // TODO: kiểm tra số lượng đối tượng đã đầy hay chưa
}
bool ArrayMovingObject::add(MovingObject *mv_obj)
{
    // TODO: thêm đối tượng mới vào cuối mảng đối tượng
}
MovingObject *ArrayMovingObject::get(int index) const
{
    // TODO: trả về đối tượng có index tương ứng
}

int ArrayMovingObject::size() const
{
    // TODO: trả về số lượng đối tượng trong mảng
}

string ArrayMovingObject::str() const
{
    // TODO: trả về chuỗi biểu diễn mảng
}
/*
 * CLASS: Configuration
 */
Configuration::Configuration(const string &filepath)
{
    //    TODO: constructor
}

Configuration::~Configuration()
{
    // TODO: destructor
}
string Configuration::str() const
{
    // TODO: trả về chuỗi mô tả file
}
/*
 * CLASS: StudyPinkProgram
 */
StudyPinkProgram::StudyPinkProgram(const string &config_file_path)
{
    config = new Configuration(config_file_path);
    map = new Map(config->map_num_rows, config->map_num_cols, config->num_walls, config->arr_walls, config->num_fake_walls, config->arr_fake_walls);
    arr_mv_objs = new ArrayMovingObject(config->max_num_moving_objects);
    sherlock = new Sherlock(1, config->sherlock_moving_rule, config->sherlock_init_pos, map, config->sherlock_init_hp, config->sherlock_init_exp);
    watson = new Watson(2, config->watson_moving_rule, config->watson_init_pos, map, config->watson_init_hp, config->watson_init_exp);
    criminal = new Criminal(0, config->criminal_init_pos, map, sherlock, watson);

    arr_mv_objs->add(criminal);
    arr_mv_objs->add(sherlock);
    arr_mv_objs->add(watson);
}
StudyPinkProgram::~StudyPinkProgram()
{
    // TODO: hủy những đối tượng cấp phát
    // * Nếu thực hiện hủy toàn bộ trong ArrayMovingObject thì không cần delete criminal, sherlock và watson
    // delete map;
    // delete config;
    // delete arr_mv_objs;
}
void StudyPinkProgram::printMap(ofstream &OUTPUT, int roundSize) const
{
    for (int i = -1; i < config->map_num_cols; i++)
    {
        if (i == -1)
            OUTPUT << setw(5) << ""
                   << "|";
        else
            OUTPUT << setw(5) << i << "|";
    }
    OUTPUT << endl;
    for (int i = 0; i < config->map_num_rows; i++)
    {
        OUTPUT << setw(5) << i << "|";
        for (int j = 0; j < config->map_num_cols; j++)
        {
            int idx = map->getElementType(i, j);
            string nameElement[3] = {"     ", "IIIII", "-----"};
            string nameChar[4] = {"S", "W", "C", "R"};
            string robotName[4] = {"c", "s", "w", "2"};
            string cellValue = nameElement[idx];
            Position charPos(i, j);
            for (int k = 0; k < roundSize; k++)
            {
                if (arr_mv_objs->get(k)->getCurrentPosition().isEqual(charPos))
                {
                    if (cellValue == "     " || cellValue == "-----" || cellValue == "IIIII")
                        cellValue = "";
                    idx = arr_mv_objs->get(k)->getObjectType();
                    if (idx == 3)
                    {
                        MovingObject *temp = arr_mv_objs->get(k);
                        cellValue += robotName[dynamic_cast<Robot *>(temp)->getType()];
                        continue;
                    }
                    cellValue += nameChar[idx];
                }
            }
            if (!(cellValue == "     " || cellValue == "-----" || cellValue == "IIIII"))
                cellValue = "(" + cellValue + ")";
            OUTPUT << setw(5) << cellValue << "|";
        }
        OUTPUT << endl;
    }
}
void StudyPinkProgram::run(ofstream &OUTPUT)
{
    if (!OUTPUT.is_open())
    {
        cout << "Can't open file" << endl;
        return;
    }
    OUTPUT << config->str() << endl;
    for (int istep = 0; istep < config->num_steps; ++istep)
    {
        OUTPUT << "__________________NEW STEP__________________" << endl;
        MovingObject *robot = nullptr;
        int roundSize = arr_mv_objs->size();
        for (int i = 0; i < roundSize; ++i)
        {

            OUTPUT << "ROUND : " << istep << " - TURN : " << i << endl;
            stringstream ss(arr_mv_objs->str());
            string lineArr = "";
            getline(ss, lineArr, 'C');
            OUTPUT << lineArr << "]" << endl;
            getline(ss, lineArr, ']');
            OUTPUT << "\tC" << lineArr.substr(1) << "]" << endl;
            while (getline(ss, lineArr, ']'))
            {
                if (lineArr.length() > 0)
                    OUTPUT << "\t" << lineArr.substr(1) << "]" << endl;
            }
            if (i == 0)
                OUTPUT << "Criminal current count : " << criminal->getCount() << endl;
            if (i == 1)
                OUTPUT << "Sherlock move direction : " << config->sherlock_moving_rule[istep % config->sherlock_moving_rule.length()] << endl;
            if (i == 2)
                OUTPUT << "Watson move direction : " << config->watson_moving_rule[istep % config->watson_moving_rule.length()] << endl;

            if (arr_mv_objs->get(i)->getObjectType() == MovingObjectType::CRIMINAL)
            {
                robot = Robot::create(arr_mv_objs->size(), map, criminal, sherlock, watson);
            }
            arr_mv_objs->get(i)->move();
            if (i == 0)
                OUTPUT << "Criminal count after moving : " << criminal->getCount() << endl;

            printMap(OUTPUT, roundSize);
            OUTPUT << "*********************************************************" << endl;
        }
        if (robot != nullptr)
        {
            if (criminal->getCount() % 3 == 0 && criminal->getCount() > 0)
            {
                string robotType[4] = {"C", "S", "W", "SW"};
                OUTPUT << "Robot " << robotType[dynamic_cast<Robot *>(robot)->getType()] << " has been created" << endl;
                arr_mv_objs->add(robot);
            }
            else
            {
                // delete robot;
            }
        }
    }
}
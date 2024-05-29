#include "fight.h"
// ! Nội dung task cũ cần bỏ vào (chỉ bỏ dòng #include "moving.h")
// ! Các mục sửa đổi:
// ! HÀM KHỞI TẠO: Sherlock và Watson thêm thuộc tính bag, Robot thêm thuộc tính để sinh item
// !
Robot::Robot(int index, const Position &pos, Map *map, RobotType robot_type, Criminal *criminal, const string &name)
    : MovingObject(index, pos, map, name), criminal(criminal), robot_type(robot_type) //! khác
{
    // TODO: tính toán loại item
}
Sherlock::Sherlock(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(index, init_pos, map, "Sherlock"), moving_rule(moving_rule), HP(init_hp), EXP(init_exp), index_moving_rule(0)
{
    // TODO: thêm thuộc tính bag
}
Watson::Watson(int index, const string &moving_rule, const Position &init_pos, Map *map, int init_hp, int init_exp)
    : Character(index, init_pos, map, "Watson"), moving_rule(moving_rule), HP(init_hp), EXP(init_exp), index_moving_rule(0)
{
    // TODO: thêm thuộc tính bag
}

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
    stopChecker = false;
}
StudyPinkProgram::~StudyPinkProgram()
{
    // delete map;
    // delete config;
    // delete arr_mv_objs;
}

void StudyPinkProgram::printMap(ofstream &OUTPUT) const
{
    for (int i = -1; i < config->map_num_cols; i++)
    {
        if (i == -1)
            OUTPUT << setw(7) << ""
                   << "|";
        else
            OUTPUT << setw(7) << i << "|";
    }
    OUTPUT << endl;
    for (int i = 0; i < config->map_num_rows; i++)
    {
        OUTPUT << setw(7) << i << "|";
        for (int j = 0; j < config->map_num_cols; j++)
        {
            int idx = map->getElementType(i, j);
            string nameElement[3] = {"     ", "IIIII", "-----"};
            string nameChar[4] = {"S", "W", "C", "R"};
            string robotName[4] = {"0", "1", "2", "3"};
            string cellValue = nameElement[idx];
            Position charPos(i, j);
            for (int k = 0; k < arr_mv_objs->size(); k++)
            {
                if (arr_mv_objs->get(k)->getCurrentPosition().isEqual(charPos))
                {
                    if (cellValue == "     " || cellValue == "-----" || cellValue == "IIIII")
                        cellValue = "";
                    idx = arr_mv_objs->get(k)->getObjectType();
                    if (idx == 3)
                    {
                        MovingObject *temp = arr_mv_objs->get(k);
                        while (cellValue[cellValue.length() - 1] == ' ')
                        {
                            cellValue = cellValue.substr(0, cellValue.length() - 1);
                        }
                        cellValue += robotName[dynamic_cast<Robot *>(temp)->getType()];
                        continue;
                    }
                    cellValue += nameChar[idx];
                }
            }
            if (!(cellValue == "     " || cellValue == "-----" || cellValue == "IIIII"))
                cellValue = "" + cellValue + "";
            OUTPUT << setw(7) << cellValue << "|";
        }
        OUTPUT << endl;
    }
}
void StudyPinkProgram::run(ofstream &OUTPUT)
{
    if (!OUTPUT.is_open())
    {
        return;
    }
    OUTPUT << config->str() << endl;
    stopChecker = sherlock->getHP() == 0 || watson->getHP() == 0;
    for (int istep = 0; istep < config->num_steps && !stopChecker; ++istep)
    {
        int roundSize = arr_mv_objs->size();
        for (int i = 0; i < roundSize && !stopChecker; ++i)
        {
            OUTPUT << endl
                   << "*********************************************************" << endl;
            OUTPUT << "ROUND : " << istep << " - TURN : " << i << endl;
            stringstream ss(arr_mv_objs->str());
            string lineArr = "";
            getline(ss, lineArr, 'C');
            OUTPUT << lineArr << "]" << endl;
            getline(ss, lineArr, ']');
            OUTPUT << "\tC" << lineArr << "]" << endl;
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
            if (arr_mv_objs->get(i)->getObjectType() == ROBOT)
            {
                BaseItem *item = dynamic_cast<Robot *>(arr_mv_objs->get(i))->NewItem();
                if (item)
                {
                    OUTPUT << "Robot holding item : " << item->str() << endl;
                    // delete item;
                }
            }
            MovingObject *robot = nullptr;
            if (arr_mv_objs->get(i)->getObjectType() == MovingObjectType::CRIMINAL)
            {
                robot = Robot::create(arr_mv_objs->size(), map, criminal, sherlock, watson);
            }
            arr_mv_objs->get(i)->move();
            stopChecker = arr_mv_objs->checkMeet(i);
            if (i == 0)
                OUTPUT << "Criminal count after moving : " << criminal->getCount() << endl;
            if (robot != nullptr)
            {
                if (criminal->getCount() % 3 == 0 && criminal->getCount() > 0)
                {
                    arr_mv_objs->add(robot);
                }
                else
                {
                    // delete robot;
                }
            }
            printMap(OUTPUT);
            OUTPUT << "---------------" << endl
                   << "LOG AFTER MOVE : " << endl
                   << "Sherlock HP_" << sherlock->getHP() << " EXP_" << sherlock->getEXP() << endl
                   << "Watson HP_" << watson->getHP() << " EXP_" << watson->getEXP() << endl
                   << "SherlockBag : " << sherlock->getBag()->str() << endl
                   << "WatsonBag : " << watson->getBag()->str() << endl;
        }
    }
    OUTPUT << "---------------" << endl
           << "RESULT : ";

    if (watson->getHP() == 0)
        OUTPUT << "Watson can not continue the journey";
    else if (sherlock->getHP() == 0)
        OUTPUT << "Sherlock can not continue the journey";
    else if (stopChecker)
        OUTPUT << "The Criminal was caught";
    else
        OUTPUT << "The Criminal escaped";
}
// *------------------------------------------------------------------
// *
// *------------------------------------------------------------------
// !-----------------------------------
// ! Lưu ý về việc xét thông số khi tăng giảm
// ! Các thay đổi thông số là dựa trên thông số hiện tại
// ! Các thông số không phải số nguyên THỰC HIỆN LÀM TRÒN LÊN -> NHÂN VẬT CHỈ HI SINH KHI INIT HP = 0
// !-----------------------------------
// *CLASS: ArrayMovingObject
bool ArrayMovingObject::checkMeet(int index)
{
    // TODO: Xét va chạm của nhân vật (theo index) với các nhân vật khác trong array
    // TODO: Thực hiện xử lý các sự kiện xảy ra (thử thách, thêm item, bắt Criminal)
}
// *CLASS: Sherlock
// ! Lưu ý: ExcemptionCard được dùng để BỎ QUA nếu THỬ THÁCH THẤT BẠI -> xem như không thực hiện thử thách -> không gọi get lần 2
// ! Thực hiện get từ bag sau khi insert item
void Sherlock::setPos(Position pos)
{
    // TODO: Sử dụng trong trường hợp thắng RobotC sẽ dịch chuyển đến vị trí Criminal
}
bool Sherlock::meet(RobotS *robotS)
{
    // TODO: Xử lý khi gặp robot S
}
bool Sherlock::meet(RobotW *robotW)
{
    // TODO: Xử lý khi gặp robot W
}
bool Sherlock::meet(RobotSW *robotSW)
{
    // TODO: Xử lý khi gặp robot SW
}
bool Sherlock::meet(RobotC *robotC)
{
    // TODO: Xử lý khi gặp robot C
}
bool Sherlock::meet(Watson *watson)
{
    // TODO: Xử lý trao đổi thẻ ExcemptionCard
    // TODO: KHI CẢ 2 ĐỀU CÓ THỂ TRAO ĐỔI && ĐỔI TOÀN BỘ NẾU NHIỀU HƠN 1 (KỂ CẢ KHI ĐỐI PHƯƠNG)
}
// *CLASS: Watson
// ! Lưu ý: PassingCard được dùng khi GẶP ROBOT để bỏ qua thử thách nếu đúng loại thẻ
// ! Thực hiện get từ bag sau khi insert item
bool Watson::meet(RobotS *robotS)
{
    // TODO: Xử lý trao đổi khi gặp robot S
}
bool Watson::meet(RobotW *robotW)
{
    // TODO: Xử lý trao đổi khi gặp robot W
}
bool Watson::meet(RobotSW *robotSW)
{
    // TODO: Xử lý trao đổi khi gặp robot SW
}
bool Watson::meet(RobotC *robotC)
{
    // TODO: Xử lý trao đổi khi gặp robot C
}
bool Watson::meet(Sherlock *sherlock)
{
    // TODO: Xử lý trao đổi khi gặp Sherlock
}

BaseBag *Sherlock::getBag() const
{
    // TODO: get bag
}
BaseBag *Watson::getBag() const
{
    // TODO: get bag
}